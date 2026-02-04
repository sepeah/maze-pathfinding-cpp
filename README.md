# Maze Pathfinding in C++

A terminal-based maze generator and solver featuring the legendary **newt** companion!

## Features

- **Random maze generation** with customizable dimensions
- **Depth-First Search (DFS) pathfinding** algorithm
- **Interactive newt companion** - escape with or without the magical creature
- **Colorful terminal output** with ANSI color codes
- **Multiple ending scenarios** based on your escape route

## How to Play

The Evil Wizard Dratsab Suoicsiv has trapped you in a random maze! Your goal is to escape from **S** (start) to **E** (end). But watch out for the golden **newt** - will your path cross with this mystical creature?

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
- `n` - The magical newt (appears in yellow)
- `.` - Your escape route (shown in solution)

## Possible Outcomes

1. **"Escaped the maze with the newt!"** - Your path crossed the newt's location
2. **"Escaped the maze! But the newt is still trapped!"** - You found a path that didn't encounter the newt
3. **"Forever trapped in the maze with the newt"** - No escape route exists

## Technical Details

- **Algorithm**: Recursive Depth-First Search with backtracking
- **Data Structure**: 2D vector grid representation
- **Random Generation**: Time-seeded random number generation
- **Memory Management**: STL containers with automatic cleanup

## Future Enhancements

- Player-controlled movement
- Multiple levels
- Inventory system
- Monster AI
- Save/load functionality

---

*A project demonstrating algorithms, object-oriented programming, and game development fundamentals in C++.*