#pragma once
#include <vector>
#include <string>

// Global constant for yellow "n"
const std::string newt = "\033[33mn\033[0m";

class Maze {
public:
    Maze(int width, int height);

    void generate();
    bool solve();
    void print_original() const;
    void print_solution() const;
    bool wasNewtEncountered() const;  // Check if newt was in the solution path

private:
    int w, h;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<bool>> visited;
    bool newtEncountered;  // Track if path goes through newt

    bool dfs(int x, int y);
};
