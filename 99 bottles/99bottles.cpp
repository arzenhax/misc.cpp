/* 

A for loop where the counter goes down 

When we know exactly how many times we want to iterate (or when we are counting), 
we can use a for loop instead of a while loop

Incrementing for loop:

for (int i = 0; i < 20; i++) 
{
    Statements
}


Decrementing for loop:

for (int i = 20; i > 0; i--) 
{
    Statements
}



*/ 

#include <iostream>

int main() {
  
  for (int i = 99; i > 0 ; i--)
  /*
  int i = 99 means that we are telling the computer than i starts at 99
  i > 0 means i has to be more than 0, if it isnt more than 0 then this loop doesnt loop
  i-- means i will subtract by 1 every time this loops
   */
  
  {
    std::cout << i << " bottles  of pop on the wall.\n"; 
    std::cout <<"Take one down and pass it around. \n"; 
    std::cout << i-1 << " bottles of pop on the wall.\n";
    
  }
  
  system("pause");  
   return 0;
  
  
}
