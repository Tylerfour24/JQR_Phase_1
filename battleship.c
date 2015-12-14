#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/*Implement a method for dynamically storing a game board that will be displayed in rows and columns in a file; this board will be at a minimal 10x10 and cannot be a hard coded value, it will be a given value randomly at runtime.*/

//aka, make game board.  Start by just making it 10/10.


struct Ship {
	char shipname[20];
	int shipsize;
};

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
	int latitude;
	int longitude;
	int orientation;

//This successfully creates the empty board
	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			battlegrid[onedim][twodim] = '*';
		}
	}

//This successfully prints the Aircraft Carrier to the board
	printf("Placing Aircraft Carrier:\n");
	latitude = rand() % 10;
	longitude = rand() % 10;
	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) { 
				orientation = rand() % 2;
				if(orientation == 0) { //HORIZONTAL
					if(latitude <= 5) {
						battlegrid[onedim][twodim] = 'A';
						battlegrid[onedim+1][twodim] = 'A';
						battlegrid[onedim+2][twodim] = 'A';
						battlegrid[onedim+3][twodim] = 'A';
						battlegrid[onedim+4][twodim] = 'A';
					}
					else {
						battlegrid[onedim][twodim] = 'A';
						battlegrid[onedim-1][twodim] = 'A';
						battlegrid[onedim-2][twodim] = 'A';
						battlegrid[onedim-3][twodim] = 'A';
						battlegrid[onedim-4][twodim] = 'A';
					}
				}
				else { //VERTICAL
					if(longitude <= 5) {
						battlegrid[onedim][twodim] = 'A';
						battlegrid[onedim][twodim+1] = 'A';
						battlegrid[onedim][twodim+2] = 'A';
						battlegrid[onedim][twodim+3] = 'A';
						battlegrid[onedim][twodim+4] = 'A';
					}
					else {
						battlegrid[onedim][twodim] = 'A';
						battlegrid[onedim][twodim-1] = 'A';
						battlegrid[onedim][twodim-2] = 'A';
						battlegrid[onedim][twodim-3] = 'A';
						battlegrid[onedim][twodim-4] = 'A';
					}
				}
			}
		}
	}

//this successfully prints the Battleship to the board
	printf("Placing Battleship:\n");
	latitude = rand() % 10;
	longitude = rand() % 10;
	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) {
				orientation = rand() % 2;
				if(orientation == 0) { //HORIZONTAL
					if(latitude <= 6) {
						battlegrid[onedim][twodim] = 'B';
						battlegrid[onedim+1][twodim] = 'B';
						battlegrid[onedim+2][twodim] = 'B';
						battlegrid[onedim+3][twodim] = 'B';
					}
					else {
						battlegrid[onedim][twodim] = 'B';
						battlegrid[onedim-1][twodim] = 'B';
						battlegrid[onedim-2][twodim] = 'B';
						battlegrid[onedim-3][twodim] = 'B';
					}
				}
				else { //VERTICAL
					if(longitude <= 6) {
						battlegrid[onedim][twodim] = 'B';
						battlegrid[onedim][twodim+1] = 'B';
						battlegrid[onedim][twodim+2] = 'B';
						battlegrid[onedim][twodim+3] = 'B';
					}
					else {
						battlegrid[onedim][twodim] = 'B';
						battlegrid[onedim][twodim-1] = 'B';
						battlegrid[onedim][twodim-2] = 'B';
						battlegrid[onedim][twodim-3] = 'B';
					}
				}
			}
		}
	}

