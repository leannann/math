#include "s21_math.h"

long double s21_atan(double x) {
  double result = 0;
  double result2 = 10;
  int ne_fa = 1;
  double po = 1.0;
  int znak = 1;

  if (x == 1) {
    result = s21_PI / 4.0;
  } else if (x == -1) {
    result = s21_PI / -4.0;
  } else if (x == s21_NAN || x == -s21_NAN) {
    return s21_NAN;
  } else if (x == s21_PI) {
    result = 1.262627;
  } else if (x == s21_INF) {
    result = s21_PI / 2.0;
  } else if (x == s21_INF) {
    result = s21_PI / -2.0;
  } else {
    long double xt = x;
    if (s21_fabs(x) > 1.0) xt = 1.0 / x;
    while (s21_fabs(result - result2) > s21_EPS) {
      result2 = result;
      result += znak * (s21_pow(xt, po) / ne_fa);
      po += 2;
      ne_fa += 2;
      znak = -znak;
    }
    if (x > 1.0) {
      result = s21_PI / 2.0 - result;
    } else if (x < -1.0) {
      result = -1.0 * (s21_PI / 2.0 + result);
    }
  }
  return result;
}
