#include <iostream>
#include <ctime>
using namespace std;

class Clock {
    int hour, minute, second;
public:
    int getHour();
    int getMinute();
    int getSecond();
    void set_time(int ,int ,int);
    int *query_time();
};

int Clock::getHour()
{
    return hour;
}

int Clock::getMinute()
{
    return minute;
}

int Clock::getSecond()
{
    return second;
}

void Clock::set_time(int _hour, int _minute, int _second)
{
    hour = _hour;
    minute = _minute;
    second = _second;
}

int *Clock::query_time()
{
    time_t rawtime;

    time(&rawtime);
    struct tm *timeinfo = localtime(&rawtime);

    int _hour = (*timeinfo).tm_hour;
    int _minute = (*timeinfo).tm_min;
    int _second = (*timeinfo).tm_sec;
    int rettime[3] = { _hour, _minute, _second };
    return rettime;
}

int main()
{
    Clock clk;
    int *a = clk.query_time();
    int hour = a[0], minute = a[1], second = a[2];
    cout << "************************************" << endl;
    cout << endl;
    cout << "*        Beijing Time         *" << endl;
    cout << "*        " << hour << ":" << minute << ":" << second << "              *" << endl;
    cout << "************************************" << endl;
    return 0;
}