#include <stdio.h>
#include <stdlib.h>

void expression0 (int x, int *result);
/* calculation of the expression0 for the value of x*/ 
void expression1 (int x, int *result);
/* calculation of the expression1 for the value of x*/ 
void expression2 (int x, int *result);
/* calculation of the expression2 for the value of x*/ 
void addition (void (*func)(int, int *), int *sum, int n);
/* obtaining the calculations for a single expression and return the result */ 
void calculation (int *sumArray, int n);
/* Obtaining the summations and assinging them to sumArray respectively*/ 
void createArray(int (*array)[10]);

int main (){
/* Declaring array, reading “n”, obtaining the results by using functions, and printing them.
Nothing else.*/ 
    int n,sumArray[3] = {0},i;
    printf("\n\n********************");
    printf("\nExpression 0 = x^2 + 5\n");
    printf("Expression 1 = 2x + 1\n");
    printf("Expression 2 = x^2\n");
    printf("********************\n\n");

    printf("To sum of x = 0 to x = n\n");
    printf("n = ");
    scanf("%d",&n);
    calculation(sumArray ,n);
    for (i=0 ; i<3 ; i++){
        printf("Sum of expression%d: %d",i,sumArray[i]); 
        printf("\n");
    }
    printf("\n");

    int myArray[10][10];
    createArray(myArray);

    return 0;
}

void expression0 (int x, int *result){
/* calculation of the expression0 for the value of x*/ 
    *result = *result + x*x+5;
}
void expression1 (int x, int *result){
/* calculation of the expression1 for the value of x*/ 
    *result = *result + 2*x+1;
}
void expression2 (int x, int *result){
/* calculation of the expression2 for the value of x*/ 
    *result = *result + x*x;
}
void addition (void (*func)(int, int *), int *sum, int n){
/* obtaining the calculations for a single expression and return the result */ 
    int i;
    for(i=0 ; i<=n ; i++){
        func(i, sum);
    }    
}
void calculation (int *sumArray, int n){
/* Obtaining the summations and assinging them to sumArray respectively*/ 
    addition(expression0, &sumArray[0] , n);
    addition(expression1, &sumArray[1] , n);
    addition(expression2, &sumArray[2] , n);

}

void createArray(int (*array)[10]){
    int randomNumber, i, j, a=0, b=0, run = 1;
    printf("\nCreating an array...\n\n");
    for (i=0 ; i<10 ; i++){
        for (j=0 ; j<10 ; j++){
            randomNumber = rand () %90 + 10;
            array[i][j]=randomNumber;
            printf ("%d ", array[i][j]);
        }
        printf("\n");
    }
    while(run){                                                /*do not run if input is invalid.*/
        printf("\nWhich element of the matrix do you want to reach?\n");
        printf("i: ");
        scanf("%d", &a);
        printf("j: ");
        scanf("%d", &b);
        if (a>=0 && b>=0 && a < 10 && b < 10)
            printf("%d. row %d. column of the matrix is %d\n", a, b, array[a][b]);
        else { 
            printf("\nInvalid input. Terminating...\n");
            run = 0;
        }
    }    
}