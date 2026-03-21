#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m;
    
    printf("enter the rows and coloum for matrix 1 & matrix 2: ");
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

    int **b = (int **)malloc(sizeof(int *)*n);
    for(int i =0; i< n; i++){
        b[i]=(int *)malloc(sizeof(int)*m);
    }

    printf("enter the elements in %d * %d matrix:\n",n,m);
    for (int i = 0; i<n;i++){
        for (int j = 0 ; j<m; j++){
            scanf("%d",&b[i][j]);
        }
        
    }

    int c[20][20];
    for(int i =0; i<n;i++){
        for(int j =0; j<m ; j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0; j<m;j++){
        printf("%d ",c[i][j]);}
        printf("\n");
    }


    for(int i = 0; i<n;i++){
        free(a[i]);
    }
    free(a);
    for(int i = 0; i<n;i++){
        free(b[i]);
    }
    free(b);
}