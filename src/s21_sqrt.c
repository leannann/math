#include "s21_math.h"

long double s21_sqrt(double x) {
  double y = 0;
  if (x == x && x >= 0) {
    if (x != -s21_INF) {
      y = x;

      if (x > -s21_INF && x < s21_INF)
        y = s21_pow(x, 0.5);
      else
        y = s21_INF;
    } else
      y = -s21_NAN;

  } else {
    y = s21_NAN;
  }
  return y;
}
