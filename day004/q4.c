#include <stdio.h>
int main(){
	int n , arr[50],c,temp;
	scanf("%d",&n);
	for(int i =0 ; i <n; i++){
		scanf("%d",&arr[i]);
	}
	int *a= arr;
	int *b= &arr[n-1];
	if (n%2 == 0){
		c= n/2;
	}
	else{
		c=(n-1)/2;
	}

	for (int i = 0;i <c; i ++){
		temp=*(a+i);
		*(a+i)=*(b-i);
		*(b-i)=temp;
	}
	for (int i =0 ; i <n; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
