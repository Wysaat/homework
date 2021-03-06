#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class String {
    char *body;
public:
    String(char *content) {
        int size = strlen(content);
        body = new char[size+1];
        strcpy(body, content);
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
    return 0;
}