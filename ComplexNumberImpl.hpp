/*
 * Project : Complex numbers in C++
 * File    : ComplexNumber<T>s.cpp
 * Author  : Luc Wachter
 *
 * Implementation of simple class to model complex numbers.
 */

#ifndef COMPLEX_NUMBER_IMPL_H
#define COMPLEX_NUMBER_IMPL_H

// Dummy include for IDE
#include "ComplexNumber.hpp"

// Friend functions ---------------------------
// Comparison operators
template <typename T, typename U>
bool operator== (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs) {
   return (lhs.getRealPart() == rhs.getRealPart() and
           lhs.getImaginaryPart() == rhs.getImaginaryPart());
}

template <typename T, typename U>
bool operator== (const ComplexNumber<T>& lhs, const U rhs) {
   return (lhs.getImaginaryPart() == 0 and
           lhs.getRealPart() == rhs);
}

template <typename T, typename U>
bool operator!= (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs) {
   return !(lhs == rhs);
}

template <typename T, typename U>
bool operator<  (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs) {
   return lhs.getModule() < rhs.getModule();
}

template <typename T, typename U>
bool operator>  (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs) {
   return rhs < lhs;
}

template <typename T, typename U>
bool operator<= (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs) {
   return !(lhs > rhs);
}

template <typename T, typename U>
bool operator>= (const ComplexNumber<T>& lhs, const ComplexNumber<U>& rhs) {
   return !(lhs < rhs);
}

// Arithmetic operators
template <typename T, typename U>
ComplexNumber<T> operator- (ComplexNumber<T> lhs, const ComplexNumber<U>& rhs) {
   return lhs -= rhs;
}

template <typename T, typename U>
ComplexNumber<T> operator- (ComplexNumber<T> lhs, const U rhs) {
   return lhs -= rhs;
}

template <typename T, typename U>
ComplexNumber<T> operator+ (ComplexNumber<T> lhs, const ComplexNumber<U>& rhs) {
   return lhs += rhs;
}

template <typename T, typename U>
ComplexNumber<T> operator+ (ComplexNumber<T> lhs, const U rhs) {
   return lhs += rhs;
}

template <typename T, typename U>
ComplexNumber<T> operator* (ComplexNumber<T> lhs, const ComplexNumber<U>& rhs) {
   return lhs *= rhs;
}

template <typename T, typename U>
ComplexNumber<T> operator* (ComplexNumber<T> lhs, const U rhs) {
   return lhs *= T(rhs);
}

template <typename T, typename U>
ComplexNumber<T> operator/ (ComplexNumber<T> lhs, const ComplexNumber<U>& rhs) {
   return lhs /= rhs;
}

template <typename T, typename U>
ComplexNumber<T> operator/ (ComplexNumber<T> lhs, const U rhs) {
   return lhs /= T(rhs);
}

// Stream operator
template <typename T>
std::ostream& operator<< (std::ostream& os, const ComplexNumber<T>& c) {
   return os << "(" << c.realPart << " + " << c.imaginaryPart << "j)";
}

// Member functions ----------------------------

// Constructors
template <typename T>
ComplexNumber<T>::ComplexNumber()
: realPart(0), imaginaryPart(0) {}

template <typename T>
ComplexNumber<T>::ComplexNumber(T realPart, T imaginaryPart)
: realPart(realPart), imaginaryPart(imaginaryPart) {}

template <typename T>
ComplexNumber<T>::ComplexNumber(const ComplexNumber<T>& c)
: realPart(c.realPart), imaginaryPart(c.imaginaryPart) {}

// Conversion constructor
template <typename T>
template <typename U>
ComplexNumber<T>::ComplexNumber(const ComplexNumber<U>& c) {
   realPart = (T) c.getRealPart();
   imaginaryPart = (T) c.getImaginaryPart();
}

template <typename T>
T ComplexNumber<T>::getRealPart() const {
   return realPart;
}

template <typename T>
T ComplexNumber<T>::getImaginaryPart() const {
   return imaginaryPart;
}

template <typename T>
double ComplexNumber<T>::getModule() const {
   return hypot(realPart, imaginaryPart);
}

template <typename T>
double ComplexNumber<T>::getArgument() const {
   double theta = atan2(imaginaryPart, realPart);

   return (theta >= 0 ? theta : theta + 2*M_PI);
}

template <typename T>
void ComplexNumber<T>::displayPolarForm() const {
   std::cout << getModule() << "(cos(" << getArgument()
             << ") + j*sin(" << getArgument() << "))" << std::endl;
}

template <typename T>
void ComplexNumber<T>::setRealPart(T realPart) {
   this->realPart = realPart;
}

template <typename T>
void ComplexNumber<T>::setImaginaryPart(T imaginaryPart) {
   this->imaginaryPart = imaginaryPart;
}

// Member operators -------------------

template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator+= (const ComplexNumber<T>& rhs) {
   realPart += rhs.getRealPart();
   imaginaryPart += rhs.getImaginaryPart();

   return *this;
}

template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator+= (const T rhs) {
   realPart += rhs;

   return *this;
}

template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator++ () {
   realPart++;

   return *this;
}

template <typename T>
ComplexNumber<T> ComplexNumber<T>::operator++ (int) {
   ComplexNumber<T> tmp = *this;
   realPart++;

   return tmp;
}

template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator-= (const ComplexNumber<T>& rhs) {
   realPart -= rhs.getRealPart();
   imaginaryPart -= rhs.getImaginaryPart();

   return *this;
}

template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator-= (const T rhs) {
   realPart -= rhs;

   return *this;
}

template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator-- () {
   realPart--;

   return *this;
}

template <typename T>
ComplexNumber<T> ComplexNumber<T>::operator-- (int) {
   ComplexNumber<T> tmp = *this;
   realPart--;

   return tmp;
}

template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator*= (const ComplexNumber<T>& rhs) {
   // Implement with module and argument
   const T a = realPart;

   // w * z = (ac - bd) + (ad + bc)j
   realPart      = (a * rhs.getRealPart() - imaginaryPart * rhs.getImaginaryPart());
   imaginaryPart = (a * rhs.getImaginaryPart() + imaginaryPart * rhs.getRealPart());

   return *this;
}

template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator*= (const T rhs) {
   realPart *= rhs;
   imaginaryPart *= rhs;

   return *this;
}

template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator/= (const ComplexNumber<T>& rhs) {
   const T r =  realPart * rhs.getRealPart() + imaginaryPart * rhs.getImaginaryPart();
   const T i = T(rhs.getModule() * rhs.getModule());

   imaginaryPart = (imaginaryPart * rhs.getRealPart() - realPart * rhs.getImaginaryPart()) / i;
   realPart = r / i;

   return *this;
}

template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator/= (const T rhs) {
   realPart /= rhs;
   imaginaryPart /= rhs;

   return *this;
}

#endif
