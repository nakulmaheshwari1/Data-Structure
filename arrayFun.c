#include <stdio.h>
#define MAX 100
// MERGE SORT----->
int merge(int a[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int temp[MAX];
    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= h)
    {
        temp[k++] = a[j++];
    }
    for (i = l; i <= h; i++)
    {
        a[i] = temp[i];
    }
}

int mergesort(int a[], int l, int h)
{
    int mid = l + (h - l) / 2;
    if (l < h)
    {
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

// BINARY SEARCH----->
int binarysearch(int a[], int n, int target)
{

    int st = 0, end = n - 1;
    int mid = (st + end) / 2;

    while (st <= end)
    {

        if (target > a[mid])
        {
            st = mid + 1;
        }
        else if (target < a[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

// INSERTION----->
int insertion(int a[], int n, int m, int key)
{
    int i;
    for (i = n; i > m; i--)
    {
        a[i] = a[i - 1];
    }
    a[m] = key;
    for (i = 0; i <= n; i++)
    {
        printf("|%d|", a[i]);
    }
}

// DELETION
int deletion(int a[], int n, int m)
{
    int i;
    for (i = m; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    for (i = 0; i < n - 1; i++)
    {
        printf("|%d|", a[i]);
    }
}

// SORTING ELEMENTS AT EVEN/ODD POSITIONS(ODD/EVEN INDICES)
int sort_even_odd(int a[], int n, char ch)
{
    if (ch == 'E')
    {
        int i, j;
        int B[MAX];
        for (i = 1, j = 0; i < n; i += 2, j++)
        {
            B[j] = a[i];
        }
        mergesort(B, 0, j - 1);
        for (i = 1, j = 0; i < n; i += 2, j++)
        {
            a[i] = B[j];
        }
        printf("Array with sorted even index :");
        for (i = 0; i < n; i++)
        {
            printf("|%d|", a[i]);
        }
    }
    else if (ch == 'O')
    {
        int i, j;
        int B[MAX];
        for (i = 0, j = 0; i < n; i += 2, j++)
        {
            B[j] = a[i];
        }
        mergesort(B, 0, j - 1);
        for (i = 0, j = 0; i < n; i += 2, j++)
        {
            a[i] = B[j];
        }
        printf("Array with sorted even index :");
        for (i = 0; i < n; i++)
        {
            printf("|%d|", a[i]);
        }
    }
}

// SORTING ELEMENT WHICH ARE EVEN / ODD
int soe(int a[], int n, char ch)
{
    int i = 0, j = 0, k = 0, B[MAX], C[MAX];
    if (ch == 'E')
    {
        for (i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                B[j++] = i;
                C[k++] = a[i];
            }
        }
    }
    else if (ch == 'O')
    {
        for (i = 0; i < n; i++)
        {
            if (a[i] % 2 != 0)
            {
                B[j++] = i;
                C[k++] = a[i];
            }
        }
    }
    mergesort(C, 0, j);
    for (k = 0; k < j; k++)
    {
        a[B[k]] = C[k];
    }
    for (i = 0; i < n; i++)
    {
        printf("|%d|", a[i]);
    }
}

int main()
{
    int i, a[MAX], n;
    printf("Enter the size of array:");
    scanf("%d", &n);
    printf("Enter the element of array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int target, key, m;
    char status;
    char ch;
    printf("\nChoose the operation to perform:\n");
    printf("Merge Sort - Enter 'm'\n");
    printf("Binary Search - Enter 'b'\n");
    printf("Insertion - Enter 'I'\n");
    printf("Deletion - Enter 'D'\n");
    printf("Sorting elements at even / odd position - Enter S\n");
    printf("Sorting element which are even / odd - Enter s\n");
    scanf(" %c", &ch);
    if (ch == 'm')
    {
        mergesort(a, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            printf("|%d|", a[i]);
        }
    }
    else if (ch == 'b')
    {
        printf("Enter the target element:");
        scanf("%d", &target);
        printf("Is the enter array sorted(enter Y for yes and N for no):");
        scanf(" %c", &status);
        if (status == 'Y')
        {
            binarysearch(a, n, target);
        }
        else if (status == 'N')
        {
            mergesort(a, 0, n - 1);
            int index = binarysearch(a, n, target);
            if (index != -1)
            {
                printf("target element is at index %d\n", index);
            }
            else
            {
                printf("Element not found\n");
            }
        }
    }
    else if (ch == 'I')
    {
        printf("Enter the key element you want to enter in the array:");
        scanf("%d", &key);
        printf("Eneter the index at which you want to insert the key:");
        scanf("%d", &m);
        insertion(a, n, m, key);
        n++;
    }
    else if (ch == 'D')
    {
        printf("Enter the index of the element you want to delete:");
        scanf("%d", &m);
        deletion(a, n, m);
    }
    else if (ch == 'S')
    {
        char id;
        printf("Enter which position elements you want to sort:\n");
        printf("For even position - Enter  E\n:");
        printf("For odd position - Enter O\n:");
        scanf(" %c", &id);
        sort_even_odd(a, n, id);
    }
    else if (ch == 's')
    {
        printf("Enter which elements you want to sort\n");
        printf("For even elements - Enter E\n");
        printf("For odd elements - Enter O\n");
        scanf(" %c", &status);
        soe(a, n, status);
    }

    return 0;
}