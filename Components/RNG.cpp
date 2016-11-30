#include "RNG.h"
#include <ctime>
#include <iostream>

float RNG::RandNum(int start, int end)
{
	srand(time(NULL));
	return rand() % (end - start + 1) + start;
}
