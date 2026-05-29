#include <stdio.h>
int main(){
    int rev,n,i,number;
    printf("enter the number to reverse it ");
    scanf("%d",&n);
    rev=0;
    number=n;
    while(n!=0){
        rev=rev*10+(n%10);
        n=n/10;
    }
    if(rev==number){
        printf("THE ENTERED NUMBER IS A PALINDROME");
    }
    else{
        printf("THE ENTERED NUMBER IS NOT A PALINDROME");
    }
    return 0;
}