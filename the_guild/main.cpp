/*
 * Author: Sepe Ahtosalo
 * Date: February 13, 2026
 * 
 * The Guild - A test for a simple Terminal-Based Game
 * 
 * A basic roguelike-style game featuring:
 * - Real-time character movement with WASD controls
 * - Dynamic room descriptions based on player position
 * - ASCII-based map visualization
 * - Cross-platform screen clearing using ANSI escape sequences
 * 
 * The player explores a tavern 
 */

#include <iostream>
#include <vector>
#include <conio.h>   // _getch()

std::string getRoomDescription(int x, int y) {
    if (x < 19 && x >0 && y < 4) {
        return "A cosy tavern, but you get strange looks and the patrons seem unfriendly.";
    }
    else if (x > 18 && y < 4) {
        return "This seems to be a private area. A scar-faced old man glares at you from the corner.";
    }
    else {
        return "It's still raining, you REALLY don't want to go out.";
    }
}

int main() {
    // Simple map
    std::vector<std::string> map = {
        "###########################",
        "..........................#",
        "#..................#......#",
        "#..................#......#",
        "###########################"
    };
    
    int px = 2;   // player X
    int py = 2;   // player Y

    while (true) {
        // Build entire screen in memory first to reduce flashing
        std::string screen = "\033[2J\033[H";  // Clear screen and move to top
        
        // Build map + player in memory
        for (int y = 0; y < map.size(); y++) {
            for (int x = 0; x < map[y].size(); x++) {
                if (x == px && y == py)
                    screen += '@';
                else
                    screen += map[y][x];
            }
            screen += "\n";
        }
        
        // Build status panel in memory
        screen += "\n" + std::string(40, '=') + "\n";
        screen += getRoomDescription(px, py) + "\n";
        screen += "POSITION: (" + std::to_string(px) + ", " + std::to_string(py) + ")\n";
        screen += "HEALTH: 100/100\n";
        screen += std::string(40, '=') + "\n";
        screen += "Commands: WASD=Move, Q=Quit\n";
        
        // Output everything at once
        std::cout << screen << std::flush;


        // Read key
        char c = _getch();

        // Movement
        if (c == 'w' && map[py - 1][px] == '.') py--;
        if (c == 's' && map[py + 1][px] == '.') py++;
        if (c == 'a' && map[py][px - 1] == '.') px--;
        if (c == 'd' && map[py][px + 1] == '.') px++;
        if (c == 'q') break;  // Press 'q' to quit
    }

    return 0;
}
