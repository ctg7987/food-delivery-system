# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Werror  # IUncluded -Werror to treat all warnings as errors

# Target executable name
TARGET = food_delivery

# Source files
SRCS = main.cpp MenuItem.cpp Restaurant.cpp Order.cpp USSDSystem.cpp

# Object files 
OBJS = $(SRCS:.cpp=.o)

# Rule to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (not actual files)
.PHONY: clean
