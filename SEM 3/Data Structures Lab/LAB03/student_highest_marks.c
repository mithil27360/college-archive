#include<stdio.h>

struct Student
{
    char name[50];
    int rollno;
    float marks;
};

void readStudents(struct Student *s, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Enter name: ");
        scanf("%s", (s + i)->name);
        printf("Enter roll no: ");
        scanf("%d", &(s + i)->rollno);
        printf("Enter marks: ");
        scanf("%f", &(s + i)->marks);
    }
}

void displayStudents(struct Student *s, int n)
{
    int i;
    printf("\nName\t\tRoll No\t\tMarks\n");
    for(i = 0; i < n; i++)
        printf("%s\t\t%d\t\t%.2f\n", (s + i)->name, (s + i)->rollno, (s + i)->marks);
}

void findHighest(struct Student *s, int n)
{
    int i, maxIndex = 0;
    
    for(i = 1; i < n; i++)
    {
        if((s + i)->marks > (s + maxIndex)->marks)
            maxIndex = i;
    }
    
    printf("\nHighest marks:\n");
    printf("Name: %s\n", (s + maxIndex)->name);
    printf("Roll No: %d\n", (s + maxIndex)->rollno);
    printf("Marks: %.2f\n", (s + maxIndex)->marks);
}

int main()
{
    int n;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    struct Student s[n];
    
    readStudents(s, n);
    displayStudents(s, n);
    findHighest(s, n);
    
    return 0;
}