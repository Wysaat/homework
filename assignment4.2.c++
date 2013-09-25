#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word {
    char *content;
    struct word *next;
} word;

void insert(char *);
word *head = (word *)malloc(sizeof(word));
word *ptr;

int main()
{
    // char *line = NULL;
    // size_t len = 0;
    // word *head = (word *)malloc(sizeof(word));
    // word *ptr;

    puts("Enter strings to sort:");
    for ( ; ; ) {
        char *line = NULL;
        size_t len = 0;
        getline(&line, &len, stdin);
        char *ptr;
        for (ptr = line; *ptr != '\n'; ptr++)
            ;
        *ptr = 0;
        if (strcmp(line, "END") == 0)
            break;
        insert(line);
    }
    puts("\nresult:");
    for (ptr = head; ptr->next != 0; ptr = ptr->next)
        puts(ptr->next->content);
    return 0;
}

void insert(char *line)
{
    word *newword = (word *)malloc(sizeof(word));
    newword->content = line;
    for (ptr = head; ptr->next != 0; ptr = ptr->next) {
        if (strcmp(line, ptr->next->content) < 0) {
            newword->next = ptr->next;
            ptr->next = newword;
            break;
        }
    }
    if (ptr->next == 0)
        ptr->next = newword;
}