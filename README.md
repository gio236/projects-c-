# Opath

An automatic file organizer for your Downloads folder.

## What does Opath do?

Opath is a simple and lightweight tool that automatically organizes your files in the Downloads folder. The program reads a customizable configuration file where you can define your preferences for directory names and destination paths.

## Features

- ✅ Automatic file organization by type
- ✅ Customizable configuration via config file
- ✅ Support for custom paths
- ✅ Simple and fast interface

## Installation

### Requirements
- C++ compiler (g++, clang++, etc.)
- Compatible operating system (Windows, Linux, macOS)

### Installation Steps

1. **Download the source code**
   ```bash
   git clone [repository-url]
   # or download main.cpp directly
   ```

2. **Configure your preferences**
   - Edit the `config` file according to your needs
   - Specify the directory names and desired paths
   - Follow the format shown in the example file

3. **Compile the program**
   ```bash
   g++ -o opath main.cpp
   ```

4. **Run Opath**
   ```bash
   ./opath
   ```

## Configuration

The configuration file allows you to fully customize Opath's behavior. Make sure to follow the correct syntax as shown in the included example file.

## Usage

Once compiled and executed, Opath:
1. Reads the configuration file
2. Scans the Downloads folder
3. Organizes files according to defined rules
4. Moves files to appropriate directories

## Contributing

Feel free to contribute to the project with suggestions, bug reports, or improvements!

---

*Script developed to simplify the organization of downloaded files.*
