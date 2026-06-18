#include <stdio.h>
int main(){
    //selection sort
    int array[100],i,j,index,num,c;
    printf("ENTER THE NUMBER OF TERMS OR THE ARRAY");
    scanf("%d",&num);
    if(num<=0){
        printf("INVALID NUMBER OF TERMS ENTERED");
        return  0;
    }
    else{
    printf("ENTER THE TERMS OF THE ARRAY");
    for(i=0;i<num;i++){
        scanf("%d",&array[i]);
    }
    for(i=0;i<num;i++){
        index=i;
        for(j=i;j<num;j++){
            if(array[index]>array[j]){
                //finding the minimun term
                index=j;
                
            }
            
        }
        //swapping after finding the minimum
        if(index!=i){
            c=array[i];
            array[i]=array[index];
            array[index]=c;
        }

    }
    printf("THE SORTED ARRAY IS \n");
    for(i=0;i<num;i++){
        printf("%d ",array[i]);
    }}
    return 0;

}