#include <time.h>
#include <windows.h>

void color ( int c )
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), c);
	return;
}

void delay (int milli_seconds) 
{
  	// Storing start time 
    clock_t start_time = clock();
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds);
    return;
}

void setxy (int x, int y)
{
	COORD c = {0, 0};
	c.X = x; c.Y = y; // Set X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clear(int x, int y)
{
	setxy( x,y );
	printf( "  " );
}
