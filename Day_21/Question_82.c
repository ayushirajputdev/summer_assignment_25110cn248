#include <stdio.h>
#include <string.h>

int main() {
  char str[100],temp;
  int len,i;
  printf("ENTER THE STRING\n");
  scanf("%s",str);

  len=strlen(str);

  for(i=0;i<len/2;i++){
    temp=str[i];
    str[i]=str[len-i-1];
    str[len-1-i]=temp;


  }
  printf("THE REVERSED STRING IS %s\n",str);
  return 0;
}
