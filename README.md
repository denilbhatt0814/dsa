# Sorting Algorithms

## Bubble sort
The algorithm of bubble-sort  repeatedly compares two adjacent elements in each iteration and if the j(th) element is greater than the j+1(th) element then the two elements are swapped.\
In this case the sorted array would be in ascending order.
* worst case : O(n^2)
* best case : O(n)

```c
void bubblesort(int arr[], int n)
{    
    // (n-1) coz size is n but last index of array will be 1 less
    for(int i = 0; i < n-1; i++){

        // (n-1)-i bcoz we know last i elements already sorted
        for(int j = 0; j < n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
```

## Selection sort
The selection sort algorithm iterates over the unsorted array and in each i(th) iteration it searches for the minimum value between i(th) index and last index to swap with the i(th) element.\
The final result is an array in ascending order.

* worst case : O(n^2)
* best case :  O(n^2)

```c
void selectionsort(int arr[], int n)
{
    // iterating over the unsorted array
    for (int i = 0; i < n; i++)
    {
        // finding the index of smallest value
        // min_i starts at i coz after swaping, first i elements already sorted
        int min_i = i; 

        for(int j = i+1; j < n; j++)
        {    
            // If adjacent j(th) element is smaller then current smallest
            if(arr[j] < arr[min_i])
            {
                // updating index of smallest value
                min_i = j; 
            }

        }

        // swapping the smallest val with i(th) element
        swap(&arr[i], &arr[min_i]);
    }
}
```

## Insertion sort
The algorithm of insertion sort works by dividing the array in two parts sorted (rigth most part) and the unsorted (left most part). In each i(th) iteration an perfect place of the i(th) element is found by iterating over the sorted part and shifting the elements 1 position towards right untill it finds the perfect place in sorted portion, Upon which i(th) element is finally kept at its place.

* worst case : O(n^2)
* best case :  O(n)

```c
void insertionsort(int arr[], int n)
{
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
```

## Quick sort
The Quick sort works upon divide and conquer algorithm where a pivot( the last element in this case ) is picked and partition is done around that pivot by sorting in a way that elements smaller than pivot fall on the left of pivot while the elements greater would lie right of the pivot.\
While making partition we mostly start from the leftmost element and keep note of index of element smaller than i(th). In that search while traversing, we swap the current j(th) element with i(th) element, if j(th) element is smaller than the pivot. Atlast we place the pivot at its correct position by swapping it with i+1(th) element. (the function also return the index where the partition happened)\
Futher, since quicksort is a recursive function it goes on making partions and sorting until the low of a partition is `>=` high i.e. Single element is left in the partition.

* worst case : O(n^2)
* best case : O(n log(n))

```c
int partition(int arr[], int low, int high)
{
    // we are considering the right most element
    // of the unsorted array as pivot
    int pivot = arr[high];

    // element index for comparison
    int i = (low-1);

    // iterating from leftmost Element(low) of unsorted array
    // to an Element before the pivot (high-1)
    for (int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Placing pivot at it correct position
    swap(&arr[i+1], &arr[high]);
    
    // returning index for next pivot
    return i+1;
}

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
```