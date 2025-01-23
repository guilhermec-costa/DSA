PROJ_NAME = DSA
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIRS = -Iinclude

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

EXECUTABLE = $(BUILD_DIR)/$(PROJ_NAME).exe
DEBUG_EXECUTABLE = $(BUILD_DIR)/$(PROJ_NAME)_debug.exe
CXXFLAGS = -Wall $(INCLUDE_DIRS)

default: $(EXECUTABLE)

debug: CXXFLAGS += -g
debug: $(DEBUG_EXECUTABLE)

# Build release executable
$(EXECUTABLE): $(OBJ_FILES) | $(BUILD_DIR)
	g++ $(OBJ_FILES) -o $@ $(CXXFLAGS)

# Build debug executable
$(DEBUG_EXECUTABLE): $(OBJ_FILES) | $(BUILD_DIR)
	g++ $(OBJ_FILES) -o $@ $(CXXFLAGS)

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	g++ -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
