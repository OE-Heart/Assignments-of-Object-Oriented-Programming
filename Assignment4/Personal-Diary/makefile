all : Entity.o pdadd.o pdremove.o pdshow.o pdlist.o
	g++ -o pdadd pdadd.o Entity.o
	g++ -o pdremove pdremove.o Entity.o
	g++ -o pdshow pdshow.o Entity.o
	g++ -o pdlist pdlist.o Entity.o
pdadd.o : pdadd.cpp Entity.cpp Entity.hpp
	g++ -c pdadd.cpp Entity.cpp
pdremove.o : pdremove.cpp Entity.cpp Entity.hpp
	g++ -c pdremove.cpp Entity.cpp
pdshow.o : pdshow.cpp Entity.cpp Entity.hpp
	g++ -c pdshow.cpp Entity.cpp
pdlist.o : pdlist.cpp Entity.cpp Entity.hpp
	g++ -c pdlist.cpp Entity.cpp
clean :
	rm pdadd pdremove pdshow pdlist Entity.o pdadd.o pdremove.o pdshow.o pdlist.o