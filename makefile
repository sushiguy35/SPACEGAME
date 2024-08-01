build:
	gcc src/main.c src/player.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o game

.PHONY run:
run: 
	./game