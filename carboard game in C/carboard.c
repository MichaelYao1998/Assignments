#include "carboard.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char selection[5];
	char *ptr;
	int sel = 0;
	
	while(sel != 3)
	{
    printf("Welcome to Car Board\n");
	printf("--------------------\n");
	printf("1. Play game\n");
	printf("2. Show students's information\n");	
	printf("3. Quit\n");
	printf("Please enter your choice: ");
	fgets(selection,5,stdin);
		 if(selection[strlen(selection) - 1] != '\n')
        {
         
            readRestOfLine();
        }
        else
        {
            selection[strlen(selection) - 1] = '\0'; 
        }
	
	
	sel = strtol(selection,&ptr,5);
	
	switch(sel)
	{
		case 1:playGame();
		         break;		   
		case 2:showStudentInformation();
		       break; 
		case 3: printf("\nGood bye! \n\n");	
                 exit(0);         
                 break;
		default: printf("\n\nInvalid\n\n");
		     break;
	}
	
	}
    return EXIT_SUCCESS;
}



void showStudentInformation()
{
    
               printf("\n--------------------\n\n");
		       printf("Name: Yuchen Yao\n");
		       printf("ID:s3548974\n");
			   printf("Email: s3548974@student.rmit.edu.au\n");
			   printf("--------------------\n\n");         
		      
	
}
