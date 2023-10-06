# Education_Initiatives_Task
# Name: Disha Dugad
# Roll No: 20BCP048

# To-Do List Manager

## Problem Statement

Create a simple To-Do List Manager where users can efficiently manage their tasks. The application should allow users to add new tasks, mark them as completed, delete them, and view tasks based on their completion status. Additionally, users should have the ability to undo or redo their actions using the Memento Pattern, and tasks should be constructed using the Builder Pattern with optional attributes like due date or tags.

## Functional Requirements

1. **Add Tasks**: Users can add new tasks with a description and due date.

2. **Task Completion**: Tasks can be marked as 'completed' or 'pending'.

3. **Task Deletion**: Users can delete tasks from the list.

4. **View Tasks**: Users can view tasks either all at once or filtered by 'completed' or 'pending' status.

## Key Focus

1. **Behavioral Pattern (Memento)**: Implement the Memento Pattern to allow users to undo or redo actions performed on tasks.

2. **Creational Pattern (Builder)**: Use the Builder Pattern for constructing tasks. This pattern allows tasks to be created with optional attributes, maintaining readability and flexibility.

3. **Object-Oriented Programming (OOP)**: Focus on encapsulation by organizing task data and methods within a class. This ensures a clear and structured design.

## Example Usage

### Possible Inputs

- **Add Task**: "Buy groceries, Due: 2023-09-20"
- **Mark Completed**: "Buy groceries"
- **View Tasks**: "Show all", "Show completed", "Show pending"

### Possible Outputs

- **Task List**: Display tasks along with their status and due dates, for example: "Buy groceries - Completed, Due: 2023-09-20".

## Solution Overview

The solution provides a Flask-based web application implementing the specified requirements. Tasks are managed using the Memento Pattern, allowing users to undo or redo their actions. The Builder Pattern is employed for task construction, enabling the addition of optional attributes. Encapsulation is maintained through appropriate class organization.

## Getting Started

1. **Clone the Repository**:

   ```bash
   git clone (https://github.com/dishadugad16/Education_Initiatives_Task.git)
   cd todo-list-manager
   ```

2. **Install Dependencies**:

   ```bash
   pip install -r requirements.txt
   ```

3. **Run the Application**:

   ```bash
   python app.py
   ```

   The application will be accessible at `http://localhost:5000`.

## Usage

- **Add Task**: Enter task details (name, description, due date) and click 'Add'.
- **Mark Completed**: Click 'Mark Completed' next to the task you want to mark as completed.
- **Delete Task**: Click 'Delete' next to the task you want to delete.
- **View Tasks**: Use the navigation links to view all tasks, completed tasks, or pending tasks.

## Contributing

1. Fork the repository on GitHub.
2. Clone your forked repository locally.
3. Create a new branch for your feature or bug fix.
4. Make your changes, and test thoroughly.
5. Commit your changes and push to your repository.
6. Submit a pull request for review.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to customize this README according to your project's specific details and requirements. Good luck with your To-Do List Manager project!
