/* Adi - Oct 7, 2014 */
/* simple program to show how struct can be used to make linked list */

#include <stdlib.h>
#include <stdio.h>


/* before looking at this code, please see this struct.c */

struct node {
  int val;  
  struct node *next; // this is the tricky line and I hope I explained this concept in 
                    // class well enough. Remember that next is just a pointer which will
                    // eventually point to variable of type node, thus this is not recursive 
                    // definition of a struct.
};

/* Nice and pretty way to print a node, you may want to play with this to make it
print the whole linked list or tree, whatever you build using the nodes */
void printNode(struct node *n) {
  printf("\n|---|");
  printf("\n| %d |", n->val);
  printf("\n|---|");
}

int main()
{
    struct node *root;      

    /* as I told you in class, if you want to use the pointers just a variable
    and not bother about creating */ 
    root = (struct node *) malloc( sizeof(struct node) ); 

    /* For curious people, the size of struct node !! */
    printf("Size of the Struct Node is %lu\n", sizeof(struct node));

    printf("Confused !!! It is because (int) is: %lu \n", sizeof(int*));

    /* If it is the root, it points to nowwhere, you could have made it NULL also */
    root->next = 0;  
    

    /* using the arrow operator (see struct.c) we can access the member varaibles */
    root->val = 5; 

    printNode(root);


    struct node child1;
    child1.val = 9;
    child1.next = root;

    printNode(&child1);

}
