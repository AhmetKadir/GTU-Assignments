#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int average_finder(double *result1 ,double *result2);
void intervew ( char s1[], char s2[], char *s3);

int main(){
    double result1 = 0, result2 = 0;
    char s1[15] = "arrival" , s2[15] = "9216" , s3[30] = {0};

    printf("\n------------------------------------------------------------------------------------------");
    printf("\n\tPART 1");
    printf("\n------------------------------------------------------------------------------------------\n");    
    average_finder(&result1 , &result2);
    printf("\nAverage of index values which sum of index numbers are positive (For example [0][0], [3][1])");
    printf("\n\nresult of first matrix: %.1f\n", result1);
    printf("\nresult of second matrix: %.1f\n", result2);
    printf("\n------------------------------------------------------------------------------------------");
    printf("\n\tPART 2");
    printf("\n------------------------------------------------------------------------------------------\n");    
    printf("\nMixing two words:");
    printf("\nword 1 = %s", s1);
    printf("\nword 2 = %s", s2);
    printf("\nResult: ");
    intervew(s1, s2, s3);

    return 0;
}

int average_finder(double *result1, double *result2){
    int i, j, Matrix[10][10]={0}, k=1, counter = 0;

    /*First matrix*/
    printf("First Matrix: \n");
    for(i=0 ; i < 3 ; i++){
        for(j=0; j< 5 ; j++){
            Matrix[i][j] = 2*(k*k) -3;
            k= k + 1;
            printf("%6d ",Matrix[i][j]);

            /*Checks if indexes are even.*/
            if ((i+j)% 2 == 0){
                *result1 = *result1 + (double) Matrix[i][j];
                counter = counter + 1;
            }    
        }
        printf("\n");
    }
    *result1 = *result1 / (double) counter ;
    printf("\n\n");
    
    /*Second matrix.*/
    printf("\nSecond Matrix: \n");
    k=1;
    counter = 0;
    for(i=0 ; i < 4 ; i++){
        for(j=0; j< 9 ; j++){
            Matrix[i][j] = 2*(k*k) -3;
            k= k + 1;
            printf("%6d ",Matrix[i][j]);
            /*Checks if indexes are even.*/
            if ((i+j)% 2 == 0){
                *result2 = *result2 + (double) Matrix[i][j];
                counter = counter + 1;
            }    
        }
        printf("\n");
    }
    *result2 = *result2 / (double) counter;
}

void intervew (char s1[], char s2[], char *s3){
    int i, j = 0;
    int newSize = strlen(s1) + strlen(s2);
    for (i=0 ; i<newSize ; i++){
        if(i < strlen(s1)){
            s3[j] = s1[i];
            j=j+1;
        }
        if(i <  strlen(s2)){
            s3[j]= s2[i];
            j=j + 1;
        }
        
    }
    for(i=0 ; i< strlen(s3) ; i++)
        printf("%c",s3[i]);
    printf("\n\n");
}