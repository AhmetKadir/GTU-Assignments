
#include <stdio.h>
#include <math.h>

typedef struct{
    double arr[3][3];
    double determinant;
}matrix;

typedef struct{
    double x;
    double y;
    double z;
}vector;

void print_matrix(matrix initial_matrix);
void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix);
int det_cal(matrix* matrix, int i, int j);
void transpoze(matrix* invertedMatrix, int det);
void determinant_of_matrix(matrix* initial_matrix);
double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec);

int main(){
    int i,j;
    matrix myMatrix;
    matrix inverted;
    vector vec_1, vec_2, product_vec;
    

    printf("\n********************************************************************************");
    printf("\n\tPART 1");
    printf("\n********************************************************************************\n\n");
            /*---------------Matrix Function---------------*/
    for(i=0 ; i<3 ; i++){
        for(j=0 ; j<3 ; j++){
            printf("Enter values for the matrix(3x3)(one by one): ");
            scanf("%lf",&myMatrix.arr[i][j]);
        }
    }
    print_matrix(myMatrix);
    inverse_matrix(&myMatrix, &inverted);
    printf("\n\nThe inverse matrix:");
    print_matrix(inverted);

        /*---------------Orthogonal Function---------------*/
        
    printf("\n\n********************************************************************************");
    printf("\n\tPart 2");
    printf("\n********************************************************************************\n\n");

    printf("Enter 3  values for the first vector(a1 b1 c1): ");
    scanf("%lf %lf %lf",&vec_1.x, &vec_1.y, &vec_1.z);
    printf("Enter 3 values for the second vector(a2 b2 c2): ");
    scanf("%lf %lf %lf",&vec_2.x, &vec_2.y, &vec_2.z);
    printf("\n\nangle between vectors: %f\n\n", find_orthogonal(vec_1,vec_2, &product_vec));
    printf("\nproduct vector: <%f, %f, %f>\n\n",product_vec.x,product_vec.y,product_vec.z);

    return 0;
}

void print_matrix(matrix initial_matrix){
    int i,j;
    printf("\n\n------ Printing matrix ------\n\n");
        /*Prints matrix in a pretty format. */
    for(i=0 ; i<3 ; i++){
        for(j=0 ; j<3 ; j++){
            printf("%-10.4f ",initial_matrix.arr[i][j]);
        }
        printf("\n");
    }

}

void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix){
    int i, j;
    determinant_of_matrix(initial_matrix);
    printf("\nDeterminant of the matrix is %.2lf", initial_matrix -> determinant);
    
    if (initial_matrix->determinant == 0)
        printf("not inversible");
    else    {
        for (i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++){
                    inverted_matrix->arr[i][j] = det_cal(initial_matrix, i, j);
             }
        }

        transpoze(inverted_matrix, initial_matrix->determinant);
    }

}

int det_cal(matrix* matrix, int i, int j){
    int res = matrix->arr[(i + 1) % 3][(j + 1) % 3] * matrix->arr[(i + 2) % 3][(j+2) % 3]
            - matrix->arr[(i+1) % 3][(j + 2) % 3] * matrix->arr[(i+2) % 3][(j + 1) % 3];
    return res;
}

void transpoze(matrix* invertedMatrix, int det){
    int i, j;
    matrix temp;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            temp.arr[i][j] = invertedMatrix->arr[i][j];
        }
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            invertedMatrix->arr[i][j] = temp.arr[j][i];
            /*divide by determinant*/
            invertedMatrix->arr[i][j] /= det;
        }
    }
}

void determinant_of_matrix(matrix* initial_matrix){
    initial_matrix->determinant = 0;
        /*Calculates determinant of matrix.*/
    initial_matrix->determinant += initial_matrix->arr[0][0]*(initial_matrix->arr[1][1]* initial_matrix->arr[2][2]- initial_matrix->arr[1][2]*initial_matrix->arr[2][1]);
    initial_matrix->determinant -= initial_matrix->arr[0][1]*(initial_matrix->arr[1][0]* initial_matrix->arr[2][2]- initial_matrix->arr[1][2]*initial_matrix->arr[2][0]);
    initial_matrix->determinant += initial_matrix->arr[0][2]*(initial_matrix->arr[1][0]* initial_matrix->arr[2][1]- initial_matrix->arr[1][1]*initial_matrix->arr[2][0]);
}

double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec){
    double angle;
        /*Calculates angle between given two vectors.*/
    angle = acos((vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z ) / ((sqrt(vec_1.x*vec_1.x + vec_1.y*vec_1.y + vec_1.z*vec_1.z))
    * sqrt(vec_2.x * vec_2.x + vec_2.y * vec_2.y + vec_2.z * vec_2.z )));
        /*Calculates cross products of two vector.*/
    output_vec->x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
    output_vec->y = - vec_1.x * vec_2.z + vec_1.z * vec_2.x;
    output_vec->z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
    return angle;
}
