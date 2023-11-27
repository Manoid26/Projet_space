CC= gcc
OPTION = -W -Wall -std=c89 -pedantic -O3

main :main.c jeu.o menu.o vaisseau.o
	$(CC) $(OPTION) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` $^ `pkg-config --libs-only-l MLV` -o $@

jeu.o : jeu.c
	$(CC) $(OPTION) -c $^                                         

menu.o : menu.c
	$(CC) $(OPTION) -c $^

vaisseau.o : vaisseau.c
	$(CC) $(OPTION) -c $^

clean :                                                                         
	rm -rf *.o *~ jeu
