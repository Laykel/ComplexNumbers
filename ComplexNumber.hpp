/*
 * Project : Complex numbers in C++
 * File    : ComplexNumbers.hpp
 * Author  : Luc Wachter
 *
 * Simple class to model complex numbers.
 * Added genericity, but no checks to see if the chosen types make sense.
 * The operators can take two complex numbers with different types, once again
 * no checks.
 */

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <iostream>
#include <cmath>

// Pre-declaration of generic class
template <typename T = double> class ComplexNumber;

// Pre-declaration of friend functions -------------------------------------------
template <typename T, typename U>
bool operator== (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs);
template <typename T, typename U>
bool operator== (const ComplexNumber<T>& lhs, const U rhs); // Example
template <typename T, typename U>
bool operator!= (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs);
template <typename T, typename U>
bool operator<  (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs);
template <typename T, typename U>
bool operator>  (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs);
template <typename T, typename U>
bool operator<= (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs);
template <typename T, typename U>
bool operator>= (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs);

template <typename T, typename U>
ComplexNumber<T> operator- (ComplexNumber<T> lhs, const ComplexNumber<U>& rhs);
template <typename T, typename U>
ComplexNumber<T> operator- (ComplexNumber<T> lhs, const U rhs);
template <typename T, typename U>
ComplexNumber<T> operator+ (ComplexNumber<T> lhs, const ComplexNumber<U>& rhs);
template <typename T, typename U>
ComplexNumber<T> operator+ (ComplexNumber<T> lhs, const U rhs);
template <typename T, typename U>
ComplexNumber<T> operator* (ComplexNumber<T> lhs, const ComplexNumber<U>& rhs);
template <typename T, typename U>
ComplexNumber<T> operator* (ComplexNumber<T> lhs, const U rhs);
template <typename T, typename U>
ComplexNumber<T> operator/ (ComplexNumber<T> lhs, const ComplexNumber<U>& rhs);
template <typename T, typename U>
ComplexNumber<T> operator/ (ComplexNumber<T> lhs, const U rhs);

template <typename T>
std::ostream& operator<< (std::ostream& os, const ComplexNumber<T>& c);
// -------------------------------------------------------------------------------

template <typename T>
class ComplexNumber {
   // Comparison operators
   friend bool operator== <>(const ComplexNumber& lhs, const ComplexNumber& rhs);
   friend bool operator== <>(const ComplexNumber& lhs, const T rhs); // Example
   friend bool operator!= <>(const ComplexNumber& lhs, const ComplexNumber& rhs);
   friend bool operator<  <>(const ComplexNumber& lhs, const ComplexNumber& rhs);
   friend bool operator>  <>(const ComplexNumber& lhs, const ComplexNumber& rhs);
   friend bool operator<= <>(const ComplexNumber& lhs, const ComplexNumber& rhs);
   friend bool operator>= <>(const ComplexNumber& lhs, const ComplexNumber& rhs);

   // Arithmetic operators
   friend ComplexNumber operator- <>(ComplexNumber lhs, const ComplexNumber& rhs);
   friend ComplexNumber operator- <>(ComplexNumber lhs, const T rhs);
   friend ComplexNumber operator+ <>(ComplexNumber lhs, const ComplexNumber& rhs);
   friend ComplexNumber operator+ <>(ComplexNumber lhs, const T rhs);
   friend ComplexNumber operator* <>(ComplexNumber lhs, const ComplexNumber& rhs);
   friend ComplexNumber operator* <>(ComplexNumber lhs, const T rhs);
   friend ComplexNumber operator/ <>(ComplexNumber lhs, const ComplexNumber& rhs);
   friend ComplexNumber operator/ <>(ComplexNumber lhs, const T rhs);
   // Stream operator
   friend std::ostream& operator<< <>(std::ostream& os, const ComplexNumber& c);

public:
   // Constructors
   ComplexNumber();
   ComplexNumber(T realPart, T imaginaryPart);
   ComplexNumber(const ComplexNumber& c);
   // Conversion constructor
   template <typename U> ComplexNumber(const ComplexNumber<U>& c);

   // Selectors
   T getRealPart() const;
   T getImaginaryPart() const;
   T getModule() const;
   T getArgument() const;
   void displayPolarForm() const; // Trigonometric form

   // Modifiers
   void setRealPart(T realPart);
   void setImaginaryPart(T imaginaryPart);

   // Member operators
   ComplexNumber& operator+= (const ComplexNumber& rhs); // With complex
   ComplexNumber& operator+= (const T rhs);         // With scalar
   // Incrementation operators increment the real part
   ComplexNumber& operator++ ();    // pré-incrémentation
   ComplexNumber  operator++ (int); // post-incrémentation

   ComplexNumber& operator-= (const ComplexNumber& rhs);
   ComplexNumber& operator-= (const T rhs);
   // Decrementation operators decrement the real part
   ComplexNumber& operator-- ();    // pré-décrémentation
   ComplexNumber  operator-- (int); // post-décrémentation

   ComplexNumber& operator*= (const ComplexNumber& rhs);
   ComplexNumber& operator*= (const T rhs);
   ComplexNumber& operator/= (const ComplexNumber& rhs);
   ComplexNumber& operator/= (const T rhs);

private:
   T realPart;
   T imaginaryPart;
};

// Genericity nonsense
#include "ComplexNumberImpl.hpp"

#endif