//this successfully prints the Cruiser to the board
	printf("Placing Cruiser:\n");
	latitude = rand() % 10;
	longitude = rand() % 10;
	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) {
				orientation = rand() % 2;
				if(orientation == 0) { //HORIZONTAL
					if(latitude <= 7) {
						battlegrid[onedim][twodim] = 'C';
						battlegrid[onedim+1][twodim] = 'C';
						battlegrid[onedim+2][twodim] = 'C';
					}
					else {
						battlegrid[onedim][twodim] = 'C';
						battlegrid[onedim-1][twodim] = 'C';
						battlegrid[onedim-2][twodim] = 'C';
					}
				}
				else { //VERTICAL
					if(longitude <= 7) {
						battlegrid[onedim][twodim] = 'C';
						battlegrid[onedim][twodim+1] = 'C';
						battlegrid[onedim][twodim+2] = 'C';
					}
					else {
						battlegrid[onedim][twodim] = 'C';
						battlegrid[onedim][twodim-1] = 'C';
						battlegrid[onedim][twodim-2] = 'C';
					}
				}
			}
		}
	}

//this successfully prints the Destroyer to the board
	printf("Placing Destroyer:\n");
	latitude = rand() % 10;
	longitude = rand() % 10;
	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) {
				orientation = rand() % 2;
				if(orientation == 0) { //HORIZONTAL
					if(latitude <= 7) {
						battlegrid[onedim][twodim] = 'D';
						battlegrid[onedim+1][twodim] = 'D';
						battlegrid[onedim+2][twodim] = 'D';
					}
					else {
						battlegrid[onedim][twodim] = 'D';
						battlegrid[onedim-1][twodim] = 'D';
						battlegrid[onedim-2][twodim] = 'D';
					}
				}
				else { //VERTICAL
					if(longitude <= 7) {
						battlegrid[onedim][twodim] = 'D';
						battlegrid[onedim][twodim+1] = 'D';
						battlegrid[onedim][twodim+2] = 'D';
					}
					else {
						battlegrid[onedim][twodim] = 'D';
						battlegrid[onedim][twodim-1] = 'D';
						battlegrid[onedim][twodim-2] = 'D';
					}
				}
			}
		}
	}

//this successfully prints the Patrol Boat to the board
	printf("Placing Patrol Boat:\n");
	latitude = rand() % 10;
	longitude = rand() % 10;
	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) {
				orientation = rand() % 2;
				if(orientation == 0) { //HORIZONTAL
					if(latitude <= 8) {
						battlegrid[onedim][twodim] = 'P';
						battlegrid[onedim+1][twodim] = 'P';
					}
					else {
						battlegrid[onedim][twodim] = 'P';
						battlegrid[onedim-1][twodim] = 'P';
					}
				}
				else { //VERTICAL
					if(longitude <= 8) {
						battlegrid[onedim][twodim] = 'P';
						battlegrid[onedim][twodim+1] = 'P';
					}
					else {
						battlegrid[onedim][twodim] = 'P';
						battlegrid[onedim][twodim-1] = 'P';
					}
				}
			}
		}
	}

//this successfully prints the Submarine to the board
	printf("Placing Submarine:\n");
	latitude = rand() % 10;
	longitude = rand() % 10;
	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			if( ((latitude == onedim) && (longitude == twodim) && (battlegrid[onedim][twodim] == '*')) ) {
				orientation = rand() % 2;
				if(orientation == 0) { //HORIZONTAL
					if(latitude <= 8) {
						battlegrid[onedim][twodim] = 'S';
						battlegrid[onedim+1][twodim] = 'S';
					}
					else {
						battlegrid[onedim][twodim] = 'S';
						battlegrid[onedim-1][twodim] = 'S';
					}
				}
				else { //VERTICAL
					if(longitude <= 8) {
						battlegrid[onedim][twodim] = 'S';
						battlegrid[onedim][twodim+1] = 'S';
					}
					else {
						battlegrid[onedim][twodim] = 'S';
						battlegrid[onedim][twodim-1] = 'S';
					}
				}
			}
		}
	}



	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			printf("%c ", battlegrid[onedim][twodim]);
		}
		printf("\n");
	}




/*FOR CHECKING BOUNDARIES FOR SHIPS
ADD VALUE OF SHIP TO GRID POINT, AND COUNT RIGHT OR DOWN (+) OR LEFT/UP (-1)
AND CHECK IF GREATER THAN 10 OR LESS THAN 0
*/
	
	return 0;
}	
