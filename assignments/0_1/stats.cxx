/*
Author: Dor Rondel
File: stats.cxx
Course: CSc-212
Professor: Feng Hu
Term: Fall 2016
Institution: CCNY
*/

#include "stats.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace main_savitch_2C {
  //Default Constructor
  statistician::statistician() {
    reset();
  }

  //Custom Constructor
  statistician::statistician(int count, double total, double tinyest, double largest) {
    m_count = count;
    m_total = total;
    m_tinyest = tinyest;
    m_largest = largest;
  }

  void statistician::next(double r) {
    m_count += 1;
    m_total += r;
    checkMin(r);
    checkMax(r);
  }

  void statistician::reset() {
    m_count = 0;
    m_total = 0;
    m_tinyest = 0;
    m_largest = 0;
  }

  // CONSTANT MEMBER FUNCTIONS
  int statistician::length( ) const {
    return m_count;
  }

  double statistician::sum( ) const {
    return m_total;
  }

  double statistician::mean( ) const {
    assert(length() > 0);
    return m_total / m_count;
  }

  double statistician::minimum( ) const {
    assert(length() > 0);
    return m_tinyest;
  }

  double statistician::maximum( ) const {
    assert(length() > 0);
    return m_largest;
  }

  void statistician::checkMin(double possibleMin) {
    if (length() == 1) changeMin(possibleMin); // If this is the first number, then its automatically the min
    (possibleMin < minimum()) ? changeMin(possibleMin) : changeMin(minimum());
  }

  void statistician::checkMax(double possibleMax) {
    if (length() == 1) changeMax(possibleMax); // If this is the first number, then its automatically the max
    (possibleMax > maximum()) ? changeMax(possibleMax) : changeMax(maximum());
  }

  void statistician::changeCount(int newCount) {
    m_count = newCount;
  }

  void statistician::changeTotal(double newTotal) {
    m_total = newTotal;
  }

  void statistician::changeMin(double newMin) {
    m_tinyest = newMin;
  }

  void statistician::changeMax(double newMax) {
    m_largest = newMax;
  }

  // FRIEND FUNCTIONS
  statistician operator+ (const statistician& s1, const statistician& s2) {
    statistician s3;
    /* Since defualt constructor sets all private member values to 0,
    If both statisticians are empty, you can return the empty statistician s3 */
    if (s1.length() == 0 && s2.length() == 0) return s3;
    else if (s1.length() == 0) return s2;
    else if (s2.length() == 0) return s1;
    else {
      s3.changeCount(s1.length() + s2.length());
      s3.changeTotal(s1.sum() + s2.sum());
      double smallestMin = (s1.minimum() < s2.minimum()) ? s1.minimum() : s2.minimum(); // find smaller min
      s3.changeMin(smallestMin);
      double largestMax = (s1.maximum() > s2.maximum()) ? s1.maximum() : s2.maximum(); // find larger max
      s3.changeMax(largestMax);
    } return s3; // return s3 post modifications if else block runs
  }

  statistician operator* (double scale, const statistician& s) {
    statistician scaled = s;
    scaled.changeTotal(s.sum() * scale);
    if (s.length() == 0) return s;
    if (scale < 0) { // negative scale
      scaled.changeMax(s.minimum() * scale);
      scaled.changeMin(s.maximum() * scale);
    } else if (scale == 0) {
      scaled.reset();
      scaled.changeCount(s.length());
    }
    else {
      scaled.changeMin(s.minimum() * scale);
      scaled.changeMax(s.maximum() * scale);
    } return scaled;
  }

  // NON-MEMBER functions for the statistician class
  bool operator ==(const statistician& s1, const statistician& s2) {
    if (s1.length() == 0 && s2.length() == 0) return true;
    else if (s1.length() == s2.length() && s1.sum() == s2.sum() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()) return true;
    else return false;
  }
};
