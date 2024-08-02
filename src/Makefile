SFML=-lsfml-graphics -lsfml-window -lsfml-system
CXX=g++
TARGET=TodoApp
WARN=-Wall
CXXFLAGS=$(WARN) $(SFML)
OBJS=main.o
LD=g++

all: $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS)
	@rm *.o
	@./$(TARGET)

main.o: main.cc
	$(CXX) -c main.cc $(CXXFLAGS) 
