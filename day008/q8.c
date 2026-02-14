/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/
#include <stdio.h>
int power(int num, int pow);
int main(){
    int a , b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    c=power(a, b);
    printf("%d",c);
    return 0;
}
int power(int num, int pow){
    if (pow == 0 ) return 1;
    
    return num*power(num,pow-1);
    
}