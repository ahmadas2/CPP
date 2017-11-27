CC=g++

FinalProject.exe : main.o player.o deck.o
	${CC} -o FinalProject.exe main.o player.o deck.o

main.o : main.cpp player.h player.cpp deck.h deck.cpp
	${CC} -c main.cpp 

player.o : player.h player.cpp
	${CC} -c player.h player.cpp
	
deck.o : deck.h deck.cpp
	${CC} -c deck.h deck.cpp
clean :
	rm *.o
	rm *.exe
	
