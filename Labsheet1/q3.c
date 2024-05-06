#include <stdio.h>
struct Students
{
    char name[50];
    float marks;
};
void printStudent(struct Students *student, int size);
void getStudent(struct Students *student, int size);

int main()
{
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    // clear the input buffer
    while (getchar() != '\n')
        ;
    struct Students student[size];
    getStudent(student, size);
    printStudent(student, size);
    return 0;
}

void printStudent(struct Students *student, int size)
{
    printf("%-20s\t%-20s\n", "Name", "Marks");
    for (int i = 0; i < size; i++)
    {
        printf("%-20s\t%-20.2f\n", student[i].name, student[i].marks);
    }
}

void getStudent(struct Students *student, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%[^\n]", student[i].name);
        // clear the input buffer
        while (getchar() != '\n')
            ;
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &student[i].marks);
        while (getchar() != '\n')
            ;
    }
}