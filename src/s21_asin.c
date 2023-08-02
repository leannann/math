#include "s21_math.h"

long double s21_asin(double x) {
  if (x >= -1 && x <= 1) {
    if (x == 1.0) {
      x = s21_PI / 2.0;
    } else if (x == -1) {
      x = s21_PI / -2.0;
    } else if (x > -1.0 && x < 1.0) {
      x = s21_atan(x / s21_sqrt(1.0 - x * x));
    } else {
      x = s21_PI;
    }
  } else {
    x = s21_NAN;
  }

  return x;
}