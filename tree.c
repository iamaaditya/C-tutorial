#include<stdlib.h>
#include<stdio.h>

struct singly_linke_list {
   int val;
   struct singly_linke_list binary_tree *parent;
};

struct binary_tree {
   int val;
   struct binary_tree * right, * left;
};

typedef struct binary_tree node;


void In_Order(node * tree) {
   if(tree->left) In_Order(tree->left);
   printf("%d\n",tree->val);
   if(tree->right) In_Order(tree->right);
}

void Pre_Order(node * tree) {
   printf("%d\n",tree->val);
   if(tree->left) Pre_Order(tree->left);
   if(tree->right) Pre_Order(tree->right);
}

void Post_Order(node * tree) {
   if(tree->left) Post_Order(tree->left);
   if(tree->right) Post_Order(tree->right);
   printf("%d\n",tree->val);
}

int main() {
   node * curr, * root;
   int i;

   root = NULL;

   for(i=1;i<=10;i++) {
      curr = (node *)malloc(sizeof(node));
      curr->left = curr->right = NULL;
      curr->val = rand() % 100;
      /* curr->val = i; */
      /* insert(&root, curr); */
   }

   Pre_Order(root);
   printf("*****\n");
   Post_Order(root);
   printf("*****\n");
   In_Order(root);
}
