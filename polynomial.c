#include<stdio.h>
struct node
{
    float coeff ; 
    int expo ;
    struct node* link ;
} ;
struct node* insert(struct node* head, float co , int ex) 
{
    struct node* temp ; 
    struct node* newP = malloc(sizeof(struct node)) ;
    newP->coeff=co ; 
    newP->expo=ex ;
    newP->link = NULL ; 
    if(head==NULL || ex > head->expo) 
    {
        newP->link = head ; 
        head=newP ; 
    }
    else{
        temp = head; 
        while(temp->link != NULL && temp->link->expo >= ex)
        temp = temp -> link ; 
        newP->link = temp->link ; 
        temp->link = newP ; 
    }
    return head ;  
}
struct node* create(struct node* head)
{
    int n , i ;
    float coeff; 
    int expo ; 
    printf("Enter the number of the terms") ; 
    scanf("%d" , &n) ;
    for(i=0 ; i,n ; i++)
    {
        printf("enter the coeff for term %d: " , i+1);
        scanf("%f" , &coeff) ; 
        printf("enter the expo for term %d: " , i+1);
        scanf("%d" , &expo) ; 
        head=insert(head,coeff,expo) ; 

     } 
     return head ; 
}
int main()
{
    struct node* head1 = NULL ; 
    struct node* head2 = NULL ; 
    printf("Enter the first polynomial\n") ; 
    head1 = create(head1) ; 
    printf("Enter the second polynomial\n" ) ; 
    head2=create(head2) ; 
    polyAdd(head1,head2) ; 
    return 0 ; 
}