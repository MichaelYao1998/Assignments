
#include "board.h"
#include "game.h"
#include "player.h"
#include<string.h>
#include<stdlib.h>
	Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED,}
};
Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};
void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	int o,p;
  for(o=0;o<BOARD_HEIGHT;o++)
  {
    for(p=0;p<BOARD_WIDTH; p++)   
    {
	 board[o][p] = EMPTY;
    } 
  }
}

void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{ 
int i,j; 

 printf("| |0|1|2|3|4|5|6|7|8|9|\n");

	for(i=0;i<BOARD_HEIGHT;i++)
  {
	  printf("|%d|",i);
    for(j=-0;j<BOARD_WIDTH; j++)   
    {
	  if(board[i][j] == EMPTY)
		{
		printf(" |");
		}
		else if(board[i][j] == BLOCKED)
		{
			printf("*|");
		}
		else if(board[i][j] == PLAYER)
		{
			
		displayDirection(player->direction);
		printf("|");
		}
    }
	printf("\n");
  }

	
}


void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
	int i,j;
	int z,c;
	for(i=0;i<BOARD_HEIGHT;i++)
    for(j=0;j<BOARD_WIDTH; j++)  
    board[i][j]=boardToLoad[i][j];
    for(z=0;z<BOARD_HEIGHT;z++)
    for(c=0;c<BOARD_WIDTH; c++) 
	board[z][c]=boardToLoad[z][c];	
}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{

    if(board[position.y][position.x]==BLOCKED)
      {
	 
		  return FALSE;
      }
	else if(board[position.y][position.x]==EMPTY)
	  {
		 board[position.y][position.x]=PLAYER;
	     return TRUE;
	  }
	  return TRUE;
}

PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
                             Player * player)
{ 
    Position position = getNextForwardPosition(player);
	
	if(position.y >= BOARD_HEIGHT || position.y < 0 || position.x >= BOARD_WIDTH || position.x < 0)
	{
		return OUTSIDE_BOUNDS;
	}	
	if(board[position.y][position.x]==BLOCKED)
	{
		return CELL_BLOCKED;
	}
	
	board[position.y][position.x]=PLAYER;	
	board[player->position.y][player->position.x]=EMPTY;
	
	updatePosition(player, position);
	
    return PLAYER_MOVED;
}











