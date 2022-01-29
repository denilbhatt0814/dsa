#include <stdio.h>

void printArray(int [], int);
void merge(int arr[], int l, int m, int r);
void mergesort(int [], int, int);

int main(){
    int arr[] = {27, 9, 81, 3, 12, 49 ,18};

    // to get length of array
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("The original array is: ");
    printArray(arr, size);

    mergesort(arr, 0, size-1);

    printf("The sorted array is: ");
	printArray(arr, size);

    return 0;
}

// merge function at first copies the data from arr[l...r] to temp
// sub-arrays after which each elements of both sub-arrays are compared
// and placed at right positon in main arr[l...r]
void merge(int arr[], int l, int mid, int r)
{   
    /* INDEXING COUNTERS OF SUB-ARRAY */
    int i, j;

    /* SIZE OF SUB-ARRAY */
    int n1 = mid - l + 1;
    int n2 = r - mid; // no +1

    /* CREATING TEMP ARRAYS */
    // L -> left array, R -> right array
    int L[n1], R[n2];

    /* COPYING DATA FROM arr TO SUB-ARRAYS L[] and R[] */
    for (i = 0; i < n1; i++) // in L[]
    {   
        // index of lowest element of req. subpart + counter
        L[i] = arr[l+i];
    }
    for(j = 0; j < n2; j++) // in R[]
    {   
        // (mid + 1)th index + counter
        R[j] = arr[mid + 1 + j];
    }
    
    /* MERGING THE TEMP ARRAYS BACK TO arr[l...r] */
    // setting counters for sub-arrays
    i = 0; // for L
    j = 0; // for R
    int k = l; // for merged sub-array

    while (i < n1 && j < n2)        
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++; // moving ahead in L[]
        }
        else // L[i] > R[j]
        {
            arr[k] = R[j];
            j++; // moving ahead in R[]
        }
        k++; // moving ahead in merged arr[]
    }

    /* COPYING THE LEFT-OUT ELEMENTS */
    // in L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++; k++; // moving ahead the counters
    }
    // in R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++; k++; // moving ahead the counters
    }   
}


// Mergesort function divides the array into smaller partitions 
// which are then sorted indiviually and merged together to get 
// a completly sorted array
void mergesort(int arr[], int l, int r)
{   
    // if more than 1 element in arr
    if(l < r)
    {   
        // the middle element of arr
        int mid = l + ((r-l)/2);

        // mergesort on left half
        mergesort(arr, l, mid);

        // mergesort on right half
        mergesort(arr, mid+1, r);

        // merging the two halves
        merge(arr, l, mid, r);
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