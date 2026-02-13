#include <iostream>
#include <vector>
#include <conio.h>   // for _getch()

std::string getRoomDescription(int x, int y) {
    if (x < 19 && x >0 && y < 4) {
        return "A cosy tavern, but you get strange looks and the patrons seem unfriendly.";
    }
    else if (x > 18 && y < 4) {
        return "This seems to be a private area. A scarfaced old man glares at you from the corner.";
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
        system("cls");  // clear screen

        // Draw map + player
        for (int y = 0; y < map.size(); y++) {
            for (int x = 0; x < map[y].size(); x++) {
                if (x == px && y == py)
                    std::cout << '@';
                else
                    std::cout << map[y][x];
            }
            std::cout << "\n";
        }
        // Status panel
std::cout << "\n" << std::string(40, '=') << std::endl;  // Separator line
std::cout << "LOCATION: " << getRoomDescription(px, py) << std::endl;
std::cout << "POSITION: (" << px << ", " << py << ")" << std::endl;
std::cout << "HEALTH: 100/100" << std::endl;
std::cout << std::string(40, '=') << std::endl;
std::cout << "Commands: WASD=Move, Q=Quit" << std::endl;


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
