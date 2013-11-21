#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct charList {
    char text[1024];
    charList *next;
};

class Member {
    int number;
    char *name;
    charList *jobs;
public:
    Member(int number, char *name) {
        this->number = number;
        this->name = name;
        charList *jobs = (charList *)malloc(sizeof(charList));
        jobs->next = 0;
    }

    void addJob(char *job) {
        charList *newJob = (charList *)malloc(sizeof(charList));
        strcpy(newJob->text, job);
        newJob->next = 0;
        charList *ptr = jobs;
        while (ptr->next != 0)
            ptr = ptr->next;
        ptr->next = newJob;
    }

    void deleteJob(char *job) {
        charList *ptr= jobs;
        while (ptr->next != 0) {
            if (strcmp(ptr->next->text, job) == 0) {
                charList *tmp = ptr->next;
                ptr->next = ptr->next->next;
                free(tmp);
            }
        }
    }

    void print() {
        printf("number: %d\n", number);
        printf("name:   %s\n", name);
        charList *ptr = jobs;
        while (ptr->next != 0) {
            printf("%s\n", ptr->next->text);
            ptr = ptr->next;
        }
    }
};

class Leader {
    int number;
    char *name;
    Member *group;

public:
    void addMember(Member newMember) {
    }

    void transferMember(Member member, Leader another_leader) {
    }

    void addJob(Member member, char *newJob) {
    }

    void deleteJob(Member member, char *job) {
    }

    void print() {
    }
};

int main()
{
    Member Tom(324, "Tom");
    Tom.addJob("google");
    Tom.print();
    return 0;
}