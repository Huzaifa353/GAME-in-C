#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
	int i;
	for ( i=0;i<256;i++ )
	{
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),i );
		printf( "PONG GAME = %d\n",i );
	}
	getch();
}
