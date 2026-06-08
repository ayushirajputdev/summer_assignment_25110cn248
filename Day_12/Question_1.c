#include <stdio.h>
int palindrome(int n){
    int num,sum=0,s;
    int num1=n;
    while(n!=0){
        num=n%10;
        sum=sum*10+num;
        n=n/10;
        

    }
    if(sum==num1){
         s=1;
    }
    else{
        s=0;
}
    return s;

}
int main(){
    int num;
    printf("ENTER THE NUMBER TO CHECK WHETHER IT IS A PALINDROME OR NOT");
    scanf("%d",&num);
    int s;
    s=palindrome(num);
    if(s==1){
        printf("THE ENTERED NUMBER IS A PALINDROME");

    }
    else if(s==0){
        printf("THE ENTERED NUMBER IS NOT A PALINDROME");

    }
    return 0;
}