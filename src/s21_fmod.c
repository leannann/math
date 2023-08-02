#include "s21_math.h"

long double s21_fmod(double x, double y) {
  int flag = 1;

  if (y != 0 && y == y && x != s21_INF && x != -s21_INF) {
    if (x < 0) flag *= -1;
    if (y == y) {
      if (y != 0) {
        x = s21_fabs(x);
        y = s21_fabs(y);
        while (x >= y) x -= y;
      }
    }
    x *= flag;
  } else {
    x = s21_NAN;
  }

  return x;
}
