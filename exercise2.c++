/* compile using g++ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {
    char word[40];
    int  times;
    info *left;
    info *right;
};

int main()
{
    char command[10];
    char word[100];

char *usage = "usage:\n\
    -read  string (press ENTER and then ctrl-D to end input)\n\
    -reset\n\
    -statistics (show how many times each word appears)\n\
    -exit";

    puts(usage);

    info *head = new info;
    head->right = 0;

    for ( ; ; ) {
        printf("%s\n", "please enter a command:");
        scanf("%s", command);

        if (strcmp(command, "-exit") == 0)
            exit(0);
        else if (strcmp(command, "-read") == 0) {
            int scanfret;
            while (scanf("%s", word) != EOF) {
                info *ptr;
                for (ptr = head; ptr->right != 0; ptr = ptr->right) {
                    if (strcmp((ptr->right)->word, word) == 0) {
                        (ptr->right)->times++;
                        break;
                    }
                    else if (strcmp(word, (ptr->right)->word) < 0) {
                        info *newinfo = new info;
                        strcpy(newinfo->word, word);
                        newinfo->times = 1;
                        (ptr->right)->left = newinfo;
                        newinfo->right = ptr->right;
                        newinfo->left = ptr;
                        ptr->right = newinfo;
                        break;
                    }
                }
                if (ptr->right == 0) {
                    info *newinfo = new info;
                    strcpy(newinfo->word, word);
                    newinfo->times = 1;
                    ptr->right = newinfo;
                    newinfo->left = ptr;
                    newinfo->right = 0;
                }
            }
        }
        else if (strcmp(command, "-reset") == 0) {
            info *ptr;
            for (ptr = head; ptr->right != 0; ptr = ptr->right) {
                delete ptr;
            }
            head->right = 0;
        }
        else if (strcmp(command, "-statistics") == 0) {
            info *ptr;
            for (ptr = head; ptr->right != 0; ptr = ptr->right) {
                printf("word: %s, times: %d\n", (ptr->right)->word, (ptr->right)->times);
            }
        }
        else {
            puts(usage);
        }
    }
}