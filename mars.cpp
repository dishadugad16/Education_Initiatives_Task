// Name: Disha Dugad
// Roll No: 20BCP048
// Date:6th October 2023

// Mars Programming Exercise for Eductaion Initiatives Coding Test

#include <iostream>
#include <vector>
#include <set>
#include<bits/stdc++.h>
using namespace std

class Component {
public:
    virtual bool hasObstacle(int x, int y) = 0;
    virtual ~Component() {}
};

class Leaf : public Component {
private:
    int x;
    int y;

public:
    Leaf(int x, int y) : x(x), y(y) {}

    bool hasObstacle(int x, int y) override {
        return (this->x == x && this->y == y);
    }
};

class Composite : public Component {
private:
    vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    bool hasObstacle(int x, int y) override {
        for (Component* child : children) {
            if (child->hasObstacle(x, y)) {
                return true;
            }
        }
        return false;
    }

    ~Composite() {
        for (Component* child : children) {
            delete child;
        }
    }
};

class Grid {
private:
    int size_x;
    int size_y;
    Composite* obstacles;

public:
    Grid(int x, int y) : size_x(x), size_y(y), obstacles(new Composite()) {}

    void addObstacle(int x, int y) {
        obstacles->add(new Leaf(x, y));
    }

    bool hasObstacle(int x, int y) {
        return obstacles->hasObstacle(x, y);
    }

    ~Grid() {
        delete obstacles;
    }
};

int main() {
    Grid grid(10, 10);
    grid.addObstacle(2, 2);
    grid.addObstacle(3, 5);

    Rover rover(0, 0, 'N', &grid);
    vector<Command*> commands = {
        new MoveCommand(&rover),
        new MoveCommand(&rover),
        new TurnRightCommand(&rover),
        new MoveCommand(&rover),
        new TurnLeftCommand(&rover),
        new MoveCommand(&rover)
    };

    for (Command* command : commands) {
        rover.executeCommand(command);
    }

    cout<<rover.generateStatusReport()<<endl;

    // Clean up the allocated command objects
    for (Command* command : commands) {
        delete command;
    }

    return 0;
}
