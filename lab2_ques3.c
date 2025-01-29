#include <stdio.h>

int arr_med(int a[]){
    for(int i=0; i<9;i++){
        for(int j=0; j<9-i-1; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return a[4];
}

int main(){
    int n;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the elements of matrix: \n");

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    int median[(n-2)*(n-2)],ind=0;

    for(int i=0;i<n-2;i++){
        int k=0;
        while(k<n-2){
            int array[9],index=0;
            for(int j=i;j<=i+2;j++){
                for(int r=k;r<=k+2;r++){
                    array[index] = a[j][r];
                    index++;
                }
            }
            k++;
            median[ind] = arr_med(array);
            ind++;
        }
    }

    int ind_med=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                a[i][j] = 0;
            }
            else{
                a[i][j] = median[ind_med];
                ind_med++;
            }
        }
    }

    printf("The final matrix is : \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}