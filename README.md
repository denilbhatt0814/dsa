# Sorting Algorithms

## Bubble sort
The algorithm of bubble-sort  repeatedly compares two adjacent elements in each iteration and if the j(th) element is greater than the j+1(th) element then the two elements are swapped.
In this case the sorted array would be in ascending order.
* worst case : O(n2)
* best case : O(n)

```c
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
```
