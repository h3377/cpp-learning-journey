# C++ Learning Journey - Build System Setup

This directory now includes a professional build system to organize and compile all C++ exercises.

## Quick Start

### Prerequisites
- CMake 3.10 or later
- G++ or Clang compiler with C++17 support
- Make (optional, but recommended)

### Build Everything

```bash
# Using Makefile (easiest)
make build

# Or using CMake directly
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .
```

### Run Individual Exercises

```bash
# Using Makefile
make run-recursion
make run-libs
make run-pointers

# Or run executables directly from build/bin/
./build/bin/Recursion_Hw
./build/bin/libs_demo
./build/bin/dereferencing_pointer
```

## What's New

### 1. **CMakeLists.txt** (Root)
- Centralized build configuration
- Automatically compiles all `.cpp` files in root directory as separate executables
- Includes subdirectories (Pointer/, 2d-arrays/, etc.)
- Sets C++17 standard

### 2. **Makefile**
- User-friendly commands for common tasks
- `make setup` - Initialize build directory
- `make build` - Compile all exercises
- `make clean` - Remove build artifacts
- `make help` - Show all available commands
- Quick single-file compilation with `make compile-filename`

### 3. **Subdirectory CMakeLists.txt**
- `Pointer/CMakeLists.txt` - Organizes pointer exercises
- `Projects/CMakeLists.txt` - Builds project files
- `2d-arrays/CMakeLists.txt` - Placeholder for 2D array exercises
- `Vectors part 2/CMakeLists.txt` - Placeholder for vector exercises

### 4. **Interactive Menu Program** (src/menu.cpp)
- Browse and run exercises from one place
- Compile with: `make build && ./build/bin/menu`

## Directory Structure

```
cpp-learning-journey/
├── CMakeLists.txt              # Main build configuration
├── Makefile                     # Easy build commands
├── src/
│   └── menu.cpp               # Interactive menu program
├── cpp-libraries/
│   ├── *.h                    # Custom library headers
│   └── main.cpp               # Libraries demo
├── Pointer/
│   ├── CMakeLists.txt
│   ├── *.cpp                  # Pointer exercises
├── Projects/
│   ├── CMakeLists.txt
│   ├── *.cpp                  # Project files
├── 2d-arrays/
│   ├── CMakeLists.txt
│   └── (exercises)
├── Vectors part 2/
│   ├── CMakeLists.txt
│   └── (exercises)
└── build/                     # Generated after build
    └── bin/                   # Compiled executables
```

## Available Commands

```bash
# Setup and build
make help              # Show all available commands
make setup            # Initialize CMake build directory
make build            # Build all exercises
make rebuild          # Clean and rebuild everything

# Run exercises
make run-recursion    # Run Recursion Hw exercise
make run-pointers     # Show pointer exercise executables
make run-vectors      # Show vector exercise executables
make run-libs         # Run custom libraries demo
make run-menu         # Run interactive menu

# Single-file compilation (without CMake)
make compile-Recursion\ Hw
```

## Benefits

✅ **Organized** - All exercises managed in one build system  
✅ **Scalable** - Easy to add new exercises  
✅ **Professional** - Industry-standard CMake + Make setup  
✅ **Flexible** - Can compile everything or individual files  
✅ **Easy to use** - Simple Makefile commands  

## Next Steps

1. **Build the system**: `make build`
2. **Run an exercise**: `./build/bin/Recursion_Hw`
3. **Add new exercises**: Update the appropriate CMakeLists.txt
4. **Use the menu**: `make run-menu` for interactive access

## Troubleshooting

- **CMake not found**: Install CMake (apt/brew/choco)
- **Compiler errors**: Ensure C++17 support (`g++ --version`)
- **File not found**: Verify the build completed successfully with `make rebuild`
