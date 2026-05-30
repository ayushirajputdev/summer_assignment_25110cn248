#include <stdio.h>
int main(){
    int num,i;
    printf("Enter the number to check whether the given number is prime or not");
    scanf("%d",&num);
        if(num<=1){
        printf("THE ENTERED NUMBER IS NOT A PRIME NUMBER");}
        else{
            for(i=2;i<num;i++){
                if(num%i==0){
                    printf("THE ENTERED NUMBER IS NOT A PRIME NUMBER");
                    break;
                }
            }
            if(i==num){
                printf("THE ENTERED NUMBER IS A PRIME NUMBER");
            }
        }
        return 0;
        
        

}