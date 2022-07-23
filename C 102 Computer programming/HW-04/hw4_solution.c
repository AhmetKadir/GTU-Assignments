#include <stdio.h>
void writePolynomial();
void armstrongOrPolindrome();
void sumOfPrimeNumbers();

int main (){
    writePolynomial();
    armstrongOrPolindrome();
    sumOfPrimeNumbers();
    return 0;
}
/*```````````````````````````````````````PART 1````````````````````````````````````````*/
void writePolynomial(){
    float num;
    int degree, temp, i;
    printf("\n-----------\n   PART1\n-----------\n");
    printf("\nEnter your polynomial [n a_n a_n-1 a_n-2 ... a_0]: ");
    scanf("%d",&degree);
    temp = degree ;
    printf ("p(x) = ");
    for(i=0; i <= degree ; i++){
        scanf("%f",&num);
        
        if (temp == 0){
            if (num == 0)
                1;
            else
                printf("%+.1f ",num);
        }
        else if (temp == 1){
            if (num > 0.95 && num <= 1.05)
                printf("+x ");
            else if (num == -1)
                printf("-x ");
            else if (num == 0)
                1;    
            else
                printf("%+.1fx ", num);

        }
        else {
            if (i==0){
                if (num > 0.95 && num <= 1.05)
                    printf("x^%d ",degree);
                else if (num == -1)
                    printf("-x^%d ",degree);
                else if (num == 0)
                    1;    
                else
                    printf("%.1fx^%d ", num, degree);
            }   
            
            else {
                if (num > 0.95 && num <= 1.05)
                    printf("+x^%d ", temp);
                else if (num == -1)
                    printf("-x^%d ", temp);
                else if(num == 0)
                    1;
                else 
                    printf("%+.1fx^%d ", num, temp);
            }
        }    
        temp = temp -1;
    }
    printf("\n");
}
/*```````````````````````````````````````PART 2````````````````````````````````````````*/
void armstrongOrPolindrome(){
    int num, i, j, counter = 0, temp,result = 0, sum = 0, IsPalindrome = 0, digit, IsArmstrong = 0;
    printf("\n-----------\n   PART2\n-----------\n");
    printf("Armstrong or Palindrome\n");
    printf("\nPlease enter an integer number: ");
    scanf("%d", &num);
    
    while (num < 0){
        printf ("Your input is negative ! Please enter a positive integer number: ");
        scanf("%d", &num);
    }
    temp = num;

    while (num != 0){                           /*Find how many digits the number has.*/
        num = num/10;
        counter = counter + 1 ;
    }
    /*Check if it is an armstrong number.*/                             /*check negative inputs*/
    num = temp;
    for (i=0 ; i < counter ; i++){
        result = result + (temp % 10)*(temp % 10)*(temp % 10);
        temp = temp / 10;
    }
    if (num == result)
        IsArmstrong = 1;

    /*Check if it is palindrome.*/

    temp = num;
    
    for (i=0 ; i < counter ; i++){
        digit = temp % 10;
        for(j=i ; j < counter - 1; j++)
            digit =  digit*10;
        
        temp = temp / 10;    
        sum = sum + digit;
    }
    
    if (sum == num)
        IsPalindrome = 1;

        if (IsArmstrong == 1 && IsPalindrome == 1)
            printf("\nThis number is both Palindrome and Armstrong number.\n");
        else if (IsArmstrong == 1)
            printf("\nThis number is only Armstrong number.\n");
        else if (IsPalindrome == 1)
            printf("\nThis number is only Palindrome number.\n");
        else 
            printf("\nThis number does not satisfy any special cases\n");
            
           
}
/*```````````````````````````````````````PART 3````````````````````````````````````````*/
void sumOfPrimeNumbers(){
    int i, j, num1, num2, result = 0, max, min, flag;
    printf("\n-----------\n   PART3\n-----------\n");
    printf("--SUM OF PRIME NUMBERS--\n");
    printf("\nPlease enter first integer number: ");
    scanf("%d", &num1);
    while (num1 < 0){
        printf ("Your input is negative ! Please enter a positive integer number: ");
        scanf("%d", &num1);
    }
    
    printf("\nPlease enter second integer number: ");
    scanf("%d", &num2);
    while (num2 < 0){
        printf ("Your input is negative ! Please enter a positive integer number: ");
        scanf("%d", &num2);
    }
    
    if (num1 < num2){                                               /*Check which number is bigger.*/
        min = num1 ;
        max = num2 ;
    }                                                               /*Assign bigger number to max variable and smaller number to min variable.*/
    else {
        min = num2 ;
        max = num1 ;
    }

    for (i = min + 1 ; i < max ; i++){
        for (j = 2; j < i ; j++){
            if (i%j == 0){
                flag = 1;                                           /*If the number can be divided by some number, it is not a prime number.*/
                break;                                              /*Assign 1 to flag variable and move on on the first loop*/  
            }
            else {                      /*If the number can not be divided by a number, it is a prime number. Then assign 0 to flag variable.*/
                flag = 0;                                           
            }

        }
        if (flag == 0){
            result = result + i;                                    /*If flag is 0 (prime number) add the value to result.*/
        }
    }
    printf("\nSum of prime numbers between %d and %d = %d\n", min, max, result);
}