#include <iostream>
#include <string.h>
using namespace std;

class Student {
    char *name;
    char *number;
public:
    Student(char *_name, char *_number) {
        name = _name;
        number = _number;
    }
    Student() {};
    void setName(char *_name) {
        name = _name;
    }
    char *getName() {
        return name;
    }
    void setNumber(char *_number) {
        number = _number;
    }
    char *getNumber() {
        return number;
    }
};

struct record {
    Student student;
    record *next;
    record(Student _student, record *_next) {
        student = _student;
        next = _next;
    }
    record(record *_next) {
        next = _next;
    }
    record() {};
};

class Students {
    record *head;
    record *ptr;
public:
    Students() {
        head = new record(0);
    }
    void addStudent(Student student) {
        for (ptr = head; ptr->next != 0; ptr = ptr->next)
            ;
        ptr->next = new record(student, 0);
    }
    void deleteStudent(Student student) {
        for (ptr = head; ptr->next != 0; ptr = ptr->next)
            if (strcmp(((ptr->next)->student).getNumber(), student.getNumber()) == 0) {
                record *temp = ptr->next;
                ptr->next = (ptr->next)->next;
                delete temp;
                break;
            }
    }
    void showStudents() {
        for (ptr = head; ptr->next != 0; ptr = ptr->next)
            cout << ((ptr->next)->student).getName() << endl;
    }
};

int main()
{
    Student tom;
    tom.setName("tom");
    cout << tom.getName() << endl;
    tom.setNumber("00001");
    cout << tom.getNumber() << endl;
    Students cs;
    cs.addStudent(tom);
    cs.showStudents();
    Student jerry("jerry", "1024");
    cs.addStudent(jerry);
    cs.showStudents();
    cs.deleteStudent(tom);
    cs.showStudents();
    Student claude("claude", "8888");
    cs.addStudent(claude);
    cout << endl;
    cs.showStudents();
    return 0;
}