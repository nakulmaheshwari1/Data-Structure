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


// exponnential moving array
void exponential_moving_array(){
       
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

    return 0;
}