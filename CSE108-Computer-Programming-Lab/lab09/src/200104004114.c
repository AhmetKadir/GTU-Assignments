#include <stdio.h>
#include <string.h>

typedef struct{
    float x1,y1,x2,y2,x3,y3,slope;
}line;

typedef struct{
    float midterm, homework, final;
}grades;

typedef struct{
    char name[20],surname[20];
    int id;
    grades grade;
}students;

typedef struct{
    char name[20],platform[20][20];
    float score;
}games;

void calculation_line(line * a);
void student_info(students * a, grades * ave);
void f_game(games * g);

int main (){
    int this_student,i, flag=0;
    line myline;
    students stud[200];
    grades grade;
    grades average={0.0, 0.0, 0.0};
    games mygame[200];

    calculation_line(&myline);
    printf("\nSlope is %.3f\n", myline.slope);
    printf("\ny3 is %.3f\n", myline.y3);

    student_info(stud,&average);
    printf("\nAverage of midterms: %f\n",average.midterm);
    printf("\nAverage of homeworks: %f\n",average.homework);
    printf("\nAverage of finals: %f\n",average.final);
    printf("\nEnter an id number:");
    scanf("%d",&this_student);
    for(i=0 ; i<200 ; i++){
        if (this_student == stud[i].id){
            printf("\n%s %s\n",stud[i].name, stud[i].surname);
            printf("\nMidterm: %f\nHomework: %f\nFinal: %f\n",stud[i].grade.midterm, stud[i].grade.homework, stud[i].grade.final);
            flag =1;
            break;
        }
    }
    if (flag == 0){
        printf("\nNo students with this id\n");
    }

    f_game(mygame);

    return 0;
}

void calculation_line(line * a){
    printf("Enter values for x1 y1 x2 y2 x3: ");
    scanf("%f %f %f %f %f",&a->x1, &a->y1, &a->x2, &a->y2, &a->x3);
    /*formula y=mx+b*/
    a->slope = (a->y2-a->y1)/ (a->x2 - a->x1);          /*Calculates slope.*/
    a->y3 = a->slope * (a->x3 - a->x1) + a->y1;         /*Calculates the missing point.*/
    
}

void student_info(students * a, grades * ave){
    int i = 0,max;
    printf("How many students are there: ");    /*Gets the max number of students from user.*/
    scanf("%d",&max);
    
    while(i<max){
        printf("Enter the name of the student: ");
        scanf("%s",a[i].name);
        printf("Enter the surname of the student: ");
        scanf("%s",a[i].surname);
        printf("Enter the id number of the student: ");
        scanf("%d",&a[i].id);
        printf("Midterm:");
        scanf("%f",&a[i].grade.midterm);
        ave->midterm += a[i].grade.midterm;
        printf("Homework: ");
        scanf("%f",&a[i].grade.homework);
        ave->homework += a[i].grade.homework;
        printf("Final: ");
        scanf("%f",&a[i].grade.final);
        ave->final += a[i].grade.final;
        i++;
    }
    ave->midterm = ave->midterm / max;
    ave->homework = ave->homework / max;
    ave->final = ave->final / max;
}

void f_game(games * g){
    int i=0, j=0, max, maxp;
    printf("How many games are there: ");   /*Gets the max number of games from user.*/
    scanf("%d",&max);
    while (i<max){
        printf("Enter the name of the game: ");
        scanf("%s",g[i].name);
        scanf("%[^\n]%*c", g[i].name);
        fflush(stdin);
        /*scanf("%[^\n]%*c", string);*/
        printf("How many platforms is the game available: ");               /*Gets the max number of the platform of each game from user.*/
        scanf("%d",&maxp);
        while(j<maxp){
            printf("Enter the name of the platform: ");
            scanf("%s",g[i].platform[j]);
            j++;
        }
        i++;
    }
}