/*
 * Project : Complex numbers in C++
 * File    : main.cpp
 * Author  : Luc Wachter
 *
 * Test program for simple complex numbers class.
 */

#include <cstdlib>
#include <iostream>
#include "ComplexNumber.hpp"

using namespace std;

int main() {
   ComplexNumber<int> cn(1, 2);
   ComplexNumber<> im(0, 4.3);
   double mul = 2;

   cout << cn << " + 4 = " << cn + 4 << endl;
   cout << cn << " - 11 = " << cn - 11 << endl;
   cout << cn << " + " << im << " = " << cn + im << endl;
   cout << endl;

   cout << cn << " * " << mul << " = " << cn * mul << endl;
   cout << cn << " / " << mul << " = " << cn / mul << endl;
   cout << cn << " * " << im << " = " << cn * im << endl;
   cout << cn << " / " << im << " = " << cn / im << endl;
   cout << endl;

   cout << "Module of " << cn << " is " << cn.getModule() << endl;
   cout << "Module of " << im << " is " << im.getModule() << endl;
   cout << "Argument of " << cn << " is " << cn.getArgument() << endl;
   cout << "Argument of " << im << " is " << im.getArgument() << endl;
   cout << endl;

   cout << "Polar form of " << cn << " is ";
   cn.displayPolarForm();
   cout << endl;

   cout << boolalpha;
   cout << im << " is bigger than " << cn << " ?  - " << (cn > im) << endl;
   cout << im << " is equal to " << cn << " ?  - " << (cn == im) << endl;
   cout << endl;

   ComplexNumber<> ce;

   cout << ce << " is default constructed" << endl;

   // Test conversion constructor
   ComplexNumber<> c2(cn);

   c2 += 19.5;
   c2.setImaginaryPart(67.2);

   cout << c2 << " is made from " << cn << endl;
   cout << endl;

   double rn = 4.6;
   ce += rn;
   cout << "Compare with a real number :" << endl;
   cout << ce << " equals " << rn << " ? - " << (ce == rn) << endl;

   return EXIT_SUCCESS;
}
