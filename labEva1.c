#include <stdio.h>
#include <stdlib.h>

// Ques. 1
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int arr[], int st, int mid, int end)
{
    int i = st, j = mid + 1, k = 0;
    int size = end - st + 1;
    int *temp = (int *)malloc(size * sizeof(int));
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    k = 0;
    for (i = st; i <= end; i++)
    {
        arr[i] = temp[k++];
    }
    free(temp);
}

void mergesort(int arr[], int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}
int partition(int arr[], int st, int end)
{
    int pivot = arr[end];
    int i = st - 1, j;
    for (j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[end], &arr[i]);
    return i;
}
void quicksort(int arr[], int st, int end)
{
    if (st < end)
    {
        int pivIdx = partition(arr, st, end);
        quicksort(arr, st, pivIdx - 1);
        quicksort(arr, pivIdx + 1, end);
    }
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d|", arr[i]);
    }
}

int main()
{
    // Ques 1
    int n;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int arr[n];
    int i;
    printf("Enter the elements of array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the type of sorting you want to do:");
    printf("1 for Mergesort\n2 for quicksort");
    int task;
    scanf("%d", &task);
    if (task == 1)
    {
        mergesort(arr, 0, n - 1);
        printarr(arr, n);
    }
    else if (task == 2)
    {
        quicksort(arr, 0, n - 1);
        printarr(arr, n);
    }

    // Ques 2
    int a, b;
    printf("Enter the indices of sub-array you want to reverse:");
    scanf("%d %d", &a, &b);
    int size = b - a + 1;
    int temp[size];
    int k = 0;
    for (i = a; i <= b; i++)
    {
        temp[k++] = arr[i];
    }
    // reversing
    k = 0;
    for(i = b, i>=a; i--){
        arr[i] = temp[k++];
    }
    for(i = 0;i < n; i++){
        printf("%d", arr[i]);
    }
    
    //Ques 3
    
    return 0;
}