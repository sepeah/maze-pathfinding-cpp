# Maze Pathfinding in C++

A terminal-based maze generator and solver featuring the **newt** companion.

*A project demonstrating algorithms, object-oriented programming, and experimenting with simple game development fundamentals in C++.*


<img width="379" height="349" alt="maze" src="https://github.com/user-attachments/assets/f8a16068-c7da-4f8e-b07c-c3631656b610" />
<img width="379" height="349" alt="maze" src="https://github.com/user-attachments/assets/f8a16068-c7da-4f8e-b07c-c3631656b610" />


## Features

- **Random maze generation** with customizable dimensions
- **Depth-First Search (DFS) pathfinding** algorithm
- **newt companion** - escape with or without the newt
- **Colorful terminal output** testing ANSI color codes
- **Multiple ending scenarios** based on your escape route

## How it works

The Evil Wizard Dratsab Suoicsiv has trapped you in a random maze! The program creates a maze, and tries to find a path to escape from **S** (start) to **E** (end). Watch out for the **newt** - will your path cross with it?

## Compilation and Running

```bash
g++ -o maze main.cpp maze.cpp
./maze
```

## Game Elements

- `S` - Start position
- `E` - End position  
- `#` - Walls
- ` ` - Open paths
- `n` - The magical newt
- `.` - Your escape route (shown in solution)

## Possible Outcomes

1. **"Escaped the maze with the newt!"** - Your path crossed the newt's location
2. **"Escaped the maze! But the newt is still trapped!"** - You found a path that didn't encounter the newt
3. **"Forever trapped in the maze with the newt"** - No escape route exists

## Technical details/what I wanted to demo with this project

- **Algorithm**: Recursive Depth-First Search with backtracking
- **Data Structure**: 2D vector grid representation
- **Random Generation**: Time-seeded random number generation
- **Memory Management**: STL containers with automatic cleanup

## Future
This small project immediately took me back some decades to my dungeon-crawling days. That's probably why the newt emerged. 
A small rogue-like game could be the next step,
It would certainly bring some challenges and teach me a lot about coding with c++.

- Player-controlled movement
- terminal/screen manipulation
- Inventory system
- Monster AI
- Save/load functionality etc.

---
