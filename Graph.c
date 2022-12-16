//By Ayush Chauhan Btech CST 21021257
//Question 9
#include <stdio.h>
#include <stdlib.h>

typedef struct linkNode{
    int dst;
    struct linkNode* next;
}linktype;
typedef struct graphNode{
    int data;
    struct linkNode *head;
}graphtype;

void addNodes(graphtype* graph, int n)                  //function to add values to graph
{
    printf("Enter data to be added:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &((graph+i)->data));
        (graph+i)->head = NULL;
    }
}
void addEdge(linktype** head, int x, int destination)   //function to add new edges
{
    linktype* p= (linktype*)malloc(sizeof(linktype));
    p->next = *head;
    p->dst = destination;
    *head = p;
}
void createEdges(graphtype* graph, int n)               //function to create edges from a node
{
    for(int i=0; i<n; i++){
        int ch;
        printf("Enter destinations for %d:\n", (graph+i)->data);
        do{
            printf("continue: 1/0:");
            scanf("%d", &ch);
            if(ch==1){
                int destination;
                scanf("%d", &destination);
                addEdge(&((graph+i)->head), (graph+i)->data, destination);
            }
        }while(ch==1);
    }
}

void display(graphtype* graph, int n)                   //function to display the graph
{
    printf("The graph:\n");
    for(int i=0; i<n; i++){
        printf("%d", (graph+i)->data);
        linktype* temp = (graph+i)->head;
        while(temp!=NULL){
            printf(" --> %d", temp->dst);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int num;
    printf("By Ayush Chauhan Btech CST 21021257\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &num);
    const int n = num;
    graphtype* graph = (graphtype*)malloc(sizeof(graphtype)*n);

    addNodes(graph, n);
    createEdges(graph, n);
    display(graph, n);

    return 0;
}
