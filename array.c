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
    printf("\n");
    // insertion at start (index==0)
    for(i=n-1;i>=0;i--){
        a[i+1]=a[i];
    }
    printf("enter the element for insertion at start:");
    scanf("%d",&a[0]);
    
    //display the array
    for(i=0;i<n+1;i++){
        printf("|%d|",a[i]);
    }
    printf("\n");
    // insertion at last
    printf("Enter the element to insert at last:");
    scanf("%d",&a[i]);
    //display the array
    for(i=0;i<=n+1;i++){
        printf("|%d|",a[i]);
    }
    printf("\n");
    // insertion at m-th index
    int m;
    printf("Enter index where you want to enter the element:");
    scanf("%d",&m);
    for(i=n+1;i>=m;i--){
        a[i+1]=a[i];
    }
    printf("Enter element to be enter at m-th index:");
    scanf("%d",&a[m]);
    for(i=0;i<n+3;i++){
        printf("|%d|",a[i]);
    }
    printf("\n");
    //deleting an element
    int d;
    printf("Enter the index of element want to delete:");
    scanf("%d",&d);
    for(i=d;i<n+3;i++){
        a[i]=a[i+1];
    }
    for(i=0;i<n+2;i++){
        printf("|%d|",a[i]);
    }
    printf("\n");
    //searching an element(linear search)
    int s,count=0;
    printf("Enter the element to be search:");
    scanf("%d",&s);
    for(i=0;i<n+2;i++){
        if(a[i]==s){
        count ++;
        }
    }
    if(count!=0){
        printf("%d appear %d times",s,count);
    }else{
        printf("Element not found");
    }
    printf("\n");
    // sorting
   

    return 0;
}