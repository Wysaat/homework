#include <iostream>
#include "intlist.c++"

using namespace std;

class IntStack {
    int *stack;
    int size;
public:
    IntStack() {
        stack = new int;
        size = 0;
    }
    void push(int number) {
        stack[size++] = number;
    }
    int pop() {
        int returnval = stack[--size];
        stack[size] = 0;
        return returnval;
    }
};

class IntQueue1 {
    int *queue;
    int size;
public:
    IntQueue1() {
        queue = new int;
        size = 0;
    }
    void enqueue(int number) {
        queue[size++] = number;
    }
    int dequeue() {
        int returnval = *queue;
        int *ptr = queue++;
        size--;
        delete ptr;
        return returnval;
    }
};

class IntQueue2 : public IntList {
public:
    IntQueue2(int number) : IntList(number) {

    }
    void enqueue(int number) {
        rightInsert(number);
    }
    int dequeue() {
        int returnval = show(0);
        deleteNode(0);
        return returnval;
    }
};

int  main()
{
    IntStack newstack;
    newstack.push(10);
    newstack.push(22);
    cout << newstack.pop() << endl;
    IntQueue1 newqueue1;
    newqueue1.enqueue(20);
    newqueue1.enqueue(48);
    int val = newqueue1.dequeue();
    cout << val << endl;
    IntQueue2 newqueue2(8);
    newqueue2.enqueue(27);
    cout << newqueue2.dequeue() << endl;
    return 0;
}