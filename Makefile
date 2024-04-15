all: car
car: car.c
	gcc car.h car.c main.c -o car -Wall
clean: 
	rm -f car
