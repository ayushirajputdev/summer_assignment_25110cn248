#include <stdio.h>
int main(){
    int num1,num2,i;
    printf("Enter the two numbers to find their LCM");
    scanf("%d%d",&num1,&num2);
    for(i=1;i<num1*num2;i++){
        if(i%num1==0 && i%num2==0){
            printf("THE LEAST COMMON MULTIPLE OF THE GIVEN NUMBER Is %d", i);
            break;
        }
    }
    return 0;


}