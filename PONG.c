#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "animation.h"
#define BORDER 30

void play ( void );
void HowToPlay( void );
void border ( void );
void ball( int x, int y );
void bar ( int bary );
void bar2 ( int bary );

int main()
{
	int i=15,j=143,k=143,ch;
	while (1)
	{
	system( "color 73" );
	system("cls");
	color(78);
	setxy( 66,2 );
	printf( "                    " );
	setxy( 65,3 );
	printf( "       PONG GAME      " );
	setxy( 64,4 );
	printf( "                        " );
	
	while( 1 )
	{
		color(i );
		setxy( 64,6 );
		printf( "                        " );
		setxy( 64,7 );
		printf( "          Play          " );
		setxy( 64,8 );
		printf( "                        " );
		
		color(j );
		setxy( 64,10 );
		printf( "                        " );
		setxy( 64,11 );
		printf( "       How To Play      " );
		setxy( 64,12 );
		printf( "                        " );
		
		color(k );
		setxy( 64,14 );
		printf( "                        " );
		setxy( 64,15 );
		printf( "          Quit          " );
		setxy( 64,16 );
		printf( "                        " );
		
		ch=getch();
		if ( ch==72 )
		{
			if (j==15)
			{
				i=15;
				j=143;
				k=143;
			}
			else if (k==15)
			{
				i=143;
				j=15;
				k=143;
			}
		}
		else if ( ch==80 )
		{
			if (i==15)
			{
				i=143;
				j=15;
				k=143;
			}
			else if (j==15)
			{
				i=143;
				j=143;
				k=15;
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
		return 0;
		
  }
}

void play ( void )
{
	int x=50,y=4,dx=2,dy=1;
	int speed=20, score=0;
	int bary=4, ch;
	system("color 7B");
	color(123);
	border();
	
	/*** Initial Score ***/ 
	color(95);
	setxy( 77,4 );
	printf( "     " );
	setxy( 77,5 );
	printf( "  %d  ",score);
	setxy( 77,6 );
	printf( "     " );
	
	color(115);
	bar ( bary );
	
	while ( 1 )
	{
		while ( !kbhit() )
		{
			delay(1000/speed);
			color(115 );
			clear(x,y);
			if ( dy>0 && y>5 )
			{
				clear( 136,y-3 );
			}
			else if ( dy<0 && y<29 )
			{
				clear( 136,y+3 );
			}
			color(68 );
			bar2(y-2);
			if ( y==BORDER+1 || y==3 )
			{
				dy*=-1;
			}
			if ( x==4*BORDER+14 || y>=bary && y<bary+5 && x==26 )
			{
				dx*=-1;
				if ( y==bary+2 )
					dy=0;
				else if ( y<bary+2 && dy==0 )
					dy=-1;
				else if ( y>bary+2 && dy==0 )
					dy=1;
			}
			if ( x==22 )
			{
				goto END;
			}
			if ( x==26 || x>76 && x<82 && y>3 && y<7 )
			{
				if (x==26)
				{
					speed++;
					score++;
				}
				color(95 );
				setxy( 77,4 );
				printf( "     " );
				setxy( 77,5 );
				printf( "  %d  ",score);
				setxy( 77,6 );
				printf( "     " );
			}
			(x)+=dx;
			(y)+=dy;
			color(85 );
			ball( x,y );
		}
		ch=getch();ch=getch();
		color(115 );
		switch ( ch )
		{
		case 72:
			if (bary>3)
			{
				bary--;
				clear( 24,bary+5 );
				bar ( bary );
			}
			break;
		case 80:
			if ( bary<27 )
			{
				bary++;
				clear( 24,bary-1 );
				bar ( bary );
			}
				break;
		}
	}
	
	END:
		system ("cls");
		system ( "color 7C" );
		border();
		setxy( 2*BORDER+14,16 );
		color(207 );
		printf( "GAME OVER!!!" );
		delay(1500);
		getch();
	return;
}

void HowToPlay( void )
{
	system( "cls" );
	system("color 70");
	setxy( 62,3 );
	printf( "How To Play" );
	setxy( 52,6 );
	printf( "Use UP and Down arrow keys to control the bar." );
	setxy( 52,7 );
	printf( "Score by hitting the ball." );
	setxy( 52,8 );
	printf( "Have FUN :)" );
	getch();
}

void border ( void )
{
	int i, j;
	for ( i=0;i<=BORDER;i++ )
	{	
		setxy( 20,2+i );
		for ( j=0;j<=2*BORDER;j++ )
		{
			if ( i==0 || j==0 || i==BORDER || j==2*BORDER )
				printf( "%c%c", 219,219 );
			else 
				printf( "  " );
		}
	}
	return;
}

void ball( int x, int y )
{
	setxy( x,y );
	printf( "%c%c", 219, 219 );
	return;
}

void bar ( int bary )
{
	int i;
	for ( i=0;i<5;i++ )
	{
		setxy( 24, bary+i );
		printf( "%c%c", 219, 219 );
	}
}

void bar2 ( int bary )
{
	int i;
	if ( bary>27 )
	{
		bary=27;
	}
	else if ( bary<3 )
	{
		bary=3;
	}
	for ( i=0;i<5;i++ )
	{
		setxy( 136, bary+i );
		printf( "%c%c", 219, 219 );
	}
}
