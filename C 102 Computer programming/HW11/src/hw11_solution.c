/**
 * @file hw11_solution.c
 * @author Ahmet Kadir Aksu
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie_Budget{
    int budget,year;
    char* name;
    struct Movie_Budget* next;
};

struct Movie_Name{
    char* genre, *name;
    double score;
    struct Movie_Name* next;
};

void get_data (char *filep, struct Movie_Budget **head, struct Movie_Name **head2);
void print_movie_list(struct Movie_Budget* Newn, struct Movie_Name* Newn2, int rank1, int rank2);
void print_movie_list_sorttype(struct Movie_Budget* Newn, struct Movie_Name* Newn2, int rank1, int rank2, char* sorttype);
void print_movie_list_sorttype_score(struct Movie_Budget* Newn, struct Movie_Name* Newn2, double rank1, double rank2);
void sorted_year_insert (struct Movie_Budget** head, struct Movie_Budget* newMovie, struct Movie_Name** head2, struct Movie_Name* newMovie2);
void sorted_budget_insert(struct Movie_Budget** head, struct Movie_Budget* newMovie, struct Movie_Name** head2, struct Movie_Name* newMovie2);
int update_movie(struct Movie_Budget* head, struct Movie_Budget* newMovie, struct Movie_Name* head2, struct Movie_Name* newMovie2);
void list_genres(struct Movie_Name* head,char** genres, int *max_p, int frequence[]);
int list_by_year(struct Movie_Budget* head);
int list_by_score(struct Movie_Name* head);
void sorted_score(struct Movie_Name* head, struct Movie_Budget* head2);
void sorted_year(struct Movie_Name* head, struct Movie_Budget* head2);
void sorted_budget(struct Movie_Name* head, struct Movie_Budget* head2);
void sorted_genre(struct Movie_Name* head, struct Movie_Budget* head2);
void sorted_name(struct Movie_Name* head, struct Movie_Budget* head2);
void freep(struct Movie_Budget** head);
void freep2(struct Movie_Name** head);
void swap(int *num1,int *num2);
void swapd(double *num1,double *num2);
void swaps(char **str1, char **str2);
double find_average_scores(struct Movie_Name* head);
int find_a_movie(struct Movie_Budget* head1, struct Movie_Name* head2, char* u_movie);
int single_selection();

int main(){
    int run = 1, option, flag = 0, i=0, max=0, freq[50]={0}, option2, run2 =1, rank, start, end;
    double averageScore, start_d, end_d;
    char* genres_list[50], *u_movie;

    printf("\n-------------------------------------------------\n");  
    printf("|\t\t\tMOVIES\t\t\t|");
    printf("\n-------------------------------------------------\n");
    
    for(i=0; i<50; i++) genres_list[i] = malloc(20*sizeof(char));
    
    struct Movie_Budget *head_budget = NULL;
    struct Movie_Name *head_name = NULL;

    get_data("Movies.txt", &head_budget, &head_name);
    
    for(i=0; i<50; i++) strcpy(genres_list[i],"empty");

    averageScore = find_average_scores(head_name);
    list_genres(head_name, genres_list, &max, freq);

    while(run){
        printf("\n\n1. List of the Sorted Data");
        printf("\n2. List of the Genres");
        printf("\n3. List of the Movie Through the Years");
        printf("\n4. List of the Movie Through the Scores");
        printf("\n5. All informations of a Single Movie");
        printf("\n6. Average of the IMDB Scores");
        printf("\n7. Frequence of the Genres");
        printf("\n8. Exit\n");
        printf("\nPlease Select an operation: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                run2 = 1;
                while(run2){
                    printf("\n1. Budget");
                    printf("\n2. Genre");
                    printf("\n3. Name");
                    printf("\n4. Score");
                    printf("\n5. Year");
                    printf("\n6. Go back");
                    printf("\nPlease select an operation: ");
                    scanf("%d",&option2);
                    switch(option2){
                        case 1:
                            sorted_budget(head_name, head_budget);
                            if (single_selection()){
                                printf("Enter the index: ");
                                scanf("%d",&rank);
                                printf("\n\n%d.", rank);
                                print_movie_list(head_budget, head_name, rank, rank);
                            }
                            else {
                                printf("Enter start value: ");
                                scanf("%d",&start);
                                printf("Enter end  value: ");
                                scanf("%d",&end);
                                print_movie_list_sorttype(head_budget, head_name, start, end, "budget");
                            }
                            run2=0;
                            break;
                        case 2:
                            sorted_genre(head_name, head_budget);
                            if (single_selection()){
                                printf("Enter the index: ");
                                scanf("%d",&rank);
                                printf("\n\n%d.", rank);

                                print_movie_list(head_budget, head_name, rank, rank);
                            }
                            else {
                                printf("Enter start value: ");
                                scanf("%d",&start);
                                printf("Enter end value: ");
                                scanf("%d",&end);
                                print_movie_list(head_budget, head_name, start, end);
                            }
                            run2=0;
                            break;
                        case 3:
                            sorted_name(head_name, head_budget);
                            if (single_selection()){
                                printf("Enter the index: ");
                                scanf("%d",&rank);
                                printf("\n\n%d.", rank);
                                print_movie_list(head_budget, head_name, rank, rank);
                            }
                            else {
                                printf("Enter start value: ");
                                scanf("%d",&start);
                                printf("Enter end value: ");
                                scanf("%d",&end);
                                print_movie_list(head_budget, head_name, start, end);
                            }
                            run2=0;
                            break;                        
                        case 4:
                            sorted_score(head_name, head_budget);
                            if (single_selection()){
                                printf("Enter the index: ");
                                scanf("%d",&rank);
                                printf("\n\n%d.", rank);
                                print_movie_list(head_budget, head_name, rank, rank);
                            }
                            else {
                                printf("Enter start value: ");
                                scanf("%lf",&start_d);
                                printf("Enter end value: ");
                                scanf("%lf",&end_d);
                                print_movie_list_sorttype_score(head_budget, head_name, start_d, end_d);
                            }
                            run2=0;
                            break;
                        case 5:
                            sorted_year(head_name, head_budget);
                            if (single_selection()){
                                printf("Enter the index: ");
                                scanf("%d",&rank);
                                printf("\n\n%d.", rank);
                                print_movie_list(head_budget, head_name, rank, rank);
                            }
                            else {
                                printf("Enter start value: ");
                                scanf("%d",&start);
                                printf("Enter end value: ");
                                scanf("%d",&end);
                                print_movie_list_sorttype(head_budget, head_name, start, end, "year");
                            }
                            run2=0;
                            break;
                        case 6: 
                            run2 = 0;
                            break;
                        default:
                            printf("\nTRY AGAIN!\n");
                            run2 = 1;
                            break;    
                    }
                }
                break;
            case 2: 
                for(i=0; i<max; i++){
                    printf("\n%s",genres_list[i]);
                }
                break;
            case 3: 
                while(list_by_year(head_budget));
                break;
            case 4:
                while(list_by_score(head_name));
                break;
            case 5:
                flag = 1;
                u_movie = malloc(150*sizeof(char));
                while(flag){
                    printf("Please enter the name of the movie:");
                    scanf(" %[^\n]s", u_movie);
                    fflush(stdin);
                    flag = find_a_movie(head_budget, head_name, u_movie);
                }
                free(u_movie);
                break;
            case 6:
                printf("\nAverage is %f",averageScore);
                break;
            case 7: 
                for(i=0; i<max; i++){
                    printf("\n%-10s%-10d",genres_list[i],freq[i]);
                }
                break;
            case 8: 
                run = 0;
                break;
            default:
                printf("\nTRY AGAIN.\n");
                break;
        }
    }
    freep(&head_budget);
    freep2(&head_name);
    for(i=0; i<50; i++) free(genres_list[i]);
    return 0;
}

void get_data(char *filep, struct Movie_Budget **head, struct Movie_Name **head2){
    FILE* source;
    char* f;
    char *token;
    f = malloc(150*(sizeof(char)));
        /*Opens file to read*/
    source = fopen(filep,"r");
        /*Exit if file cannot be reached*/
    if (source == NULL){
        printf("\nCould not open the file");
        printf("\nTerminating...\n");
        exit(0);
    }
        /* Takes the first line. */
    fgets(f, 150, source);
    while(fgets(f,150, source) != NULL){
        struct Movie_Budget* new_movie = malloc(sizeof(struct Movie_Budget));
        struct Movie_Name* new_movie2 = malloc(sizeof(struct Movie_Name));
        
                /*Saves informations to new_movie and new_moive2.*/
        token = strtok(f ,",");
        new_movie->budget = atoi(token);
        if(new_movie->budget == 0) new_movie->budget = -1;
        
        token = strtok(NULL, ",");
        new_movie2->genre = malloc((strlen(token)+1)*sizeof(char));
        strcpy(new_movie2->genre, token );
        
        token = strtok(NULL, ",");
        new_movie->name = malloc((strlen(token)+1)*sizeof(char));
        new_movie2->name = malloc((strlen(token)+1)*sizeof(char));
        strcpy(new_movie->name, token);
        strcpy(new_movie2->name, token);
        
        token = strtok(NULL ,",");
        new_movie2->score = strtod (token,NULL);
        
        token = strtok(NULL,",");
        new_movie->year = atoi(token);
        
        new_movie->next = NULL;
        new_movie2->next = NULL;

                /*Checks if the movie is already exist, if it does, remove the previous one.*/
        update_movie((*head), new_movie, (*head2), new_movie2);
                /*Inserts the new movie into the linked list.*/
        sorted_year_insert(&(*head), new_movie, &(*head2), new_movie2);
    }
    
    free(f);
    printf("\nFile read succesfully.");
    
}

