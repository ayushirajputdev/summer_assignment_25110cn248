#include <stdio.h>
int factorial(int num){
    
    if(num==1||num==0){
    return 1;}
    else{
    return num*factorial(num-1);
}

}
int main(){
    int num;
    printf("Enter the number to find its factorial");
    scanf("%d",&num);
    printf("THE FACTORIAL OF THE GIVEN NUMBER IS %d",factorial(num));
    return 0;
}
