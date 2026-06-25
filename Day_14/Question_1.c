#include <stdio.h>
int main(){
    int array[100],i,term,n,num=0,j=0,pos[100];
    printf("ENTER THE NUMBER OF TERMS TO ENTER THE ARRAY");
    scanf("%d",&n);
    
    if(n<=0){
        printf("INVALID NUMBER OF TERMS ENTERED");
        return  0;
    }
    else{
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    
    }
    printf("ENTER THE TERM TO BE SEARCHED IN THE ARRAY");
    scanf("%d",&term);
    for(i=0;i<n;i++){
        if(array[i]==term){
            num++;
            pos[j]=i;
            j++;
            
        }
    }
    if(num>0){
        printf("THE TERM IS FOUND IN THE ARRAY AT POSITION ");
        for(i=0;i<num;i++){
            printf("%d ",pos[i]);
        }

    }
    else{
        printf("THE TERM IS NOT FOUND IN THE ARRAY");

    }}
    return 0;
}