void print_movie_list(struct Movie_Budget* Newn, struct Movie_Name* Newn2, int rank1, int rank2){
    int i=0;
            /*Checks if the list is empty*/
    if (Newn == NULL) printf("\nThe list is null\n");
            /*Prints movies for values in the given range.*/
    while(Newn != NULL && i <= rank2){
        if(i>=rank1 && i <= rank2){
            if(Newn->budget == -1) printf("\nUnknown\t %-10s %-40s %-10.1f %-10d ",Newn2->genre, Newn->name, Newn2->score, Newn->year);
            else printf("\n%-5d %-10s %-40s %-10.1f %-10d ",Newn->budget, Newn2->genre, Newn->name, Newn2->score, Newn->year);
        }
        Newn = Newn->next;
        Newn2 = Newn2->next;
        i++;
    }
}

void print_movie_list_sorttype(struct Movie_Budget* Newn, struct Movie_Name* Newn2, int rank1, int rank2, char* sorttype){
            
    if (Newn == NULL) printf("\nThe list is null\n");
            /*Checks sort type*/
    if(strcmp(sorttype,"year")== 0){
        while(Newn != NULL){
                    /*Prints movies for values in the given range.*/
            if(Newn->year >= rank1 && Newn->year <= rank2){
                        /*If budget is unknown print unknown as string*/
                if(Newn->budget == -1) printf("\nUnknown\t %-10s %-40s %-10.1f %-10d ",Newn2->genre, Newn->name, Newn2->score, Newn->year);
                else printf("\n%-5d %-10s %-40s %-10.1f %-10d ",Newn->budget, Newn2->genre, Newn->name, Newn2->score, Newn->year);
            }
            else if(Newn->year > rank2) return;
            Newn = Newn->next;
            Newn2 = Newn2->next;
            
        }
    }

    else if(strcmp(sorttype,"budget")== 0){
        while(Newn != NULL){
                    /*Prints movies for values in the given range.*/
            if(Newn->budget >= rank1 && Newn->budget <= rank2){
                        /*If budget is unknown prints unknown as string*/
                if(Newn->budget == -1) printf("\nUnknown\t %-10s %-40s %-10.1f %-10d ",Newn2->genre, Newn->name, Newn2->score, Newn->year);
                else printf("\n%-5d %-10s %-40s %-10.1f %-10d ",Newn->budget, Newn2->genre, Newn->name, Newn2->score, Newn->year);
            }
            else if(Newn->budget > rank2) return;
            Newn = Newn->next;
            Newn2 = Newn2->next;
        }
    }
}

