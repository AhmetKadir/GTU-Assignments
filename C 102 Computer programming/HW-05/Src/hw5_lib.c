/*
** hw5_lib.c:
**
** The source file implementing library functions.
**
** Author: Ahmet Kadir Aksu
** 
*/
#include <math.h>
#include <stdio.h>
#include "hw5_lib.h"


void operate_polynomials  (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double* b0, char op)
{
	double c6,c5,c4,c3,c2,c1,c0;
	/*Addition*/
	if (op == '+'){
		c3 = *a3 + *b3;
		c2 = *a2 + *b2;
		c1 = *a1 + *b1;
		c0 = *a0 + *b0;
		printf("%.2f %.2f %.2f %.2f", c3, c2, c1, c0);
	}
	/*Substraction*/
	else if (op == '-'){
		c3 = *a3 - *b3;
		c2 = *a2 - *b2;
		c1 = *a1 - *b1;
		c0 = *a0 - *b0;
		printf("%.2f %.2f %.2f %.2f", c3 ,c2, c1, c0);
	}	 
	/*Multiplication*/
	else if (op == '*'){
		c6 = *a3 * *b3;
		c5 = *a3 * *b2 + *a2 * *b3;
		c4 = *a3 * *b1 + *a2 * *b2 + *a1 * *b3;
		c3 = *a3 * *b0 + *a2 * *b1 + *a1 * *b2 + *a0 * *b3;
		c2 = *a2 * *b0 + *a1 * *b1 + *a0 * *b2 ;
		c1 = *a1 * *b0 + *a0 * *b1;
		c0 = *a0 * *b0;
		printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f", c6,c5,c4,c3, c2, c1, c0);
	}
	printf("\n\n");
}


void four_d_vectors (double* mean_a0, double* mean_a1, double* mean_a2, double* mean_a3, double* longest_distance, int N)
{
	double d0 = 0.0, d1 = 0.0, d2 = 0.0, d3 = 0.0, euclidian_distance, tempd0 = 0, tempd1 = 0,tempd2 = 0,tempd3 = 0 ;
	int i, counter =0;

	for (i=0 ; i < N ; i++){
		/*break condition*/
		if (d0 == -1.0 && d1 == -1.0 && d2 == -1.0 && d3 == -1.0 ){  
			*mean_a0 = *mean_a0 + 1;
			*mean_a1 = *mean_a1 + 1;										
			*mean_a2 = *mean_a2 + 1;
			*mean_a3 = *mean_a3 + 1;
			counter = counter -1;
			break;
		}
		else{
			/*Saves previous vector.*/
			tempd0 = d0;
			tempd1 = d1;
			tempd2 = d2;
			tempd3 = d3;
			/*Gets new vector from user.*/
			printf("\nEnter %d. 4d vector: ", i+1);
			scanf("%lf %lf %lf %lf", &d0, &d1 ,&d2 ,&d3);
			
			*mean_a0 = *mean_a0 + d0;
			*mean_a1 = *mean_a1 + d1;
			*mean_a2 = *mean_a2 + d2;
			*mean_a3 = *mean_a3 + d3;
			counter = counter + 1;
			/*evaluate difference*/
			d0 = d0 - tempd0;
			d1 = d1 - tempd1;
			d2 = d2 - tempd2;
			d3 = d3 - tempd3;
			
			if ( i!=0 ) distance_between_4d_points (d0, d1, d2, d3, &euclidian_distance);
			/*Get values of points back.*/
			d0 = d0 + tempd0;
			d1 = d1 + tempd1;
			d2 = d2 + tempd2;
			d3 = d3 + tempd3;
			/*Assigning longest distance.*/
			if(i != 0){
				if (*longest_distance > euclidian_distance)
					1;
				else	
					*longest_distance = euclidian_distance;	
			}
		}	
	}
	*mean_a0 = *mean_a0 / (counter );
	*mean_a1 = *mean_a1 / (counter );
	*mean_a2 = *mean_a2 / (counter );
	*mean_a3 = *mean_a3 / (counter );
	printf("\n\n");
}


void distance_between_4d_points (double d0, double d1, double d2, double d3, double* euclidian_distance)
{
	/*euclid formula*/
	*euclidian_distance = sqrt(d0*d0  + d1*d1 + d2*d2 + d3*d3);
}


