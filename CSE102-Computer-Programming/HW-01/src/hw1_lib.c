/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Ahmet Kadir Aksu
** 
*/

#include <stdio.h>
#include "hw1_lib.h"
#include <math.h>

double integral3(double a0, double a1, double a2, double a3, double xs, double xe, double delta)
{
    /*initialize the x with first term */
    double  sum=0, 
            x=xs,                                                          
            integral;
    while(x <= xe){                             /*reimann sums trapezoid formula = (delta/2)*(f(x0) + 2f(x1) + 2f(x2)... + 2f(x(n-1)) + f(x(n))) */
        if ((x == xs) || (x > xe-delta))                                    /* at the first and last term, divide by 2 */                  
            sum+=(a0*pow(x,3)+ a1*pow(x,2) + a2*x + a3)/2;
        else                                                               /*for the other terms*/
            sum+=(a0*pow(x,3)+ a1*pow(x,2) + a2*x+ a3);    
        
        x=x+delta;                                                         /*increment x till reach end of the range*/
    }
    integral = sum*delta;                                             

    return integral;
}


double integral4(double a0, double a1, double a2, double a3, double a4, double xs, double xe, double delta)
{
        double  sum=0, 
                x=xs,                                                      /*initialize the x with first term */
                integral; 
    while(x <= xe){                                                         /*reimann sums trapezoid formula = (delta/2)*(f(x0) + 2f(x1) + 2f(x2)... + 2f(x(n-1)) + f(x(n))) */
        if ((x == xs) || (x > xe-delta))                                    /* at the first and last term, divide by 2 */                  
            sum+=(a0*pow(x,4) + a1*pow(x,3)+ a2*pow(x,2) + a3*x + a4)/2;
        else                                                                /*for the other terms*/
            sum+=(a0*pow(x,4) + a1*pow(x,3)+ a2*pow(x,2) + a3*x+ a4);    
        
        x=x+delta;                                                          /*increment x till reach end of the range*/
    }
    integral = sum*delta;                                             

    return integral;
}


double root3(double a0, double a1, double a2, double a3, double xs, double xe)
{                                                                           /*newton bisection method*/   
    double root = (xs+xe)/2;                                                /*take the average of upper and lower limit*/ 
    while (xe-xs > 0.000001){                                                /*stop when interval is too small.*/
        if(a0*pow(root,3) + a1*pow(root,2)+ a2*root + a3 == 0)              
            break;
        
        else if((a0*pow(root,3) + a1*pow(root,2)+ a2*root + a3 ) * (a0*pow(xe,3) + a1*pow(xe,2)+ a2*xe + a3) < 0){   
            xs = root;                                                      /*if f(root)*f(xe) is negative, then the root must be between these numbers */
            root = (root+xe)/2;                     
        }    
        
        else{
            xe = root;
            root = (root+xs)/2;
        }
    }
    return root;
}


double root4(double a0, double a1, double a2, double a3, double a4, double xs, double xe)
{                                                                                    /*newton bisection method*/
    double root = (xs+xe)/2;                                                         /*take the average of upper and lower limit*/ 
    while (xe-xs > 0.000001){                                                          /*stop when interval is too small.*/
        if(a0*pow(root,4) + a1*pow(root,3)+ a2*pow(root,2) + a3*root + a4 == 0)     
            break;
        
        else if((a0*pow(root,4) + a1*pow(root,3)+ a2*pow(root,2) + a3*root + a4) * (a0*pow(xe,4) + a1*pow(xe,3)+ a2*pow(xe,2) + a3*xe + a4) < 0){
            xs = root;                                                              /*if f(root)*f(xe) is negative, then the root must be between these numbers*/
            root = (root+xe)/2;    
           
        }    
        else{
            xe = root;
            root = (root+xs)/2;
        }
    }
    return root;
}
