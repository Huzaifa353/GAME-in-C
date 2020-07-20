#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include "animation.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPEED 50

struct score {
	char name[100];
	int points;
};

void play ( void );
void HowToPlay( void );
void display ( int length, int **co );
void food ( int fco[2] );
void border ( void );
void score ( int *points );
void save ( int score );
void view_scores ( void );

int main()
{
	int i=15,j=143,k=143,l=143,ch;
	while (1)
	{
	system( "color 73" );
	system("cls");
	color(47);
	setxy( 66,2 );
	printf( "                    " );
	setxy( 65,3 );
	printf( "      SNAKE GAME      " );
	setxy( 64,4 );
	printf( "                        " );
	
	while( 1 )
	{
		color(i);
		setxy( 64,6 );
		printf( "                        " );
		setxy( 64,7 );
		printf( "          Play          " );
		setxy( 64,8 );
		printf( "                        " );
		
		color(j);
		setxy( 64,10 );
		printf( "                        " );
		setxy( 64,11 );
		printf( "       How To Play      " );
		setxy( 64,12 );
		printf( "                        " );
		
		color(k);
		setxy( 64,14 );
		printf( "                        " );
		setxy( 64,15 );
		printf( "       View Scores      " );
		setxy( 64,16 );
		printf( "                        " );
		
		color(l);
		setxy( 64,18 );
		printf( "                        " );
		setxy( 64,19 );
		printf( "          Quit          " );
		setxy( 64,20 );
		printf( "                        " );
		
		ch=getch();
		if ( ch==72 )
		{
			if (j==15)
			{
				i=15;
				j=143;
			}
			else if (k==15)
			{
				j=15;
				k=143;
			}
			else if ( l==15 )
			{
				k=15;
				l=143;
			}
		}
		else if ( ch==80 )
		{
			if (i==15)
			{
				i=143;
				j=15;
			}
			else if (j==15)
			{
				j=143;
				k=15;
			}
			else if ( k==15 )
			{
				k=143;
				l=15;
			}
		}
		else if ( ch==32 )
		{
			break;
		}
	}
	if ( i==15 )
		play();
		
	else if ( j==15 )
		HowToPlay();
		
	else if ( k==15 )
		view_scores();
		
	else if ( l==15 )
		return 0;
  }
}

void play ( void )
{
	srand(time(0));
	system( "color F0" );
	system( "cls" );
	int i, ch, length=7, direction=0; // 0=right 1=down 2=left 3=up
	int fco[2],points=-1;
	int **co = (int**) calloc ( (length+1), sizeof(int*) );
	for ( i=0;i<=length;i++ )
	{
		co[i] = ( int* ) calloc ( 2, sizeof( int ) );
	}
	co[0][0]=30;
	co[0][1]=10;
	
	border();
	food( fco );
	score( &points );
	
	color( 47 );
	for( i=0;i<3;i++ )
	{
		setxy( 76,1+i );
		printf( "                                         " );
	}
	setxy( 80,2 );
	printf( "How long can you take your snake?" );
	
	while (1)
	{
		while( !kbhit() )
		{
			delay(SPEED);
			display( length, co );
			
			if ( fco[0]==co[0][0] && fco[1]==co[0][1] )
			{
				food( fco );
				score( &points );
				length++;
				co = (int**) realloc ( co, (length+1)*sizeof(int*) );
				co[length] = ( int* ) calloc ( 2, sizeof( int ) );
			}
			if ( co[0][0]==1 || co[0][0]==79 || co[0][1]==5 || co[0][1]==40 )
			{
				goto END;
			}
			for( i=3;i<length;i++ )
			{
				if ( co[0][0]==co[i][0] && co[0][1]==co[i][1] )
				{
					goto END;
				}
			}
			
			for ( i=length;i>0;i-- )
			{
				co[i][0]=co[i-1][0];
				co[i][1]=co[i-1][1];
			}
			
			if ( direction==0 )
				co[0][0]++;
			else if ( direction==1 )
				co[0][1]++;
			else if ( direction==2 )
				co[0][0]--;
			else if ( direction==3 )
				co[0][1]--;
		}
		ch=getch();
		if ( ch==RIGHT && direction!=2 )
		{
			direction=0;
		}	
		else if ( ch==DOWN && direction!=3 )
		{
			direction=1;
		}
		else if ( ch==LEFT && direction!=0 )
		{
			direction=2;
		}
		else if ( ch==UP && direction!=1 )
		{
			direction=3;
		}
	}
	END:
		color(207);
		setxy( 0,19 );
		for( i=0;i<825;i++ )
			printf( " " );
		setxy( 70, 21 );
		printf( "GAME OVER!!!" );
		delay(1500);
		getch();
	//	save( points );
		return;
}

void HowToPlay( void )
{
	system( "cls" );
	system("color 70");
	setxy( 62,3 );
	printf( "How To Play" );
	setxy( 52,6 );
	printf( "Use the arrow keys to control the snake." );
	setxy( 52,7 );
	printf( "Make Score by eating the food." );
	setxy( 52,8 );
	printf( "Have FUN :)" );
	getch();
}

void display ( int length, int **co )
{
	color(242);
	clear( co[length][0]*2,co[length][1] );
	setxy( co[0][0]*2,co[0][1] );
	printf( "%c%c",178,178 );
	return;
}

void score ( int *points )
{
	int i,j;
	(*points)++;
	color(95);
	for( i=0;i<3;i++ )
	{
		setxy( 36,1+i );
		printf( "                 " );
	}
	setxy( 40,2 );
	printf( "SCORE:  %d",*points );
	return;
}

void food ( int fco[2] )
{
	fco[0]=2+rand()%77;
	fco[1]=6+rand()%34;
	setxy( 2*fco[0],fco[1] );
	color( 244 );
	printf( "%c",254 );
	return;
}

void save ( int score )
{
	struct score s;
	s.points = score;
	FILE *fp = fopen( "snake_scores.txt", "ab" );
	if ( fp == NULL )
	{
		fp = fopen( "snake_scores.txt", "wb" );
	}
	system( "cls" );
	system( "color BF" );
	setxy( 60,19 );
	printf( "Enter Name: " );
	gets( s.name );
	fwrite( &s, sizeof(s), 1, fp );
	setxy( 60,21 );
	printf( "Your score has been saved!" );
	setxy( 60,23 );
	printf( "press any key to continue..." );
	getch();
	fclose( fp );
	return;
}

void view_scores ( void )
{
	struct score s;
	int i=0;
	system( "cls" );
	system( "color BF" );
	FILE *fp = fopen( "snake_scores.txt", "rb" );
	if ( fp==NULL )
		puts( "No Record was found!!!" );
	else {
		setxy( 62,2 );
		printf( "Name\t\tScore" );
		while ( fread( &s, sizeof(s), 1, fp )==1 )
		{
			setxy( 60,4+(2*i) );
			i++;
			if ( strlen(s.name)>9 )
				printf( "%d.%s\t  %d\n", i, s.name, s.points );
			else 
				printf( "%d.%s\t\t  %d\n", i, s.name, s.points );
		}
	}
	getch();
	return;
}

void border ( void )
{
	int i,j;
	color(243);
	for ( i=0;i<36;i++ )
	{
		setxy( 2,5+i );
		for( j=0;j<79;j++ )
		{
			if ( i==0 || j==0 || i==35 || j==78 )
				printf( "%c%c",219,219 );
			else 
				printf( "  " );
		}
		printf( "\n" );
	}
	return;
}
