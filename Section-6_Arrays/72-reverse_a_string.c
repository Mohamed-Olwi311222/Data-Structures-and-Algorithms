#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *reverseString(char *str)
{
    int size = strlen(str);
    if (!str || size < 2)
        return (NULL);

    char *new_str = malloc((sizeof(char) * size) + 1);
        if (new_str == NULL)
            return (NULL);

    for(int i = 0; i < size; i++)
    {
        new_str[i] = str[size - i - 1];
    }
    new_str[size] = '\0';
    return (new_str);
}
int main(void)
{
    char *str = "Mohamed && Sama -> true";
    printf("Normal string: %s\n", str);
    char *rev_str = reverseString(str);
    printf("Reversed string: %s\n", rev_str);
    free(rev_str);
    return (0);
}