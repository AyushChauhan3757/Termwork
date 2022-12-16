//By Ayush Chauhan Btech CST 21021257
//Question 5
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    int id;//id of process
    struct node *next;
}processtype;

void createList(processtype** tail, int i)                  //function to create process list
{
    processtype* p = (processtype*)malloc(sizeof(processtype));
    printf("enter time taken by process:");
    scanf("%d", &p->data);
    p->id = i;
    if(*tail==NULL){
        (*tail) = p;
        (*tail)->next = p;
        return;
    }
        
    p->next = (*tail)->next;
    (*tail)->next = p;
    (*tail) = p;
}
void displayList(processtype* tail)                         //function to displayList
{
    if(tail==NULL){
        printf("All processes completed\n");
        return;
    }
    processtype* p = tail->next;
    do{
        printf("%d for %d\n", p->data, p->id);
        p = p->next;
    }while(p!=tail->next);
    printf("\n");
}
void simulate(processtype** tail, int slot, int n)                     //function to simulate multiprocessing schedule
{
    int i=0, time=0;
    processtype* current = (*tail)->next;
    processtype* prev = (*tail); //useful when deleting nodes
    while((*tail)!=NULL){
        if(current->data>0){
            current->data -= slot; //cutting spent time
            prev=current;
            current = current->next;
            time+=slot;
        }
        if(current->data<=0){                                     //if required time is done
            printf("process %d completed after %d nanoseconds\n", current->id, time);
            processtype* temp = current;
            if(current==current->next)
                (*tail)=NULL;
            else{
                prev->next = temp->next;
                if(temp==(*tail))
                    (*tail) = prev;
            }
            current = current->next;
            free(temp);
            printf("time left for other processes:\n");
            displayList(*tail);
        }
        if(current==(*tail)) ++i;
    }
}

int main()
{
    printf("By Ayush Chauhan Btech CST 21021257\n");
    int n, slot=10;
    printf("Enter number of processes:");
    scanf("%d", &n);
    processtype* tail=NULL;
    printf("create process list\n");
    for(int i=1; i<=n; i++){
        createList(&tail, i);
    }
    displayList(tail);
    simulate(&tail, slot, n);
    return 0;
}
