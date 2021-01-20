CC = g++
CFLAGS = -Wall -Wextra -g
LIBS = -lpng
OBJECTS = $(shell find src/ -type f -name '*.cpp' | grep -v 'main.cpp' | sed 's/cpp/o/g')
EXAMPLES = $(shell ls examples/example*.cpp | sed 's/.cpp//g')
TARGET = RayTracer

$(TARGET): src/main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o : %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

examples/example%: examples/example%.cpp $(OBJECTS)
	$(CC) $(FLAGS) $^ -o $@ $(LIBS)

examples: $(EXAMPLES)

.PHONY: doc
doc:
	doxygen Doxyfile

.PHONY: clean
clean:
	rm -f $(OBJECTS)
	if [ -f "$(TARGET)" ]; then rm "$(TARGET)"; fi
	rm -f $(EXAMPLES)

re: clean $(TARGET)