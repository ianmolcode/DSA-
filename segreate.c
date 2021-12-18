#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}nodetype;

void insertNode(nodetype **start , nodetype **rear,int data);
void display(nodetype *start , nodetype *rear , int ch);
void convertEvenOdd(nodetype *start,nodetype *rear,nodetype **evenStart,nodetype **evenRear,nodetype **oddStart,nodetype **oddRear);

int main()
{
    nodetype *start=NULL,*rear=NULL,*evenStart=NULL,*evenRear=NULL,*oddStart=NULL,*oddRear=NULL;
    int ch,data;
    do{
        printf("1 InsertNode , 2 DisplayNode , 3 OperateLinkedList , 4 Exit : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter Data to insert : ");
                scanf("%d",&data);
                insertNode(&start,&rear,data);   
                break;
            }
            case 2:{
                display(start,rear,1);
                display(evenStart,evenRear,2);
                display(oddStart,oddRear,3);
                break;
            }
            case 3:{
                convertEvenOdd(start,rear,&evenStart,&evenRear,&oddStart,&oddRear);
            }
            case 4:
                printf("Exiting");
                break;
            default:
                printf("Invaild!");
                break;
        } 
    }while(ch!=4);
    return 0;
}

void insertNode(nodetype **start,nodetype **rear, int data){
    nodetype *P = (nodetype *)malloc(sizeof(nodetype));
    if(P!=NULL)
    {
        P->info = data;
        if((*start) == NULL)
        {
            (*start)=(*rear)=P;
        }
        else{
            (*rear)->next = P;
            (*rear) = P;
            }
    }
    else{
        printf("Memory Allocation Failure!");
    }
}
void display(nodetype *start , nodetype *rear , int ch){
    switch(ch){
        case 1:
            printf("Displaying all Nodes:\t");
            break;
            
        case 2:
            printf("Displaying Even Nodes:\t");
            break;
            
        case 3:
            printf("Displaying Odd Nodes:\t");
            break;
    }
    if(start == NULL){
        printf("No node found!\n");
    }
    else{
        while(start!=NULL){
            printf("%d \t",start->info);
            start=start->next;
        }
        printf("\n");
    }
}

void convertEvenOdd(nodetype *start,nodetype *rear,nodetype **evenStart,nodetype **evenRear,nodetype **oddStart,nodetype **oddRear)	
{
    if((start)==NULL){
        printf("\nCannot operate with empty linked List");
    }
    else{
        nodetype *temp = start;
        while(temp!=NULL){
            if(temp->info%2==0){
                insertNode(&(*evenStart),&(*evenRear),temp->info);
            }
            else{
                insertNode(&(*oddStart),&(*oddRear),temp->info);
            }
            temp = temp->next;
        }
        display(start,rear,1);
        display((*evenStart),(*evenRear),2);
        display((*oddStart),(*oddRear),3);
    }
}
