#include <stdio.h>
int main(){
    int n,prod,i;
    printf("enter the  number to find the products of its digits");
    scanf("%d",&n);
    prod=1;
    while(n!=0){
    prod=prod*(n%10);
    n=n/10;
    }
    printf("THE PRODUCT OF THE DIGITS OF ENTERED NUMBER IS %d",prod);
    return 0;
}