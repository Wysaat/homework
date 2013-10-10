#include <stdio.h>

class Singleton {
public:
    void hello() {
        puts("hello");
    }
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
private:
    Singleton() {}
};

int main() {
    Singleton single = Singleton::getInstance();
    single.hello();
    return 0;
}