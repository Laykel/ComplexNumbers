/*
 * Project : Complex numbers in C++
 * File    : ComplexNumbers.hpp
 * Author  : Luc Wachter
 *
 * Simple class to model complex numbers.
 */

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <iostream>
#include <cmath>

class ComplexNumber {
   // Comparison operators
   friend bool operator== (const ComplexNumber& lhs, const ComplexNumber& rhs);
   friend bool operator== (const ComplexNumber& lhs, const double rhs); // Example
   friend bool operator!= (const ComplexNumber& lhs, const ComplexNumber& rhs);
   friend bool operator<  (const ComplexNumber& lhs, const ComplexNumber& rhs);
   friend bool operator>  (const ComplexNumber& lhs, const ComplexNumber& rhs);
   friend bool operator<= (const ComplexNumber& lhs, const ComplexNumber& rhs);
   friend bool operator>= (const ComplexNumber& lhs, const ComplexNumber& rhs);

   // Arithmetic operators
   friend ComplexNumber operator- (ComplexNumber lhs, const ComplexNumber& rhs);
   friend ComplexNumber operator- (ComplexNumber lhs, const double rhs);
   friend ComplexNumber operator+ (ComplexNumber lhs, const ComplexNumber& rhs);
   friend ComplexNumber operator+ (ComplexNumber lhs, const double rhs);
   friend ComplexNumber operator* (ComplexNumber lhs, const ComplexNumber& rhs);
   friend ComplexNumber operator* (ComplexNumber lhs, const double rhs);
   friend ComplexNumber operator/ (ComplexNumber lhs, const ComplexNumber& rhs);
   friend ComplexNumber operator/ (ComplexNumber lhs, const double rhs);
   // Stream operator
   friend std::ostream& operator<< (std::ostream& os, const ComplexNumber& c);

public:
   // Constructors
   ComplexNumber();
   ComplexNumber(double realPart, double imaginaryPart);
   ComplexNumber(const ComplexNumber& c);

   // Selectors
   double getRealPart() const;
   double getImaginaryPart() const;
   double getModule() const;
   double getArgument() const;
   void displayPolarForm() const; // Trigonometric form

   // Modifiers
   void setRealPart(double realPart);
   void setImaginaryPart(double imaginaryPart);

   // Member operators
   ComplexNumber& operator+= (const ComplexNumber& rhs); // With complex
   ComplexNumber& operator+= (const double rhs);         // With scalar
   // Incrementation operators increment the real part
   ComplexNumber& operator++ ();    // pré-incrémentation
   ComplexNumber  operator++ (int); // post-incrémentation

   ComplexNumber& operator-= (const ComplexNumber& rhs);
   ComplexNumber& operator-= (const double rhs);
   // Decrementation operators decrement the real part
   ComplexNumber& operator-- ();    // pré-décrémentation
   ComplexNumber  operator-- (int); // post-décrémentation

   ComplexNumber& operator*= (const ComplexNumber& rhs);
   ComplexNumber& operator*= (const double rhs);
   ComplexNumber& operator/= (const ComplexNumber& rhs);
   ComplexNumber& operator/= (const double rhs);

private:
   double realPart;
   double imaginaryPart;
};

#endif
