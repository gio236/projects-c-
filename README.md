# 🎮 Terminal Maze Adventure

An interactive maze game developed in C++ using the ncurses library. Navigate through multiple interconnected mazes, explore houses, and discover new areas in this engaging terminal-based adventure!

## ✨ Features

- **🗺️ Multiple Maps**: Interconnected map system with smooth transitions
- **🏠 House Exploration**: Enter houses and discover new areas
- **🎯 Collision Detection**: Precise and responsive collision system
- **🕹️ Intuitive Controls**: Movement with arrow keys or WASD
- **🖥️ Clean Interface**: Clear and minimal ASCII graphics

## 🚀 Getting Started

### Prerequisites

Make sure you have installed:
- GCC Compiler
- ncurses library

#### On Arch Linux:
```bash
sudo pacman -S gcc ncurses
```

#### On Ubuntu/Debian:
```bash
sudo apt-get install gcc libncurses5-dev
```

#### On macOS:
```bash
brew install ncurses
```

### Installation

1. **Clone the repository:**
```bash
git clone https://github.com/yourusername/projects-c.git
cd projects-c
git checkout little-game-in-c++
```

2. **Compile the game:**
```bash
g++ -o maze_game main.cpp -lncurses
```

3. **Run the game:**
```bash
./maze_game
```

## 🎮 How to Play

### Controls
- **Movement**: Use arrow keys or `W A S D`
- **Quit**: Press `Q` to exit the game

### Symbols
- `@` - Your character
- `#` - Walls (impassable)
- `|` - Special doors
- ` ` - Free space

### Objective
Navigate through the mazes, find exits, and explore different areas of the game!

## 🏗️ Architecture

The game is structured with:
- **Modular map system**: Each area has its own collision matrix
- **State management**: Smooth transitions between different areas
- **Optimized rendering**: Efficient screen updates
- **Input handling**: Robust user command management

## 🛠️ Code Structure

```
little-game-in-c++/
├── main.cpp            # Main file with game loop
├── README.md           # This file
└── screenshots/        # Game screenshots (optional)
```

### Main Functions

- `labirinto()` - Renders the main maze
- `mappacasaspawn()` - Renders the house map
- `mvmcolmap()` - Handles movement with collision detection
- `mvmcolmapcas()` - Handles movement in the house area

## 🎯 Roadmap

- [ ] **Room System**: Implement interior rooms for each house
- [ ] **Inventory**: Object collection system
- [ ] **NPCs**: Non-player characters with dialogues
- [ ] **Save System**: Game progress persistence
- [ ] **Audio**: Sound effects and background music
- [ ] **Minimap**: Explorative map visualization

## 🐛 Known Issues

- No critical bugs currently known
- Report any issues in the [Issues](https://github.com/yourusername/projects-c/issues) section

## 🤝 Contributing

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

## 👨‍💻 Author

Developed by [Your Name] - A passionate 15-year-old developer!

**Connect with me:**
- GitHub: [@yourusername](https://github.com/yourusername)
- Email: your.email@example.com

---

⭐ **Enjoyed the project?** Give it a star to support development!

## 📸 Screenshots

*[Add your game screenshots here if you want]*

---

**Version**: 1.0.0  
**Last Updated**: July 2025

## 🔧 Technical Details

**Language**: C++  
**Graphics**: ncurses library  
**Platform**: Linux, macOS, Windows (with proper setup)  
**Compiler**: GCC/G++

## 🎖️ Achievements

This project demonstrates:
- Advanced C++ programming skills
- Terminal-based game development
- Memory management
- Multi-dimensional array handling
- Event-driven programming
- Clean code architecture

---

*Made with ❤️ and lots of ☕ by a young developer learning the ropes!*
