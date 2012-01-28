#include<stdlib.h>
#include "Node.h"

Node::Node(int I, int J, int Val, int branch, Node *p) {

	i = I;
	j = J;
	val = Val;
	branching = branch;
	
	parent = p;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}
