#include <stdio.h>

int main()
{
    double avg_month, avg_year, avg_over_years, total_expends;
    int choice, interval;
    printf("Please select an option:\n");
    printf("1. Calculate Average Expenditure Of A Month.\n");
    printf("2. Calculate Average Expenditure Of A Year\n");
    printf("3. Calculate Average Expenditure Over Years\n");
    printf("4. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter number of months: ");
        scanf("%d", &interval);
        printf("Enter the total expenditure:");
        scanf("%lf", &total_expends);
        avg_month = total_expends / interval;
        printf("Average expenditure of a month: %.2lf\n", avg_month);
        break;
    case 2:
        printf("Enter number of years: ");
        scanf("%d", &interval);
        printf("Enter the total expenditure:");
        scanf("%lf", &total_expends);
        avg_year = total_expends / interval;
        printf("Average expenditure of a year: %.2lf\n", avg_year);
        break;
    case 3:
        printf("Enter number of years: ");
        scanf("%d", &interval);
        printf("Enter the total expenditure:");
        scanf("%lf", &total_expends);
        avg_over_years = total_expends / interval;
        printf("Average expenditure over years: %.2lf\n", avg_over_years);
        break;
    case 4:
        printf("Exiting...\n");
        break;
    }

    return 0;
}