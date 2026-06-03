#include <stdio.h>
int rev_of_digits(int n,int rev) {

    if(n==0){
        return rev;
    }
    rev=(rev*10)+(n%10);
    return rev_of_digits(n/10,rev);
    
}
int main(){
    int num;
    printf("ENTER THE NUMBER TO FIND THE REVERSE OF ITS DIGITS");
    scanf("%d",&num);
    printf("THE REVERSE OF THE GIVEN NUMBER IS %d",rev_of_digits(num,0));
    return 0;
}