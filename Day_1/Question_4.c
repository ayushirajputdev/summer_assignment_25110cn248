#include <stdio.h>
int main(){
    int n,sum,i;
    printf("Enter the number to find its total digits");
    scanf("%d",&n);
    sum=0;
    while(n!=0){
        n=n/10;
        sum++;
    }
    printf("The total number of digits in the given number is %d",sum);
    return 0;
}