#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info {
    char name[40];
    int  number;
    struct info *next;
} info;

int main()
{
    printf(
"usage:\n\
     -read:    filename\n\
     -add:     student_name student_number\n\
     -delete:  student_number\n\
     -save:    filename\n");

    info *head = (info *)malloc(sizeof(info));

    for ( ; ; ) {
        char command[10];
        char filename[40];
        FILE *file;

        puts("please enter your command:");

        scanf("%s", command);
        if (strcmp(command, "-read") == 0) {
            char name[40];
            int  number;

            scanf("%s", filename);
            if ((file = fopen(filename, "r")) == NULL) {
                perror("open file error");
                exit(0);
            }
            for ( ; ; ) {
                if (fscanf(file, "%s", name) == EOF)
                    break;
                if (fscanf(file, "%d", &number) == EOF)
                    break;

                info *ptr;
                ptr = (info *)malloc(sizeof(info));
                strcpy(ptr->name, name);
                ptr->number = number;

                info *iter;
                for (iter = head; iter->next != 0; iter = iter->next)
                    ;
                iter->next = ptr;
            }
        }
        else if (strcmp(command, "-add") == 0) {
            char name[40];
            int  number;

            scanf("%s", name);
            scanf("%d", &number);
            info *ptr = (info *)malloc(sizeof(info));
            strcpy(ptr->name, name);
            ptr->number = number;

            info *iter;
            for (iter = head; iter->next != 0; iter = iter->next)
                ;
            iter->next = ptr;
        }
        else if (strcmp(command, "-save") == 0) {
            char outfilename[40];
            FILE *outfile;

            scanf("%s", outfilename);
            if ((outfile = fopen(outfilename, "w")) == NULL) {
                perror("open outfile orror");
                exit(0);
            }

            info *iter;
            for (iter = head->next; iter->next != 0; iter = iter->next) {
                fprintf(outfile, "%s ", iter->name);
                fprintf(outfile, "%d\n", iter->number);
            }
            fprintf(outfile, "%s ", iter->name);
            fprintf(outfile, "%d\n", iter->number);
        }
        else if (strcmp(command, "-delete") == 0) {
            int number;

            scanf("%d", &number);

            info *iter;
            for (iter = head; iter->next != 0; iter = iter->next) {
                if ((iter->next)->number == number) {
                    info *tempinfo = iter->next;
                    iter->next = (iter->next->next);
                    free(tempinfo);
                    break;
                }
            }
        }
        else
            exit(0);
    }

    return 0;
}