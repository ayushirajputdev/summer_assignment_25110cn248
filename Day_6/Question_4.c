#include <stdio.h>
int main(){
    int base,exp,result=1,i;
    printf("ENTER THE BASE ANF EXPONENT TO CALCULATE THE POWER");
    scanf("%d%d",&base,&exp);
    for(i=0;i<exp;i++){
        result=result*base;
    }
    printf("THE POWER OF THE GIVEN NUMBER IS%d",result);
    return 0;
    
}