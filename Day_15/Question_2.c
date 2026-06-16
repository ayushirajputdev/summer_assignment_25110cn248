#include <stdio.h>
int main(){
    int array[100],i,num,term1;
    printf("ENTER THE NUMBER OF TERMS IN THE ARRAY TO BE ENTERED ");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&array[i]);
    }//to rotate the array by left
    term1=array[0];
    

    for(i=0;i<num;i++){
       array[i]=array[i+1];
    }
    array[num-1]=term1;
    
    printf("THE ROTATED ARRAY IS \n");
    for(i=0;i<num;i++){
        printf("%d ",array[i]);

    }
    return 0;
}