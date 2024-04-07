// C program to add two numbers
#include <stdio.h>
#include <stdlib.h>
struct call{
    int a, *b;
};

int nFac(int n){
    if(n == 1){
        return 1;
    }
    else{
        int res = n * nFac(n - 1);
        return res;
    } 
}

int nFib(int n){
    if(n <= 1)
        return n;
    else {
        int res=  nFib(n - 1) + nFib(n - 2); 
        return res;
    }
}

int main()
{
    int n;
    int c  = 10, d  = 15, *e = &d;
    
    struct call newcall;

    newcall.a = c;
    newcall.b = e;

    printf("The given two numbers are: %d, %d, and Address of second number is %p\n", c, d, e);

    printf("Enter the any numbers: "); // Prompt the user to enter the numbers
    scanf("%d", &n); // Read the two integers
    
    int factorial = nFac(n);
    printf("Factorial of a %d is = %d\n", n, factorial);

    printf("Fibonacci Series: ");
    for(int i = 0; i < n; i++){
        int x = nFib(i);
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}