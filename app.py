from datetime import datetime
from flask import Flask, render_template, request, redirect, url_for
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///db.sqlite'
db = SQLAlchemy(app)

# Represents the state of a Todo object at a specific point in time
class TodoMemento:
    def __init__(self, name, description, due_date, done):
        self.name = name
        self.description = description
        self.due_date = due_date
        self.done = done

# Originator class for creating mementos and restoring the state
class TodoOriginator:
    def __init__(self, todo):
        self._todo = todo

    def create_memento(self):
        return TodoMemento(self._todo.name, self._todo.description, self._todo.due_date, self._todo.done)

    def restore(self, memento):
        self._todo.name = memento.name
        self._todo.description = memento.description
        self._todo.due_date = memento.due_date
        self._todo.done = memento.done

# Caretaker class to manage mementos
class TodoCaretaker:
    def __init__(self):
        self._mementos = []

    def add_memento(self, memento):
        self._mementos.append(memento)

    def get_memento(self, index):
        return self._mementos[index]

# Builder pattern for creating Todo objects
class TodoBuilder:
    def __init__(self):
        self.name = None
        self.description = None
        self.due_date = None
        self.done = False

    def set_name(self, name):
        self.name = name
        return self

    def set_description(self, description):
        self.description = description
        return self

    def set_due_date(self, due_date):
        self.due_date = due_date
        return self

    def set_done(self, done):
        self.done = done
        return self

    def build(self):
        return Todo(name=self.name, description=self.description, due_date=self.due_date, done=self.done)

# Todo model representing tasks
class Todo(db.Model):
    task_id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(100))
    description = db.Column(db.String(255))
    due_date = db.Column(db.Date)
    done = db.Column(db.Boolean)

# Route for the home page, displaying all tasks
@app.route('/')
def home():
    todo_list = Todo.query.all()
    return render_template('base.html', todo_list=todo_list)

# Route for adding a new task
@app.route('/add', methods=['POST'])
def add():
    name = request.form.get("name")
    description = request.form.get("description")
    due_date_str = request.form.get("due_date")
    due_date = datetime.strptime(due_date_str, '%Y-%m-%d').date() if due_date_str else None
    todo_builder = TodoBuilder().set_name(name).set_description(description).set_due_date(due_date)
    new_task = todo_builder.build()
    db.session.add(new_task)
    db.session.commit()
    return redirect(url_for("home"))

# Route for displaying completed tasks
@app.route('/completed')
def completed_tasks():
    completed_todo_list = Todo.query.filter_by(done=True).all()
    return render_template('base.html', todo_list=completed_todo_list)

# Route for displaying pending tasks
@app.route('/pending')
def pending_tasks():
    pending_todo_list = Todo.query.filter_by(done=False).all()
    return render_template('base.html', todo_list=pending_todo_list)

# Route for updating task status (toggle between done and pending)
@app.route('/update/<int:todo_id>')
def update(todo_id):
    todo = Todo.query.get(todo_id)
    todo.done = not todo.done
    db.session.commit()
    return redirect(url_for("home"))

# Route for deleting a task
@app.route('/delete/<int:todo_id>')
def delete(todo_id):
    todo = Todo.query.get(todo_id)
    db.session.delete(todo)
    db.session.commit()
    return redirect(url_for("home"))

# Route for undoing the last action
@app.route('/undo')
def undo():
    todo = Todo.query.get(1)  # Assuming you have at least one Todo object in the database
    originator = TodoOriginator(todo)
    if len(caretaker._mementos) > 0:
        memento = caretaker.get_memento(-1)
        originator.restore(memento)
        caretaker._mementos.pop(-1)
    return redirect(url_for("home"))

# Route for redoing the last undone action
@app.route('/redo')
def redo():
    todo = Todo.query.get(1)  # Assuming you have at least one Todo object in the database
    originator = TodoOriginator(todo)
    if caretaker._mementos:
        memento = caretaker.get_memento(-1)
        originator.restore(memento)
    return redirect(url_for("home"))

if __name__ == '__main__':
    app.run(debug=True)
