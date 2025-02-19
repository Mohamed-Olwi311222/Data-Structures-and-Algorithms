COMPILER = gcc
FLAGS = -Wall -g -o
FUNCTIONS = functions.c
MAIN = main.c
OUTPUT = output_file
WINEXT = .exe
windows: 
	$(COMPILER) $(MAIN) $(FUNCTIONS) $(FLAGS) $(OUTPUT)$(WINEXT)
linux:
	$(COMPILER) $(MAIN) $(FUNCTIONS) $(FLAGS) $(OUTPUT) -lm
clean:
	rm -f $(OUTPUT) $(OUTPUT)$(WINEXT)