void print_movie_list_sorttype_score(struct Movie_Budget* Newn, struct Movie_Name* Newn2, double rank1, double rank2){
    if (Newn == NULL) printf("\nThe list is null\n");
    while(Newn != NULL){
                /*Prints movies for values in the given range.*/
        if(Newn2->score >= rank1 && Newn2->score <= rank2){
                    /*If budget is unknown prints unknown as string*/
            if(Newn->budget == -1) printf("\nUnknown\t %-10s %-40s %-10.1f %-10d ",Newn2->genre, Newn->name, Newn2->score, Newn->year);
            else printf("\n%-5d %-10s %-40s %-10.1f %-10d ",Newn->budget, Newn2->genre, Newn->name, Newn2->score, Newn->year);
        }
        else if(Newn2->score > rank2) return;
        Newn = Newn->next;
        Newn2 = Newn2->next;
    }
}

void sorted_year_insert (struct Movie_Budget** head, struct Movie_Budget* newMovie, struct Movie_Name** head2, struct Movie_Name* newMovie2){
            /*Recursive sorted insert function(according to movies years)*/
            /*If the linked list is empty, inserts the new movie to the beginning of the list.*/
    if (*head == NULL){
        *head = newMovie;
        *head2 = newMovie2;
    } 
    
    else{
        if(newMovie->year > (*head)->year){
            struct Movie_Budget* temp = *head;
            *head = newMovie;
            newMovie->next = temp;
            struct Movie_Name* temp2 = *head2;
            *head2 = newMovie2;
            newMovie2->next = temp2;
        }
                /*If the years are the same, sorts according to budgets.*/
        else if(newMovie->year == (*head)->year ){
            sorted_budget_insert(&(*head), newMovie, &(*head2), newMovie2);
        }
                /*Pass the next node the function.*/
        else    sorted_year_insert(&(*head)->next, newMovie, &(*head2)->next, newMovie2);
    }
}

