# Binary Directory

## Purpose
This directory contains the compiled executable files for the Banking System application.

## Contents
After building the project, this directory will contain:
- `banking_system`: The main executable for the Banking System application

## How to Generate the Executable
The executable file is generated using the provided Makefile:

```bash
# Compile the project
make

# Run the application
make run
# or
./bin/banking_system
```

## Notes
- This directory is intentionally kept empty in version control.
- The binaries are automatically generated during the build process.
- Compiled binaries are excluded from version control to:
  - Avoid platform-specific issues
  - Keep the repository size smaller
  - Prevent merge conflicts
  - Follow best practices for version control
- If you're having issues with the executable, try running `make clean` followed by `make` to rebuild it. 