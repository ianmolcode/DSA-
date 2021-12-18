#include <stdio.h>
#include <stdlib.h>
void merge(int array[] , int mid , int lb , int ub) 
{
    int i  , j , k = lb ; 
    int n1 = mid - lb + 1 ;
    int n2 = ub - mid ;
    int a[n1] , b[n2] ;
    while(i<= mid && j<=ub) 
    {
        if(a[b] <= a[j])
        {
           b[k] = a[i] ;
           i++ ;
        }
        else
        {
            b[k] = a[j] ;
           j++ ; 
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
             b[k] = a[j] ;
             j++ ; 
             k++ ; 
        }
    }
    else
    {
        while(i<=mid)
        {
        b[k] = a[i] ;
        i++ ; 
        k++ ; 
        }
    }
    for(k=lb ; k<= ub ; k++)
    {
        a[k] = b[k];
    }

}
void mergeSort(int array[], int lb , int ub )
{
    if(lb<ub)
    {
        int mid = (lb+ub)/2 ; 
        mergeSort(array, lb , mid) ; 
        mergeSort(array, mid+1 , ub);
        merge(array, lb , mid , ub) ; 
    }
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver code */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}