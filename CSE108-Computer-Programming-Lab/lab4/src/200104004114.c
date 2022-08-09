#include <stdio.h>
void russian_multiplication (unsigned int* multiplicand, unsigned int* multiplier);
void multiply_polynomials(double *a3, double *a2, double *a1, double *a0, double *b3, double *b2, double *b1, double b0);

    int main()
{
    int i,multiplicand, multiplier;
    double a3,a2,a1,a0,b3,b2,b1,b0;
    printf("\nEnter the value for multiplicand: ");
    scanf ("%u",&multiplicand);
    printf("\nEnter the value for multiplier: ");
    scanf ("%u",&multiplier);
    printf ("%u * %u =",multiplicand, multiplier);
    russian_multiplication (&multiplicand, &multiplier);
    printf ("= %u",multiplicand);
    printf("\nMultiplier = %u\n",multiplier);
    
    
    
    printf("\nEnter 4 values for the first polynomial\n");
    printf("(Correct format => #2 3 5 4#): ");
    scanf ("%lf %lf %lf %lf",&a3 , &a2 , &a1 , &a0);
    printf("\nEnter 4 values for the second polynomial\n");
    printf("(Correct format => #2 3 5 4#): ");
    scanf ("%lf %lf %lf %lf",&b3 , &b2 , &b1 , &b0);
    multiply_polynomials(&a3, &a2, &a1 ,&a0, &b3, &b2, &b1, b0);
    printf("\n");

    /*printing format*/
    if(a3 == 0)
        1;
    else if (a3 == 1)
        printf ("x^6 ");
    else if (a3 == -1)
        printf ("-x^6 ");
    else
        printf("%.1fx^6 ", a3);
    
    if( a2 == 0)
        1;
    else if (a2 == 1)
        printf("+x^5 ");
    else if (a2 == -1)
        printf ("-x^5 ");
    else
        printf("%+.1fx^5 ", a2);
    
    if( a1 == 0)
        1;
    else if (a1 == 1)
        printf("+x^4 ");
    else if (a1 == -1)
        printf ("-x^4 ");
    else
        printf("%+.1fx^4 ", a1);

    if( a0 == 0)
        1;
    else if (a0 == 1)
        printf("+x^3 ");
    else if (a0 == -1)
        printf ("-x^3 ");
    else
        printf("%+.1fx^3 ", a0);
    
    if( b3 == 0)
        1;
    else if (b3 == 1)
        printf("+x^2 ");
    else if (b3 == -1)
        printf ("-x^2 ");
    else
        printf("%+.1fx^2 ", b3);

    if( b2 == 0)
        1;
    else if (b2 == 1)
        printf("+x ");
    else if (b2 == -1)
        printf ("-x ");
    else
        printf("%+.1fx ", b2);

    if( b1 == 0)
        1;
    else
        printf("%+.1f ", b1);       

    printf ("\n");     
    return 0;
}

void russian_multiplication (unsigned int* multiplicand, unsigned int* multiplier){
    int result = 0;
    while(*multiplier > 1){
        if (*multiplier % 2 == 1 ){
            result = result + *multiplicand;
            printf("%u + ",*multiplicand);
        } 
        *multiplier = *multiplier / 2;
        *multiplicand = *multiplicand * 2;
    }
    printf("%u",*multiplicand);
    if (*multiplier == 1)
        result = result + *multiplicand;    
    *multiplicand = result;
}

void multiply_polynomials(double *a3, double *a2, double *a1, double *a0, double *b3, double *b2, double *b1, double b0)
{
    double tempa3, tempa2, tempa1, tempa0, tempb3, tempb2, tempb1, tempb0;
    /*Saves values to temp, so do not mix them.*/
    tempa3 = *a3;
    tempa2 = *a2;
    tempa1 = *a1;
    tempa0 = *a0;
    tempb3 = *b3;
    tempb2 = *b2;
    tempb1 = *b1;
    tempb0 = b0;

    /*Products.*/
    *a3 = tempa3 * tempb3;
    *a2 = tempa2 * tempb3 + tempa3 * tempb2;
    *a1 = tempa3 * tempb1 + tempb3 * tempa1 + tempb2 * tempa2 + tempa2 * tempb2;
    *a0 = tempa3 * tempb0 + tempa2 * tempb1 + tempa1 * tempb2 + tempa0 * tempb3;
    *b3 = tempa2 * tempb0 + tempa1 * tempb1 + tempa0 * tempb2;
    *b2 = tempa1 * tempb0 + tempa0 * tempb1;
    *b1 = tempa0 * tempb0;          
}