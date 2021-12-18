/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[lb..midterm]
// Second subarray is arr[midterm+1..r]
void merge(int arr[], int lb, int midterm, int r)
{
	int i, j, k;
	int n1 = midterm - lb + 1; //4+1 , 8-4 
	int n2 = r - midterm;

	/* create temp arrays */
   int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[lb + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[midterm + 1 + j];

	/* Merge the temp arrays back into arr[lb..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = lb; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* lb is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int lb, int r )
{
	if (lb < r) {
		// Same as (lb+r)/2, but avoids overflow for
		// large lb and h
		int midterm = lb + (r - lb) / 2;

		// Sort first and second halves
		mergeSort(arr, lb, midterm);
		mergeSort(arr, midterm + 1, r);

		merge(arr, lb, midterm, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
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
