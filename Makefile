all: programa2

main.o: main.cpp classes.h
			g++ main.cpp -c

menu.o: menu.cpp classes.h
			g++ menu.cpp -c 

gerenciador.o: gerenciador.cpp classes.h
					g++ gerenciador.cpp -c

jogador.o: jogador.cpp classes.h
				g++ jogador.cpp -c

programa2: main.o menu.o gerenciador.o jogador.o
			g++ main.o menu.o gerenciador.o jogador.o -o programa2


clean:
		rm -rf *.o
		rm programa2