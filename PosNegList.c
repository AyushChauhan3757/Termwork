//By Ayush Chauhan Btech CST 21021257
//Question 2
typedef struct node{
	int data;
	struct node *next;
}nodetype;

#include <stdio.h>
#include <stdlib.h>

void insertNode(nodetype **head, int x)                   //function to insert new node
{
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    p->data = x;
	p->next = *head;
    *head = p;
}
void separator(nodetype *head, nodetype **pos, nodetype **neg)     //negative and positive separator
{
    while(head!=NULL){
        if(head->data >= 0)
            insertNode(pos, head->data);
        else
            insertNode(neg, head->data);
        head = head->next;
    }
}
void display(nodetype *head)                                  //display function
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
    nodetype *head = NULL, *positive= NULL, *negative=NULL;
    printf("Enter linked list elements:\n");
    while (n!=0)
    {
        int x;
        scanf("%d", &x);
        insertNode(&head, x);
        n--;
    }
    //separating the nodes
    separator(head, &positive, &negative);
    //printing...
    printf("positive elements are: ");
    display(positive);
    printf("negative elements are: ");
    display(negative);
    
    return 0;
}
