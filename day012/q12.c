#include <stdio.h>
#include <stdlib.h>


int main(){
    int n,m;
    
    printf("enter the rows and coloum for matrix 1 : ");
    scanf("%d %d",&n,&m);
    bool issymmetric = true;
    if (m!=n) issymmetric = false;

    else{
    int **a = (int **)malloc(sizeof(int *)*n);
    for(int i =0; i< n; i++){
        a[i]=(int *)malloc(sizeof(int)*m);
    }


    printf("enter the elements in %d * %d matrix:",n,m);
    for (int i = 0; i<n;i++){
        for (int j = 0 ; j<m; j++){
            scanf("%d",&a[i][j]);
        }
        
    }
    
    
        for (int i = 0 ; i< n && issymmetric; i++){
            for (int j = 0; j <m; j++){
                if (a[i][j]!= a[j][i]) {
                    issymmetric = false;
                    break;
                }
            }
        }
    
    
    for(int i = 0; i<n;i++){
        free(a[i]);
    }
    free(a);
    }
    printf("%s", issymmetric ? "it is symmetric matrix": "it is not a symmetric matrix");

    return 0;
}