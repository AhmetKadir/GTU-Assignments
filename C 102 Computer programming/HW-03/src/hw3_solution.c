#include <stdio.h>
#include <stdlib.h>
void calculate_fibonacci_sequence();
void decide_perfect_harmonic_number();
void difference_max_min ();
void bmi_calculation ();

int main(){
    calculate_fibonacci_sequence();
    decide_perfect_harmonic_number();
    difference_max_min ();
    bmi_calculation ();

    return 0;
}

void calculate_fibonacci_sequence(){
    int x, temp, result, num = 1, i, control = 1, b;
    char a;
    printf("\n******\nPART 1\t\t#FIBONACCI SEQUENCE#\n******\n");
    while (control){                                                  
        x=1, temp=0, result=1;
        printf("Please enter terms number: ");
        b = scanf("%d", &num);
        a = getchar();
        if (a == '*'){                                                      /*If the input is '*', assign the control value to 0 to end the program.*/
            control = 0;
            num = 0;
            b = 1;
        }
                                                                            /*If the input is not a numeric value, b will equal to 0*/
        while (b == 0 || num < 0){                                                 
            if (b == 0){                                                    
                printf("Please enter “numeric” term(s) number: ");          /*Ask the user to enter a number again.*/
                b = scanf("%d",&num);
                a = getchar();
            }
            if (num < 0){                                                   /*If the input is not a positive integer, ask the user to enter a number again.*/
                printf("Please enter “positive” term(s) number: ");
                b = scanf("%d",&num);
                a = getchar();                                                
            }
            if (a == '*'){
                control = 0;
                num = 0;
                b = 1;
            }
        }

       
        for (i = 0; i < num ; i++){                                        /*Fibonacci sequence*/
            x = result;
            result = result + temp;
            temp = x;
            printf("%d\n", x);
        }
    }
}

void decide_perfect_harmonic_number(){
    int num, i,sum_perfect, check_int, control = 1 ;
    double sum_harm, counter, check_harm;
    float x;
    char a;
    printf("\n******\nPART 2\t\t#PERFECT HARMONIC NUMBER#\n******\n");
    while (control){                                                    /*As long as the control value is 1, the program will run. */ 
        num = 0, i,sum_perfect = 0, check_int = 0;
        sum_harm = 0, counter = 0, check_harm = 0;
        x = 0;
        printf("\nPlease enter input number: ");
        scanf("%d",&num);
        a= getchar();
        if (a == '*'){                                                  /*If the input is '*', assign the control value to 0 to end the program.*/
            control = 0;
        }
        else{
            printf("\nNatural number divisors:");
            for(i=1 ; i<= num; i++){
                if (num % i == 0){
                    printf(" %d",i);
                    if (i !=num){
                        printf (",");                                   /*Print commas.*/
                        sum_perfect = sum_perfect + i ;                 /*Sum of all natural number divisors.*/
                    }
                    sum_harm = sum_harm + (double) 1/i;                 /*Calculate harmonic sum of all natural number divisors.*/ 
                    counter = counter +1 ;                              /*Total number of all natural number divisors.*/
                }
            }
            /*Perfect Number is the number at which the sum of all natural number divisor of a natural number n is equal to itself*/
            
            printf ("\n\nIs Perfect Number? : ");     
            if (sum_perfect == num)                          
                printf ("Yes\n");
            else 
                printf ("No\n");    
            
            check_harm = counter /sum_harm ;                            /*Save the harmonic mean as the float value.*/
            check_int = counter /sum_harm ;                             /*Save the harmonic mean as the integer value.*/

            printf ("\nIs Harmonic Division Number? : ");               /*If these values are equal ,it means that the harmonic mean is equals to an integer.*/
            if (check_harm - check_int < 0.0001 )                       /*Avoid small mistakes.*/
                printf("Yes\n");
            else 
                printf("No\n");
            printf("\n\t----------------------------------\n");
        }    
    }
}

void difference_max_min (){
    double num, max ,min, diff;
    int i;
    printf("\n******\nPART 3\t\t#MAX MIN DIFFERENCE#\n******\n");
    printf("\nenter 5 inputs: ");
    for (i=0; i<5 ;i++){
        scanf("%lf",&num);                                              /*Get 5 numbers from user*/
        if (i == 0){                                                    /*Assign the first input to max and min value.*/
            max = num;
            min = num;
        }
        else{
            if (num > max)                                              /*Determine the max value.*/
                max = num;
            if (num < min)                                              /*Determine the min value.*/
                min = num;   
                 
        }
    }
    diff = max - min;                                                   /*Calculate the difference between max and min value.*/
    printf("\nMaximum number is: %g\n", max);
    printf("\nMinimum number is: %g\n", min);
    printf("\nDifference between maximum and minimum is: %g\n", diff);
    
}

void bmi_calculation (){
    float height, weight, bmi;
    printf("\n******\nPART 4\t\t#BMI CALCULATOR#\n******\n");
    printf("\nPlease enter weight(kg) : ");
    scanf("%f",&weight);
    printf("\nPlease enter height(m): ");
    scanf("%f",&height);
                                                              /*Body Mass Index*/
    bmi = weight / (height * height);                         /*This formula is taken from hw3 pdf*/
    printf("\nYour category: ");                              /*These categories are taken from hw3 pdf*/
    if (bmi < 16.0)
        printf ("Severely Underweight\n");
    else if (bmi >= 16.0 && bmi < 18.5)
        printf ("Underweight\n");    
    else if (bmi >= 18.5 && bmi < 25.0)
        printf ("Normal\n");    
    else if (bmi >= 25.0 && bmi < 30)
        printf ("Overweight\n");
    else if (bmi >= 30)
        printf ("Obese\n");    
}