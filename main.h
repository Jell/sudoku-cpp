#include <stdio.h>
#include"SortedList.h"
#include"Node.h"

typedef struct point
{
  int i;
  int j;
  int constraint;
} point ;

SortedList * openList;


int table[9][9];

int printMatrix();

point *findHigherConstraint();

bool checkLineJ(int, int);
bool checkLineI(int, int);
bool checkSquare(int, int, int);

void loadMatrix();
