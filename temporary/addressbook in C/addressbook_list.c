#include "addressbook_list.h"
#include<string.h>
/**
* Note this file is *NOT* to contain console output,
* meaning printf's are *NOT* to be present in this file.
*/

AddressBookList * createAddressBookList()
{ 
    /**
    * Allocates and initialises a new AddressBookList.
    * malloc or calloc are expected to be used to create the
    * AddressBookList memory.
    * 
    * If memory cannot be allocated for the list NULL is returned.
    * 
    * Note head, tail and current should all be initialised to NULL.
    */
     AddressBookList *list=malloc(sizeof (*list));
     if(list == NULL)
    {
      return NULL;
    }
   if (list != NULL)
    {
    list->size=0;
    list->current=list->head=list->tail=NULL;
    } 

    return list;    
}

void freeAddressBookList(AddressBookList * list)
{
    /**
     * Free's all nodes within the list and the AddressBookList itself.
     * 
     * Note the freeAddressBookNode(...) function is used to free a node.
     */
     
     AddressBookNode * current= list->head;
	 AddressBookNode * nextNode;
     
    while (current != NULL)
   {
      nextNode = current->nextNode;
      
	  freeAddressBookNode(current);
	  
      current = nextNode;
   }
	free(list);
}

AddressBookNode * createAddressBookNode(int id, char * name)
{
    /**
    * Allocates and initialises a new AddressBookNode.
    * malloc or calloc are expected to be used to create the
    * AddressBookNode memory.
    * 
    * Note the array of the node should also be created and initialised,
    * which should be done with the createAddressBookArray(...) function.
    * 
    * If memory cannot be allocated for the node or array NULL is returned.
    * 
    * Note previousNode and nextNode should both be initialised to NULL.
    */
     AddressBookNode * node= malloc(sizeof(*node));
     if(node!=NULL)
     {
     	node->array=createAddressBookArray();
     	if(node->array==NULL)
     	{
     		free(node);
     		return NULL;
		}
		 node->nextNode=node->previousNode=NULL;
		 node->id=id;
		 strcpy(node->name,name);
    }
	 return node;
}

void freeAddressBookNode(AddressBookNode * node)
{
    freeAddressBookArray(node->array);
    free(node);
}

Boolean insertNode(AddressBookList * list, AddressBookNode * node)
{
    /**
     * Inserts the node into the list and returns TRUE.
     * 
     * If the list already contains a node with the same id
     * then FALSE is returned and the node is not inserted.
     */
    
    AddressBookNode *temp;
    temp=list->head;
    while(temp!=NULL)
    {
    	if(temp->id==node->id)
    	{
    		return FALSE;
		}
    	temp=temp->nextNode;
	}
		
     	if(list->head==NULL)
 		{
 			list->head=list->tail=list->current=node;
 		}
 		else
 		{
 			list->tail->nextNode=node;
 			node->previousNode=list->tail;
 			list->tail=node;
		}
	
		list->size++;
    	
    	return TRUE;
}

Boolean deleteCurrentNode(AddressBookList * list)
{
    /**
     * Delete's and free's the current node in the list and returns TRUE.
     * 
     * Note the freeAddressBookNode(...) function is used to free a node.
     * 
     * If the list has no nodes (i.e., there is no current node)
     * then FALSE is returned.
     */
    AddressBookNode *node=list->current;
    if(node==NULL)
    {
    	return FALSE;
	}
	if(node==list->head)
    {
    	list->head=node->nextNode;
	}
    if(node==list->tail)
    {
    	list->tail=node->previousNode;
	}
	if(node->previousNode!=NULL)
	{
		node->previousNode->nextNode=node->nextNode;
		list->current=node->previousNode;
	}
	if(node->nextNode!=NULL)
	{
		node->nextNode->previousNode=node->previousNode;
		list->current=node->nextNode;
	}
	if(list->current==node)
	{
		list->current=NULL;
	}
	freeAddressBookNode(node);
	list->size--;
    return TRUE;
}

Boolean forward(AddressBookList * list, int forward)
{
    /**
     * Moves the current node forward in the list by the number provided
     * and returns TRUE.
     * 
     * If the current node cannot be moved forward by that many positions
     * then FALSE is returned and current remains unchanged.
     */
	AddressBookNode *node;
	int i = 0;
	node=list->current;
	while(i<forward)
	{
		if(node->nextNode==NULL)/*prevent pointer goes out the boundary*/
		{
			return FALSE;
		}
		node=node->nextNode;
		i++;
	}
	list->current=node;
    return TRUE;
}

Boolean backward(AddressBookList * list, int backward)
{
    /**
    * Moves the current node backward in the list by the number provided
    * and returns TRUE.
    * 
    * If the current node cannot be moved backward by that many positions
    * then FALSE is returned and current remains unchanged.
    */

    AddressBookNode *node;
    int i=0;
	node=list->current;
    while(i<backward)
    {
    	if(node->previousNode==NULL)/*prevent pointer goes out the boundary*/
		{
			return FALSE;
		}
    	node=node->previousNode;
    	i++;
	}
	list->current=node;
    return TRUE;
}

AddressBookNode * findByID(AddressBookList * list, int id)
{
    /**
     * Returns the node that matches the id provided.
     * 
     * If no node with a matching id exists then NULL is returned.
     */

    return NULL;
}

AddressBookNode * findByName(AddressBookList * list, char * name)
{
     
   	struct addressBookNode *node;
	node=list->head;
	while(node)
	{
		if(strcmp(name,node->name)==0)
		{
			list->current=node;	/*move the pointer to the corresponding name*/ 
			return node;		 
		}
	node=node->nextNode;
	}
	return NULL;
}
