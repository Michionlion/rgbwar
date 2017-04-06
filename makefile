#files to compile
SOURCES = $(wildcard src/*.cpp)
CC = g++
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2
EXEC = rgbw

#This is the target that compiles our executable
$(EXEC) : $(SOURCES) clean
	$(CC) $(SOURCES) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC)

# To remove generated files
clean:
	rm -f $(EXEC)
