#include <stdio.h>
int main(){
    // to reverse an array 
    int array[100],i,num;
    printf("ENTER THE NUMBER OF TERMS IN THE ARRAY TO BE ENTERED ");

    if(num<=0){
        printf("INVALID NUMBER OF TERMS ENTERED");
        return  0;
    }
    else{
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&array[i]);
    }
    //to reverse it 
    printf("THE REVERSED ARRAY IS \n");
    for(i=num-1;i>=0;i--){
        printf("%d ",array[i]);
    }}
    return 0;

}