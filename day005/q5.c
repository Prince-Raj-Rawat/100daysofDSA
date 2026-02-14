/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/
#include <stdio.h>
int main(){
    int n, m;
    int arr1[100],arr2[100],seq[200];
    scanf("%d",&n);
    for(int i =0 ; i< n; i++)
        scanf("%d",&arr1[i]);
    scanf("%d",&m);
    for(int i =0; i<m; i++)
        scanf("%d",&arr2[i]);
    
    int i =0, j=0 , k=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            seq[k]= arr1[i];
            k++,i++;   
        }
        else{
            seq[k]=arr2[j];
            k++,j++;
        }
    }
    while (i<n || j<m){
        if (i<n){
            seq[k]=arr1[i];
            k++,i++;
        }
        else{
            seq[k]=arr2[j];
            k++,j++;
        }
    }
    for (int a =0; a<(m+n);a++){
        printf("%d ",seq[a]);
    }
    return 0;
}