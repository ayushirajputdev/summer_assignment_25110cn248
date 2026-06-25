#include <stdio.h>
int  main(){
    char string[100];
    int len=0;
    printf("ENTE THE STRING");
    fgets(string,sizeof(string),stdin);
    while(string[len]!=0){
        len++;
    }
    printf("THE LENGTH OF THE ENTERED STRING IS %d",len);
    return 0;
}