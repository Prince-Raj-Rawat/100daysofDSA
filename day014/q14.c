#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m;
    
    printf("enter the rows and coloum for matrix 1 : ");
    scanf("%d %d",&n,&m);
    bool identity = true;

    if(m!=n) identity = false;
    else{
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

    
        for (int i = 0; i < n && identity ; i ++){
            for (int j = 0 ; j < m ; j++){
                if (i == j){
                    if(a[i][j]!=1) identity = false; 
                }
                else{
                    if (a[i][j]!= 0) identity = false;
                }
            }
        }
    

    
    for(int i = 0; i<n;i++){
        free(a[i]);
    }
    free(a);
    }
    printf("%s",identity ? "it is a identity matrix": "it is not a identity matrix");
    return 0;

}