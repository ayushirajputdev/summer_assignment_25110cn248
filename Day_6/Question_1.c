#include <stdio.h>
int main(){
    int n,i,sum=0,num=0;
    printf("Enter the decimal number to convert them into binary");
    scanf("%d",&n);
    while(n>0){
        num=n%2;
        sum=sum*10+num;
        n=n/2;

    }
    printf("THE BINARY EQUIVALENT OF THE GIVEN NUMBER IS %d",sum);
    return 0;
}