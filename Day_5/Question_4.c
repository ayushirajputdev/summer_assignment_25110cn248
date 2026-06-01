#include <stdio.h>
int main(){
    int n,i,j,maxPrime=-1,isPrime=0;
    printf("Enter the number to find its largest prime factor ");
    scanf("%d",&n);
    for (i = 2; i <= n; i++) {
        
        if (n % i == 0) {
             isPrime = 1; 
            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    isPrime = 0; 
                    break;
                }
            }

            
            if (isPrime == 1) {
                maxPrime = i;
            }
        }
    }

    if (maxPrime != -1)
        printf("THE LARGEST PRIME FACTOR IS %d", maxPrime);
    else
        printf("No prime factors found.");
    
    return 0;

}