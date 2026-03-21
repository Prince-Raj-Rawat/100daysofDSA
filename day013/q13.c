#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m;
    
    printf("enter the rows and coloum for matrix 1 : ");
    scanf("%d %d",&n,&m);
    int **a = (int **)malloc(sizeof(int *)*n);
    for(int i =0; i< n; i++){
        a[i]=(int *)malloc(sizeof(int)*m);
    }


    printf("enter the elements in %d * %d matrix:\n",n,m);
    for (int i = 0; i<n;i++){
        for (int j = 0 ; j<m; j++){
            scanf("%d",&a[i][j]);
        }
    }
    int top = 0 , bottom = n-1 , left = 0 , right = m-1;

    while(top <= bottom && left <= right){
        for(int i =left; i<= right; i++){
            printf("%d ",a[top][i]);
        }
        top ++;
        for(int i = top; i <= bottom ; i++){
            printf("%d ",a[i][right]);
        }
        right--;
        if (top <= bottom){
            for(int i = right; i>=left;i--){
                printf("%d ",a[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i = bottom; i >= top;i--){
                printf("%d ",a[i][left]);
            }
            left++;
        }
    }


    for(int i = 0; i<n;i++){
        free(a[i]);
    }
    free(a); 
    return 0;
    }  