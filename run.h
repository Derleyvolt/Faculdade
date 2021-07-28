#include <string>
#include <iostream>
#include <cstring>
#include "KMP.h"
#include "generate_cases.h"
#include "brute_force.h"

void run_random(char bound, int pattern_len, int text_len, int instance_len);
void run_real(int l, int r);