void sorted_budget_insert (struct Movie_Budget** head, struct Movie_Budget* newMovie, struct Movie_Name** head2, struct Movie_Name* newMovie2)
{
            /*Recursive function to sorted insert according to movie budgets*/
    if (*head == NULL){
        *head = newMovie;
        *head2 = newMovie2;
    } 
            
    else{
                /*If new movie has higher budget than the current movie, inserts new movie.*/
        if(newMovie->budget >= (*head)->budget && newMovie->year == (*head)->year){
            struct Movie_Budget* temp = *head;
            *head = newMovie;
            newMovie->next = temp;
            struct Movie_Name* temp2 = *head2;
            *head2 = newMovie2;
            newMovie2->next = temp2;
        }   
                /*If new movie's year is bigger than current movie, inserts the new movie.*/
        else if(newMovie->year > (*head)->year){
            struct Movie_Budget* temp = *head;
            *head = newMovie;
            newMovie->next = temp;
            struct Movie_Name* temp2 = *head2;
            *head2 = newMovie2;
            newMovie2->next = temp2;
        }
                /*Pass the next node the function.*/
        else    sorted_budget_insert(&(*head)->next, newMovie, &(*head2)->next, newMovie2);
    }
}

int update_movie(struct Movie_Budget* head, struct Movie_Budget* newMovie, struct Movie_Name* head2, struct Movie_Name* newMovie2){
            /*Recursive function to delete repeated movie*/
            /*If linked list is empty, exits program.*/
    if (head == NULL)      return 0;
            /*If next link in the linked list is empty, exits program.*/
    else if (head->next == NULL) return 0;
    
            /*If new movie name and current movie names are the same, removes the current one*/
            /*Then we will insert the new movie in get_data function*/
    else if(strcmp(head->next->name,newMovie->name)==0){
        struct Movie_Budget* temp = head->next->next;
        head->next = temp;
        struct Movie_Name* temp2 = head2->next->next;
        head2->next = temp2;
        return 1;
    }   
            /*Pass next node to the function*/
    else return update_movie(head->next, newMovie, head2->next, newMovie2);
}

void list_genres(struct Movie_Name* head, char** genres, int *max_p, int frequence[]){
            /*Function to save genres of the movies into an array*/
    int flag, i;
    
    while(head != NULL){
        flag = 0; 
        for(i=0 ; i<50; i++){
                    /*If the genre has already been entered, adds 1 to the frequence of that genre and breaks the for loop for this movie*/
            if(strcmp(genres[i], head->genre)==0){
                frequence [i] += 1; 
                flag = 1;
                break;
            }    
            else if(strcmp(genres[i],"empty") == 0)   break;
        }
                /*If genre type is new, add to the genres array.*/
        if (flag == 0){
            frequence [*max_p] += 1;
            strcpy(genres[*max_p], head->genre);
            (*max_p) += 1;
        }
                /*Go for the next one.*/
        head = head->next;
    }
}

int list_by_year(struct Movie_Budget* head){
    int u_year, sel, flag = 0;
            /*Function to print the movies according to users years choice*/
    printf("\nEnter a year: ");
    scanf("%d",&u_year);
    printf("\nUntil (0) or Since (1) %d: ",u_year);
    scanf("%d",&sel);
    while(head != NULL){
        if (sel==1){
                    /*Prints the movies, which has bigger years than the input value*/
            if (head->year >= u_year){
                printf("\n%s",head->name);
                flag = 1;
            }
            head = head->next;
        }
        else if (sel == 0){
                    /*Prints the movies, which has smaller years than the input value*/
            if (head->year <= u_year) {
                printf("\n%s",head->name);
                flag = 1;
            }
            head = head->next;                        
        }
        else {
            printf("\nTRY AGAIN !\n");
            return 1;
        }  
    }
            /*If there is no movie in given range, gives error.*/
    if (flag == 0) {
        printf("\nTRY AGAIN\n");
        return 1;
    }
    else return 0;
}

