#include "maze.h"
#include <iostream>

int main() {

    std::cout << "\n\nThe Evil Wizard Dratsab Suoicsiv has trapped you in his random maze!\n";
    std::cout << "Let's see if you can escape!\n\n\n";
    Maze m(18, 12);

    m.generate();
    m.print_original();

    if (m.solve()) {
        if (m.wasNewtEncountered()) {
            std::cout << "\n\nEscaped the maze with the " << newt << "ewt!\n\n";
        } else {
            std::cout << "\n\nEscaped the maze! But the " <<newt<< "ewt is still trapped!\n\n";
        }
        m.print_solution();
    } else {
        std::cout << "No path found. Forever trapped in the maze with the " << newt << "ewt\n\n";
    }

    return 0;
}
