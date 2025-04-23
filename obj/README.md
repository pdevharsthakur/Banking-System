# Object Files Directory

## Purpose
This directory stores intermediate object files (`.o` files) generated during the compilation process of the Banking System application.

## Contents
During compilation, this directory will temporarily contain:
- `main.o`: Compiled object file for the main entry point
- `account.o`: Compiled object file for account operations
- `database.o`: Compiled object file for database operations
- `menu.o`: Compiled object file for menu handling
- `ui.o`: Compiled object file for user interface components

## How Object Files are Used
Object files are intermediate compilation artifacts that:
1. Contain the compiled code for individual source files
2. Are linked together to create the final executable
3. Allow for faster incremental builds by only recompiling changed source files

## Notes
- This directory is intentionally kept empty in version control
- Object files are excluded to:
  - Reduce repository size
  - Prevent platform-specific binary files from being shared
  - Follow standard practices for C/C++ projects
- The directory structure is maintained to ensure the build process works correctly
- If you experience build issues, run `make clean` to remove all object files and rebuild from scratch 