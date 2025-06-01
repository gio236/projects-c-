# gim
# Terminal Text Editor (ncurses)

This is a basic terminal-based text editor written in C++ using the `ncurses` library.

## ✨ Features

- Start in two modes:
  - Create a new file
  - Open and edit an existing file
- Basic cursor movement with arrow keys
- Line and column overflow management
- Handles line wrapping when `x >= COLS`
- Adds new lines when `y >= LINES`
- Saves the file with `Ctrl + W`
- Exits the editor with `Ctrl + X`
- Supports character insertion and backspace
- Prevents terminal suspension (`Ctrl + Z`) and interruption (`Ctrl + C`)
- Uses `disableFlowControl()` to prevent conflicts with `Ctrl + S` and `Ctrl + Q`

## 🧠 To Do / Future Improvements

- [ ] Add command-line argument support (e.g. `./main file.txt`)
- [ ] Enable automatic scrolling when reaching bottom of the screen
- [ ] Improve file loading (e.g., add save confirmation or line highlighting)
- [ ] Implement syntax highlighting (optional)
- [v] Implement insert mode behavior

## ⚙️ Usage

Compile with:

```bash
g++ -o main editor.cpp -lncurses
```

Run with:

```bash
./main
```
