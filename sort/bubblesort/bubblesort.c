#include <stdio.h>

void bubblesort(int [], int);
void printArray(int [], int);
void swap(int *, int *);

int main(){
    // The array to be sorted
	int arr[] = {50,40,30,20,10};
	
    // to get length of array
	int size = sizeof(arr) / sizeof(arr[0]);

    printf("The original array is: ");
    printArray(arr, size);

    // Sorting here
	bubblesort(arr, size);

    printf("The sorted array is: ");
	printArray(arr, size);
}

// swap will interchange the values of the two inputed variables
// Input must be address(&) of the variables
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// bubblesort sorts the array in O(n^2): it compares adjacent elements
// on each iterations and then swaps them if the j(th) element is 
// greater then the j+1(th) element.
// The sorted array will be in ascending order.
void bubblesort(int arr[], int n){
    
    // (n-1) coz size is n but last index of array will be 1 less
    for(int i = 0; i < n-1; i++){

        // (n-1)-i bcoz we know last i elements already sorted
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
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