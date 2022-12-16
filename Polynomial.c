//By Ayush Chauhan Btech CST 21021257
//Question 4
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}nodetype;

void insert(nodetype **head, int total)                        //Function to insert a new node
{
	nodetype* p = (nodetype*)malloc(sizeof(nodetype));
	p->data = total;
	p->next = NULL;
    
    if((*head)==NULL)
    	*head = p;
    else{
    nodetype* temp = (*head);
    while(temp->next!=NULL)
    	temp=temp->next;
    temp->next = p;
    }
}
void createPoly(nodetype **head, int x)                   //Function to create a polynomial
{
	int con;
	for(int i=0; i<=x; i++){
        printf("Enter value of coefficient: ");
	    scanf("%d", &con);
    	insert(head, con);
	}
}
void addPoly(nodetype *p1, nodetype *p2, nodetype **p3, int x)        //Function to add polynomials
{
	while(x-- >= 0){
    	int total = p1->data + p2->data;
    	insert(p3, total);
    	p1=p1->next;
    	p2=p2->next;
	}
}
void display(nodetype *head)                    //Display Function
{
    while(head->next!=NULL){
   	 printf("%d, ", head->data);
   	 head = head->next;
    }
    printf("%d\n", head->data);
}
int main(){
	nodetype *p1, *p2, *p3;
	p1=p2=p3=NULL;
	int x;
	printf("Enter the degree of polynomial: ");
	scanf("%d", &x);
	printf("Create first polynomial:\n");
	createPoly(&p1, x);
	display(p1);
	printf("Create second polynomial:\n");
	createPoly(&p2, x);
	display(p2);
	printf("Adding to create 3rd polynomial:\n");
	addPoly(p1, p2, &p3, x);
	display(p3); 
	return 0;   
}
