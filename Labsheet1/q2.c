#include <stdio.h>
int main()
{
    char sentence[] = "idea without execution is worthless";
    char *ptr = sentence;
    while (*ptr != 'c')
    {
        ptr++;
    }
    printf("The position of 'c' in the sentence is: %d\n", ptr - sentence + 1);
    return 0;
}