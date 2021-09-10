
# Specify compiler
CXX=g++

# Specify linker
LINK=g++

# Compilation options
CXXFLAGS= -static-libgcc -static-libstdc++ -static


LDFLAGS = -L..\lib -lmingw32 -lSDL2main -lSDL2 -mwindows  -Wl,--dynamicbase -Wl,--nxcompat -Wl,--high-entropy-va -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid


# Names of the executables to be generated
EXEC=mandelbrot-covid

# Path of source files
SRC_DIR=../srcs/

# Path of header files
HEADER_DIR=-I../includes/

# Path of object files
OBJ_DIR=../build/

# List of project source files ('wildcard' allows to explore the entire folder in a variable)
SRC= $(wildcard $(SRC_DIR)*.cpp)

# List of objects files generated thanks to the list of sources files ('SRC' variable)
OBJ= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

all: $(EXEC)

julia: $(OBJ)
		$(LINK) -o $@ $^  $(CXXFLAGS) $(HEADER_DIR) $(LDFLAGS)

# https://linux.die.net/man/1/gcc
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
		$(CXX) -o $@  -c $< $(CXXFLAGS) $(HEADER_DIR)

# .PHONY is a particular target thats allows to systematically rebuild its dependencies
.PHONY: clean mrproper

# Delete all intermediate files
clean:
		del *.o

# Delete all that can be regenerated and allows a complete project rebuid 
mrproper: clean
		del $(EXEC)
