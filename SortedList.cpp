#include<stdlib.h>
#include "SortedList.h"


SortedList::SortedList() {
	Mysl = NULL;
}

SortedList::~SortedList() {
	// TODO Auto-generated destructor stub
}

//Insert a node in the list according to its heuristic value
void SortedList::Insert(Node *aNode)
{
	int Val = 0;

	slist *tmp = NULL;
	slist *csl = Mysl;
	slist *elem = new slist;

	if(!elem) exit(EXIT_FAILURE);
	elem->value = Val;
	elem->myNode = aNode;
	while(csl && csl->value > Val)
	{
		tmp = csl;
		csl = csl->next;
	}
	elem->next = csl;
	if(tmp) tmp->next = elem;
	else Mysl = elem;
}

// Pop the first node of the list
Node * SortedList::Pop()
{
	slist *tmp;
	Node *node;
	if(!Mysl) return NULL;     
	tmp = (Mysl)->next;
	node = (Mysl)->myNode;
	//free(Mysl);
	Mysl = tmp;             
	return node;            
}

//Clear the list
void SortedList::Clear()
{
	slist *tmp;
	while(Mysl)
	{
		tmp = (Mysl)->next;
		free(Mysl->myNode);
		free(Mysl);
		Mysl = tmp;
	}
}

//Give the length of the List
int SortedList::Length()
{
	slist *sl = Mysl;
	int n=0;
	while(sl)
	{
		n++;
		sl = sl->next;
	}
	return n;
}

//Display the heuristic values of the list
void SortedList::View()
{
	slist *sl = Mysl;
	while(sl)
	{
		printf("i: %d, j: %d, val: %d\n",sl->myNode->i, sl->myNode->j, sl->myNode->val);
		sl = sl->next;
	}
}
