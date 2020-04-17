CC=g++
SRC=src

all: bot.o main.o funzioniD.o mappa.o mostri.o player.o 
	$(CC) *.o -o Test
main.o: main.cpp
	g++ -c main.cpp -o main.o 
bot.o: bot.cpp bot.hpp
	g++ -c bot.cpp -o bot.o 
mappa.o: mappa.cpp mappa.hpp
	g++ -c mappa.cpp -o mappa.o 
mostri.o: mostri.cpp mostri.hpp
	g++ -c mostri.cpp -o mostri.o
player.o: player.cpp player.hpp
	g++ -c player.cpp -o player.o
funzioniD.o: funzioniD.cpp funzioniD.hpp
	g++ -c funzioniD.cpp -o funzioniD.o

clean:
	rm * Test
