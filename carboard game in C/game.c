#define INPUT_LENGTH 50
#define PROMPT_LENGTH 80
#define SUCCESS 1
#include "game.h"
#include "player.h"
#include "board.h"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>


void playGame()
{   
      Cell board[BOARD_HEIGHT][BOARD_WIDTH];
	char choice[30];

	 printf("\nYou can use the following commands to play the game:\n\n");
	 printf("load <g>\n");
	 printf("  g: number of the game board to load\n");
	 printf("init <x>,<y>,<direction>\n");
	 printf("  x: horizontal postion of the car on the board (between 0 & 9)\n");
	 printf("  y: vertical positon of the car on the board (between 0 & 9)\n");
	 printf("  direction: direction of the car's movement (north, east, south, west)\n");
	 printf("forward (or f)\n");
	 printf("turn_left (or l)\n");
	 printf("turn_right (or r)\n");
	 printf("quit\n\n");
	 printf("Press enter to continue...\n\n");
     getchar();
		 
    initialiseBoard(board);
    displayBoard(board,NULL);
	printf("\n");
	 message3();
	 while(!strcmp(choice,"quit" )== 0)
	 {
	char *tok;
	char *tok2;
	char *tok3;
	char *tok4; 
	char *ptr;
	char *ptr2;
	  char string[INPUT_LENGTH + 1];
    char prompt[PROMPT_LENGTH + 1];	
		long xa,xb;
	int getString(char* string, unsigned length, char* prompt);
	Player player;
	Position position;
	Direction direction;
	
	 fgets(choice,30,stdin);
	 
	 if(choice[strlen(choice) - 1] != '\n')
        {
            printf("Input was too long, try again. \n\n");
            readRestOfLine();
        }
        else
        {
            choice[strlen(choice) - 1] = '\0'; 
        }
		
	 if (strcmp(choice,"load 1" )== 0)
	 {
		 loadBoard(board, BOARD_1);
		 displayBoard(board,NULL);
		 message();	 
	sprintf(prompt, "Enter a string (max %d characters): ", INPUT_LENGTH); 
    printf("please type twice time if nothing comes out\n");
    getString(string,INPUT_LENGTH, prompt);
    
    tok = strtok(string, " ");
	tok2 = strtok(NULL,",");
	tok3 = strtok(NULL,",");
	tok4 = strtok(NULL,"\0");
	 if(strcmp(tok,"init")==0)
	{
		xa=strtol(tok2,&ptr,10);
				position.x=xa;

		xb=strtol(tok3,&ptr2,10);
				position.y=xb;

	    if((xa>=0 && xa<10) && (xb>=0 && xb<10))
	   {     
		if(strcmp(tok4,"north")==0)
		{     
	     direction= NORTH;
 	    }
			else if(strcmp(tok4,"south")==0){direction=SOUTH;}
			else if(strcmp(tok4,"east")==0){direction=EAST;}
			else if(strcmp(tok4,"west")==0){direction=WEST;}
			else{printf("\nInvalid\n");}
			
			if(!placePlayer(board, position))
			{
				printf("Cannot place player \n");
				displayBoard(board, NULL);
				message3();
			}
			else
			{
			placePlayer(board, position);
			initialisePlayer(&player,&position, direction);
			displayBoard(board,&player);
			message2();
			}
	   }
	}
	 }/*display board1*/
	 
	 else if(strcmp(choice,"load 2" )== 0)
	 {
		  	
		 loadBoard(board, BOARD_2);
         displayBoard(board, NULL);
         message();
	sprintf(prompt, "Enter a string (max %d characters): ", INPUT_LENGTH); 
    printf("please type twice time if nothing comes out\n");
    getString(string,INPUT_LENGTH, prompt);
    
    tok = strtok(string, " ");
	tok2 = strtok(NULL,",");
	tok3 = strtok(NULL,",");
	tok4 = strtok(NULL,"\0");

	 if(strcmp(tok,"init")==0)
	{
		xa=strtol(tok2,&ptr,10);
		position.x=xa;

		xb=strtol(tok3,&ptr2,10);
		position.y=xb;

	    if((xa>=0 && xa<10) && (xb>=0 && xb<10))
	   {     
		if(strcmp(tok4,"north")==0)
		{     
	     direction= NORTH;
 	    }
			else if(strcmp(tok4,"south")==0){direction=SOUTH;}
			else if(strcmp(tok4,"east")==0){direction=EAST;}
			else if(strcmp(tok4,"west")==0){direction=WEST;}
			else{printf("\nInvalid\n");}
			 if(!placePlayer(board, position))
			{
				printf("Cannot place player \n");
				displayBoard(board, NULL);
				message3();
			}
			else
			{
			placePlayer(board, position);
			initialisePlayer(&player,&position, direction);
			displayBoard(board,&player);
			message2();
			}
	   }
	   
	}
	 }/*display board2*/
     else if(strcmp(choice,"l")==0||strcmp(choice,"turn_left")==0)
	 {
		
          turnDirection(&player,TURN_LEFT);
		  displayBoard(board,&player);
		  message2();
	 }/*turn left*/
	 else if(strcmp(choice,"r")==0||strcmp(choice,"turn_right")==0)
	 {
		 turnDirection(&player,TURN_RIGHT);
		 displayBoard(board,&player);
		message2();
	 }
	 else if(strcmp(choice,"f")==0||strcmp(choice,"forward")==0)
	 {
	 	
		 movePlayerForward(board,&player);
		 displayBoard(board,&player);
		message2();
	 }/*forward*/
	 else if(strcmp(choice,"quit" )== 0)
	 {
		 printf("Return to the menu\n");
		 printf("Total player moves: %d \n\n", player.moves);
	 }/*quit*/

	 else 
	 { 
      printf("Invalid type\n\n");
      initialiseBoard(board);
	  printf("\n");
	  message3();
	 }
	 }
	 }

int getString(char* string, unsigned length, char* prompt)
{
   int finished = FALSE;
   char* tempString;
   	      if ((tempString = malloc(sizeof(char) * (length+2))) == NULL)
   {
      fprintf(stderr, "Fatal error: malloc() failed in getString().\n");
      exit(EXIT_FAILURE);
   }

   /* Continue to interact with the user until the input is valid. */
   do
   {


      /* Provide a custom prompt. */
      printf("%s", prompt);
      
      /* Accept input. "+2" is for the \n and \0 characters. */
      fgets(tempString, length + 2, stdin);

      /* A string that doesn't have a newline character is too long. */
      if (tempString[strlen(tempString) - 1] != '\n')
      {
         printf("Input was too long.\n");
         readRestOfLine();
      }
	  
      else
      {
         finished = TRUE;
      }

   } while (finished == FALSE);

   /* Overwrite the \n character with \0. */
   tempString[strlen(tempString) - 1] = '\0';
   
   /* Make the result string available to calling function. */
   strcpy(string, tempString);
   
   free(tempString);
   return SUCCESS;
}
 void message()
 {
	 
	 	 printf("At this stage of the program. only three commands are acceptable\n");
		 printf("load <g>\n");
		 printf("init <x>,<y>,<direction>\n");
		 printf("quit\n\n"); 

 }
  void message2()
  {
  	printf("\nAt this stage of the program, only four commands are acceptable: \n");
            printf("forward\n");
            printf("turn_left (or l)\n");
            printf("turn_right (or r)\n");
            printf("quit\n\n");
  }
void message3()
{
	printf("At this stage of the program. only two commands are acceptable\n");
	  printf("load <g>\n");
	  printf("quit\n\n"); 
}

