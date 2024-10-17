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
$(shell mkdir $(BUILD_DIR) 2> NUL)

# Rule for the final executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
.PHONY: clean
clean:
	if exist $(BUILD_DIR) rd /s /q $(BUILD_DIR)
	if exist $(EXEC) del $(EXEC)
