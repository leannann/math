#include "s21_math.h"

long double pow_for_int(double base, double exp) {
  long double total = 1;
  if (exp < 0) {
    exp *= -1;
    for (int i = 0; i < exp; i++) total *= base;
    total = 1 / total;
  } else if (exp > 0) {
    for (int i = 0; i < exp; i++) total *= base;
  }
  return total;
}

long double pow_for_frac(double base, double exp) {
  long double res;
  if (base == 0 && !s21_ISNAN(exp))
    res = exp < 0 ? s21_INF : 0;
  else if (base == -1 && s21_ISINF(exp))
    res = 1;
  else if (base == 1)
    res = 1;
  else if (exp == 0)
    res = 1;
  else if (s21_ISNAN(base))
    res = s21_NAN;
  else if (exp == s21_INF)
    res = s21_fabs(base) < 1 ? 0 : s21_INF;
  else if (exp == -s21_INF)
    res = s21_fabs(base) < 1 ? s21_INF : 0;
  else if (base == -s21_INF && !s21_ISNAN(exp))
    res = exp < 0 ? 0 : s21_INF;
  else
    res = s21_exp(exp * s21_log(base));
  return res;
}

long double s21_pow(double base, double exp) {
  long double res = 0;
  long double condition = exp - (long long int)exp;
  if (condition <= 0.0000001 && condition >= -0.0000001 && !s21_ISNAN(exp) &&
      !s21_ISNAN(base)) {
    res = pow_for_int(base, exp);
  } else {
    res = pow_for_frac(base, exp);
  }

  return res;
}