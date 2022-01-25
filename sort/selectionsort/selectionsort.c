// Selection sort implemented in C
// Author: Denil Bhatt

#include <stdio.h>

void selectionsort(int [], int);
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
	selectionsort(arr, size);

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


// Selectionsort works by finding the smallest value in the array
// and then swapping it with the i(th) element of iteration
void selectionsort(int arr[], int n){

    // iterating over the unsorted array
    for (int i = 0; i < n; i++)
    {
        // finding the index of smallest value
        // min_i starts at i coz after swaping first i elements already sorted
        int min_i = i; 

        for(int j = i+1; j < n; j++){
            
            // If adjacent j(th) element is smaller then current smallest
            if(arr[j] < arr[min_i]){
                // updating index of smallest value
                min_i = j; 
            }
            
        }

        // swapping the smallest val with i(th) element
        swap(&arr[i], &arr[min_i]);
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