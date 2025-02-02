# Basic Voting System

A modular C project for implementing a simple voting system where users can vote for candidates and view the results. The project uses an organized folder structure and a `Makefile` for building and running the application.

## Project Structure

The project is organized as follows:

```bash
voting-system/
├── src/ # Source code directory
│   ├── main.c # Main application file
│   ├── vote.c # Voting logic implementation
├── include/ # Header files directory
│   ├── main.h # Main function declarations
│   ├── vote.h # Voting logic declarations
├── build/ # Generated object files
├── Makefile # Build automation script
├── README.md # Project documentation
```

### Explanation of the Structure

1. **Makefile**: Automates the build process, compiles the source code, and links object files to produce the executable.
2. **README.md**: Provides documentation on the project, including structure and build instructions.
3. **src/**: Contains the source code (`main.c` and `vote.c`) for the application.
4. **include/**: Contains the header files (`main.h` and `vote.h`) with function prototypes.
5. **build/**: This folder is created during the compilation process and stores intermediate object files (`.o`).

---

## How to Build and Run the Project

### Prerequisites

- GCC (GNU Compiler Collection) or Clang installed on your system.
- `make` utility installed.

### Steps to Compile and Run

1. **Clone the Repository**:

    ```bash
    git clone <repository-url>
    cd voting-system
    ```

2. **Build the Project**:
   Use the `make` command to compile the project:

    ```bash
    make
    ```

    - This compiles `main.c`, `vote.c`, and supporting source files.
    - Object files are stored in the `build/` directory.
    - The executable is generated in the project root with the name `voting-system`.

3. **Run the Executable**:
   After building, run the executable:

    ```bash
    ./voting-system
    ```

    The program will allow users to vote for candidates and view the voting results. It supports multiple voting sessions and displays the winner(s).

4. **Clean the Project**:
   To remove the generated files (`build/` folder and the executable), run:

    ```bash
    make clean
    ```

---

## Troubleshooting

1. **Build Errors**:

    - Verify the directory structure matches the described layout.
    - Ensure the `Makefile` is in the project root and uses proper tabs for commands.

2. **Permission Issues**:

    - Ensure you have execution permissions on the `voting-system` file:

    ```bash
    chmod +x voting-system
    ```

3. **Missing Tools**:
    - Make sure `gcc` and `make` are installed on your system.

---

## License

This project is open-source. You can use, modify, and distribute it as per your needs.
