#include <stdio.h>
int main(){
    int array2[100],i;
     int size1;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size1) != 1 || size1 <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr1[size1];
    printf("Enter %d elements:\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
     int size2;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size2) != 1 || size2 <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr2[size2];
    printf("Enter %d elements:\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }
    int count=0;
    for(i=0;i<size1+size2;i++){
        if(i<size1){
            array2[i]=arr1[i];
        }
        else{
            array2[i]=arr2[count];
            count++;
        }
    }
    for(i=0;i<size1+size2;i++){
        printf("%d ",array2[i]);
    }
    return 0;
}