#include <stdio.h>

void printArray(int [], int);
void insertionsort(int [], int );

int main(){
    int arr[] = {88,44,66,22,100};
    // Getting the length of array
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Original array is: ");
    printArray(arr, size);

    insertionsort(arr, size);

    printf("Sorted array is: ");
    printArray(arr, size);
    return 0;
}

// insertionsort 
void insertionsort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {   
        // first Element of unsorted part
        int currentElem = arr[i];

        // index of Element in sorted part
        int indexInSorted = i-1;
        
        // shifts the array 1 element right unitl perfect position for currentElem
        while (indexInSorted >= 0 && arr[indexInSorted] > currentElem)
        {    
            arr[indexInSorted + 1] = arr[indexInSorted];
            indexInSorted--;
        }

        // placing the currentElem at it correct position
        arr[indexInSorted + 1] = currentElem;
    }   
}


// printArray displays the Array elements spaced in one line
// arr[] -> array to be printed
// n -> size of the array
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}