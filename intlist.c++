#include <iostream>
using namespace std;

struct Int {
    int value;
    int rank;
    Int *left;
    Int *right;
};

class IntList {
    Int *head;
public:
    IntList(int );
    //~IntList();
    void test();
    void leftInsert(int );
    void rightInsert(int );
    void insert(int, int );
    void deleteNode(int );
    int size();
    int show(int );
};

IntList::IntList(int number) {
    head = new Int;
    head->value = number;
    head->rank = 0;
}

void IntList::test() {
    Int *ptr;
    for (ptr = head; ptr->right != 0; ptr = ptr->right)
        cout << "rank: " << ptr->rank << ", value: " << ptr->value << endl;
    cout << "rank: " << ptr->rank << ", value: " << ptr->value << endl;
}

void IntList::leftInsert(int number) {
    Int *newInt = new Int;
    newInt->value = number;
    newInt->rank = 0;
    newInt->right = head;
    head->left = newInt;
    head = newInt;

    int current_rank = 0;
    Int *ptr;

    for (ptr = head; ptr->right != 0; ptr = ptr->right)
        ptr->rank = current_rank++;
    ptr->rank = current_rank;
}

void IntList::rightInsert(int number) {
    Int *newInt = new Int;
    newInt->value = number;

    Int *ptr;
    for (ptr = head; ptr->right != 0; ptr = ptr->right)
        ;
    ptr->right = newInt;
    newInt->left = ptr;
    newInt->rank = ptr->rank + 1;
}

// insert number after the given rank
void IntList::insert(int number, int rank) {
    Int *newInt = new Int;
    newInt->value = number;

    Int *ptr;
    for (ptr = head; ptr->right != 0 && ptr->rank != rank; ptr = ptr->right)
        ;
    newInt->rank = ptr->rank + 1;
    newInt->left = ptr;
    newInt->right = ptr->right;
    if (ptr->right != 0)
        (ptr->right)->left = newInt;
    ptr->right = newInt;
    if (newInt->right == 0)
        return;
    for (ptr = newInt->right; ptr->right != 0; ptr = ptr->right)
        (ptr->rank)++;
    (ptr->rank)++;
}

void IntList::deleteNode(int rank) {
    Int *ptr;
    for (ptr = head; ptr->right != 0 && ptr->rank != rank; ptr = ptr->right)
        ;
    if (ptr == head) {
        ptr = head->right;
        delete head;
        head = ptr;
    }
    else if (ptr->rank == rank && ptr->right != 0) {
        (ptr->left)->right = ptr->right;
        (ptr->right)->left = ptr->left;
        delete ptr;

        int current_rank = 0;
        for (ptr = head; ptr->right != 0; ptr = ptr->right)
            ptr->rank = current_rank++;
        ptr->rank = current_rank;
    }
    else {
        (ptr->left)->right = 0;
        delete ptr;
    }
}

int IntList::size() {
    Int *ptr;
    for (ptr = head; ptr->right != 0; ptr = ptr->right)
        ;
    int size = ptr->rank + 1;
    return size;
}

int IntList::show(int rank) {
    Int *ptr;
    for (ptr = head; ptr->right != 0 && ptr->rank != rank; ptr = ptr->right)
        ;
    if (ptr->rank == rank)
        return ptr->value;
    else
        return 0;
}