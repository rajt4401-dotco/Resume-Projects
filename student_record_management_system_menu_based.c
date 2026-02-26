#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks1, marks2, marks3;
    int total;
    float average;
    char grade;
};

void calculateResult(struct Student *s) {
    s->total = s->marks1 + s->marks2 + s->marks3;
    s->average = s->total / 3.0;

    if (s->average >= 75)
        s->grade = 'A';
    else if (s->average >= 60)
        s->grade = 'B';
    else if (s->average >= 50)
        s->grade = 'C';
    else
        s->grade = 'D';
}

void displayStudent(struct Student s) {
    printf("\n--- Student Report ---\n");
    printf("Name: %s\n", s.name);
    printf("Total Marks: %d\n", s.total);
    printf("Average: %.2f\n", s.average);
    printf("Grade: %c\n", s.grade);
}

int main() {
    struct Student s;
    int choice;

    printf("===== Student Record Management System =====\n");

    printf("Enter Student Name: ");
    scanf("%s", s.name);

    printf("Enter Marks of 3 Subjects: ");
    scanf("%d %d %d", &s.marks1, &s.marks2, &s.marks3);

    calculateResult(&s);

    do {
        printf("\nMenu:\n");
        printf("1. Display Student Report\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayStudent(s);
                break;
            case 2:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 2);

    return 0;
}