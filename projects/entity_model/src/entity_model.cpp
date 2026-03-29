#include "../include/entity_model.hpp"

using namespace std;

int main() {
  SteeringWheel myWheel;
  cout << "Current position " << myWheel.getPosition() << endl;

  myWheel.turnLeft();
  cout << "Current position - " << myWheel.getPosition() << endl;

  myWheel.turnRight();
  cout << "Current position - " << myWheel.getPosition() << endl;

  myWheel.straighten();
  cout << "Current position - " <<myWheel.getPosition() << endl;
  return 0;
};
