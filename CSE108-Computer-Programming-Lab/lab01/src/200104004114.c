/* 

The variable names that used in this file have no relation with the ones in the pdf file. 

<?> in the functions means something other than void, you should find the correct type for these functions.

*/

#include <stdio.h>

void trigonometry_calculation(double a, double b, double c)
{
    double sinx,cosx,tanx;
    sinx = a/c;
    cosx = b/c;
    tanx = a/b;
    printf("a: %.2lf\nb: %.2lf\nc: %.2lf\nsinx: %.2lf\ncosx: %.2lf\ntanx: %.2lf\n", a, b, c, sinx, cosx, tanx);
    return;
    
}

void trigonometry(int a, int b, int c)
{
    double a1 = a,b1 = b,c1 = c;
    trigonometry_calculation(a1,b1,c1);
    return;

}



unsigned long age_calculation(int x)
{
    unsigned long seconds;
    unsigned long a=(unsigned long)x;
    seconds=a*365*24*60*60;
    return seconds;
}

void age(int x)
{
    printf("Your age: %d\nYou are %lu seconds\n", x, age_calculation(x));
    return;
}




int main()
{
    trigonometry(5,12,13);
    age(85);
    return 0;
}
