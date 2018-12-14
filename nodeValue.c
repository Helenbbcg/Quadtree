#include"buildTree.h"
#include"treeStructure.h"
#include"nodeValue.h"
#include"writeTree.h"
#include"stdio.h"
#include"stdlib.h"
#include"math.h"
int add=0;
int rem=0;
int maxlevel=6;
// Evaluate function at centre of quadtree node

double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function

double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}
//Produce value to leaf nodes
void makeFlag(Node *node){
	int i;
	double j;
	if(node->child[0]==NULL){
		node->flag=0;
		j=nodeValue(node, 0.0 );
		if(j>0.5)
		   node->flag=1;
		if (j<-0.5)
		   node->flag=-1;
	}
	else{
	node->flag=0;
	for(i=0;i<4;i++)
	makeFlag(node->child[i]);
 
	}
return;	
}

void changeNode(Node *node){
	int i;
	int num=0;
	int level=node->level;
	if(node->child[0]==NULL){
	    if(node->flag==1&&level<maxlevel){
		makeChildren( node );
		add+=4;
	    }
    }
    else{
    	for(i=0;i<4;i++)
		{
			if(node->child[i]->flag==-1)
			   num+=1;
	    }
		if(num==4){
			removeChildren(node);
			rem+=4;
		    }
		else{
		    for(i=0;i<4;i++)
	            changeNode(node->child[i]);
		    }
        
	    }
} 

void adapt(Node *head){
	while(add!=0||rem!=0){
                add=0;
                rem=0;
		makeFlag(head);
		changeNode(head);
		printf("The number of add nodes is:%i\n",add);
        printf("The number of remove nodes is:%i\n",rem);    
	}
}


