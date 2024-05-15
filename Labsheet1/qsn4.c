#include <stdio.h>
#include <string.h>

struct Students
{
    char name[50];
    int roll_no;
    float marks;
    int phone_number;
};

#define MAX_STUDENTS 100
struct Students student[MAX_STUDENTS];

// function prototypes
void enter_data(struct Students *student, int size);
void retrive_data(struct Students *student);
void clear_buffer();

int main()
{
    int size, choice;
    printf("Please Choose an Option : \n");
    printf("1. Enter Student Data\n");
    printf("2. Retrive Student Data\n");
    scanf("%d", &choice);
    clear_buffer(); // clear the input buffer

    switch (choice)
    {
    case 1:
        enter_data(student, size);
        break;
    case 2:
        retrive_data(student); // Call retrive_data without passing student array
        break;
    default:
        printf("Invalid Choice\n");
    }

    return 0;
}

void enter_data(struct Students *student, int size)
{
    FILE *file;
    file = fopen("student_data.txt", "r");
    if (file == NULL)
    {
        file = fopen("student_data.txt", "w");
        fclose(file);
    }
    else
    {
        fclose(file);
    }

    file = fopen("student_data.txt", "a");
    if (file == NULL)
    {
        printf("Error in opening the file\n");
        return;
    }

    printf("Enter the number of students: ");
    scanf("%d", &size);
    clear_buffer(); // clear the input buffer

    for (int i = 0; i < size; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%49[^\n]", student[i].name);
        clear_buffer(); // clear the input buffer

        printf("Enter the roll number of student %d: ", i + 1);
        scanf("%d", &student[i].roll_no);
        clear_buffer(); // clear the input buffer

        printf("Enter the marks of student %d: ", i + 1);
        // take in only 2 decimal places
        scanf("%f", &student[i].marks);
        clear_buffer(); // clear the input buffer

        printf("Enter the phone number of student %d: ", i + 1);
        scanf("%d", &student[i].phone_number);
        clear_buffer(); // clear the input buffer

        fprintf(file, "%s;%d;%.2f;%d", student[i].name, student[i].roll_no, student[i].marks, student[i].phone_number);
        if (i != (size - 1))
            fprintf(file, "\n");
    }

    fclose(file);
}

void retrive_data(struct Students *student)
{
    FILE *file;
    file = fopen("student_data.txt", "r");
    if (file == NULL)
    {
        printf("Error in opening the file\n");
        return;
    }

    // check if the file is empty
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0)
    {
        printf("File is empty\n");
        fclose(file);
        return;
    }

    // count the number of students
    int count = 0;
    rewind(file);
    char buffer[100];
    while (fgets(buffer, 100, file) != NULL)
    {
        count++;
    }
    rewind(file);

    // create an array of student structures
    struct Students students[count];
    int i = 0;
    while (fscanf(file, "%49[^;];%d;%f;%d", students[i].name, &students[i].roll_no, &students[i].marks, &students[i].phone_number) != EOF)
    {
        i++;
    }
    fclose(file);

    // sort the details according to the name alphabetically
    for (int j = 0; j < count - 1; j++)
    {
        for (int k = 0; k < count - j - 1; k++)
        {
            if (strcmp(students[k].name, students[k + 1].name) > 0)
            {
                struct Students temp = students[k];
                students[k] = students[k + 1];
                students[k + 1] = temp;
            }
        }
    }

    // print the details
    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Name", "Roll Number", "Marks", "Phone Number");
    for (int j = 0; j < count; j++)
    {
        printf("%-20s\t%-20d\t%-20.2f\t%-20d\n", students[j].name, students[j].roll_no, students[j].marks, students[j].phone_number);
    }
}
void clear_buffer()
{
    while (getchar() != '\n')
        ;
}