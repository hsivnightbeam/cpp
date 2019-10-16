#include <iostream.h>
#include "stackWithArray.h"

int main() {
   Stack<char, 10> s; // 10 chars
   char ch;
   while ((ch = cin.get()) != '\n')
      if (!s.full()) s.push(ch);
   while (!s.empty())
      cout << s.pop();
   cout << endl;
   Stack<double, 4> ds; // 4 doubles
   double d[] =
      {1.0, 3.0, 5.0, 7.0, 9.0, 0.0};
   int i = 0;
   while (d[i] != 0.0 && !ds.full())
      if (!ds.full()) ds.push(d[i++]);
   while (!ds.empty())
      cout << ds.pop() << "  ";
   cout << endl;
   return 0;
}

/*
 *
 * Stack Using a C++ Template: This program takes the simple stack given elsewhere, and writes it in a "templated" version, that is, in generic form using C++ templates.
In the listings below, code related to templates appears in red, while parameters to the template are given in orange.
In the implementation, whenever a stack is instantiated, the actual parameters to the template are textually substituted in for the formal parameters to the stack.
Thus below, first char and 10 are substituted for Typ and MaxStack. Next double and 4 are substituted for Typ and MaxStack.
After this substitution, the compiler compiles the resulting code, which contains only references to specific types, and so can be optimized.
The main function below shows the instantiation of two stacks, the first a stack of up to 10 chars, and the second a stack of up to 4 doubles.
The code pushes items on each stack until they are full, and then pops them for printing until the stack is empty.
As in the earlier programs, this code is simplified, without even any checking for underflow or overflow.
This version allocated the actual memory locations for the stack on the program stack, so here there is no memory leak.

This version will work for user-defined types also. These C++ features allow the creation of much more complex templated "container" classes in the C++ Standard Template Library (STL).









 */