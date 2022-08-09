#include <stdio.h>

int find_max_distance(int num_inputs);
void find_odd_average();

int main (){
    int num_inputs = 5;
    printf("\nMax dist between two consecutive nums = %d\n",find_max_distance(num_inputs));
    find_odd_average();
    return 0;
}

int find_max_distance(int num_inputs){
    int temp = 0, max= 0, num= 0, counter=0, i;
    printf("\n\n****************************************");
    printf("\n\tFIND MAX DISTANCE");
    printf("\n****************************************\n");
    printf("\nPlease enter five numbers:\n");
    for (i=0 ; i<num_inputs ; i++){
        temp = num;                                     /*Temp value is to save previous value*/
        printf("%d : ", i+1);
        scanf("%d", &num);
        if (num > temp ){                               /*If the number is bigger than previous number, do (current number - previous number)*/
            if (num - temp > max)
                max = num - temp;                           /*If it is the maximum difference, save it. */
        }
        else if (num <= temp){                          /*If the number is smaller than previous number, do (previous number - current number )*/
            if (temp - num > max)
                max = temp - num;                           /*If it is the maximum difference, save it. */
        }
        
        counter = counter + 1;                          /*Counter to track the number of entries*/
    }
    return max;                                         /*Return the max distance value*/
}

void find_odd_average(){
    int num= 0, i, counter_odd = 0 , sum = 0, counter = 0;
    float avg;
    printf("\n\n****************************************");
    printf("\n\tAVERAGE OF ODD NUMBERS");
    printf("\n****************************************\n");
    printf("\nPlease enter positive integers (-1 to stop):\n");
    while (num != -1){
        scanf("%d",&num);                               /* take value from user until input is -1*/
        if (num % 2 == 1 ){                             /*Check if the number is odd number or not*/
            counter_odd = counter_odd + 1;              /*Counter to count odd numbers*/
            sum = sum + num;                            /*Add sum if the number is odd*/
        }        
        counter = counter + 1;                          /*Counter to track the number of entries*/
    }
    avg = sum / counter_odd ;                   
    printf("\nAverage of odd numbers: %.2f\n",avg);
}