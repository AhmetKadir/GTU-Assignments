/**
 * @file hw6_solution.c
 * @author Ahmet Kadir Aksu
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define N 3                                                         /*Format of game board is N*N */

void game_board(int board[N][N]);
void print_puzzle(int b[N][N]);
void move(int *r, int *c, int *d, int b[N][N]);
int solved(int b[N][N]);

int main (){
    int board[N][N] = {0},row = 0,column,direction, movement = 0;
    printf("\n\nThe game begins.\n");
    game_board(board);
    print_puzzle(board);
    while(solved(board) == 0 && row != -1){                         /*The game continues until game solved or user enter -1.*/
        printf("\nEnter -1 to quit\n");
        printf("Row: ");
        scanf("%d",&row);
        if (row == -1){
            printf("\nYou have made %d move.\n", movement);
            printf("\nTerminating...\n");
        }
        else{
            printf("Column: ");
            scanf("%d",&column);
            printf("Which direction you want to move: (0-Down, 1-Left, 2-Up, 3-Right): ");
            scanf("%d",&direction);
            move(&row, &column, &direction, board);    
            movement = movement + 1;                                /*Calculates how many moves have been made.*/
            print_puzzle(board);
        }
    }
    /*Prints message on the screen if the game has been completed succesfully.*/
    
    if (solved(board) == 1){
        printf("\nCongrulations ! The game has been completed.\n");
        printf("\nYou have solved the puzzle in %d move.\n", movement);
        printf("\nTerminating...\n");
    }
    return 0;
}

void game_board(int board[N][N]){
    /*Creates the board.*/
    int i,j,k = 1 ,randnum,space = 0 , control = 0,arr[N*N] = {0} , temp;
    for (i=0 ; i<N*N-1 ; i++){
            arr[i]=k;
            k=k+1;
    }
    for(i=0 ; i<N*N-1 ; i++){
        randnum = rand() % (N*N);
        temp = arr[randnum];
        arr[randnum] = arr[i];
        arr[i] = temp;
    }
    k=0;
    for (i=0 ; i<N ; i++){
        for (j=0; j<N ; j++){
            board[i][j] = arr[k]; 
            k=k+1;
        }
    }
    printf("\n\n");
}
void print_puzzle(int b[N][N]){
    /*Prints the current puzzle on the console properly.*/
    int i,j,k;
    printf("\n");
    for(i=0 ; i<N; i++)
        printf("****************");
    printf("\n");
    for(i=0 ; i<N ; i++){
        for(j=0 ; j<N ; j++){
            if(b[i][j] == 0)
                printf("*\t\t");
            else
                printf("*\t%-3d\t",b[i][j]);
        }
        printf("*\n");
        for(k=0 ; k<N; k++)
            printf("****************");
        printf("\n");
    }
    printf("\n");
    
}

void move(int *r, int *c, int* d, int b[N][N]){
    /*Performs the desired move on the puzzle board. */
    typedef enum {down, left, up, right}
    movement;
    int k , i,j,i_zero , j_zero;
    for(i=0 ; i< N ; i++)
        for(j=0 ; j< N ; j++)
            if (b[i][j] == 0){
                i_zero = i;
                j_zero = j;
            }
            
    if (b[*r][*c] == 0 || *r > N-1 || *r < 0 || *c > N-1 || *c < 0 ){            /*Wrong move conditions.*/
        printf("\nInvalid Move !\n\n");                                          
    }
    else{
        switch (*d)
            {
            case down:
                if (j_zero == *c && *r < i_zero){
                    k = i_zero;
                    while(k >= *r){
                        if(b[k-1][*c] == 0) 
                            1;
                        else    
                            b[k][*c] = b[k-1][*c];
                        k=k-1;
                    }
                    b[*r][*c] = 0;
                }
                else    
                    printf("\nInvalid Move !\n\n");
                break;
            case left:
                if (i_zero == *r && j_zero < *c){
                    k=j_zero;
                    while( k <= *c){
                        if(b[*r][k+1] == 0)
                            1;
                        else
                            b[*r][k] = b[*r][k+1];
                        k=k+1;
                    }
                    b[*r][*c] = 0;
                }
                else    
                    printf("\nInvalid Move !\n\n");
                break;
            case up:
                if (j_zero == *c && *r > i_zero){
                    k = i_zero;
                    while(k <= *r){
                        if(b[k+1][*c] == 0) 
                            1;
                        else    
                            b[k][*c] = b[k+1][*c];
                        k=k+1;
                    }
                    b[*r][*c] = 0;
                }
                else    
                    printf("\nInvalid Move !\n\n");
                break;
            case right:
                if (i_zero == *r && j_zero > *c){
                    k = j_zero;
                    while( k >= *c){
                        if(b[*r][k-1]== 0)
                            1;
                        else
                            b[*r][k] = b[*r][k-1];
                        k=k-1;
                    }
                    b[*r][*c] = 0;
                }
                else    
                    printf("\nInvalid Move !\n\n");
                break;
            
            default:
                printf("\nWrong input !\n\n");
                break;
        }
    }
}

int solved(int b[N][N]){
    /*Checks if the puzzle is solved correct*/
    
    int result = 0, temp[N][N] = {0} , k=0,m=1, i, j, a = 0;
    for (i=0 ; i<N ; i++){
        for(j=0 ; j<N ; j++){
            temp[i][j] = b[i][j];
            if (k == N-1 && m == N-1 || b[0][0] == 0)
                break;
            else{
                if(b[k][m] > temp [i][j])
                    a = a + 1;
                
                if(m == N-1){
                    k = k+1;
                    m = 0;
                }
                else    
                    m = m+1;
            }    
        }
    }
    
    if (a == N*N-2){
        result = 1;
    }
    else 
        result = 0;
    return result;
}