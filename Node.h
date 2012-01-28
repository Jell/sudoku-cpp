#ifndef NODE_H
#define NODE_H

#include<stdlib.h>
#include<stdio.h>
#include<string>

using namespace std;

class Node{
	private:

	public:
		int i;
		int j;
		int val;
		int branching;
		
		Node * parent;
		
		Node(int, int, int, int, Node *);
		~Node();
};


#endif
