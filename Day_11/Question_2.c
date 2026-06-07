#include <stdio.h>
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    int num1,num2;
    printf(" ENTER THE TWO NUMBERS TO FIND THE MAXIMUM");
    scanf("%d%d",&num1,&num2);
    printf("THE MAXIMUM OF %d AND %d IS %d ",num1,num2,max(num1,num2));
    return 0;

}
