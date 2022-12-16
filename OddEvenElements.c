
//By Ayush Chauhan Btech CST 21021257
//Question 3
typedef struct node{
	int data;
	struct node *next;
}nodetype;

#include <stdio.h>
#include <stdlib.h>

void insertNode(nodetype **head, int x)                      //function to insert new node
{
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    p->data = x;
	p->next = *head;
    *head = p;
}
void separator(nodetype *P, nodetype **Q, nodetype **R)      //odd/even separator based on position
{
    int i=1;
    while(P!=NULL){
        if(i%2)
            insertNode(Q, P->data);
        else
            insertNode(R, P->data);
        P = P->next;
        i++;
    }
}
void display(nodetype *head)                                 //display function
{
    while (head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main(){
    int n;
    printf("By Ayush Chauhan Btech CST 21021257\n");
    printf("Enter num of nodes: ");
    scanf("%d", &n);
    nodetype *P = NULL, *Q= NULL, *R=NULL;
    printf("Enter a linked list elements:\n");
    while (n!=0)
    {
        int x;
        scanf("%d", &x);
        insertNode(&P, x);
        n--;
    }
    //separating the nodes
    separator(P, &Q, &R);
    //printing...
    printf("elements at odd positions are: ");
    display(Q);
    printf("elements at even positions are: ");
    display(R);
    
    return 0;
}
