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
	struct Ship Patrol_Boat;
	struct Ship Submarine;
	struct Ship Cruiser;
	struct Ship Destroyer;
	struct Ship Battleship;
	struct Ship Aircraft_Carrier;

	//starting with patrol boat
	strcpy(Patrol_Boat.shipname, "Patrol Boat");
	Patrol_Boat.shipsize = 2;

	//now the submarine?
	strcpy(Submarine.shipname, "Submarine");
	Submarine.shipsize = 2;

	//and so on
	strcpy(Cruiser.shipname, "Cruiser");
	Cruiser.shipsize = 3;

	//and so forth
	strcpy(Destroyer.shipname, "Destroyer");
	Destroyer.shipsize = 3;

	//until done
	strcpy(Battleship.shipname, "Battleship");
	Battleship.shipsize = 4;

	//with each ship
	strcpy(Aircraft_Carrier.shipname, "Aircraft Carrier");
	Aircraft_Carrier.shipsize = 5;
	
	printf("Aircraft Carrier Stats:\nName: %s\nSize: %d\n", Aircraft_Carrier.shipname, Aircraft_Carrier.shipsize);
	
		
	return 0;
}	
