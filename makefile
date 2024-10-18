# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iheaders

# Directories
SRC_DIR = sources
BUILD_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable
EXEC = vehicle.exe

# Create build directory if it doesn't exist
$(shell mkdir -p $(BUILD_DIR))

# Rule for the final executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(EXEC)
