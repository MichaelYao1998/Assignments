#include "addressbook.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INPUT_LENGTH 50
/**
* This file is to contain the main menu loop and thus it will have console
* output, meaning printf's are expected to be seen in this file.
* 
* After the user enters a command, then the corresponding function is to be
* called from commands.c, e.g., "forward" corresponds to "commandForward(...)".
*/

int main(int argc, char ** argv)
{ 	
    char string[INPUT_LENGTH + 1];
	char *tok1;char *tok2;char *ptr;char *ptr2;char *ptr3;
	AddressBookList *list;
	char *fileName;
	char *name;
	char *telephone;
	int id;
	int moves;
	printf("\n------------------------------------------------------------------\n");
	printf("Student name:Yuchen Yao\n");
	printf("Student number:3548974\n");
	printf("Advanced Programming Techniques, Assignment Two, Semester 1, 2017\n");
	printf("------------------------------------------------------------------\n\n");
	if(argc!=2)
	{
		list=createAddressBookList();
	}
	else
	{
		list=commandLoad(argv[1]);
	}
	
	printf("Enter your command:");
	
        while(!strcmp(string,"quit")==0)
        {
        	 
             fgets(string,INPUT_LENGTH + 1,stdin);
             if(strlen(string)<=1)
             {
            	printf(">Invalid input\n");
            	printf("Enter your command:");
            	continue;
			 }
	    	 if(string[strlen(string) - 1] != '\n')
             {
         
               readRestOfLine();
             }
             else
             {
               string[strlen(string) - 1] = '\0'; 
             }
		
			tok1 = strtok(string," ");
			
       if(strcmp(tok1,"load")==0)
		{
			fileName=strtok(NULL," ");	
		    
			list=commandLoad(fileName);
		   
			printf("\nEnter your command:");
		} /*load the file*/
	
		else if(strcmp(string,"unload")==0)
		{
			commandUnload(list);
			list = createAddressBookList();
			printf("\nEnter your command:");
		}/*Unload the list*/
		
		else if(strcmp(string,"display")==0)
		{		
			commandDisplay(list);
			printf("\nEnter your command:");
		}/*display the list*/
		
		else if(strcmp(string,"insert")==0)
		{
	        tok2=strtok(NULL,",");
			id=strtol(tok2,&ptr,10);
			name=strtok(NULL,",");
			telephone=strtok(NULL," ");
			commandInsert(list,id,name,telephone);
			printf("Enter your command:");
		}/*insert node*/
		
		else if(strcmp(tok1,"find")==0)
		{
			name=strtok(NULL," ");
			commandFind(list,name);
			printf("Enter your command:");
		}/*find node*/
		
		else if(strcmp(tok1,"forward")==0)
		{
			tok2=strtok(NULL," ");
			moves=strtol(tok2,&ptr2,10);
			commandForward(list,moves);
			printf("Enter your command:");
		}/*move forwrd*/
		
		else if(strcmp(tok1,"backward")==0)
		{
			tok2=strtok(NULL," ");
			moves=strtol(tok2,&ptr3,10);
			commandBackward(list,moves);
			printf("Enter your command:");
		}/*move backward*/
		
		else if(strcmp(string,"delete")==0)
		{
			commandDelete(list);
			printf("Enter your command:");
		}/*delete the entry*/
		
		else if(strcmp(tok1,"save")==0)
		{
			fileName=strtok(NULL," ");
			commandSave(list,fileName);
			printf("\nEnter your command:");
		}/*save the file*/
		
		else if(strcmp(tok1,"add")==0)
		{
			telephone=strtok(NULL," ");
		    commandAdd(list,telephone);	
            printf("Enter your command:");
		}/*add telephone number*/
		
		else if(strcmp(tok1,"remove")==0)
		{
			telephone=strtok(NULL," ");
            commandRemove(list,telephone);
            printf("Enter your command:"); 
		}/*remove telephone number*/
		
	    else if(strcmp(string,"quit")==0)
     	{
		printf("> Goodbye. \n\n");
		freeAddressBookList(list);
		exit(0);
	    }/*quit program*/
	    
	    else
	    {
	    	printf("Invalid\n");
	    	printf("Enter your command:");
		}/*Invalid input*/
    
}
    return EXIT_SUCCESS;
}

