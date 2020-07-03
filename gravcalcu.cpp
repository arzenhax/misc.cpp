#include <iostream>

int main() {
  
  // this just tells C++ that we are going to use some numbers and variables 
  double weight, planetGrav;
  int planetNumber;

  //we ask a question
  std::cout << "What is your weight?\n";
  //they type an answer
  std::cin >> weight;

  std::cout << "Enter Planet Number:\n";
  std::cout << "1: Venus, 2: Mars, 3: Jupiter, 4: Saturn, 5: Uranus, 6: Neptune\n";
  std::cin >> planetNumber;

  // we tell c++ that were gonna have a number called finalWeight that will equal to these
  double finalWeight = weight * planetGrav;

  /* this function tells c++ that once they enter the planetNumber, the computer will take that number,
  and each "case" has a number next to it, the commands of whatever number matches will be executed*/
  switch(planetNumber) {
    case 1://venus
      planetGrav = 0.90;
      break;
    case 2: //Mars
      planetGrav = 0.39;
      break;
    case 3: //Jupiter
      planetGrav = 2.65;
     break;
    case 4:// Saturn
      planetGrav = 1.13;
      break;
    case 5://Uranus
      planetGrav = 1.09;
     break;
    case 6://Neptune
      planetGrav = 1.43;
      break;
}

  std::cout << "Your final weight on that planet will be " << finalWeight << "\n";


system("pause");  
   return 0;

}