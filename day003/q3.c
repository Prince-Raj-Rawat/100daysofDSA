/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/

#include <stdio.h>
int main(){
    int arr[100],n,comparison=0;
    int found = -1;
    scanf("%d",&n);
    for (int i = 0; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    int search ;
    scanf("%d",&search);
    for (int i =0 ; i <n ; i++){
        comparison++;
        if (arr[i]==search){
            found = i;
            break;
        }
    }
    if (found == -1){
        printf("not found\n");
    }
    else{
        printf("found at position : %d\n", found);
    }
    printf("no. of comparisons: %d",comparison);
    return 0;
}