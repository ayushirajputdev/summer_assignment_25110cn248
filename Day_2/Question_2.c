#include <stdio.h>
int main(){
    int rev,n,i;
    printf("enter the number to reverse it ");
    scanf("%d",&n);
    rev=0;
    while(n!=0){
        rev=rev*10+(n%10);
        n=n/10;
    }
    printf("THE REVERSED NUMBER IS %d",rev);
    return 0;
}