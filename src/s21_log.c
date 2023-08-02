#include "s21_math.h"

long double s21_log(double x) {
  double res = 0;
  if (x == 0) {
    res = -s21_INF;
  } else if (x < 0) {
    res = s21_NAN;
  } else if (x < s21_INF && x > -s21_INF) {
    int ex_pow = 0;
    double result = 0;
    double compare = 0;

    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
    res = result + ex_pow;
  } else if (x == s21_INF || x == -s21_INF) {
    res = s21_INF;
  } else {
    res = s21_NAN;
  }
  return res;
}