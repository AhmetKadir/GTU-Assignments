/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
*/

#include <stdio.h>
#include "hw2_lib.h"
#include <math.h>


int find_weekday_of_data(int day, int month, int year)
{
    int diff_days = 0, i, weekday, leapdays = 0,
        initial_day = 5,   /* 00 00 00 - day month year*/       /*Assume that there is a 0000 year and 00 00 0000 is friday*/
        IsValid = 1;
    int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};     /*Save the month days into an array*/     
    
    /*Check if the dates are valid dates.*/
    if (month <= 0 || month > 12 || year <= 0){
        IsValid = 0;
    }
    else if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0 )){
        if (month == 2 && day == 29){
            IsValid = 1;
        }
        else if  (day > days[month] || day <= 0){
            IsValid = 0;
        }
    }
    else if  (day > days[month] || day <= 0){
        IsValid = 0;
    }

    if (IsValid){    
        for(i = 0 ; i < month ; i++)                                /*Add days of previous months.*/
            diff_days = diff_days + days[i];
        
        diff_days = diff_days + day;                                /*Add days of entered date*/

        for (i = 0; i <= year ; i++){                               /*Determine the leap years, e.g., 1972, 2000, 2012*/   
            if (i % 100 == 0 && i % 400 != 0 )                      /*1700, 1800, 1900 etc. are common years, not leap years, so do not add those years.*/
                1;
            else if (i % 4 == 0)
                leapdays = leapdays + 1;   
            else 
                1; 
        }

        if (year % 100 == 0 && year % 400 != 0)                     
            1;
        else if (year % 4 == 0 && month < 3 )                       /*If the year is leap year and the month is 1st or 2nd month, then substract one from leapdays.*/    
            leapdays = leapdays - 1;   
        
        diff_days = diff_days + year*365;                           /*Assume that every year has 365 days and multiple that by year, then add days in the entered year. */
        weekday = (diff_days + leapdays + initial_day) % 7   ;      /*Finally, add leapdays and add the initial day value (friday = 5) and calculate mod by 7.*/
        if (weekday == 0)
            weekday = 7;                                            /*If the result is equal to 0 then, assign as 7 so it means sunday.*/   
        return weekday;
    }  
    else{ 
        printf("Please enter a valid date !\n");
        printf("Please enter a valid date !\n");
        return -111111;
    }
}


int count_day_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year)
{
    int diff_days = 0, i;
    int weekday, leapdays = 0, commonyears, IsValid = 1;
    int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};     /*Save the month days into an array*/     
    
    /*Check if the dates are valid dates.*/
    if (start_month <= 0 || start_month > 12 || start_year <= 0 || end_month <= 0 || end_month > 12 || end_year <= 0){
        IsValid = 0;
    }
    else if (((start_year % 4 == 0) && (start_year % 100 != 0)) || (start_year % 400 == 0 )){
        if (start_month == 2 && start_day == 29){
            IsValid = 1;
        }
        else if  (start_day > days[start_month] || start_day <= 0){
            IsValid = 0;
        }
    }
    else if (((end_year % 4 == 0) && (end_year % 100 != 0)) || (end_year % 400 == 0 )){
        if (end_month == 2 && end_day == 29){
            IsValid = 1;
        }
        else if  (end_day > days[end_month] || end_day <= 0){
            IsValid = 0;
        }
    }
    else if  (start_day > days[start_month] || start_day <= 0){
        IsValid = 0;
    }
    else if  (end_day > days[end_month] || end_day <= 0){
        IsValid = 0;
    }

    if (IsValid){
        if(end_month > start_month)                                 /*Check if end month value is bigger than start month value.*/
            for(i = start_month ; i < end_month ; i++)              /*In that case, add days of previous months.*/
                diff_days = diff_days + days[i];            
        else
            for(i = end_month ; i < start_month ; i++)              /*If not so, substract days of previous months.*/
                diff_days = diff_days - days[i];

        diff_days = diff_days + end_day - start_day;                /*Add the day of end date, and substract the day of start date*/

        for (i = start_year ; i <= end_year ; i++){                 /*Determine the leap years, e.g., 1972, 2000, 2012*/
            if (i % 100 == 0 && i % 400 != 0 )                      /*1700, 1800, 1900 etc. are common years, not leap years, so do not add those years.*/
                1;
            else if (i % 4 == 0)
                leapdays = leapdays + 1;                            /*Calculate how many leap days between these two dates.*/
            else 
                1; 
        }
        
        if  (start_year % 100 == 0 && start_year % 400 != 0)        
            1;                                                              
        else if (start_year % 4 == 0 && start_month >= 3)           /*If the start year is leap year but the date is after february, substract one from leap days*/   
            leapdays = leapdays - 1;                                /*We should not add that day, since the interval does not include the leap day.*/
        
        if (end_year % 100 == 0 && end_year % 400 != 0)             /*Same check for the end date*/
            1;
        else if (end_year % 4 == 0 && end_month < 3)  
            leapdays = leapdays - 1;  
                                                                    /*Assume that every year has 365 days and multiple by year then add to the result*/
        diff_days = diff_days + leapdays + (end_year - start_year)*365;  /*And add leapdays to the result*/
        return diff_days;
    }
    else{
        printf ("Please enter a valid date !\n");
        printf ("Please enter a valid date !\n");
        return -111111;
    }    
}


double find_angle(double a, double b, double c)
{
    double PCsquare = (2*b*b + 2*a*a - c*c)/9,                  /*PC^2 --- P is the centroid of the triangle*/
           PBsquare = (2*c*c + 2*a*a - b*b)/9,                  /*PB^2*/
           result = acos((PCsquare + PBsquare - a*a ) / (2 * sqrt(PBsquare) * sqrt(PCsquare)));
    return result ; /*cos alpha = (PC^2 + PB^2 - a^2) / (2*PB*PC )  */
}


void print_tabulated(unsigned int r11, double r12, int r13, 
                     unsigned int r21, double r22, int r23, 
                     unsigned int r31, double r32, int r33, char border)
{
    int i;

    printf("|");
    for (i=0 ; i<55 ;i++)
        printf("%c",border);
    printf("|\n");
    printf("|   ROW 101\t|\tRow ABCDEFG\t|   Row XYZ123  |\n");
      for (i=0 ; i<57 ;i++)
        if (i == 0 || i == 16 || i == 40 || i == 56)
            printf("|");
        else      
            printf("%c",border);

    printf("\n|\t%u\t|%.2g\t\t\t|%+d\t\t|\n", r11, r12, r13);
    
    for (i=0 ; i<57 ;i++)
        if (i == 0 || i == 16 || i == 40 || i == 56)
            printf("|");
        else      
            printf("%c",border);

    printf("\n|\t%u\t|%.2g\t\t\t|%+d\t\t|\n", r21, r22, r23);

    for (i=0 ; i<57 ;i++)
        if (i == 0 || i == 16 || i == 40 || i == 56)
            printf("|");
        else      
            printf("%c",border);

    printf("\n|\t%u\t|%.2g\t\t\t|%+d\t\t|\n", r31, r32, r33);


    printf("|");
    for (i=0 ; i<55 ;i++)
        printf("%c",border);
    printf("|\n");
}

