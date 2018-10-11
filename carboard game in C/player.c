#include "player.h"

void initialisePlayer(Player * player, Position * position, Direction direction)
{
   	
	player -> position.x=position->x;
    player -> position.y=position->y;
	player ->moves =0;
	player -> direction = direction;
   
}

void turnDirection(Player * player, TurnDirection turnDirection)
{
    /* TODO */
	
	if(turnDirection==TURN_LEFT)
	{
		if(player->direction==NORTH)
		{
	    player->direction=WEST;
	    }
		else if(player->direction==WEST)
		{
			 player->direction=SOUTH;
		}
		else if(player->direction==SOUTH)
		{
			 player->direction=EAST;
		}
		else if(player->direction==EAST)
		{
		player->direction=NORTH;
		}
	}
		else if(turnDirection==TURN_RIGHT)
		{
			if(player->direction==NORTH)
			{
				  player->direction=EAST;
			}
			else if(player->direction==EAST)
			{
				 player->direction=SOUTH;
			}
			else if(player->direction==SOUTH)
			{
				 player->direction=WEST;
			}
			else if(player->direction==WEST)
			{
				 player->direction=NORTH;
			}
		}
}

Position getNextForwardPosition(const Player * player)
{
	Position position = player->position; 

	if(player->direction==NORTH)
	{
	    position.y--;
	}
	else if(player->direction==SOUTH)
	{
		position.y++;
	}
	else if(player->direction==EAST)
	{
		position.x++;
	}
	else if(player->direction==WEST)
	{
		position.x--;
	}
    return position;
}

void updatePosition(Player * player, Position position)
{
   player->position = position;
   player->moves++;
}

void displayDirection(Direction direction)
{
	if(direction == NORTH)
	{
		printf(DIRECTION_ARROW_OUTPUT_NORTH);
	}
	else if(direction == EAST)
	{
		printf(DIRECTION_ARROW_OUTPUT_EAST );
	}
	else if(direction == SOUTH)
	{
		printf(DIRECTION_ARROW_OUTPUT_SOUTH);
	}
	else if(direction == WEST)
	{
		printf(DIRECTION_ARROW_OUTPUT_WEST);
	}
}
