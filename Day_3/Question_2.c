#include <stdio.h>
int main(){
    int num1,num2,i,j;
    printf("enter the range of the numbers to list out the prime numbers in the range \n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    if(num1>num2){
        printf("INVALID RANGE");

    }
    else{
        printf("THE PRIME NUMBERS ARE \n");
        for(i=num1;i<=num2;i++){
            if(i<2)continue;
            for(j=2;j<i;j++){
                if(i%j==0){
                    break;
                }
            }
            if(j==i){
                printf("%d\n",i);

            }
            
            
        }

    }
    return 0;


}