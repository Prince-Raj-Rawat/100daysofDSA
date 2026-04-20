#include <stdio.h>
#include <stdlib.h>

int index_find(int *vertice, int a,int ver){
    for(int i= 0; i<a;i++){
        if(vertice[i]== ver) return i;
    }
    printf("the value vertice doesnt exist");
    return -1;
}

int main(){
    int v,e;
    printf("enter the no of vertices: ");
    scanf("%d",&v);
    printf("enter the no. of edges: ");
    scanf("%d",&e);
    int *vert=(int * )malloc(sizeof(int)*v);
    for(int i= 0; i< v; i++){
        printf("enter the %d vertice: ",i+1);
        scanf("%d",&vert[i]);
    }
    int **edge=(int **)calloc(v,sizeof(int *));
    for(int i = 0; i< v;i++){
        edge[i]=(int *)calloc(v,sizeof(int));
    }
    int v1,v2,weight;
    for(int i = 0;i<e;i++){
        here:
        printf("enter the vertice label: ");
        scanf("%d",&v1);
        v1=index_find(vert,v,v1);
        printf("enter the other vertice label: ");
        scanf("%d",&v2);
        v2=index_find(vert,v,v2);
        if(v2 == -1 || v1 == -1){
            printf("invalid vertice input try again...");
            goto here;
        }
        printf("enter the weight of the edge: ");
        scanf("%d",&edge[v1][v2]);
        edge[v2][v1]=edge[v1][v2];
    }
    int *degree = (int*)malloc(sizeof(int)*v);
    for(int i = 0; i<v ; i++){
        int d=0;
        for(int j = 0 ; j< v;j++){
            if(edge[i][j]> 0) d++;
        }
        degree[i]=d;
    }
    printf("\nEdges in the graph:\n");
    for (int i = 0; i < v; i++) {
        for (int j = i+1; j < v; j++) {
            if (edge[i][j] > 0) {
                printf("(%d -- %d) weight = %d\n", vert[i], vert[j], edge[i][j]);
            }
        }
    }
    printf("\n");
    for (int i = 0; i <v; i++){
        printf("the degree of %d is : %d\n",vert[i],degree[i]);
    }
    free(vert);
    free(degree);
    for (int i = 0; i<v; i++){
        free(edge[i]);
    }  
    free(edge);
    return 0;
}