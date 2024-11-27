# Currency Converter

A modular C project for converting currencies using an organized folder structure and a `Makefile` for building and running the application.

## Project Structure

The project is organized as follows:

```bash
currency-converter/
├── src/ # Source code directory
│   ├── main.c # Main application file
│   ├── functions.c # Function implementations
├── include/ # Header files directory
│   └── main.h # Function declarations
├── build/ # Generated object files (created during compilation)
├── Makefile # Build automation script
├── README.md # Project documentation
```

### Explanation of the Structure

1. **Makefile**: Automates the build process, compiles the source code, and links object files to produce the executable.
2. **README.md**: Provides documentation on the project, including structure and build instructions.
3. **src/**: Contains the source code (`main.c` and `functions.c`) for the application.
4. **include/**: Contains the header file (`main.h`) with function prototypes.
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
    cd currency-converter
    ```

2. **Build the Project**:
   Use the `make` command to compile the project:

    ```bash
    make
    ```

    - This compiles `main.c` and `functions.c`.
    - Object files are stored in the `build/` directory.
    - The executable is generated in the project root with the name `main`.

3. **Run the Executable**:
   After building, run the executable:

    ```bash
    ./main
    ```

    The program will prompt you to input the amount, source currency, and target currency. It then outputs the converted amount based on predefined exchange rates.

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

    - Ensure you have execution permissions on the `converter` file:

    ```bash
    chmod +x converter
    ```

3. **Missing Tools**:
    - Make sure `gcc` and `make` are installed on your system.

---

## License

This project is open-source. You can use, modify, and distribute it as per your needs.
