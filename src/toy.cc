#include "toy.h"
#include <cmath>

float sigmoid(float f) {
  return 1 / (1 + expf(-f));
}
