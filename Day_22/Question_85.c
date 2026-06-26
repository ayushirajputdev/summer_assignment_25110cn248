#include <stdio.h>
#include <string.h>

int main() {
  char str[100],str2[100],temp;
  int len,i;
  printf("ENTER THE STRING\n");
  scanf("%s",str);
 strcpy(str2,str);
  

  len=strlen(str);

  for(i=0;i<len/2;i++){

    temp=str[i];
    str[i]=str[len-i-1];
    str[len-1-i]=temp;


  }
 if(strcmp(str2,str)==0){//comparing for equality
    printf("THE ENTERED STRING IS A PALINDROME");
 }
 else{
    printf("not a palindrome");
 }
  
  return 0;
}
