SFML=-lsfml-graphics -lsfml-window -lsfml-system -Llib -ltgui
CXX=g++ -std=c++17
TARGET=TodoApp
WARN=-Wall
CXXFLAGS=$(WARN) $(SFML) 
OBJS=main.o
LD=g++

all: $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS)
	@rm -rf *.o

main.o: main.cc
	$(CXX) -c main.cc $(CXXFLAGS)

clean:
	rm -rf *.o
