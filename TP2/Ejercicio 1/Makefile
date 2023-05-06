CC = g++
CPPFLAGS = -g -std=c++14 -O3
OUTPUT_PATH := bin

.PHONY: all clean

# target por defecto
main: app
	./$(OUTPUT_PATH)/app

# target para correr los tests
tests: app
	@time $(OUTPUT_PATH)/app < tests/test1.txt

# compilacion
app: main.cpp									
	@mkdir -p $(OUTPUT_PATH)
	$(CC) $(CPPFLAGS) $< -o $(OUTPUT_PATH)/app

clean:
	rm -f *.o
	rm -rf $(OUTPUT_PATH)