int list_by_score(struct Movie_Name* head){
    double u_score;
    int sel, flag = 0;
            /*Function to print the movies according to users score choice*/
    printf("\nEnter a score: ");
    scanf("%lf",&u_score);
    printf("\nLess (0) or Greater (1) %1.f: ",u_score);
    scanf("%d",&sel);
    while(head != NULL){
        if (sel==1){
                    /*Prints the movies, which has higher scores than the input value*/
            if (head->score >= u_score){
                printf("\n%s",head->name);
                flag = 1;
            }
            head = head->next;
        }
        else if (sel == 0){
                    /*Prints the movies, which has lower scores than the input value*/
            if (head->score <= u_score) {
                printf("\n%s",head->name);
                flag = 1;
            }
            head = head->next;                        
        }
        else {
            printf("\nTRY AGAIN !\n");
            return 1;
        }  
    }
            /*If there is no movie in given range, gives error.*/
    if (flag == 0) {
        printf("\nTRY AGAIN\n");
        return 1;
    }
    else return 0;
}

void sorted_score(struct Movie_Name* head, struct Movie_Budget* head2){
            /*Function to sort the linked list according to scores*/
    int control= 1;
    struct Movie_Name* comp;
    struct Movie_Name* temp = NULL;   
    struct Movie_Budget* comp2;

    while(control){
        control = 0;
        comp = head;
        comp2 = head2;
        /*Compares first node of the linked list till the end and sort.*/
        while(comp->next != temp){
            if(comp->score > comp->next->score){
                swapd(&comp->score,&comp->next->score);
                swap(&comp2->year,&comp2->next->year);
                swap(&comp2->budget,&comp2->next->budget);
                swaps(&comp2->name, &comp2->next->name);
                swaps(&comp->name, &comp->next->name);
                swaps(&comp->genre, &comp->next->genre);
                control = 1;
            }
            comp = comp->next;
            comp2= comp2->next;
        }
        temp = comp;
    }
}

void sorted_year(struct Movie_Name* head, struct Movie_Budget* head2){
            /*Function to sort the linked list according to years*/
    int control= 1;
    struct Movie_Name* comp;
    struct Movie_Budget* comp2;
    struct Movie_Budget* temp2 = NULL;   


    while(control){
        control = 0;
        comp = head;
        comp2 = head2;
                
                /*Compares first node of the linked list till the end and sorts.*/
        while(comp2->next != temp2){
            if(comp2->year > comp2->next->year){
                swapd(&comp->score,&comp->next->score);
                swap(&comp2->year,&comp2->next->year);
                swap(&comp2->budget,&comp2->next->budget);
                swaps(&comp2->name, &comp2->next->name);
                swaps(&comp->name, &comp->next->name);
                swaps(&comp->genre, &comp->next->genre);
                control = 1;
            }
            comp = comp->next;
            comp2= comp2->next;
        }
        temp2 = comp2;
    }
}

void sorted_genre(struct Movie_Name* head, struct Movie_Budget* head2){
            /*Function to sort the linked list according to genres of the movies.*/
    int control= 1;
    struct Movie_Name* comp;
    struct Movie_Name* temp = NULL;   
    struct Movie_Budget* comp2;

    while(control){
        control = 0;
        comp = head;
        comp2 = head2;
                /*Compares first node of the linked list till the end and sorts.*/
        while(comp->next != temp){
            if(strcmp(comp->genre,comp->next->genre) > 0){
                swapd(&comp->score,&comp->next->score);
                swap(&comp2->year,&comp2->next->year);
                swap(&comp2->budget,&comp2->next->budget);
                swaps(&comp2->name, &comp2->next->name);
                swaps(&comp->name, &comp->next->name);
                swaps(&comp->genre, &comp->next->genre);
                control = 1;
            }
            comp = comp->next;
            comp2= comp2->next;
        }
        temp = comp;
    }
}

