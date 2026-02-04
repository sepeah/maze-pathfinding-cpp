#include "maze.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Maze::Maze(int width, int height)
    : w(width), h(height),
      grid(height, std::vector<char>(width, '#')),
      visited(height, std::vector<bool>(width, false)),
      newtEncountered(false)
{
    std::srand(std::time(nullptr));
}

void Maze::generate() {
    for (int y = 1; y < h - 1; y++) {
        for (int x = 1; x < w - 1; x++) {
            if (std::rand() % 10 < 7) // 60% chance of open space
                grid[y][x] = ' ';
        }
    }

    // Ensure start and end are always accessible
    grid[1][1] = 'S';
    grid[h - 2][w - 2] = 'E';
    
    // Clear paths around start and end to improve connectivity
    if (w > 3) grid[1][2] = ' ';
    if (h > 3) grid[2][1] = ' ';
    if (w > 3) grid[h-2][w-3] = ' ';
    if (h > 3) grid[h-3][w-2] = ' ';

    // insert a newt in a random position
    int randX = 1 + std::rand() % (w - 2);  // Random interior position
    int randY = 1 + std::rand() % (h - 2);
    grid[randY][randX] = 'n';
}

void Maze::print_original() const {
    for (const auto& row : grid) {
        for (char c : row) {
            if (c == 'n') {
                std::cout << newt; // yellow newt
            } else {
                std::cout << c;
            }
        }
        std::cout << "\n\n";
    }
}

bool Maze::dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= w || y >= h)
        return false;

    if (grid[y][x] == '#' || visited[y][x])
        return false;

    visited[y][x] = true;

    if (grid[y][x] == 'E')
        return true;

    // Mark path
    if (grid[y][x] == ' ' || grid[y][x] == 'n') {
        if (grid[y][x] == 'n') {
            newtEncountered = true;  // Track that we found the newt
        }
        grid[y][x] = '.';
    }

    if (dfs(x + 1, y)) return true;
    if (dfs(x - 1, y)) return true;
    if (dfs(x, y + 1)) return true;
    if (dfs(x, y - 1)) return true;

    // Backtrack: restore original character (but don't touch S)
    if (grid[y][x] == '.')
        grid[y][x] = ' ';

    return false;
}

bool Maze::solve() {
    // Reset visited array and newt flag before solving
    newtEncountered = false;
    for (auto& row : visited) {
        std::fill(row.begin(), row.end(), false);
    }
    return dfs(1, 1);
}

void Maze::print_solution() const {
    for (const auto& row : grid) {
        for (char c : row) {
            if (c == 'n') {
                std::cout << newt; // yellow newt
            } else {
                std::cout << c;
            }
        }
        std::cout << "\n\n";
    }
}

bool Maze::wasNewtEncountered() const {
    return newtEncountered;
}
