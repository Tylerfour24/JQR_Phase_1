#include <stdio.h>
#include <string.h>

/*Implement a method for dynamically storing a game board that will be displayed in rows and columns in a file; this board will be at a minimal 10x10 and cannot be a hard coded value, it will be a given value randomly at runtime.*/

//aka, make game board.  Start by just making it 10/10.


struct Ship {
	char shipname[20];
	int shipsize;
};

int main(void)
{
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

//create the grid on which the game is played via two-dimensional array

	char battlegrid[10][10];
	int onedim = 0;
	int twodim = 0;

	for(onedim = 0; onedim < 10; onedim++) {
		for(twodim = 0; twodim < 10; twodim++) {
			battlegrid[onedim][twodim] = '0';
			printf("%c ", battlegrid[onedim][twodim]);
		}
		printf("\n");
	}

	return 0;
}	
