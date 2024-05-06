#include <stdio.h>
int readFile(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 0;
    }
    return 1;
}

struct Students
{
    char name[50];
    int roll;
    char address[50];
    long int phone;
};

int main()
{
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    // clear the input buffer
    while (getchar() != '\n')
        ;
    struct Students student[size];

    return 0;
}
