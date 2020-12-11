/*

C++ vs Java

General syntax
  comment sequence
  use of braces, parentheses, commas, semi-colons
  variable/parameter declarations, function call
Primitive variable types
  char, int, double, but note Java boolean is C++ bool
Operators
  arithmetic, relational, logical
Control structures
  for, while, if/else, switch, return


C++ user-defined types

Enumerations
  Define new types with set of constrained options
    enum directionT {North, South, East, West};
    directionT dir = East;
    if (dir == West) ...

Records
  Define new type which aggregates a set of fields
    struct pointT {
      double x;
      double y;
    };
    pointT p, q;
    p.x = 0;
    p = q;

*/

#include <iostream>
using namespace std;

const int NumScores = 4;

double GetScoresAndAverage(int numScores);  // prototype function
double GetScoresAndAverageSentinel(int sentinel=-1);  // default -1 if not specified

int main() 
{
  cout << "This program averages " << NumScores << " scores" << endl;
  // double average = GetScoresAndAverage(NumScores);
  double average = GetScoresAndAverageSentinel();
  cout << "Average is " << average << endl;
  return 0;
}

double GetScoresAndAverage(int numScores)
{
  int sum = 0;  // if declare int here, result truncated
  for (int i = 0; i < numScores; i++) {
    cout << "Next score? ";
    int nextScore;
    cin >> nextScore;
    sum += nextScore;
  }
  return (double)sum/numScores;  // double here to avoid truncated result
}

double GetScoresAndAverageSentinel(int sentinel)
{
  int sum = 0, numScores = 0;
  int value;
  while (true) {
    cout << "Next? " << "(" << sentinel << " if done): ";
    cin >> value;
    if (value == sentinel) break;
    sum += value;
    numScores++;
  }
  return (double)sum/numScores;  // double here to avoid truncated result
}


