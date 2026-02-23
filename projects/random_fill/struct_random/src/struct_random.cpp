#include <iostream>
#include <ctime>
using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    const int SIZE = 5;
    Point points[SIZE];

    srand(time(NULL));
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        points[i].x = rand() % 101 - 50;
        points[i].y = rand() % 101 - 50;
    }
    i = 0;
    for (i = 0; i < SIZE; i++)
        cout << "points[" << i << "]: x = " << points[i].x << ", y = " << points[i].y << endl;

    return 0;
}