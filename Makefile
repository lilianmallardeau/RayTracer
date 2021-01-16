CC = g++
CFLAGS = -Wall -Wextra -g
LIBS = -lpng
OBJECTS = $(shell find src/ -type f -name '*.cpp' | sed 's/cpp/o/g')
TARGET = RayTracer

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

src/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	find . -type f -name "*.o" -delete
	if [ -f "$(TARGET)" ]; then rm "$(TARGET)"; fi

re: clean $(TARGET)