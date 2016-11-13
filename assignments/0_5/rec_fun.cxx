#include <iostream>
#include <assert.h>

using namespace std;

void binary_print(ostream& outs, unsigned int n) {
  if (n == 0 || n == 1) cout << n;
  else {
    binary_print(outs, n/2);  // reduce n by order of 2
    binary_print(outs, n%2);  // print binary for that power of 2
  }
}

void triangle(ostream& outs, unsigned int m, unsigned int n) {
  assert(m <= n);
  if(m == n) {
      for (int i = 0; i < m; i++) cout << "*";
      cout << endl;
  } else {
      for (int i = 0; i < m; i++) cout << "*";
      cout << endl;
      triangle(outs, m + 1, n);
      for (int i = 0; i < m; i++) cout << "*";
      cout << endl;
  }
}

double pow(double x, int n) {
  if (x == 0) assert(n > 0);
  if (n == 0) return 1;
  if (n == 1) return x;
  else if(n < 0) return (1 / pow(x,-n));
  else if(n > 0 && n % 2 == 0) return (pow(x, n/2) * pow(x, n/2));
  else return (x*pow(x, n/2) * pow(x, n/2));
}

void indented_sentences(size_t m, size_t n) {
  assert(m <= n+1);
  if (m <= n) {
    for(size_t i = m; i > 1; i--) cout << " ";
    cout << "This was written by calling number " << m << endl;
    indented_sentences(m+1, n);
    for(size_t i = m; i > 1; i--) cout << " ";
    cout << "This was ALSO written by calling number " << m << endl;
  }
}

#if 0
int main() {
  cout << "Decimal 0 in binary is: "; binary_print(cout, 0);
  cout << endl << "Decimal 4 in binary is: "; binary_print(cout, 4);
  cout << endl << "Decimal 27 in binary is: "; binary_print(cout, 27);
  cout << endl; triangle(cout, 3, 5);
  cout << "2 to the 0: " << pow(2, 0) << endl;
  cout << "2 to the -3: " << pow(2, -3) << endl;
  cout << "2 to the 1: " << pow(2, 1) << endl;
  cout << "2 to the 2: " << pow(2, 2) << endl;
  cout << "2 to the 3: " << pow(2, 3) << endl;
  cout << endl;
  indented_sentences(1, 4);
  return 0;
}
#endif
