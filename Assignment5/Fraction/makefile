Fraction : main.o Fraction.o
	g++ -o Fraction main.o Fraction.o
main.o : main.cpp Fraction.hpp
	g++ -c main.cpp
Fraction.o : Fraction.cpp Fraction.hpp
	g++ -c Fraction.cpp
clean :
	rm Fraction main.o Fraction.o
