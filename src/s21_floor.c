#include "s21_math.h"

long double s21_floor(double x) {
  if (x != -s21_INF && x != s21_INF && x == x) {
    if (x < 0)
      if (x < (int)x) x -= 1;

    x = (int)x;
  }
  return x;
}
