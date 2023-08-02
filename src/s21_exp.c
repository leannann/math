#include "s21_math.h"

long double s21_exp(double x) {
  if (s21_ISNAN(x)) return s21_NAN;
  if (s21_ISINF(x)) return x < 0 ? 0 : s21_INF;
  int sign = x < 0;
  if (sign) x *= -1;
  long double result = 1;
  long double temp = x;
  unsigned flag = 1;
  while (s21_fabs(temp) >= s21_EPS) {
    result += temp;
    temp = (temp * x) / ++flag;
  }
  return sign ? (1 / result) : result;
}
