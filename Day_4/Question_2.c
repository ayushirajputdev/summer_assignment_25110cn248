#include <stdio.h>
int main(){
    int n,i=0,a=0,b=0,next=0;
    printf("Enter the nth terms needed in the fibonacci series");
    scanf("%d",&n);
    printf("THIS IS THE FIBONACCI SERIES Nth TERM\n");
    for(i=0;i<n;i++){
        if(i==0){
            a=i;
            
        }
        else if(i==1){
            b=i;
            next =b;

        }
        else{
            next=b+a;
            a=b;
            b=next;
}
            

        
    
    }printf("%d",next);
    return 0;
}