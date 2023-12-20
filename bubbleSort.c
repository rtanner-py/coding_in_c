/*
does a bubble sort by swapping numbers in the memory locations:
Number: 64 Pointer: 0x7ffcf2667c40
Number: 34 Pointer: 0x7ffcf2667c44
Number: 25 Pointer: 0x7ffcf2667c48
Number: 12 Pointer: 0x7ffcf2667c4c
Number: 22 Pointer: 0x7ffcf2667c50
Number: 11 Pointer: 0x7ffcf2667c54
Number: 90 Pointer: 0x7ffcf2667c58

Sorted array:
Number: 11 Pointer: 0x7ffcf2667c40
Number: 12 Pointer: 0x7ffcf2667c44
Number: 22 Pointer: 0x7ffcf2667c48
Number: 25 Pointer: 0x7ffcf2667c4c
Number: 34 Pointer: 0x7ffcf2667c50
Number: 64 Pointer: 0x7ffcf2667c54
Number: 90 Pointer: 0x7ffcf2667c58
*/


#include <stdbool.h>
#include <stdio.h>

void swap (int *xp, int *yp) //*xp and *yp pass the memory locations for xp and yp;
{
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;

    for (i=0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]); // &arr[j] refers to the memory element where j is stored;
                swapped = true;
            }
        }

        if (swapped == false){
            break;
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++){
        printf("Number: %d Pointer: %p\n", arr[i], &arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64,34,25,12,22,11,90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr,n);
    bubbleSort(arr,n);
    printf("Sorted array: \n");
    printArray(arr,n);
    return 0;
}
