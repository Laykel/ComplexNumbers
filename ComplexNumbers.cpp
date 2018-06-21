/*
 * Project : Complex numbers in C++
 * File    : ComplexNumbers.cpp
 * Author  : Luc Wachter
 *
 * Implementation of simple class to model complex numbers.
 */

#include "ComplexNumbers.hpp"

// Friend functions ---------------------------
// Comparison operators
bool operator== (const ComplexNumber& lhs, const ComplexNumber& rhs) {
   return (lhs.realPart == rhs.realPart and
           lhs.imaginaryPart == rhs.imaginaryPart);
}

bool operator== (const ComplexNumber& lhs, const double rhs) {
   return (lhs.imaginaryPart == 0 and
           lhs.realPart == rhs);
}

bool operator!= (const ComplexNumber& lhs, const ComplexNumber& rhs) {
   return !(lhs == rhs);
}

bool operator<  (const ComplexNumber& lhs, const ComplexNumber& rhs) {
   return lhs.getModule() < rhs.getModule();
}

bool operator>  (const ComplexNumber& lhs, const ComplexNumber& rhs) {
   return rhs < lhs;
}

bool operator<= (const ComplexNumber& lhs, const ComplexNumber& rhs) {
   return !(lhs > rhs);
}

bool operator>= (const ComplexNumber& lhs, const ComplexNumber& rhs) {
   return !(lhs < rhs);
}

// Arithmetic operators
ComplexNumber operator- (ComplexNumber lhs, const ComplexNumber& rhs) {
   return lhs -= rhs;
}

ComplexNumber operator- (ComplexNumber lhs, const double rhs) {
   return lhs -= rhs;
}

ComplexNumber operator+ (ComplexNumber lhs, const ComplexNumber& rhs) {
   return lhs += rhs;
}

ComplexNumber operator+ (ComplexNumber lhs, const double rhs) {
   return lhs += rhs;
}

ComplexNumber operator* (ComplexNumber lhs, const ComplexNumber& rhs) {
   return lhs *= rhs;
}

ComplexNumber operator* (ComplexNumber lhs, const double rhs) {
   return lhs *= rhs;
}

ComplexNumber operator/ (ComplexNumber lhs, const ComplexNumber& rhs) {
   return lhs /= rhs;
}

ComplexNumber operator/ (ComplexNumber lhs, const double rhs) {
   return lhs /= rhs;
}

// Stream operator
std::ostream& operator<< (std::ostream& os, const ComplexNumber& c) {
   return os << "(" << c.realPart << " + " << c.imaginaryPart << "j)";
}

// Member functions ----------------------------

// Constructors
ComplexNumber::ComplexNumber()
: realPart(0), imaginaryPart(0) {}

ComplexNumber::ComplexNumber(double realPart, double imaginaryPart)
: realPart(realPart), imaginaryPart(imaginaryPart) {}

ComplexNumber::ComplexNumber(const ComplexNumber& c)
: realPart(c.realPart), imaginaryPart(c.imaginaryPart) {}

double ComplexNumber::getRealPart() const {
   return realPart;
}

double ComplexNumber::getImaginaryPart() const {
   return imaginaryPart;
}

double ComplexNumber::getModule() const {
   return hypot(realPart, imaginaryPart);
}

double ComplexNumber::getArgument() const {
   double theta = atan2(imaginaryPart, realPart);
   
   return (theta >= 0 ? theta : theta + 2*M_PI);
}

void ComplexNumber::displayPolarForm() const {
   std::cout << getModule() << "(cos(" << getArgument()
             << ") + j*sin(" << getArgument() << "))" << std::endl;
}

void ComplexNumber::setRealPart(double realPart) {
   this->realPart = realPart;
}

void ComplexNumber::setImaginaryPart(double imaginaryPart) {
   this->imaginaryPart = imaginaryPart;
}

// Member operators -------------------

ComplexNumber& ComplexNumber::operator+= (const ComplexNumber& rhs) {
   realPart += rhs.realPart;
   imaginaryPart += rhs.imaginaryPart;
   
   return *this;
}

ComplexNumber& ComplexNumber::operator+= (const double rhs) {
   realPart += rhs;
   
   return *this;
}

ComplexNumber& ComplexNumber::operator++ () {
   realPart++;

   return *this;
}

ComplexNumber ComplexNumber::operator++ (int) {
   ComplexNumber tmp = *this;
   realPart++;

   return tmp;
}

ComplexNumber& ComplexNumber::operator-= (const ComplexNumber& rhs) {
   realPart -= rhs.realPart;
   imaginaryPart -= rhs.imaginaryPart;

   return *this;
}

ComplexNumber& ComplexNumber::operator-= (const double rhs) {
   realPart -= rhs;

   return *this;
}

ComplexNumber& ComplexNumber::operator-- () {
   realPart--;

   return *this;
}

ComplexNumber ComplexNumber::operator-- (int) {
   ComplexNumber tmp = *this;
   realPart--;

   return tmp;
}

ComplexNumber& ComplexNumber::operator*= (const ComplexNumber& rhs) {
   // Implement with module and argument
   const double a = realPart;

   // w * z = (ac - bd) + (ad + bc)j
   realPart      = (a * rhs.realPart - imaginaryPart * rhs.imaginaryPart);
   imaginaryPart = (a * rhs.imaginaryPart + imaginaryPart * rhs.realPart);

   return *this;
}

ComplexNumber& ComplexNumber::operator*= (const double rhs) {
   realPart *= rhs;
   imaginaryPart *= rhs;

   return *this;
}

ComplexNumber& ComplexNumber::operator/= (const ComplexNumber& rhs) {
   const double r =  realPart * rhs.realPart + imaginaryPart * rhs.imaginaryPart;
   const double i = rhs.getModule() * rhs.getModule();

   imaginaryPart = (imaginaryPart * rhs.realPart - realPart * rhs.imaginaryPart) / i;
   realPart = r / i;

   return *this;
}

ComplexNumber& ComplexNumber::operator/= (const double rhs) {
   realPart /= rhs;
   imaginaryPart /= rhs;

   return *this;
}