void sorted_budget(struct Movie_Name* head, struct Movie_Budget* head2){
            /*Function to sort the linked list according to budget of the movies.*/
    int control= 1;
    struct Movie_Name* comp;
    struct Movie_Budget* comp2;
    struct Movie_Budget* temp2 = NULL;   


    while(control){
        control = 0;
        comp = head;
        comp2 = head2;
                /*Compares first node of the linked list till the end and sorts.*/
        while(comp2->next != temp2){
            if(comp2->budget > comp2->next->budget){
                swapd(&comp->score,&comp->next->score);
                swap(&comp2->year,&comp2->next->year);
                swap(&comp2->budget,&comp2->next->budget);
                swaps(&comp2->name, &comp2->next->name);
                swaps(&comp->name, &comp->next->name);
                swaps(&comp->genre, &comp->next->genre);
                control = 1;
            }
            comp = comp->next;
            comp2= comp2->next;
        }
        temp2 = comp2;
    }
}

void sorted_name(struct Movie_Name* head, struct Movie_Budget* head2){
            /*Function to sort the linked list according to names of the movies.*/
    int control= 1;
    struct Movie_Name* comp;
    struct Movie_Name* temp = NULL;   
    struct Movie_Budget* comp2;


    while(control){
        control = 0;
        comp = head;
        comp2 = head2;
                /*Compares first node of the linked list till the end and sorts.*/
        while(comp->next != temp){
            if(strcmp(comp->name, comp->next->name) > 0){
                swapd(&comp->score,&comp->next->score);
                swap(&comp2->year,&comp2->next->year);
                swap(&comp2->budget,&comp2->next->budget);
                swaps(&comp2->name, &comp2->next->name);
                swaps(&comp->name, &comp->next->name);
                swaps(&comp->genre, &comp->next->genre);
                control = 1;
            }
            comp = comp->next;
            comp2= comp2->next;
        }
        temp = comp;
    }
}

void freep(struct Movie_Budget** head){
            /*Function to free allocated memory for the linked list.*/
    if ((*head)!=NULL && (*head)->next != NULL) freep(&(*head)->next);
    free(*head);
}

void freep2(struct Movie_Name** head){
            /*Function to free allocated memory for the linked list.*/
    if ((*head)!=NULL && (*head)->next != NULL) freep2(&(*head)->next);
    free(*head);
}

void swap(int *num1,int *num2){
            /*Function to swap two integers.*/
    int temp1;
    temp1 = *num1;
    *num1 = *num2;
    *num2 = temp1;
}

void swapd(double *num1,double *num2){
            /*Function to swap two double values.*/
    double temp1;
    temp1 = *num1;
    *num1 = *num2;
    *num2 = temp1;
}

void swaps(char **str1, char **str2){
            /*Function to swap two strings.*/
    char *temp;
    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

double find_average_scores(struct Movie_Name* head){
            /*Function to calculate the average scores of the movies*/
    double ave=0;
    int counter=0;
    while(head != NULL){
        ave += head->score;
        counter++;
        head = head->next;
    }
    ave = ave/ counter;
    return ave;
}

int find_a_movie(struct Movie_Budget* head1, struct Movie_Name* head2, char* u_movie){
            /*Function to print all informations for a movie*/
    printf("\nlooking for :'%s' ...\n",u_movie);
    while(head1 != NULL){
                /*If name is the same, prints the informations about the movie.*/
        if(strcmp(head1->name, u_movie)== 0){
            if (head1->budget == -1) printf("\nBudget:\tUnknown");
            else printf("\nBudget:\t%-5d",head1->budget);
            printf("\nGenre:\t%-5s",head2->genre);
            printf("\nName:\t%-5s",head1->name);
            printf("\nScore:\t%-5.1f",head2->score);
            printf("\nYear:\t%-5d",head1->year);
            return 0;
        }
        else {
            head1 = head1->next;
            head2 = head2->next;
            return 0;
        }
                /*If there is no movie with the entered name, prints error.*/
        if (head1 == NULL) {
            printf("NO MATCHES FOUND\nTRY AGAIN\n");
            return 1;
        }
    }
    return 1;
}

int single_selection(){
    int selection, running = 1;
    while(running){
        printf("\n1. Single selection: ");
        printf("\n2. Multiple selection: ");
        printf("\nEnter your selection: ");
        scanf("%d", &selection);
        switch (selection){
            case 1: 
                return 1;
                break;
            case 2:
                return 0;
                break;
            default:
                printf("\nTRY AGAIN \n");
                break;
        }
    }
    return selection;
}