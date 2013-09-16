#include <iostream>
// #include "assignment2.3_4.c++"

using namespace std;

class IntStack {
    int *stack;
    int size;
public:
    IntStack() {
        size = 0;
        int zero = 0;
        stack = &zero;
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
        size = 0;
    }
    void enqueue(int number) {
        queue[size++] = number;
    }
    int dequeue(){
        int returnval = queue[0];
        queue++;
        size--;
    }
};

int  main()
{
    IntStack newstack;
    newstack.push(10);
    cout << newstack.pop() << endl;
    return 0;
}