void dhondt_method (int* partyA, int* partyB, int* partyC, int* partyD, int* partyE, int numberOfSeats)
{
	int i,dividerA=2, dividerB=2, dividerC=2 , dividerD=2 , dividerE=2;
	int seatA = 0, seatB = 0, seatC = 0, seatD = 0, seatE = 0;
	int pA = *partyA ,pB= *partyB ,pC=*partyC ,pD= *partyD, pE= *partyE;
	/*Compares votes.*/
	while (seatA + seatB + seatC + seatD + seatE < numberOfSeats){
		if (pA >= pB && pA >= pC && pA >= pD && pA >= pE){
			pA = *partyA / dividerA;
			dividerA = dividerA + 1 ;
			seatA = seatA + 1;
		}
		else if (pB >= pA && pB >= pC && pB >= pD && pB >= pE){
			pB = *partyB / dividerB;
			dividerB = dividerB + 1 ;
			seatB = seatB + 1;
		}
		else if (pC >= pA && pC >= pB && pC >= pD && pC >= pE){
			pC = *partyC / dividerC;
			dividerC = dividerC + 1 ;
			seatC = seatC + 1;
		}
		else if (pD >= pA && pD >= pB && pD >= pC && pD >= pE){
			pD = *partyD / dividerD;
			dividerD = dividerD + 1 ;
			seatD = seatD + 1;
		}
		else if (pE >= pA && pE >= pB && pE >= pC && pE >= pD){
			pE = *partyE / dividerE;
			dividerE = dividerE + 1 ;
			seatE = seatE + 1;
		}	
	}
	/*Assigns seats.*/
	*partyA = seatA ;  *partyB =seatB ; *partyC =  seatC ; *partyD = seatD ; *partyE = seatE ;
}


void order_2d_points_cc (double* x1, double* y1, double* x2, double* y2, double* x3, double* y3)
{
	
	double res1, res2, res3 ;
	double tempx1, tempy1, tempx2, tempy2, tempx3, tempy3;
	int check0_x =0, check0_y =0;
	/*Check if points are zero and assign a small value.*/
	if (*x1 == 0.0){
		*x1 = 0.001;
		check0_x = 1;
	}
	if (*x2 == 0.0){
		*x2 = 0.001;
		check0_x = 1;
	}
	if (*x3 == 0.0 ){
		*x3 = 0.001;
		check0_x = 1;
	}
	if (*y1 == 0.0){
		check0_y = 1;
		*y1 = 0.001;
	}
	if (*y2 == 0.0){
		*y2 = 0.001;
		check0_y = 1;
	}
	if (*y3 == 0.0){
		*y3 = 0.001;
		check0_y = 1;
	}

	res1 = *y1/ *x1 ; res2 =*y2/ *x2 ; res3 = *y3/ *x3;
	/*categorising vectors by their quadrants (0-90)(90-180)(180-270)(270-360)*/
	if(*x3 > 0 && *y3 > 0) res3 = res3 -100000 ;
	else if (*x3 < 0 && *y3 > 0) res3 = res3 -1000 ;
	else if (*x3 < 0 && *y3 < 0) 1 ;
	else res3 = res3 +10000 ;
	
	if(*x2 > 0 && *y2 > 0)res2 = res2 -100000 ;
	else if (*x2 < 0 && *y2 > 0) res2 = res2 -1000 ;
	else if (*x2 < 0 && *y2 < 0) 1;
	else res2 = res2 +10000 ;
	
	if(*x1 > 0 && *y1 > 0) res1 = res1 -100000 ;
	else if (*x1 < 0 && *y1 > 0) res1 = res1 -1000 ;
	else if (*x1 < 0 && *y1 < 0) 1;
	else res1 = res1 +10000 ;
	
	/*Compares the slopes of vectors (y/x).*/
	if (res1 >= res2 && res1 >= res3){
		tempx1 = *x1;
		tempy1 = *y1;
		if (res2 >= res3){
			tempx2 = *x2;
			tempy2 = *y2;
			tempx3 = *x3;
			tempy3 = *y3;
		}
		else {
			tempx2 = *x3;
			tempy2 = *y3;
			tempx3 = *x2;
			tempy3 = *y2;
		}
	}
	else if (res2 >= res1 && res2 >= res3){
		tempx1 = *x2;
		tempy1 = *y2;
		if (res3 >= res1){
			tempx2 = *x3;
			tempy2 = *y3;
			tempx3 = *x1;
			tempy3 = *y1;
		}
		else{
			tempx2 = *x1;
			tempy2 = *y1;
			tempx3 = *x3;
			tempy3 = *y3;
		}
	}	
	else  {
		tempx1 = *x3;
		tempy1 = *y3;
		if (res1 >= res2){
			tempx2 = *x1;
			tempy2 = *y1;
			tempx3 = *x2;
			tempy3 = *y2;
		}
		else {
			tempx2 = *x2;
			tempy2 = *y2;
			tempx3 = *x1;
			tempy3 = *y1;
		}
	}
	
	*x1 = tempx3; *y1 = tempy3; *x2 = tempx2; *y2 = tempy2; *x3 = tempx1; *y3 = tempy1;
	/*Fix zero part.*/
	if (*x1 == 0.001 && check0_x == 1)
		*x1 =0.0;
	if (*x2 == 0.001 && check0_x == 1)
		*x2 =0.0;
	if (*x3 == 0.001 && check0_x == 1)
		*x3 =0.0;
	if (*y1 == 0.001 && check0_y == 1)
		*y1 =0.0;
	if (*y2 == 0.001 && check0_y == 1)
		*y2 =0.0;
	if (*y3 == 0.001 && check0_y == 1)
		*y3 =0.0;
}


