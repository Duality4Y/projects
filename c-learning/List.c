#include "List.h"

//function to create a list.
List *List_creat()
{
	//allocate space for our list structure
	//that which holds how many nodes there are.
	//which is the first node.
	//and which is the last node.
	return calloc(1, sizeof(List));
}

//function that removes/deletes a list.
void List_destroy(List *list)
{
	//for every node in list
	LIST_FOREACH(list, first, next, cur)
	{
		//as long as there is a previous node.
		if(cur->prev)
		{
			//free the space of that node in the list.
			free(cur->prev);
		}
	}
	free(list->last);//free the last node.
	free(list); //and free the list struct.
}

//a function to free all the values in a list.
void List_clear(List *list)
{
	LIST_FOREACH(list, first, next, cur)
	{
		free(cur->value);
	}
}
//function that clears all the values and deletes the list.
void List_clear_destroy(List *list)
{
	List_clear(list);
	List_destroy(list);
}

//a function that adds a node to a list. and also add value to node.
void List_push(List *list, void *value)
{
	//create space for 1 node.
	ListNode *node = calloc(1, sizeof(ListNode));
	//check_mem(node);
	//put the value in that node.
	node->value = value;
	//if it's the first element (cause no prevous elements)
	if(list->first == NULL)
	{
		//we make the first node in the list node.
		list->first = node;
		//and we make the last one also node.
		list->last = node;
	}
	else
	{
		//else if we already got nodes.
		//we add the node as last node.
		list->last->next = node;
		//we make the nodes previous reference the list's last node.
		node->prev = list->last;
		//and then we make the list's last reference the node we just added.
		list->last = node;
	}
	//keep an index of how many elemenst/nodes we have in the list
	list->count++;
	return;
}

void *List_pop(List *list)
{
	ListNode *node = list->last;
	return node != NULL ? List_remove(list, node): NULL;
}

void List_unshift(List *list, void *value)
{
	ListNode *node = calloc(1, sizeof(ListNode));
	
	node->value = value;
	if(list->first == NULL)
	{
		list->first = node;
		list->last = node;
	}
	else
	{
		node->next = list->first;
		list->first->prev = node;
		list->first = node;
	}
	list->count++;
	return;
}

void *List_shift(List *list)
{
	ListNode *node = list->first;
	return node != NULL ? List_remove(list, node): NULL;
}

void *List_remove(List *list, ListNode *node)
{
	void *result = NULL;
	
	if(node == list->first && node == list->last)
	{
		list->first = NULL;
		list->last = NULL;
	}
	else if(node == list->first)
	{
		
	}
	return result;
}
