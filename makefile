all: sdu-nav

sdu-nav: main.o menu.o
	@echo " - Linking all files - "
	gcc main.o menu.o -lncurses -o sdu-nav

main.o: main.c
	@echo " - Compiling main file - "
	gcc -c main.c

menu.o: menu.c
	@echo " - Compiling menu file - "
	gcc -c menu.c

clean:
	@echo " - Removing everything but the source files - "
	rm main.o menu.o sdu-nav
