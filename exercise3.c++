#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool contains(char *, char *);
bool compare(char *, char *);

bool has(char *str1, char *str2)
{
    int i = 0;
    while (true) {
        while (str2[i] != '*' && str2[i] != 0) {
            if (str2[i] == '-')
                i++;
            i++;
        }
        char *str = (char *)malloc(sizeof(char));
        strcpy(str, str2);
        str[i] = 0;
        if (!contains(str1, str))
            return false;
        str2 += i;
        if (*str2 == 0)
            return true;
        while (*str2 == '*')
            str2++;
    }
}

bool contains(char *str1, char *str2)
{
    int escape = 0;
    if (*str2 == '-') {
        str2++;
        escape = 1;
    }
    while (true) {
        if (!(*str2 == '.' && escape == 0))
            while (*str1 != *str2) {
                if (*str1 == 0)
                    return false;
                str1++;
            }
        char *str = (char *)malloc(sizeof(char));
        strcpy(str, str1);
        int size = strlen(str2);
        int i;
        int countit = 1;
        for (i = 0; str2[i] != 0; i++) {
            if (str2[i] == '-' && countit == 1) {
                size--;
                if (str[i+1] == '-')
                    countit == 0;
            }
            else if (str2[i] == '-')
                countit = 1;
        }
        if (size > 0 && str[size-1] == 0)
            return false;
        str[size] = 0;
        if (compare(str, str2))
            return true;
        str1++;
    }
}

bool compare(char *str1, char *str2)
{
    int i, even = 0;
    for (i = 0; str1[i] != 0; i++) {
        if (even == 0 && str2[i] == '-') {
            str2++;
            if (str2[i+1] == '-')
                even = 1;
        }
        else if (str2[i] == '-')
            even = 0;
        if (str2[i] != '.' && str2[i] != str1[i])
            return false;
    }
    return true;
}

int main()
{
    bool a = contains("ab", ".b");
    bool b = has("d?ggd", "-*gg");
    bool c = compare("a", "ab");
    bool d = has("abc", "-.b");
    bool e = has("ba", "ab");
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);
    printf("%d\n", e);

    char *x = "abc", *y = "ba", *z = "a.b";
    char *chars[] = {"ab", ".b", "-.b", "*b"};
    for (int i = 0; i < 4; i++) {
        printf("%d %d %d\n", has(x, chars[i]),
                             has(y, chars[i]),
                             has(z, chars[i]));
    }
    return 0;
}