void number_encrypt (unsigned char* number)
{
	char b7='-', b6='-', b5='-', b4='-', b3='-', b2='-', b1='-', b0='-';
	get_number_components (*number, &b7, &b6, &b5, &b4, &b3, &b2, &b1, &b0);
	reconstruct_components (number, b7, b6, b5, b4, b3, b2, b1, b0);
}


void get_number_components (unsigned char number, char* b7, char* b6, char* b5, char* b4, char* b3, char* b2, char* b1, char* b0)
{
	unsigned char temp = number;
	int i, counter = 0, mod;
	while(temp > 0){
		temp = temp / 2;
		counter = counter + 1;
	}
	/*Convert decimal to binary.*/
	for(i=0 ; i < counter ; i++){
		mod = number % 2;
		number = number / 2;
		switch (i){
			case (0):*b0 =mod;
				break;
			case (1):*b1 =mod;
				break;
			case (2):*b2 =mod;
				break;
			case (3):*b3 =mod;
				break;
			case (4):*b4 =mod;
				break;
			case (5):*b5 =mod;
				break;
			case (6):*b6 =mod;
				break;
			case (7):*b7 =mod;
				break;
			default: 1;
				break;
		}
	}
	/*Assigns zero to empty bits.*/
	if ( *b0 > 1) *b0 = 0;
	if ( *b1 > 1) *b1 = 0;
	if ( *b2 > 1) *b2 = 0;
	if ( *b3 > 1) *b3 = 0;
	if ( *b4 > 1) *b4 = 0;
	if ( *b5 > 1) *b5 = 0;
	if ( *b6 > 1) *b6 = 0;
	if ( *b7 > 1) *b7 = 0;
}


void reconstruct_components (unsigned char* number, char b7, char b6, char b5, char b4, char b3, char b2, char b1, char b0)
{
	int temp ,temp1, temp2 , temp3 , temp4, temp5, temp6, temp7;
	/*Change bit-7 with bit-2, bit-6 with bit-3, bit-5 with bit-0, bit 4 with bit-1.*/
	temp = b7;
	b7 = b2;
	b2 = temp;

	temp = b6;
	b6 = b3;
	b3 = temp;

	temp = b5;
	b5 = b0;
	b0 =temp;

	temp = b4;
	b4 = b1;
	b1 = temp;
	/*Do exactly two circular left shift.*/
	temp = b0;
	temp1 = b1;
	temp2 = b2;
	temp3 = b3;
	temp4 = b4;
	temp5 = b5;
	temp6 = b6;
	temp7 = b7;

	b7 = temp5;
	b6 = temp4;
	b5 = temp3;
	b4 = temp2;
	b3 = temp1;
	b2 = temp;
	b1 = temp7;
	b0 = temp6;
	/*Converts binary to decimal.*/
	*number = 0;
	if (b7 == 1) 
		*number = *number + 128;
	if (b6 == 1) 
		*number = *number + 64;
	if (b5 == 1) 
		*number = *number + 32;
	if (b4 == 1) 
		*number = *number + 16;
	if (b3 == 1) 
		*number = *number + 8;
	if (b2 == 1) 
		*number = *number + 4;	
	if (b1 == 1) 
		*number = *number + 2;
	if (b0 == 1) 
		*number = *number + 1;	
}
