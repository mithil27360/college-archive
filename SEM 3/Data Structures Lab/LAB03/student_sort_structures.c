#include<stdio.h>

struct Student
{
    char name[50];
    int rollno;
    char grade;
};

void readStudents(struct Student s[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter roll no: ");
        scanf("%d", &s[i].rollno);
        printf("Enter grade: ");
        scanf(" %c", &s[i].grade);
    }
}

void displayStudents(struct Student s[], int n)
{
    int i;
    printf("\nName\t\tRoll No\t\tGrade\n");
    for(i = 0; i < n; i++)
        printf("%s\t\t%d\t\t%c\n", s[i].name, s[i].rollno, s[i].grade);
}

void sortStudents(struct Student s[], int n)
{
    int i, j;
    struct Student temp;
    
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(s[j].rollno > s[j + 1].rollno)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    struct Student s[n];
    
    readStudents(s, n);
    displayStudents(s, n);
    
    sortStudents(s, n);
    
    printf("\nAfter sorting:\n");
    displayStudents(s, n);
    
    return 0;
}