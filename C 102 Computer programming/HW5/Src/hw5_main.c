/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Ahmet Kadir Aksu
** 
*/

#include <math.h>
#include <stdio.h>
#include "hw5_lib.h"


void test_operate_polynomials () 
{
	double a1,a2,a3,a0,b0,b1,b2,b3, val;
	int degree, i , control =1;
	char op;
	
	printf ("Enter coefficents for the first polynomial:\n");
	for(i=0 ; i<4 ; i++){
		scanf("(%d,%lf)",&degree , &val);
		switch(degree){
			case (3):a3 = val;
				break;
			case(2):a2 =val;
				break;
			case (1):a1 = val;
				break;
			case (0):a0 = val;				
				break;
			default:printf("Wrong input. Try again.");
		}
		
	}
	getchar();
	
	printf ("\nEnter coefficents for the second polynomial:\n");
	for(i=0 ; i<4 ; i++){
		scanf("(%d,%lf)",&degree , &val);
		switch(degree){
			case (3):b3 = val;
				break;
			case(2):b2 =val;
				break;
			case (1):b1 = val;
				break;
			case (0):b0 = val;
				break;
			default:printf("Wrong input. Try again.");
		}
	}
	
	printf("\nChoose operator: addition(+), multiplication(*), substraction(-): ");
	scanf(" %c",&op);
	printf("\nCoefficients : ");

	operate_polynomials(&a3, &a2, &a1, &a0, &b3, &b2, &b1, &b0,op);
	
}


void test_four_d_vectors ()
{
	double mean_a0=0.0, mean_a1=0.0, mean_a2=0.0, mean_a3=0.0, longest_distance=0.0;
	int N=5;
	four_d_vectors (&mean_a0, &mean_a1, &mean_a2, &mean_a3, &longest_distance, N);
	printf("Mean a0: %f\nMean a1: %f\nMean a2: %f\nMean a3: %f\nThe longest distance between two points: %f\n\n\n", mean_a0, mean_a1, mean_a2, mean_a3, longest_distance);
}


void test_dhondt_method ()
{
	int partyA=100000, partyB=80000, partyC=30000, partyD=20000, partyE=10000, numberOfSeats=550;
	dhondt_method (&partyA, &partyB, &partyC, &partyD, &partyE, numberOfSeats);
	printf("Party A: %d seat(s).\nParty B: %d seat(s).\nParty C: %d seat(s).\nParty D: %d seat(s).\nParty E: %d seat(s).\n\n\n", partyA, partyB, partyC, partyD, partyE);
}


void test_order_2d_points_cc ()
{
	double x1=1.0, y1=1.0, x2=2, y2=5.0, x3=-2.0, y3=4.0;
	order_2d_points_cc (&x1, &y1, &x2, &y2, &x3, &y3);
	printf("Counter-Clockwise Order: (%f,%f) - (%f,%f) - (%f,%f)\n\n\n", x1, y1, x2, y2, x3, y3);
}


void test_number_encrypt ()
{
	unsigned char number=128;
	number_encrypt (&number);
	printf("Encrypted number: %d\n\n\n", number);
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_operate_polynomials ();
	test_four_d_vectors ();
	test_dhondt_method ();
	test_order_2d_points_cc ();
	test_number_encrypt ();
	return (0);
} /* end main */
