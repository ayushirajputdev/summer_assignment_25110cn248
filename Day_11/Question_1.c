#include <stdio.h>
int sum(int a,int b){
    return a+b;
}
int main(){
    int num1,num2;
    printf("Enter two number to find the sum ");
    scanf("%d%d",&num1,&num2);
    printf("THE SUM OF %d AND %d IS %d ", num1,num2,sum(num1,num2));
    return 0;
    

}