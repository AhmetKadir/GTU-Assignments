#include <stdio.h>
#include <math.h>
void standart_calculator ();
void integer(int);
void complex(int);
void area_Perimeter_calculator ();
int temperature_calculator (int, int);
void calculation_type (int);
void circle();
void rectangle();
void triangle();

int main (){
    int Selection;
    printf("Enter the calculator type:\n");
    printf("1. Standart Calculator\n2. Area&Perimeter Calculator\n3. Temperature Calculator\n");
    printf("---------------\n");
    scanf("%d", &Selection);
    fflush(stdin);

    switch (Selection){
        case (1): standart_calculator();
                  break;
        case (2): area_Perimeter_calculator();
                  break;
        case (3): temperature_calculator;
                  break;
        default : printf("Please enter a number between 1-3\n");                 
                  break;
    }
    return 0;
}

void standart_calculator (){
    int selection;
    printf("Enter the number type:\n");
    printf("1. Integer\n2. Complex\n");
    printf("---------------\n");
    scanf("%d", &selection);
    fflush(stdin);

    switch (selection){
        case (1): calculation_type (1);
                break;
        case (2): calculation_type (2);
                break;
        default : printf("Please enter a number between 1-2\n");
                  standart_calculator();
                break;         
    }

    
}

void calculation_type(int selection){
    int type;

    printf("Enter the calculation type:\n");
    printf("1. Addition\n2. Multiplication\n");
    printf("---------------\n");
    fflush(stdin);

    printf("Your choice: ");
    scanf("%d",&type);
    fflush(stdin);
    printf("\n");
    

    switch (selection)
    {
        case (1):
            integer(type);
            break;
        case (2):
            complex(type);
            break;
        default : 
            printf("Please enter a number between 1-2\n");
            break;     
    }
    
}

void integer(int type){
    int num1, num2, sum = 0 ,multi = 0;
    printf("Please enter the first integer number: ");
    scanf("%d", &num1);
    fflush(stdin);

    printf("Please enter the second integer number: ");
    scanf("%d", &num2);
    fflush(stdin);

    switch (type){
        case (1):
            sum=num1 + num2;
            printf("Addition of the numbers = %d\n",sum);
            break;
        case (2):
            multi= num1 * num2;
            printf("Multiplication of the number = %d\n",multi);
            break;
    }
    
}

void complex(int type){
    int real1, real2, img1, img2, real3, img3;
    printf("Please enter the first complex number(real part first)\n");
    printf("For example if your real number is 5 + 3i, then your input should be #5 3# : ");
    scanf("%d %d", &real1 , &img1);
    fflush(stdin);

    printf("Please enter the second complex number(real part first)\n");
    printf("For example if your real number is 5 + 3i, then your input should be #5 3# : ");
    scanf("%d %d", &real2 , &img2);
    fflush(stdin);

    switch (type){
        case (1):
            real3 = real1 + real2;
            img3 =img1 + img2;
            printf("Addition of the numbers =  %d +(%di)\n", real3, img3);
            break;
        case (2):
            real3 = real1 * real2 - img1 * img2;
            img3 = real1*img2 + real2*img1;
            printf("Multiplication of the numbers = %d + (%di)\n",real3 , img3);
            break;
    }
}

/**
 * This function calculates the area and perimeter of a rectangle.
 */
void area_Perimeter_calculator (){
    int select;
    printf("Enter the shape type\n");
    printf("1.Rectangle\n2.Triangle\n3.Circle");
    printf("\nYour choice: ");
    scanf("%d", &select);
    fflush(stdin);

    switch (select)
    {
    case (1):
        rectangle();
        break;
    case (2):
        triangle();
        break;
    case (3):
        circle();
        break;
    default:
        printf("wrong input !");
        break;
    }

}

void rectangle() {
    int a,b;
    printf("Please enter two sides of rectangle(a b)\n");
    printf("Correct input example => #3 7# : ");
    scanf("%d %d", &a, &b);
    fflush(stdin);

    printf("\nperimeter of rectangle = %d", a+a+b+b);
    printf("\narea of rectangle = %d", a*b);
}

void triangle() {
    int s, a, b, c;
    printf("Please enter three sides of triangle(a b c)\n");
    printf("Correct input example => #5 8 13# : ");
    scanf("%d %d %d", &a, &b, &c);
    fflush(stdin);

    s=(a+b+c)/2;
    printf("\nperimeter of triangle = %d", s);
    printf("\narea of triangle = %lf", sqrt(s*(s-a)*(s-b)*(s-c)));
}

void circle() {
    double r;
    printf("Please enter the diameter of circle: ");
    scanf("%lf", &r);
    fflush(stdin);

    printf("\nperimeter of circle = %lf", 2*M_PI*r);
    printf("\narea of circle = %lf", M_PI*r*r);
}