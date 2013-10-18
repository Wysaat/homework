#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

class Singleton {
    int number;
public:
    static Singleton& getInstance() {
        static Singleton instance;
        instance.number = 0;
        return instance;
    }
    void hello() {
        puts("hello");
    }
    void count() {
        number++;
    }
    void getNumber() {
        printf("%d\n", number);
    }
private:
    Singleton() {};
};

class Time {
    int hour, minute, second;
public:
    Time(int hour, int minute, int second)
        : hour(hour), minute(minute), second(second) {}
    Time() {}
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }
    void setHour(int hour) { this->hour = hour; }
    void setMinute(int minute) { this->minute = minute; }
    void setSecond(int second) { this->second = second; }
    void show() {
        printf("%d: %d: %d\n", getHour(), getMinute(), getSecond());
    }
    Time operator-(Time another) {
        Time tmp;
        tmp.hour = hour - another.hour;
        tmp.minute = minute - another.minute;
        tmp.second = second - another.second;
        if (tmp.second < 0) {
            tmp.second += 60;
            tmp.minute -= 1;
        }
        if (tmp.minute < 0) {
            tmp.minute += 60;
            tmp.hour -= 1;
        }
        if (tmp.hour < 0) {
            tmp.hour += 24;
        }
        return tmp;
    }
    bool operator>(Time another) {
        if (hour > another.hour) return true;
        if (hour < another.hour) return false;
        if (minute > another.minute) return true;
        if (minute < another.minute) return false;
        if (second > another.minute) return true;
        else return false;
    }
    bool operator<(Time another) {
        if (another > *this)
            return true;
        return false;
    }
    bool operator==(Time another) {
        if ((*this > another) || (*this < another))
            return false;
        return true;
    }
    bool operator>=(Time another) {
        return !(*this < another);
    }
    bool operator<=(Time another) {
        return !(*this > another);
    }
    Time operator++() {
        Time subber(23, 59, 59);
        *this = *this - subber;
        return *this;
    }
    Time operator++(int) {
        Time tmp = *this;
        Time subber(23, 59, 59);
        *this = *this - subber;
        return tmp;
    }
    Time operator--() {
        Time subber(0, 0, 1);
        *this = *this - subber;
        return *this;
    }
    Time operator--(int) {
        Time tmp = *this;
        Time subber(0, 0, 1);
        *this = *this - subber;
        return tmp;
    }
    // friend std::istream& operator>>(std::istream&, Time);
};

std::ostream& operator<<(std::ostream &out, Time t) {
    out << t.getHour() << ": "
        << t.getMinute() << ": "
        << t.getSecond() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Time t) {
    std::string hour, minute, second;
    in >> hour >> minute >> second;
    t.setHour(atoi(hour.c_str()));
    t.setMinute(atoi(minute.c_str()));
    t.setSecond(atoi(second.c_str()));
    return in;
}

int main() {
    Singleton single = Singleton::getInstance();
    Singleton single2 = Singleton::getInstance();
    single.count();
    single2.hello();
    single.getNumber();
    single2.getNumber();
    single.getNumber();
    Time now(6, 25, 30);
    now.show();
    Time then(23, 8, 47);
    then.show();
    Time delta = now - then;
    delta.show();
    printf("%d\n", now > then);
    printf("%d\n", now < then);
    printf("%d\n", then < now);
    ++then;
    then.show();
    Time a(23, 59, 59);
    (then - a).show();
    std::cout << "now: " << now;
    Time empty;
    std::cin >> empty;
    std::cout << "empty is " << empty;
    return 0;
}