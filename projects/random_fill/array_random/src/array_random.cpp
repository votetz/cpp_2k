#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    const int sz = 3;
    int arr[sz][sz];

    srand(time(NULL));
    int i;
    for (i = 0; i < sz; ++i)
    {
        int j;
        for (j = 0; j < sz; ++j)
        {
            arr[i][j] = rand() % 101 - 50;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}