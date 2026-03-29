#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class SteeringWheel {
    string position;

    public:
    void turnLeft()
    {
        position = "left";
        cout << "Turning wheel left" << endl;
    }
    void turnRight()
    {
    position = "right";
        cout << "Turning wheel right" << endl;
    };

    void straighten()
    {
        position = "straight";
        cout << "Straightening the wheel..." << endl;
    };

    string getPosition() const {
        return position;
    };

};

