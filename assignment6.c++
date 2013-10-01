#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class String {
    char *body;
public:
    String(char *content) {
        init(content);
    }

    String(int number) {
        char content[50];
        sprintf(content, "%d", number);
        init(content);
    }

    String(float number) {
        char content[50];
        sprintf(content, "%f", number);
        init(content);
    }

    String(double number) {
        char content[50];
        sprintf(content, "%f", number);
        init(content);
    }

    void init(char *content) {
        int size = strlen(content);
        body = new char[size+1];
        strcpy(body, content);
        cout << "constructing a String object" << endl;
    }

    bool hasOne(char *another) {
        for (int i = 0; *(body + i) != 0; i++) {
            for (int j = 0; ; j++) {
                if (*(another + j) == 0)
                    return true;
                else if (*(body + i + j) != *(another + j))
                    break;
            }
        }
        return false;
    }

    char *content() {
        return body;
    }

    bool hasOne(String another) {
        return String::hasOne(another.content());
    }
};

int main()
{
    String tom("tommmi");
    String jerry("jerry");
    String aaaaa("aaakkk");
    cout << tom.hasOne("tom") << endl;
    cout << tom.hasOne("ton") << endl;
    cout << tom.hasOne("tommmis") << endl;
    cout << tom.hasOne("mm") << endl;
    String strings[] = {tom, jerry, aaaaa};
    for (int i = 0; i < 3; i++) {
        if (strings[i].hasOne("aa"))
            cout << "string[" << i << "] has " << "\"aa\"" << endl;
    }
    String carl("to");
    cout << carl.content() << endl;
    cout << tom.hasOne(carl) << endl;
    String *raz = new String("raz");
    String kilo(1024);
    String two(2);
    cout << kilo.content() << endl;
    cout << kilo.hasOne(two) << endl;
    String three(3);
    cout << kilo.hasOne(two) << " " << kilo.hasOne(three) << endl;
    String pie(3.14);
    cout << pie.content() << endl;
    return 0;
}