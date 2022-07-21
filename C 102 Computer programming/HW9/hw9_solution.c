/**
 * @file hw9_solution.c
 * @author Ahmet Kadir Aksu
 * @copyright Copyright (c) 2022
 * 
 */

#define N 50

#include <stdio.h>
#include <string.h>


typedef struct {
    int label;
    char name[20];
    int age;
}system;

system add_customer(system person[]);
system process_customer(system person[]);
int check_sequence(int label, system person[], int n, int limit);
int check_line(int label, system person[], int n);

int main(){
    system customer[N];
    int option, control =1 ,i ,empty = 1, Full = 0;
     
    printf("\n***********Banking System***********\n");
            /*Sets default label value as 5.*/
    for(i=0 ; i<N ; i++){
        customer[i].label = 5;
    }
    while(control){
        empty = 1, Full = 0;
                /*Prints current sequence and checks if it is empty.*/
        printf("\nCurrent Sequence: ");
        for(i=0 ; i<N ; i++){
            if (customer[i].label != 5){
                printf("%d ",customer[i].label);
                empty = 0;
            }
        }
        if(empty){
            printf("EMPTY");
        }
                /*Checks if the sequence is full*/
        if (customer[N-1].label != 5) Full = 1;
    
        printf("\n1-Add customer\n2-Process customer\n");
        printf("\nYour entry: ");
        scanf("%d",&option);
        getchar();
        switch(option){
            case (1):if (Full) printf("\nSequence is full ! You can not add more customer.\n"); 
                    else add_customer(customer);
                    break;
            case (2):if(empty)
                        printf("\nThere is not any customer in bank system sequence.\n");
                    else{
                        printf("\nProceed customer is %s\n", customer[0].name);
                        process_customer(customer);
                    }
                    break;
            case (3):control=0;         /*Exit.*/
                    break;
            default: printf("\nEnter a valid entry.\n");
                    break;
        }
    }
}

system add_customer(system person[]){
    int i, j, age, label, flag = 0, base;
    char name[20];
            /*Gets inputs from user.*/
    printf("Please enter the name of the customer: ");
    scanf("%s", name);
    printf("Please enter the age of the customer: ");
    while (!scanf("%d",&age)){
        for(i=0; i<sizeof(age); i++) getchar();
        fflush(stdin);
        printf("\nYour input is invalid ! \n");
        printf("Please enter the age of the customer: ");
    }

    printf("Please enter the label of the customer(0, 1, 2, 3, 4): ");
      while (!scanf("%d", &label) || label > 4 || label < 0){
        getchar();
        fflush(stdin);
        printf("\nYour input is invalid ! \n");
        printf("Please enter the label of the customer: ");
    }

    if (check_sequence(label, person, 0, N-1)){
        for (i=N-2; i>=0 ; i--){
            if (label == person[i].label) {
                for(j = N-1; j > i+1 ; j--){
                    strcpy(person[j].name, person[j-1].name);
                    person[j].age = person[j-1].age;
                    person[j].label = person[j-1].label;
                }
                strcpy(person[i+1].name, name);
                person[i+1].age = age;
                person[i+1].label = label;
                flag = 1;
                break;
            }
        }    
        if (flag == 0){
            for (i=0; i < N-1 ; i++){
                if (label < person[i].label) {
                    for(j = N-1; j > i ; j--){
                        strcpy(person[j].name, person[j-1].name);
                        person[j].age = person[j-1].age;
                        person[j].label = person[j-1].label;
                    }
                    strcpy(person[i].name, name);
                    person[i].age = age;
                    person[i].label = label;
                    break;
                }
                else if (person[i].label > person[i+1].label){
                    for(j = N-1; j > i+1 ; j--){
                            strcpy(person[j].name, person[j-1].name);
                            person[j].age = person[j-1].age;
                            person[j].label = person[j-1].label;
                        }
                    strcpy(person[i+1].name, name);
                    person[i+1].age = age;
                    person[i+1].label = label;
                    break;
                }
            }    
        }
    }

    else {
        int base = check_line(label, person, 0), stop, stop_label;

        if(person[base].label != 5){
            for(i=base; i<N-1; i++){
                if (person[i].label > label ){
                    for(j = N-1; j > i ; j--){
                            strcpy(person[j].name, person[j-1].name);
                            person[j].age = person[j-1].age;
                            person[j].label = person[j-1].label;
                        }
                        strcpy(person[i].name, name);
                        person[i].age = age;
                        person[i].label = label;
                        flag = 1;
                        break;
                }
                else if (!check_sequence(person[i].label, person, base, i-1) && label != person[i].label){
                    for(j = N-1; j > i ; j--){
                            strcpy(person[j].name, person[j-1].name);
                            person[j].age = person[j-1].age;
                            person[j].label = person[j-1].label;
                        }
                        strcpy(person[i].name, name);
                        person[i].age = age;
                        person[i].label = label;
                        flag = 1;
                        break;
                }
            }
        }
        else {
            for(j=N-1 ; j>=0; j--){
                if(person[j].label != 5 && person[j].label != person[j-1].label){
                    stop = j;
                    stop_label = person[j].label;
                    break;
                }
            }
            if (stop_label != label){
                for(j=stop+2 ;j<N-1; j++){
                    if(!check_sequence(stop_label, person, stop+1, j)){
                        strcpy(person[j].name, name);
                        person[j].age = age; 
                        person[j].label=label;
                        flag =1;
                        break;
                    }
                }
            }
            if (flag != 1){                             /*Adds the customer to the end of the sequence.*/
                strcpy(person[base].name, name);
                person[base].age = age; 
                person[base].label=label;
            }
        }
    }
}

system process_customer(system person[]){
    int i;
            /*Removes the customer and arranges sequence.*/
    for(i=0 ; i<N ; i++){
        if(i!=N-1){
            strcpy(person[i].name, person[i+1].name);
            person[i].age = person[i+1].age;
            person[i].label = person[i+1].label;
        }
        else    
            person[i].label = 5;
    }
    
}

int check_sequence(int label, system person[],int n, int limit){   /*Checks if the label can repeat again.*/
    int i, counter= 0;                                              /*Always limit > n */
    for (i=limit ; i>=n; i--){
        if (person[i].label == label)                               /*Helps to organize the sequence considering the limitations.*/
            counter += 1;                                           /*It returns 0 if the label needs to be added to the next row.*/
        else if (counter > 0 && person[i].label != label)
            break;
    }
    switch(label){
        case(0):if (counter < 5) return 1;
                else return 0;
                break;
        case(1):if (counter < 3) return 1;
                else return 0;
                break;
        case(2):if (counter < 3) return 1;
                else return 0;
                break;
        case(3):if (counter < 2) return 1;
                else return 0;
                break;
        case(4):if (counter < 2) return 1;
                else return 0;
                break;
        default:
                break;
    }
}

int check_line(int label, system person[], int n){      /*Finds which row the customer should be added.*/
    int j, base;
    for(j=n; j<N-1; j++){
        if (person[j].label > person[j+1].label ){
            base = j+1;
            break; 
        }
        else if (person[j].label == 5){
            base = j;
            return base;
            break;
        }
    }
    if (!check_sequence(label, person, base, N-1)) 
        return check_line(label, person, base);
    else 
        return base;
}
