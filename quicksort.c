#include<stdio.h>

int partition(int array[], int lb, int ub)
{
  int pivot = array[lb] ; 
  int start = lb ; 
  int end = ub ; 
  while(start<end) 
  {
      while(array[start] <= pivot )
      {
          pivot++ ;
      }
      while(array[end] > pivot) 
      {
          end-- ; 
      }
      while(start<end) //when start is smaller then end
      {
          swap(&array[start] , &array[end]) ;
      }
  }
      swap(&array[lb] , &array[end] ) ; //when end>start so swapping of first element and element at end
      return end ;  //return location of the pivot
} 
void QuickSort(int array[] , int lb , int ub )
{ 
    int loc ; 
    if(lb<ub)
    {
      loc = partition (array,lb,ub) ;
      QuickSort(array,lb,loc-1) ;
      QuickSort(array,loc+1,ub);
    }

}
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void printArray(int array[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", array[i]);  
}  
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    QuickSort(arr, 0 , n-1);
    printf("Quick Sort array: \n");
    printArray(arr, n);
    return 0;
}