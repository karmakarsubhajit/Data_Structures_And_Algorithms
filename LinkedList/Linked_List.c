#include<stdio.h>
#include <stdlib.h>

struct node{

  int val;
  struct node* next;  
};


struct node* insertNode(struct node* head, int val)
{
  if(head==NULL)
    {
         struct node* new_node = (struct node*)malloc(sizeof(struct node));
         new_node->next=NULL;
         new_node->val = val;
         return new_node;  
   }
   else  
     {
	 struct node* new_node = (struct node*)malloc(sizeof(struct node));
          new_node->val = val;
         new_node->next = head;
         return new_node; 
     }
   
}

void printList(struct node* n)
{
  while(n!=NULL)
  {
    printf("%d, ",n->val);
    n = n->next;
  }
}

int main()
{
    struct node* head =NULL;
    head=insertNode(head, 32);    
    head=insertNode(head, 2);    
    head=insertNode(head, 3);    
    head=insertNode(head, 11);    
    printList(head);
    return 0;
}