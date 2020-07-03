/*
This is the first program ever to run on a stored-program computer (the EDSAC). 
It was written and run by David Wheeler in the computer laboratory at Cambridge University, 
England, on May 6th, 1948, to calculate and print a simple list of squares.
*/

#include <iostream>

int main() {
  
  int i = 0;
  int square = 0;
  



/* 
Notice how this takes no input from a user. 
It only shows text that has already been coded and calculated

The condition (i < 10) will take every number less than 10 and
save it as i
*/
  while (i < 10) {
    
      std::cout << i << "  " << i * i << "\n"; 
/* 
This i++ means add 1 to whatever i is. 
That means when  the while loop executes again, i will be always be a different number
*/
       i++;
  }
system("pause");  
   return 0;

}