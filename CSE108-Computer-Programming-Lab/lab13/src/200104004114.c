#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char *country, *capital;
    int population;
    bool driving_side; 
}Country;

struct Countries_read{
    char *country, *capital;
    int population;
    bool driving_side;
    struct Countries_read *next; 
}Countries_read;

void readFile(struct Countries_read **head);
void insertEnd(struct Countries_read **head, char* name, char* capital, int population, int drivingSide);
void print_list(struct Countries_read *head);

int main(){
    int run = 1,option, tempb, max=0, mem=1, i=0;
    Country *countries = (Country*)malloc(sizeof(Country));
    char *name, *capital;



    while(run){
        printf("\n1: Enter new record");
        printf("\n2: Write to the file");
        printf("\n3: Read from the file");
        printf("\n4: Print the linked list");
        printf("\n5: Exit\n");
        scanf("%d",&option);
        printf("\nYour choice: %d\n",option);
        switch(option){
            case 1:
                countries =(Country*)realloc(countries, mem*sizeof(Country));
                name = (char*)malloc(20 * sizeof(char));
                capital = (char*)malloc(20 * sizeof(char));
                printf("Country name: ");
                scanf("%s", name);
                countries[max].country = name;
                printf("Capital: ");
                scanf("%s", capital);
                countries[max].capital = capital;
                printf("Population of %s: ",countries[max].country);
                scanf("%d", &countries[max].population);
                printf("Do people in %s drive on the right side ? (YES:1 NO:0) : ",countries[max].country);
                scanf("%d", &tempb);
                if (tempb == 1) countries[max].driving_side = true;
                else countries[max].driving_side = false;
                max++;
                mem++;

                break;
            case 2:
                    i=0;
                    FILE* fptr;
                    fptr = fopen("Countries.txt","a");
                    while(i < max){
                        fprintf(fptr,"%s %s %d %d\n",countries[i].country, countries[i].capital, countries[i].population, countries[i].driving_side);
                        i++;    
                    }
                    fclose(fptr);
                    printf("\n\nWriting to the file is successful !\n");
                    break;
            case 3:;
                    struct Countries_read * country_head = NULL;
                    readFile(&country_head);
                    break;
            case 4:print_list(country_head);
                    break;
            case 5: run = 0;
                    break;
            default: printf("\nTRY AGAIN\n");
                    break;

        }

    }

    return 0;
}

void readFile(struct Countries_read** head){
    FILE* readf;
    char *name, *capital;
    name = (char*)malloc(20 * sizeof(char));
    capital = (char*)malloc(20 * sizeof(char));
    int population, drivingSide;
    readf = fopen("Countries.txt", "r");
    while(fscanf(readf, "%s %s %d %d\n", name, capital, &population, &drivingSide) == 4){
        insertEnd(&(*head), name, capital, population, drivingSide);
        name = (char*)malloc(20 * sizeof(char));
        capital = (char*)malloc(20 * sizeof(char));
    }
    printf("\nREADING FILE SUCCESSFUL\n");
    fclose(readf);
}

void insertEnd(struct Countries_read **head, char *name, char *capital, int population, int drivingSide){
        struct Countries_read *newN = (struct Countries_read*)malloc(sizeof(struct Countries_read));
        newN->country = name;
        newN->capital = capital;
        newN->population = population;
        newN->driving_side = drivingSide ? true : false;
        newN->next = NULL;


        if((*head) == NULL )
            *head = newN;
        else{
            struct Countries_read *temp = *head;
            while(temp->next != NULL){
                temp = temp->next;
            }   
            temp->next = newN; 
        }

}

void print_list(struct Countries_read* head){
    if (head == NULL) printf("\nThe list is null\n");
    while(head != NULL){
        printf("\nCountry: %-10s\tCapital: %-10s\tPopulation: %-10d\tDriving Side: %-10s",head->country, head->capital, head->population, 
            head->driving_side ? "true" : "false");
        head = head->next;
    }
}