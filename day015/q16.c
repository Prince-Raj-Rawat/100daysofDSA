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

    int min = m<n ? m:n;
    int dsum = 0;
    for (int i =0 ; i<min;i++){
        dsum += a[i][i];
    }

    printf("%d ",dsum);

    for(int i = 0; i<n;i++){
        free(a[i]);
    }
    free(a);
    return 0;
}