#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Ship {
	char shipname[20];
	int shipsize;
};

int placeships(struct Ship ship, int onedim, int twodim, char battlegrid[][10]);
int down(char battlegrid[][10], int onedim, int twodim, struct Ship ship);
int up(char battlegrid[][10], int onedim, int twodim, struct Ship ship);
int left(char battlegrid[][10], int onedim, int twodim, struct Ship ship);
int right(char battlegrid[][10], int onedim, int twodim, struct Ship ship);

int main(void)
{
	srand(time(NULL));

//use a struct to create the ships

	struct Ship Patrol_Boat;
	struct Ship Submarine;
	struct Ship Cruiser;
	struct Ship Destroyer;
	struct Ship Battleship;
	struct Ship Aircraft_Carrier;
	
	strcpy(Patrol_Boat.shipname, "Patrol Boat");
	Patrol_Boat.shipsize = 2;

	strcpy(Submarine.shipname, "Submarine");
	Submarine.shipsize = 2;

	strcpy(Cruiser.shipname, "Cruiser");
	Cruiser.shipsize = 3;

	strcpy(Destroyer.shipname, "Destroyer");
	Destroyer.shipsize = 3;

	strcpy(Battleship.shipname, "Battleship");
	Battleship.shipsize = 4;

	strcpy(Aircraft_Carrier.shipname, "Aircraft Carrier");
	Aircraft_Carrier.shipsize = 5;
	
	printf("Boat Statistics:\n\n");
	printf("Boat 1: %s\nSize: %d\n\n", Patrol_Boat.shipname, Patrol_Boat.shipsize);
	printf("Boat 2: %s\nSize: %d\n\n", Submarine.shipname, Submarine.shipsize);
	printf("Boat 3: %s\nSize: %d\n\n", Cruiser.shipname, Cruiser.shipsize);
	printf("Boat 4: %s\nSize: %d\n\n", Destroyer.shipname, Destroyer.shipsize);
	printf("Boat 5: %s\nSize: %d\n\n", Battleship.shipname, Battleship.shipsize);
	printf("Boat 6: %s\nSize: %d\n\n", Aircraft_Carrier.shipname, Aircraft_Carrier.shipsize);

//create the grid on which the game is played via two-dimensional array, and place ships on grid

	char battlegrid[10][10];
	int onedim = 0;
	int twodim = 0;

//This successfully creates the empty board
	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			battlegrid[onedim][twodim] = '*';
		}
	}

	while(placeships(Aircraft_Carrier, onedim, twodim, battlegrid) != 1);
	while(placeships(Battleship, onedim, twodim, battlegrid) != 1);
	while(placeships(Cruiser, onedim, twodim, battlegrid) != 1);
	while(placeships(Destroyer, onedim, twodim, battlegrid) != 1);
	while(placeships(Patrol_Boat, onedim, twodim, battlegrid) != 1);
	while(placeships(Submarine, onedim, twodim, battlegrid) != 1);

	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			printf("%c ", battlegrid[onedim][twodim]);
		}
		printf("\n");
	}
	return 0;
}

