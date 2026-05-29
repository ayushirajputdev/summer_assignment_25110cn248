#include <stdio.h>
int main(){
    int n,i,sum=0;
    printf("Enter the number to find the sum of its digits");
    scanf("%d",&n);
    i=n;
    while(i!=0){
        sum=sum+(i%10);
        i=i/10;

    }
    printf("THE SUM OF THE DIGITS IS %d",sum);
    return 0;

}
