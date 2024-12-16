# Define compiler and flags
CXX = g++ -fsanitize=address -g
CXXFLAGS = -std=c++17

# Default build type is Release
BUILD ?= Release

# Add debug flags if BUILD is Debug
ifeq ($(BUILD), Debug)
    CXXFLAGS += -g -O0 -DDEBUG
else
    CXXFLAGS += -O2
endif

# List all .cpp files in the current directory
SRCS = $(wildcard *.cpp)

# Generate .o files for each .cpp file
OBJS = $(SRCS:.cpp=.o)

# Define the output executable
TARGET = main

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
