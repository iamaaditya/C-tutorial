/* Adi - Oct 7, 2014 */
/* expansion of Struct code into more nodes */
/* please see struct_simple.c and struct.c before looking at this code */

#include <stdlib.h>
#include <stdio.h>


struct node {
  int val;
  struct node *next;
};

void printNode(struct node *n) {
  printf("\n|---|");
  printf("\n| %d |", n->val);
  printf("\n|---|");
}

int main()
{
    /* This will be the unchanging first node */
    struct node *root;

    /* following are the declarations of other nodes we will be using */
    struct node *child;
    struct node *grand_child;
    struct node *great_grand_child;

    /* Now root points to a node struct */
    root = (struct node *) malloc( sizeof(struct node) );
    /* simillary for others */
    child = (struct node *) malloc( sizeof(struct node) );
    grand_child = (struct node *) malloc( sizeof(struct node) );
    great_grand_child = (struct node *) malloc( sizeof(struct node) );

  
    
    root->next = 0;

    root->val = 5;

    /* look carefully here, the way I am building the list is different from the code
    shared by Storer. See if you can spot the difference */
    child->next = root;
    child->val = 100;

    grand_child->next  = child;
    grand_child->val = 200;

    /* now you would expect the great_grand_child to point to grand_child */ 
    /* but just as thought experiment, I am showing you that it can point to 
    whereever you want. Programming is like canvas, you can draw whatever you want */
    great_grand_child->next = root ;

    printNode(root); /* try printing other nodes too */
}
