#include <stdio.h>
#include <string.h>
#include "lib.h"

void add_book(Book * x , int * _id);
void list_books (Book * x, int numberOfBooks);
void find_a_book_title(const Book * x, int numberOfBooks);
void find_a_book_author(const Book * x, int numberOfBooks);
void find_a_book_subject(const Book * x, int numberOfBooks);
void list_by_year(Book * x, int numberOfBooks);
void list_by_id(Book * x, int numberOfBooks);
void printBooks(Book * x, int numberOfBooks);

int main(){
    Book books[100];
    int option1, control = 1, _id = 0;
    
    while(control){
        printf("\nNumber of books = %d\n", _id);
        printf("\nMENU\n\t1. Add New Book\n\t2. List Books\n\t3. EXIT\n");
        scanf("%d",&option1);
        switch(option1){
            case(1):add_book(books, &_id);
                    break;
            case(2):list_books(books, _id);
                    break;
            case(3):control = 0;
                    printf("\nTerminating...\n");
                    break;
            default:printf("\nTRY AGAIN !\n");
                    break;
        }
    }
}

void add_book(Book * x, int * _id){                      /*Adds a book.*/
    
    printf("\nPlease enter book title = ");
    scanf(" %[^\n]%*c",x[*_id].title);
  
    printf("\nPlease enter book author = ");
    scanf(" %[^\n]%*c",x[*_id].author);
    
    printf("\nPlease enter book subject = ");
    scanf(" %[^\n]%*c",x[*_id].subject);
    
    printf("\nPlease enter book year = ");
    scanf("%d",&x[*_id].year);
    x[*_id].id = *_id;
    (*_id)++;
}

void list_books(Book * x, int numberOfBooks){                      /*Opens submenu.*/
    int control = 1, option2;
    while(control){
        printf("\nSUBMENU\n\t1. Get by Title\n\t2. Get by Author\n\t3. Get by Subject\n\t4. Sorted List by Year (DESC)\n\t5. List All Books\n\t6. EXIT SUBMENU\n");
        scanf("%d",&option2);
        switch(option2){
            printf("\nChoose - %d\n", option2);
            case(1):
                    find_a_book_title(x, numberOfBooks);
                    break;
            case(2):
                    find_a_book_author(x, numberOfBooks);
                    break;
            case(3):
                    find_a_book_subject(x, numberOfBooks);
                    break;
            case(4):
                    list_by_year(x, numberOfBooks);
                    printBooks(x, numberOfBooks);
                    break;
            case(5):
                    list_by_id(x, numberOfBooks);
                    printBooks(x, numberOfBooks);
                    break;
            case(6):control = 0;
                    break;
            default:printf("\nTRY AGAIN !\n");
                    break;
        }
    }
}

void printBooks(Book * x, int numberOfBooks){
    int i;
    for (i = 0; i < numberOfBooks; i++){
        printf("\nTitle = %s", x[i].title);
        printf("\nAuthor = %s", x[i].author);
        printf("\nSubject = %s", x[i].subject);
        printf("\nYear = %d", x[i].year);
        printf("\n\n");
    }
}

void find_a_book_title(const Book * x, int numberOfBooks){                             /*Finds a book by title.*/
    int i=0;            
    char name[20];
    printf("Enter a books title: ");
    scanf(" %[^\n]%*c", name);
    printf("*********************************");
    for(i=0 ; i<numberOfBooks; i++){
        if(strcmp(x[i].title, name) == 0){
            printf("\nBook found\n");
            printf("\nTitle -> %s\n", x[i].title);
            printf("\nAuthor -> %s\n",x[i].author);
            printf("\nSubject -> %s\n",x[i].subject);
            printf("\nYear -> %d\n",x[i].year);
            break;
        }
    }
    printf("*********************************");
}

void find_a_book_author(const Book * x, int numberOfBooks){            /*Finds a book by author.*/
    int i=0;
    char name[20];
    printf("Enter a books author: ");
    scanf(" %[^\n]%*c", name);
    printf("*********************************");
    for(i=0 ; i<numberOfBooks; i++){
        if(strcmp(x[i].author, name) == 0){
            printf("\nBook found\n");
            printf("\nTitle -> %s\n", x[i].title);
            printf("\nAuthor -> %s\n",x[i].author);
            printf("\nSubject -> %s\n",x[i].subject);
            printf("\nYear -> %d\n",x[i].year);
            break;
        }
    }
    printf("*********************************");
}

void find_a_book_subject(const Book * x, int numberOfBooks){               /*Finds a book by subject.*/
    int i=0;
    char name[100];
    printf("Enter a books subject: ");
    scanf(" %[^\n]%*c", name);
    printf("*********************************");
    for(i=0 ; i<numberOfBooks; i++){
        if(strcmp(x[i].subject, name) == 0){
            printf("\nBook found\n");
            printf("\nTitle -> %s\n", x[i].title);
            printf("\nAuthor -> %s\n",x[i].author);
            printf("\nSubject -> %s\n",x[i].subject);
            printf("\nYear -> %d\n",x[i].year);
            break;
        }
    }
    printf("*********************************");
}

void list_by_year(Book * x, int numberOfBooks){                    /*Lists books by years.*/
    int i = 0,j,temp1,temp2;
    char temp3[20],temp4[20],temp5[100];
    for(i=0;i<numberOfBooks - 1; i++){
        for(j=i+1; j<numberOfBooks; j++){
            if(x[i].year < x[j].year){
                strcpy(temp3,x[i].title);
                strcpy(temp4,x[i].author);
                strcpy(temp5,x[i].subject);
                temp1 = x[i].year;
                temp2 = x[i].id;
                strcpy(x[i].title, x[j].title);
                strcpy(x[i].author, x[j].author);
                strcpy(x[i].subject, x[j].subject);
                x[i].year= x[j].year;
                x[i].id = x[j].year;
                strcpy(x[j].title, temp3);
                strcpy(x[j].author, temp4);
                strcpy(x[j].subject, temp5);
                x[j].year= temp1;
                x[j].id = temp2;
            }
        }
    }
   
}

void list_by_id(Book * x, int numberOfBooks){                      /*Lists books by ids*/
    int i = 0, j, temp1,temp2;
    char temp3[20],temp4[20],temp5[100];
    for(i = 0; i < numberOfBooks - 1; i++){
        for(j= i+1; j<numberOfBooks; j++){
            if(x[i].id > x[j].id){
                strcpy(temp3,x[i].title);
                strcpy(temp4,x[i].author);
                strcpy(temp5,x[i].subject);
                temp1 = x[i].year;
                temp2 = x[i].id;
                strcpy(x[i].title, x[j].title);
                strcpy(x[i].author, x[j].author);
                strcpy(x[i].subject, x[j].subject);
                x[i].year= x[j].year;
                x[i].id = x[j].year;
                strcpy(x[j].title, temp3);
                strcpy(x[j].author, temp4);
                strcpy(x[j].subject, temp5);
                x[j].year= temp1;
                x[j].id = temp2;
            }
        }
    }
}
