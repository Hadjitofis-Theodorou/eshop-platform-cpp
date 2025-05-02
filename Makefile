# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Source files
SOURCES = src/Admin.cpp src/Datahandler.cpp src/Person.cpp src/User.cpp src/Product.cpp src/globalfiles.cpp src/Cart.cpp src/Customer.cpp src/main.cpp 

# Executable name
EXECUTABLE = ./oop24

# Default target
all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

# Clean up build files
clean:
	rm -f $(EXECUTABLE)

# Phony targets
.PHONY: all clean
