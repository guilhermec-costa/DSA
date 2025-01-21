PROJ_NAME = DSA
SRC_DIR = src
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
INCLUDE_DIRS = -Iinclude

EXECUTABLE = $(BUILD_DIR)/$(PROJ_NAME).exe
DEBUG_EXECUTABLE = $(BUILD_DIR)/$(PROJECT_NAME)_debug.exe
CXXFLAGS = $(INCLUDE_DIRS) 

default: $(EXECUTABLE)

debug: CXXFLAGS += -g
debug: $(DEBUG_EXECUTABLE)

$(EXECUTABLE):
	g++ $(SRC_FILES) -o $(EXECUTABLE) $(CXXFLAGS)

$(DEBUG_EXECUTABLE): $(SRC_FILES)
	g++ $(SRC_FILES) -o $(DEBUG_EXECUTABLE) $(CXXFLAGS)