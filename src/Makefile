SFML=-lsfml-graphics -lsfml-window -lsfml-system -L/home/samuel/Documentos/fun/TGUI-1.x/build/lib -ltgui
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
