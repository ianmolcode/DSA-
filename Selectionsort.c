#include<stdio.h>
#include <math.h>
void insertsort(int array[] , int n )
{
    int i , j ; 
    int temp ;
    for(i=1 ; i<n ; i++)
    {
       temp=array[i];
       j = i-1;
       while(j>=0 && array[j]>temp)
       {
         array[j+1] = array[j] ; 
         j--; 
       }
       array[j+1] = temp ; 
    }
}
void print(int array[],int n)
{
    for(int i=0; i<n ; i++)
    printf("%d" , array[i]);
    printf("\n"); 
}
int main()
{
    int n ; 
    int array[5] = {5,4,3,2,1} ;  
    n = sizeof(array) / sizeof(array[0] ) ; 
    insertsort(array,n);
    print(array,n) ; 

}
