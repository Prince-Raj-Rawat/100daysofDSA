#include <stdio.h>
#include <stdlib.h>

typedef struct EDGE{
    int starting;
    int ending;
    int weight;
}edge;

int ispresent(edge *e1,edge *e2){
    if ((e1->ending==e2->ending || e1->ending == e2->starting) && (e1->starting == e2->starting || e1->starting == e2->ending)) return 1;
    return 0;
}

int main(){
    int v,e;
    printf("enter the no of vertices: ");
    scanf("%d",&v);
    int *vert = (int *)malloc(sizeof(char)*v);
    printf("enter the no. of edges: ");
    scanf("%d",&e);
    edge *edges = (edge *)malloc(sizeof(edge)*e);
    for(int i=0 ; i< v; i++){
        printf("enter the %d vertice: ",i+1);
        scanf("%d",&vert[i]);
    }
    edge clone;
    for(int i =0; i< e; i++){
        here:
        printf("%d edge\n",i+1);
        printf("enter the starting vert: ");
        scanf("%d",&clone.starting);
        printf("enter the ending vert: ");
        scanf("%d",&clone.ending);
        printf("enter the weight : ");
        scanf("%d",&clone.weight);
        for(int j = 0; j<i;j++){
            if(ispresent(&clone,&edges[j])){ 
                printf("the edge is already present int he code");
                goto here;}
        }
        edges[i]=clone;
    }
    int *degree=(int*)calloc(v,sizeof(int));
    for(int i =0;i<v;i++){
        for(int j=0; j<e;j++){
            if(vert[i]==edges[j].starting || vert[i] == edges[j].ending){ 
                degree[i]++;
            }
        }
    }
    printf("the edges and the weight are : ");
    for (int i = 0; i<e; i++){
        printf("vertices: %d <-> %d weight: %d\n",edges[i].starting,edges[i].ending,edges[i].weight);
    }
    for(int i=0;i<v;i++){
        printf("vertice: %d degree: %d\n",vert[i],degree[i]);
    }
    free(edges);
    free(vert);
    free(degree);

    return 0;
}



    
