#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data ;
    struct node* link ;
};
struct node* reverse(struct node *head) 
{
    struct node *prev = NULL ;
    struct node *current = NULL ; 
    while(head!=NULL)
    {
        next = head->link ; 
        head->link = prev ; 
        prev = head ; 
        head = next ; 
    }
    head = prev ;
    return head ;
}
struct node* addnode(struct node* head , int value) 
{
    struct node* newNode = NULL ; 
    newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = value ; 
    newNode->link= NULL ;

    newNode->link = head ;
    head = newNode ;
    return head ;  

} 
struct node* createLL(struct node* head , int num)
{
    while(num!=0)
    {
        head= addnode(head,num%10) ; 
        num = num/10 ; 
    }
    return head ; 
}
void print(struct node* head )
{
  struct node* temp = head ; 
  if(head==NULL)
  {
      printf("Empty") ; 

  }
  else{
      while(temp->link!=NULL)
      {
          printf("%d->",temp->data) ; 
          temp = temp->link ;
      }
      printf("%d" , temp->data) ; 
  }
}


int main()
{
    int num1 , num2; 
    printf("Enter the number one of the LL") ; 
    scanf("%d" , &num1) ; 
    printf("Enter the number two of the LL") ; 
    scanf("%d" , &num2) ; 
    printf("Linked list representation of the first number is\n") ; 
    struct node* head1 = NULL  ;
    head1 = createLL(head1,num1)  ;
    print(head1); 
    printf("\nLinked list representation of the second number is\n") ; 
    struct node* head2 = NULL  ;
    head2 = createLL(head2,num2) ;
    print(head2) ;
    head1 = reverse(head1) ; 
    head2 = reverse(head2) ;
    printf("Reverse Linked List Is\n") ; 
    print(head1) ; 
    printf("\n") ; 
    print(head2) ; 

    

}