#include <stdio.h>

void swap(int *, int *);
int partition(int [], int, int);
void quicksort(int [], int, int);
void printArray(int [], int);

int main(){
    int arr[] = {50, 40, 20, 10, 30, 60, 90, 80, 70};

    int size = sizeof(arr)/sizeof(arr[0]);

    printf("The original array is: ");
    printArray(arr, size);

    // Sorting here
	quicksort(arr, 0, size-1);

    printf("The sorted array is: ");
	printArray(arr, size);
    return 0;
}

// swap will interchange the values of the two inputed variables
// Input must be address(&) of the variables
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Patition function sorts the unsorted array 
// with respect to Pivot in a way that element to the 
// left of it are are lesser in value while elements to
// right of pivot are higher in value
int partition(int arr[], int low, int high){
    // we are considering the right most element
    // of the unsorted array as pivot
    int pivot = arr[high];

    // element index for comparison
    int i = (low-1);

    // iterating from leftmost Element(low) of unsorted array
    // to an Element before the pivot (high-1)
    for (int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Placing pivot at it correct position
    swap(&arr[i+1], &arr[high]);
    
    // returning index for next pivot
    return i+1;
}

// quicksort funciton works recurssively using divide and conquer algo
// to partition and sort the array around the pivot.
// This Algo takes O(nLog(n))
void quicksort(int arr[], int low, int high){
    if (low < high)
    {
        // sorting it with respect to pivot(elem at high(th) index)
        int pi = partition(arr, low, high);

        // sorting the left part from pivot
        quicksort(arr, low, pi-1);

        // sorting the right part from pivot
        quicksort(arr, pi+1, high);
    }
    
}

// printArray displays the Array elements spaced in one line
// arr[] -> array to be printed
// n -> size of the array
void printArray(int arr[], int n)
{
	for(int i = 0; i < n; i++)	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}