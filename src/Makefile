SFML=-Iinclude/ -lsfml-graphics -lsfml-window -lsfml-system  -ltgui -Llib
CXX=g++ -std=c++17
TARGET=TodoApp
WARN=-Wall
CXXFLAGS=$(WARN) $(SFML) 
OBJS=main.o
LD=g++

all: $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS)

main.o: main.cc
	$(CXX) -c main.cc $(CXXFLAGS)

# text.o: text.cc
# 	$(CXX) -c text.cc $(CXXFLAGS)
clean:
	rm -rf *.o
