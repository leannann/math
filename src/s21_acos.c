#include "s21_math.h"

long double s21_acos(double x) {
  if (x >= -1 && x <= 1) {
    if (x == 1.0) {
      x = 0.0;
    } else if (x == -1.0) {
      x = s21_PI;
    } else if (x == 0.0) {
      x = s21_PI / 2.0;
    }

    else if (x > 0 && x < 1) {
      x = s21_atan(s21_sqrt(1.0 - x * x) / x);
    } else if (x > -1 && x < 0) {
      x = s21_PI + s21_atan(s21_sqrt(1.0 - x * x) / x);
    } else {
      x = s21_NAN;
    }
  } else {
    x = s21_NAN;
  }

  return x;
}
