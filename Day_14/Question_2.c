#include <stdio.h>
int main(){
    int array[100],i,term,n,num=0;
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
    printf("ENTER THE TERM TO FIND ITS FREQUENCY IN THE ARRAY");
    scanf("%d",&term);
    for(i=0;i<n;i++){
        if(array[i]==term){
            num++;
        }}
if(num>0){
    printf("THE NUMBER IS FOUND WITH FREQUENCY %d",num);
}
else{
    printf("THE NUMBER IS NOT FOUND IN THE ENTERED ARRAY");

}}
return 0;
}