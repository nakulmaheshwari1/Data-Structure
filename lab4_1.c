#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the value:");
        scanf("%d",&arr[i]);
    }
    int L,U;
    printf("enter the lower index: ");
    scanf("%d",&L);
    printf("enter the upper index: ");
    scanf("%d",&U);
    if(L<0 && L>n || U>=n){
        printf("Invalid index");
    }
    else{
        int temp;
        for(int j=0;j<U+1;j++){
            for(int i=L;i<=U;i++){
                temp=arr[i];
                if(arr[i]>arr[i+1]){
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
            }
    }
}}
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
