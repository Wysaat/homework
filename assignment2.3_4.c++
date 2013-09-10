#include <iostream>
using namespace std;

struct Int {
    int value;
    int rank;
    Int *left;
    Int *right;
    /**************************************************************************
     ****** can't put rank at the end *****************************************
     ****** or if rank is 0, it will be used *********************************/
    // int rank;
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
    void deleteNode(int, int );
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

    for (ptr = head; ptr->right != 0; ptr = ptr->right) {
        ptr->rank = current_rank;
        current_rank += 1;
    }
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
    for (ptr = head; ptr->right != 0; ptr = ptr->right)
        if (ptr->rank == rank)
            break;
    newInt->rank = ptr->rank + 1;
    newInt->left = ptr;
    newInt->right = ptr->right;
    (ptr->right)->left = newInt;
    ptr->right = newInt;
    for (ptr = newInt->right; ptr->right != 0; ptr = ptr->right)
        (ptr->rank)++;
    (ptr->rank)++;
}

int main()
{
    IntList newlist(3);
    newlist.leftInsert(88);
    newlist.rightInsert(72);
    newlist.leftInsert(-3);
    newlist.insert(28, 2);
    newlist.test();
    return 0;
}