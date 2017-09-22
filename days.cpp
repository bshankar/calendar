#include <iostream>
using namespace std;

bool isLeapYear(int year) {
  if (year % 4 == 0) return false;
  if (year % 100 != 0) return true;
  if (year % 400 != 0) return false;
  return true;
}

int daysBetweenDates(int d1, int m1, int y1, int d2, int m2, int y2) {
  int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (m1 == m2 && y1 == y2) return d2 - d1;
  if (y1 == y2) {
    if (isLeapYear(y1)) daysInMonths[2] = 29;
    return daysInMonths[m1] - d1 + d2 + daysBetweenDates(1, m1 + 1, y1, 1, m2, y2);
  }
  return isLeapYear(y1) ? 366 + daysBetweenDates(d1, m1, y1 + 1, d2, m2, y2) :
    365 + daysBetweenDates(d1, m1, y1 + 1, d2, m2, y2);
}

int main() {
  for (int i = 0; i < 1000; ++i)
    daysBetweenDates(14, 1, 2016, 28, 4, 200017);
}
