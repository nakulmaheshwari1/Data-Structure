#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}
void binarysort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void selectionsort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int smallIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[smallIdx])
            {
                smallIdx = j;
            }
        }
        swap(&a[i], &a[smallIdx]);
    }
}

void merge(int a[], int st, int mid, int end)
{
    int temp[100];
    int i = st, j = mid + 1, k = st;
    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (i = st; i <= end; i++)
    {
        a[i] = temp[i];
    }
}
int mergesort(int a[], int st, int end)
{
    int mid = st + (end - st) / 2;
    if (st < end)
    {
        mergesort(a, st, mid);
        mergesort(a, mid + 1, end);
        merge(a, st, mid, end);
    }
}
int binarySearch(int a[], int l, int h, int target)
{
    int mid = l + (h - l) / 2;
    while (l <= h)
    {
        if (target < a[mid])
        {
            h = mid - 1;
        }
        else if (target > a[mid])
        {
            l = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int a[10];
    int i;
    printf("Enter the element:");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, 9);
    for (i = 0; i < 10; i++)
    {
        printf("|%d|", a[i]);
    }

    // Binary Search
    int target;
    printf("Enter the target element for search:");
    scanf("%d", &target);
    int bS = binarySearch(a, 0, 9, target);
    if (bS == -1)
    {
        printf("target element is not in the given array");
    }
    else
    {
        printf("%d", bS);
    }
    return 0;
}