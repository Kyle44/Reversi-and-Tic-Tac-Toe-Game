all:
	g++ -Wall -ansi Proj4.cpp Proj4Aux.cpp TicTacToe.cpp Reversi.cpp GridGame.cpp -o Proj4.out
run:
	./Proj4.out ttt
clean:
	rm -rf *.o *~ *#
