#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char str[100];
    int len,i,vowels=0,consonants=0;
    printf("ENTER THE STRING");
    scanf("%c",str);
     fgets(str, sizeof(str), stdin);


    len=strlen(str);
    for(i=0;str[i]!=0;i++){
        char ch=tolower(str[i]);
        if(ch>='a'&&ch<='z'){
        if(ch=='i'||ch=='a'||ch=='e'||ch=='i'||ch=='o'){
            vowels++;
        }
        else{
            consonants++;
        }
    }
        
    }
    printf("THE VOWELS AND CONSONANTS ARE %d and %d",vowels,len-vowels);
    return 0;
}