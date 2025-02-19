#include <stdio.h>
// sum function for calculating avg
int sum(int s, int e, int a[])
{
    int i, sum_n = 0;
    for (i = s; i <= e; i++)
    {
        sum_n += a[i];
    }
    return sum_n;
}

// simple moving avg
void simple_Moving_Avg(int a[],int n, int m ){
     int b[n - m + 1], j = 0, i;
    for (i = 0; i < n - 1; i++)
    {
        int avg = (sum(i, i + m -1, a)) / m;
        b[j++] = avg;
    }
    for (i = 0; i < j; i++)
    {
        printf("|%d|", b[i]);
    }
}

// exponential moving average
void Exp_Mov_avg(int arr[], int n, int m) {
    int B[n - m + 1];
    float EMA = arr[0]; 
    float a = 2.0 / (m + 1); 
    
    for (int i = 1; i < n; i++) {
        EMA = (arr[i] * a) + EMA * (1 - a);
        if (i >= m - 1) {
            B[i - m + 1] = EMA;
        }
    }
    for (int i = 0; i<n-m+1; i++) {
        printf("|%d| ", B[i]);
    }
    printf("\n");
}

int main()
{
    
    int n, m;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int i, a[n];
    printf("Enter the elements in array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the size of moving avg window:");
    scanf("%d", &m);
    simple_Moving_Avg(a,n,m);


    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
    printf("Enter the size of the window: ");
    scanf("%d", &m);
    Exp_Mov_avg(arr, n, m);

    return 0;
}