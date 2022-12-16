//By Ayush Chauhan Btech CST 21021257
//Question 6
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}nodetype;

void insert(nodetype **head, int x)                  //function to compare and insert
{
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    p->data = x;
    p->prev = p->next = NULL;
    if(*head==NULL)
        *head = p;
    else if((*head)->data > p->data){
        p->next = *head;
        *head = p;
    }
    else{
      nodetype* temp = (*head)->next;
      nodetype* last = *head;
      while (temp->data<p->data)
        temp=temp->next;
      p->prev=temp->prev;
      temp->next=p;
      p->next=temp;
      temp->prev=p;
    }
}

void display(nodetype *head)                      //display function
{
    while(head->next!=NULL){
        printf("%d, ", head->data );
        head = head->next;
    }
    printf("%d\n", head->data);
}
int main(){
    printf("By Ayush Chauhan Btech CST 21021257\n");
    int n;
    printf("Enter num of nodes: ");
    scanf("%d", &n);
    nodetype *head = NULL;
    printf("Enter linked list elements: \n");
    while (n!=0)
    {
        int x;
        scanf("%d", &x);
        insert(&head, x);
        n--;
    }
    printf("sorted: ");
    display(head);  
    return 0;
}
