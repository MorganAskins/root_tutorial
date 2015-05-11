// Simple class example
#include <iostream>

class particle
{
  // private members
  double mass;			// MeV
  double charge;		
public:
  particle(double mass, double charge){
      this->mass = mass;
      this->charge = charge;
    };
  void say_hello()
    {
      std::cout << "particle mass: " << mass << std::endl;
      std::cout << "particle charge: " << charge << std::endl;
    }
};

int main()
{
  particle electron(0.511, -1);
  electron.say_hello();
  return 0;
}
