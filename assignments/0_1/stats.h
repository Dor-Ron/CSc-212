// Provided by:  Dor Rondel
// Email Address: dor.rondel@gmail.com
// FILE: stats.h
// CLASS PROVIDED: statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace main_savitch_2C.
//
// CONSTRUCTOR for the statistician class:
//   statistician( );
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of numbers. Various statistics will be calculated about the
//     sequence.
//
// PUBLIC MODIFICATION member functions for the statistician class:
//   void next(double r)
//     The number r has been given to the statistician as the next number in
//     its sequence of numbers.
//   void reset( );
//     Postcondition: The statistician has been cleared, as if no numbers had
//     yet been given to it.
//
// PUBLIC CONSTANT member functions for the statistician class:
//   int length( ) const
//     Postcondition: The return value is the length of the sequence that has
//     been given to the statistician (i.e., the number of times that the
//     next(r) function has been activated).
//   double sum( ) const
//     Postcondition: The return value is the sum of all the numbers in the
//     statistician's sequence.
//   double mean( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the arithmetic mean (i.e., the
//     average of all the numbers in the statistician's sequence).
//   double minimum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the tinyest number in the
//     statistician's sequence.
//   double maximum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the largest number in the
//     statistician's sequence.
//
// NON-MEMBER functions for the statistician class:
//   statistician operator +(const statistician& s1, const statistician& s2)
//     Postcondition: The statistician that is returned contains all the
//     numbers of the sequences of s1 and s2.
//   statistician operator *(double scale, const statistician& s)
//     Postcondition: The statistician that is returned contains the same
//     numbers that s does, but each number has been multiplied by the
//     scale number.
//   bool operator ==(const statistician& s1, const statistician& s2)
//     Postcondition: The return value is true if s1 and s2 have the zero
//     length. Also, if the length is greater than zero, then s1 and s2 must
//     have the same length, the same  mean, the same minimum,
//     the same maximum, and the same sum.
//
// VALUE SEMANTICS for the statistician class:
// Assignments and the copy constructor may be used with statistician objects.



/* Own Documentation
--------------------

# Modification Member Functions

void checkMin(double possibleMin)
  Precondition: A single double type parameter is passed in
  Postcondition: If the parameter is smaller than the current m_tinyest,
  m_tinyest is set to equal possibleMin by invoking changeMin with the possibleMin
  otherwise it remains unchanged

void changeMin(double newMin)
  Precondition: A single double type parameter
  Postcondition: m_tinyest equals newMin

void checkMax(double possibleMax)
  Precondition: A single parameter is of type double
  Postcondition: If the parameter is larger than the caller object's
  m_largest attribute, m_largest is changed to the parameter by invoking checkMax with that same parameter,
  otherwise m_largest remains the same.

void changeMax(double newMax)
  Precondition: A single double type parameter
  Postcondition: m_largest is set equal to newMax

void changeCount(int newCount)
  Precondition: A single int type parameter
  Postcondition: m_count is set equal to newCount

void changeTotal(double newTotal)
  Precondition: A single double type parameter
  Postcondition: m_total is set equal to newTotal

*/

#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H
#include <iostream>

namespace main_savitch_2C
{
    class statistician {
      public:
          // CONSTRUCTORs
          statistician();
          statistician(int count, double total, double tinyest, double largest);

          // MODIFICATION MEMBER FUNCTIONS
          void next(double r);
          void reset( );
          void checkMax(double possibleMax);
          void checkMin(double possibleMin);
          void changeCount(int newCount);
          void changeTotal(double newTotal);
          void changeMin(double newMin);
          void changeMax(double newMax);

          // CONSTANT MEMBER FUNCTIONS
          int length( ) const;
          double sum( ) const;
          double mean( ) const;
          double minimum( ) const;
          double maximum( ) const;

          // FRIEND FUNCTIONS
          friend statistician operator +
              (const statistician& s1, const statistician& s2);
          friend statistician operator *
              (double scale, const statistician& s);
      private:
          int m_count;       // How many numbers in the sequence
          double m_total;    // The sum of all the numbers in the sequence
          double m_tinyest;  // The smallest number in the sequence
          double m_largest;  // The largest number in the sequence
      };

    // NON-MEMBER functions for the statistician class
    bool operator ==(const statistician& s1, const statistician& s2);
}

#endif
