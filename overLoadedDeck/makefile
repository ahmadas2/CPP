CC=g++

pgm5.exe : main.o deck.o
	${CC} -o pgm4.exe main.o deck.o

main.o : main.cpp deck.cpp deck.h
	${CC} -c main.cpp 
	
deck.o: deck.cpp deck.h
	${CC} -c deck.cpp
	
clean :
	rm *.o
	rm *.exe
