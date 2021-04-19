CPP = g++ -std=c++11
FLAGS = -o
TARGET = adventure
OBJS = main.o Castle.o Room.o

$(TARGET): $(OBJS)
	$(CPP) $(FLAGS) $(TARGET) $(OBJS)
main.o: main.cpp Castle.o Room.o
Castle.o: Castle.cpp
Room.o: Room.cpp