.PHONY: build clean run help setup

# Build directory
BUILD_DIR := build

help:
	@echo "C++ Learning Journey - Build System"
	@echo "===================================="
	@echo ""
	@echo "Available commands:"
	@echo "  make setup       - Initialize build directory"
	@echo "  make build       - Build all exercises (using CMake)"
	@echo "  make clean       - Remove build artifacts"
	@echo "  make menu        - Run interactive menu program"
	@echo ""
	@echo "Individual exercises (compiled with cmake build):"
	@echo "  make run-recursion      - Run Recursion Hw"
	@echo "  make run-pointers       - Run Pointer exercises"
	@echo "  make run-vectors        - Run Vector exercises"
	@echo "  make run-libs           - Run custom libraries demo"
	@echo ""

setup:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake .. -DCMAKE_BUILD_TYPE=Debug
	@echo "✓ Build directory initialized"

build: setup
	@cd $(BUILD_DIR) && cmake --build . --config Debug
	@echo "✓ All exercises built successfully"

rebuild: clean build

clean:
	@rm -rf $(BUILD_DIR)
	@echo "✓ Build artifacts cleaned"

run-menu: build
	@./$(BUILD_DIR)/bin/menu

run-recursion: build
	@./$(BUILD_DIR)/bin/Recursion_Hw

run-pointers: build
	@echo "Pointer exercises built. Run individual exercises:"
	@ls -1 $(BUILD_DIR)/bin/pointer* | sed 's|^|  ./|'

run-vectors: build
	@echo "Vector exercises built. Run individual exercises:"
	@ls -1 $(BUILD_DIR)/bin/*Vector* 2>/dev/null || echo "  (Vector exercises)"

run-libs: build
	@./$(BUILD_DIR)/bin/libs_demo

# Quick single-file compilation (for testing)
compile-%:
	g++ -std=c++17 -I./cpp-libraries "$*.cpp" -o ./bin/$*
	@echo "✓ Compiled $* to ./bin/$*"

list-exercises:
	@echo "Available exercises:"
	@find . -maxdepth 1 -name "*.cpp" -type f | sed 's|^\./||' | sort
	@echo ""
	@echo "Subdirectories:"
	@ls -d */ 2>/dev/null | sed 's|/||' | sort