int placeships(struct Ship ship, int onedim, int twodim, char battlegrid[][10]) {
	int count = 1;
	if(strcmp(ship.shipname, "Patrol Boat") == 0) {
		printf("Placing Patrol Boat:\n");
		int latitude = rand() % 10;
		int longitude = rand() % 10;
		for(onedim = 0; onedim < 10; onedim++) {
			for(twodim = 0; twodim < 10; twodim++) {
				if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) {
					int orientation = rand() % 2;
					if(orientation == 0) { //HORIZONTAL
						if(latitude <= 8) {
							count = right(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'P';
								battlegrid[onedim+1][twodim] = 'P';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = left(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'P';
								battlegrid[onedim-1][twodim] = 'P';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
					else { //VERTICAL
						if(longitude <= 8) {
							count = down(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'P';
								battlegrid[onedim][twodim+1] = 'P';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = up(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'P';
								battlegrid[onedim][twodim-1] = 'P';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
				}
			}
		}
		return 0;
	}
	else if(strcmp(ship.shipname, "Submarine") == 0) {
		printf("Placing Submarine:\n");
		int latitude = rand() % 10;
		int longitude = rand() % 10;
		for(onedim = 0; onedim < 10; onedim++) {
			for(twodim = 0; twodim < 10; twodim++) {
				if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) {
					int orientation = rand() % 2;
					if(orientation == 0) { //HORIZONTAL
						if(latitude <= 8) {
							count = right(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'S';
								battlegrid[onedim+1][twodim] = 'S';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = left(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'S';
								battlegrid[onedim-1][twodim] = 'S';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
					else { //VERTICAL
						if(longitude <= 8) {
							count = down(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'S';
								battlegrid[onedim][twodim+1] = 'S';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = up(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'S';
								battlegrid[onedim][twodim-1] = 'S';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
				}
			}
		}
		return 0;
	}
	else if(strcmp(ship.shipname, "Cruiser") == 0) {
		printf("Placing Cruiser:\n");
		int latitude = rand() % 10;
		int longitude = rand() % 10;
		for(onedim = 0; onedim < 10; onedim++) {
			for(twodim = 0; twodim < 10; twodim++) {
				if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) {
					int orientation = rand() % 2;
					if(orientation == 0) { //HORIZONTAL
						if(latitude <= 7) {
							count = right(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'C';
								battlegrid[onedim+1][twodim] = 'C';
								battlegrid[onedim+2][twodim] = 'C';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = left(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'C';
								battlegrid[onedim-1][twodim] = 'C';
								battlegrid[onedim-2][twodim] = 'C';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
					else { //VERTICAL
						if(longitude <= 7) {
							count = down(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'C';
								battlegrid[onedim][twodim+1] = 'C';
								battlegrid[onedim][twodim+2] = 'C';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = up(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'C';
								battlegrid[onedim][twodim-1] = 'C';
								battlegrid[onedim][twodim-2] = 'C';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
				}
			}
		}
		return 0;
	}
	else if(strcmp(ship.shipname, "Destroyer") == 0) {
		printf("Placing Destroyer:\n");
		int latitude = rand() % 10;
		int longitude = rand() % 10;
		for(onedim = 0; onedim < 10; onedim++) {
			for(twodim = 0; twodim < 10; twodim++) {
				if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) {
					int orientation = rand() % 2;
					if(orientation == 0) { //HORIZONTAL
						if(latitude <= 7) {
							count = right(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'D';
								battlegrid[onedim+1][twodim] = 'D';
								battlegrid[onedim+2][twodim] = 'D';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = left(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'D';
								battlegrid[onedim-1][twodim] = 'D';
								battlegrid[onedim-2][twodim] = 'D';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
					else { //VERTICAL
						if(longitude <= 7) {
							count = down(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'D';
								battlegrid[onedim][twodim+1] = 'D';
								battlegrid[onedim][twodim+2] = 'D';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = up(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'D';
								battlegrid[onedim][twodim-1] = 'D';
								battlegrid[onedim][twodim-2] = 'D';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
				}
			}
		}
		return 0;
	}
	else if(strcmp(ship.shipname, "Battleship") == 0) {
		printf("Placing Battleship:\n");
		int latitude = rand() % 10;
		int longitude = rand() % 10;
		for(onedim = 0; onedim < 10; onedim++) {
			for(twodim = 0; twodim < 10; twodim++) {
				if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) {
					int orientation = rand() % 2;
					if(orientation == 0) { //HORIZONTAL
						if(latitude <= 6) {
							count = right(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'B';
								battlegrid[onedim+1][twodim] = 'B';
								battlegrid[onedim+2][twodim] = 'B';
								battlegrid[onedim+3][twodim] = 'B';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = left(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'B';
								battlegrid[onedim-1][twodim] = 'B';
								battlegrid[onedim-2][twodim] = 'B';
								battlegrid[onedim-3][twodim] = 'B';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
					else { //VERTICAL
						if(longitude <= 6) {
							count = down(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'B';
								battlegrid[onedim][twodim+1] = 'B';
								battlegrid[onedim][twodim+2] = 'B';
								battlegrid[onedim][twodim+3] = 'B';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = up(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'B';
								battlegrid[onedim][twodim-1] = 'B';
								battlegrid[onedim][twodim-2] = 'B';
								battlegrid[onedim][twodim-3] = 'B';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
				}
			}
		}
		return 0;
	}
	else if(strcmp(ship.shipname, "Aircraft Carrier") == 0) {
		printf("Placing Aircraft Carrier:\n");
		int latitude = rand() % 10;
		int longitude = rand() % 10;
		for(onedim = 0; onedim < 10; onedim++) {
			for(twodim = 0; twodim < 10; twodim++) {
				if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) { 
					int orientation = rand() % 2;
					if(orientation == 0) { //HORIZONTAL
						if(latitude <= 5) {
							count = right(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'A';
								battlegrid[onedim+1][twodim] = 'A';
								battlegrid[onedim+2][twodim] = 'A';
								battlegrid[onedim+3][twodim] = 'A';
								battlegrid[onedim+4][twodim] = 'A';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = left(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'A';
								battlegrid[onedim-1][twodim] = 'A';
								battlegrid[onedim-2][twodim] = 'A';
								battlegrid[onedim-3][twodim] = 'A';
								battlegrid[onedim-4][twodim] = 'A';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
					else { //VERTICAL
						if(longitude <= 5) {
							count = down(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'A';
								battlegrid[onedim][twodim+1] = 'A';
								battlegrid[onedim][twodim+2] = 'A';
								battlegrid[onedim][twodim+3] = 'A';
								battlegrid[onedim][twodim+4] = 'A';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
						else {
							count = up(battlegrid, onedim, twodim, ship);
							if(count != 0) {
								battlegrid[onedim][twodim] = 'A';
								battlegrid[onedim][twodim-1] = 'A';
								battlegrid[onedim][twodim-2] = 'A';
								battlegrid[onedim][twodim-3] = 'A';
								battlegrid[onedim][twodim-4] = 'A';
								return 1;
							}
							else {
								return 0; //RESET
							}
						}
					}
				}
			}
		}
		return 0;
	}
	else {
		printf("SOMETHING WENT WRONG\n");
		return 0;
	}
}

int down(char battlegrid[][10], int onedim, int twodim, struct Ship ship) {
	int count = 1;
	for(count = 1; count < ship.shipsize; count++) {
		if(battlegrid[onedim][twodim + count] == '*') {
			; //DO NOTHING
		}
		else {
			/*for(; count >= 1; --count) {
				battlegrid[onedim][twodim+count] = '*';
			}*/
			count = 0;
			break;
		}
	}
	return count;
}

int up(char battlegrid[][10], int onedim, int twodim, struct Ship ship) {
	int count = 1;
	for(count = 1; count < ship.shipsize; count++) {
		if(battlegrid[onedim][twodim - count] == '*') {
			; //DO NOTHING
		}
		else {
			/*for(; count >= 1; --count) {
				battlegrid[onedim][twodim-count] = '*';
			}*/
			count = 0;
			break;
		}
	}
	return count;
}

int left(char battlegrid[][10], int onedim, int twodim, struct Ship ship) {
	int count = 1;
	for(count = 1; count < ship.shipsize; count++) {
		if(battlegrid[onedim - count][twodim] == '*') {
			; //DO NOTHING
		}
		else {
			/*for(; count >= 1; --count) {
				battlegrid[onedim - count][twodim] = '*';
			}*/
			count = 0;
			break;
		}
	}
	return count;
}

int right(char battlegrid[][10], int onedim, int twodim, struct Ship ship) {
	int count = 1;
	for(count = 1; count < ship.shipsize; count++) {
		if(battlegrid[onedim + count][twodim] == '*') {
			; //DO NOTHING
		}
		else {
			/*for(; count >= 1; --count) {
				battlegrid[onedim + count][twodim] = '*';
			}*/
			count = 0;
			break;
		}
	}
	return count;
}
