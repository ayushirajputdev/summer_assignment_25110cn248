#include <stdio.h>
int sum_of_digits(int n ){
    if(n==0){
        return 0;

    }
    else{
        return (n%10)+sum_of_digits(n/10);
    }
}
int main(){
    int num;
    printf("ENTER THE NUMBER TO FIND THE SUM OF ITS DIGITS");
    scanf("%d",&num);
    printf("THE SUM OF DIGITS OF THE GIVEN NUMBER IS %d",sum_of_digits(num));
    return 0;
}