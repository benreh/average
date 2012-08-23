#include "average.h"
#include <iostream>



using namespace std;

int main() {
	Average<float> a_f;
	a_f.add(6);
	a_f.add(4);
	a_f.add(2);
	assert( a_f.getAverage() ==4.0);
	assert( a_f.getDeviation() - sqrt(2) < 0.00001);
	
	Average<int> a_i;
	a_i.add(6);
	a_i.add(4);
	a_i.add(2);
	assert( a_i.getAverage() == 4);
	assert( a_i.getDeviation() == 1);

	a_i.add(10);

	//test cache
	assert( a_i.getDeviation() == a_i.getDeviation());
	
	return 0;
}
