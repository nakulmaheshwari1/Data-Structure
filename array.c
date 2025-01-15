#include<stdio.h>
#define MAX 1000
int main()
{
    int n;
    //size input
    printf("Enter the size of array:");
    scanf("%d",&n);
    int i,a[MAX];
    // elements input and display
    printf("enter the elements of array:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        printf("|%d|",a[i]);
    }
    // insertion at start (index==0)
    for(i=n-1;i<=0;i--){
        a[i+1]=a[i];
    }
    printf("enter the element for insertion at start:");
    scanf("%d",&a[0]);
    
    //display the array
    for(i=0;i<n+1;i++){
        printf("|%d|",a[i]);
    }




    return 0;
}