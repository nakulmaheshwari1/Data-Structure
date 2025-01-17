#include <stdio.h>
void mergesort(int a[], int st, int mid, int end)
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
int divide(int a[], int st, int end)
{
    int mid = st + (end - st) / 2;
    if (st < end)
    {
        divide(a, st, mid);
        divide(a, mid + 1, end);
        mergesort(a, st, mid, end);
    }
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
    divide(a, 0, 9);
    for (i = 0; i < 10; i++)
    {
        printf("|%d|", a[i]);
    }
    return 0;
}