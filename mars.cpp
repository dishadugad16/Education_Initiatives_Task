// Name: Disha Dugad
// Roll No: 20BCP172
// Date:6th October 2023

// Mars Programming Exercise for Eductaion Initiatives Coding Test

#include <iostream>
#include <vector>
#include <set>
#include<bits+/stdcpp>
using namespace std

class Grid {
private:
    int size_x;
    int size_y;
    set<pair<int, int>> obstacles;

public:
    Grid(int x, int y) : size_x(x), size_y(y) {}

    void addObstacle(int x, int y) {
        obstacles.insert({x, y});
    }

    bool hasObstacle(int x, int y) {
        return obstacles.find({x, y}) != obstacles.end();
    }
};

class Rover {
private:
    int x;
    int y;
    char direction;
    Grid* grid;
    bool obstacleDetected;

public:
    Rover(int startX, int startY, char startDirection, Grid* gridPtr) 
        : x(startX), y(startY), direction(startDirection), grid(gridPtr), obstacleDetected(false) {}

    void move() {
        int newX = x, newY = y;

        if (direction == 'N') {
            newY++;
        } else if (direction == 'S') {
            newY--;
        } else if (direction == 'E') {
            newX++;
        } else if (direction == 'W') {
            newX--;
        }

        if (newX >= 0 && newX < grid->getSizeX() && newY >= 0 && newY < grid->getSizeY() && !grid->hasObstacle(newX, newY)) {
            x = newX;
            y = newY;
        } else {
            obstacleDetected = true;
        }
    }

    void turnLeft() {
        if (direction == 'N') {
            direction = 'W';
        } else if (direction == 'S') {
            direction = 'E';
        } else if (direction == 'E') {
            direction = 'N';
        } else if (direction == 'W') {
            direction = 'S';
        }
    }

    void turnRight() {
        if (direction == 'N') {
            direction = 'E';
        } else if (direction == 'S') {
            direction = 'W';
        } else if (direction == 'E') {
            direction = 'S';
        } else if (direction == 'W') {
            direction = 'N';
        }
    }

    std::string generateStatusReport() {
        if (obstacleDetected) {
            return "Rover is at (" + to_string(x) + ", " + to_string(y) + ") facing " + direction + ". Obstacle detected. Rover stopped.";
        } else {
            return "Rover is at (" + to_string(x) + ", " + to_string(y) + ") facing " + direction + ". No obstacles detected.";
        }
    }
};

int main() {
    Grid grid(10, 10);
    grid.addObstacle(2, 2);
    grid.addObstacle(3, 5);

    Rover rover(0, 0, 'N', &grid);
    vector<char> commands = {'M', 'M', 'R', 'M', 'L', 'M'};

    for (char command : commands) {
        if (command == 'M') {
            rover.move();
        } else if (command == 'L') {
            rover.turnLeft();
        } else if (command == 'R') {
            rover.turnRight();
        }
    }

    cout<<rover.generateStatusReport()<<endl;

    return 0;
}
