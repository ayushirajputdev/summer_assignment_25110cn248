#include <stdio.h>
#include <string.h>
int check_anagram(char str1[], char str2[]) {
    int count[256] = {0};
    int i = 0;

   
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    
    for (i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

   
    for (i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    char str1[100], str2[100];

   
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    
   
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

   
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    
    if (check_anagram(str1, str2)) {
        printf("The strings are anagrams of each other.\n");
    } else {
        printf("The strings are NOT anagrams of each other.\n");
    }

    return 0;
}
