#include "commands.h"
#include "addressbook_list.h"
#include "addressbook_array.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Note this file is to contain console output,
 * meaning printf's are expected to be seen in this file.
 */

AddressBookList * commandLoad(char * fileName)
{
    /**
     * Loads the given file and returns a new AddressBookList.
     * 
     * If the file doesn't exist or corruption is found in the file
     * then NULL is returned.
     */
      
	AddressBookNode *node;
	AddressBookList *list;
	
	char line[MAX_LINE_LENGTH];
	char *name;int id;
	FILE*fp;
	
	char* val1;
	char* val3;
	
	char *ptr;
	fp = fopen(fileName , "r");
	if(!fp) 
	{
    printf(">Opening the file %s\n",fileName);
    printf(">Error:Unable to find the specified file.\n");
    return NULL;
    }
    if(fp==NULL)
    {
    	printf(">Opening the file %s\n",fileName);
    	printf(">Loading the file...\n");
    	printf(">Error: The specified file is in the wrong format and cannot be opened\n");
    	return NULL;
	}
	list=createAddressBookList();
    while (fgets(line, sizeof(line), fp) != NULL)
    {
    	if(line[0] == '#')/*skip lines start with #*/
    	{
    		continue;
		}
    	if(line[strlen(line) - 1] == '\n')
    	{
    		line[strlen(line) - 1] = '\0';
		}
        val1 = strtok(line, ",");/*read first token*/
        id=strtol(val1,&ptr,10);
        name = strtok(NULL, ",");  /*read second token*/
        
        node=createAddressBookNode(id,name);
       
	   
	   while(TRUE)
	   {
	   		val3 = strtok(NULL,",");
	   		if(val3 == NULL)
	   		{
	   			break;
			}
	   		addTelephone(node->array, val3);
	   }
       
       insertNode(list,node);
    }
    fclose(fp);
	printf("> opening the file %s\n",fileName);
	printf("> Loading the file ...\n");
	printf("> %d phone book entries have been loaded from the file\n",list->size);
	printf("> Closing the file.\n");
	return list;
}

void commandUnload(AddressBookList * list)
{ 
	freeAddressBookList(list);
	printf(">The list is unload\n");

}

void commandDisplay(AddressBookList * list)
{
	AddressBookNode * node;
	int i=1;int j;int max_len=0;int length;
	node = list->head;
	while(node != NULL)
	{
		 	
        length=strlen(node->name);/*get the length of name field*/ 
	    if(length>max_len)
      	{
		    max_len=length;/*the largest size of name field*/
        }
       	node=node->nextNode;/*Get the next node in the list*/
	}
	 
    printf("--------------------------------------------\n");
    printf("| Pos | Serial | ID | Name    | Telephones |\n");
    printf("--------------------------------------------\n");
		
	node = list->head;
	while(node != NULL)
	{
		if(list->current==node)
		{
			printf("| CUR |");
     	}
     	else
     	{
     		printf("|     |");	
		}	
    	printf("%5d   |%d |",i,node->id);/*print out id*/
        
	    
        printf("%-*s|",max_len+2,node->name);/*print name*/
        if(node->array->telephones!=NULL)
       	{
        	for(j=0;j<node->array->size;j++)
	     	{
		   		printf("%s,",node->array->telephones[j]);/*print telephone and comma*/
	     	}
        }
        printf("\n");
	    node = node->nextNode;/*Get the next node in the list*/
	  	i++;
		}
printf("-----------------------------------------------\n");
printf("| Total phone book entries: %d                 |\n",list->size);
printf("-----------------------------------------------\n");	
}

void commandForward(AddressBookList * list, int moves)
{ 
		if(!forward(list,moves))
		{
			printf(">Cannot move forward any more\n");
		}
		
}

void commandBackward(AddressBookList * list, int moves)
{ 
		if(!backward(list,moves))
		{                  
			printf(">Cannot move backward any more\n");
		}
		
}

void commandInsert(AddressBookList * list, int id, char * name, char * telephone)
{
	AddressBookNode * node;int j;
	node=createAddressBookNode(id,name);
	if(id<NODE_MINIMUM_ID)/*validate id length*/
	{
		printf(">Invalid input\n");
		return;
	}
	if(strlen(name)>NAME_LENGTH)/*validate name length*/
	{
		printf(">invalid input\n");
        return;
	}
	if(strlen(telephone)>TELEPHONE_LENGTH)/*validate telephone length*/
	{
		printf(">invalid input\n");
		return;
	}	
	while(j<strlen(telephone))/*validate telephone numbers without characters*/
	{
	    if(!isdigit(telephone[j]))
	    {
	    	printf(">Invalid input\n");
			return;
		}
		j++;
	}
	
	if(!insertNode(list,node))/*reject the same id and insert id and name*/
	{
		printf(">Cannot insert with the existed ID\n");
	}
	
    list->current=node;
	addTelephone(node->array, telephone);/*insert telephone*/
}

void commandAdd(AddressBookList * list, char * telephone)
{
	AddressBookNode *node;
	node=list->current;
	
	if(!addTelephone(node->array, telephone))
	{
		printf(">Invalid input\n");
	}	
	
}

void commandFind(AddressBookList * list, char * name)
{ 
	AddressBookNode *node;
   	node=findByName(list,name);   
  	if(!node) 
  	{
  		printf(">Unable to find node\n");
  	}
}

void commandDelete(AddressBookList * list)
{
  deleteCurrentNode(list); 
}

void commandRemove(AddressBookList * list, char * telephone)
{
	AddressBookNode *node;
	node=list->current;
    if(!removeTelephone(node->array,telephone))
    {
    	printf(">Invalid input\n");
	}
}

void commandSort(
    AddressBookList * list,
    int sort(const void * node, const void * otherNode))
{
    /* Sort the nodes within list in ascending order using the
     * provided sort function to compare nodes.
     */
}

int compareName(const void * node, const void * otherNode)
{
    /* Compare node name with otherNode name.
     * 
     * return < 0 when node name is smaller than otherNode name.
     * return 0 when the names are equal.
     * return > 0 when node name is bigger than otherNode name.
     */
    return 0;
}

int compareID(const void * node, const void * otherNode)
{
    /* Compare node id with otherNode id.
     * 
     * return < 0 when node id is smaller than otherNode id.
     * return 0 when the ids are equal.
     * return > 0 when node id is bigger than otherNode id.
     */
    return 0;
}

void commandSave(AddressBookList * list, char * fileName)
{
  AddressBookNode *node;
  FILE *fp;
  fp=fopen(fileName,"wb");
  if(!fp) {
    printf(">Cannot open file.\n");
    return;
  }
  printf(">Opening file %s\n",fileName);
  printf(">Writing list content to file...\n");
  printf(">Closing file.");
  node=list->head;
  while(node)
  {
  	fwrite(node,1,sizeof(*node),fp);
  	node=node->nextNode;
  }
  fclose(fp);
}


