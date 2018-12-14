#include"buildTree.h"
#include"treeStructure.h"
#include"nodeValue.h"
#include"writeTree.h"
#include"stdio.h"
#include"stdlib.h"
#include"math.h"
// function definitions


// main

int main( int argc, char **argv ) {
  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );
  // make a tree
  
  /*//Task1
  growTree(head);
  makeChildren(head->child[0]);
  writeTree(head);
  destroyTree(head);*/
  
  
  /*//Task2-1
  growTree(head);
  growTree(head);
  //makeChildren(head->child[0]);
  //makeChildren(head->child[1]);
  //Free nodes from a level 1 node
  removeChildren(head->child[0]);
  writeTree(head);
  destroyTree(head);*/
 
 
  
/*//Task2-2
growTree(head);
makeChildren(head);
makeChildren(head->child[0]);
//makeChildren(head->child[0]->child[0]);
//removeChildren(head->child[0]);
writeTree(head);
destroyTree(head);*/


//Task3
growTree(head);
growTree(head);
growTree(head);
makeFlag(head);
changeNode(head);
adapt(head);
writeTree(head);


  //destroyTree(head);
  //removeChildren (head->child[0]);
  // print the tree for Gnuplot*/
  //writeTree( head );
  //printf("add:%i remove:%i\n",num1,num2);
  //destroyTree(head);
  

  return 0;
}

