#include "main.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int main()
{
  openList = new SortedList();

  Node *nodeTmp = NULL;
  Node *nextNode = NULL;
  Node *toBeFree = NULL;
  point *tmp = NULL;
  int count;
  int k;

  loadMatrix();

  printf("\n\nGrid to be solved:\n\n");

  printMatrix();



  tmp = findHigherConstraint();

  for(k = 0; k<10000; k++){

    if(tmp->constraint == 0) break;

    if(tmp->constraint>8){

      table[nodeTmp->j][nodeTmp->i] = 0;
      nextNode = openList->Pop();

      while(!(nodeTmp->i == nextNode->i && nodeTmp->j == nextNode->j)){

        table[nodeTmp->j][nodeTmp->i] = 0;

        toBeFree = nodeTmp;
        nodeTmp = nodeTmp->parent;
        free(toBeFree);

      }

      toBeFree = nodeTmp;
      nodeTmp = nextNode;
      free(toBeFree);

      table[nodeTmp->j][nodeTmp->i] = nodeTmp->val;

      tmp = findHigherConstraint();

    }else{
      for(int n = 1; n<10;n++){
        if(checkLineJ(n, tmp->j) && checkLineI(n, tmp->i) && checkSquare(n, tmp->i / 3, tmp->j / 3)){
          openList->Insert(new Node(tmp->i, tmp->j, n, 9 - tmp->constraint ,nodeTmp));
        }
      }

      nodeTmp = openList->Pop();

      table[nodeTmp->j][nodeTmp->i] = nodeTmp->val;
      tmp = findHigherConstraint();

    }
  }

  printf("\nSolution found after %d iterations: \n\n", k);

  printMatrix();

  string stop;
  getline(cin,stop,'\n');

  openList->Clear();
  free(tmp);
  return 0;
}

int printMatrix(){
  int i, j;

  printf(" -----------------------------\n");

  for(j=0;j<9;j++){

    printf("|");
    for(i=0;i<9;i++){
      if(table[j][i] == 0){
        printf("   ");
      }else{
        printf(" %d ", table[j][i]);
      }
      if(i==2 || i == 5) printf("|");
    }

    printf("|\n");
    if(j == 2 || j == 5 || j==8){
      printf(" ----------------------------- \n");
    }else{
      printf("|         |         |         |\n");
    }
  }
  return 0;
}

point *findHigherConstraint(){
  point *tmp = new point;
  int i, j, constraintTmp;
  int constraint = 0;

  for(j=0;j<9;j++){
    for(i=0;i<9;i++){
      if(table[j][i] == 0){

        constraintTmp = 0;
        for(int n = 1; n<10;n++){
          if(checkLineJ(n, j) && checkLineI(n, i) && checkSquare(n, i / 3, j / 3)){

          }else{
            constraintTmp++;
          }
        }

        if(constraintTmp>constraint){
          constraint = constraintTmp;
          tmp->i = i;
          tmp->j = j;
          tmp->constraint = constraint;
        }
      }
    }
  }
  return tmp;
}

bool checkLineJ(int n, int J){
  for(int i = 0; i<9; i++){
    if(table[J][i]==n) return false;
  }
  return true;
}

bool checkLineI(int n, int I){
  for(int j = 0; j<9; j++){
    if(table[j][I]==n) return false;
  }
  return true;
}

bool checkSquare(int n, int I, int J){
  for(int j = 0; j<3; j++){
    for(int i = 0; i<3; i++){
      if(table[j + 3*J][i + 3*I]==n) return false;
    }
  }
  return true;
}

void loadMatrix(){
  // Open a stream
  ifstream file;
  string fileName ="matrix.txt";
  file.open(fileName.c_str());
  if (!file){
    cout << "Error in openening file";
    return;
  }

  string lineread;
  int value;
  int i,j;
  i = 0;
  j = 0;

  while(std::getline(file, lineread,',')){

    value = atoi(lineread.c_str());

    table[j][i]=value;
    i++;
    if(i==9){
      i = 0;
      j++;
    }

  }

}
