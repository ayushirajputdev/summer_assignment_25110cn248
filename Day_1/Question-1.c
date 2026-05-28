#include <stdio.h>
int main(){
    int n ,sum,i;
    printf("Enter the value of n");
    scanf("%d",&n);
    sum=0;
    for(i=1;i<=n;i++){
        sum+=i;
    }
    printf("The sum of first n natural  numbers is %d",sum);
        return 0;

}