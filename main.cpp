// Copyright 2012 Benjamin Reh <benjamin.reh@iwr.uni-heidelberg.de>
 // 
 // This program is free software; you can redistribute it and/or modify
 // it under the terms of the GNU General Public License as published by
 // the Free Software Foundation; either version 2 of the License, or
 // (at your option) any later version.
 // 
 // This program is distributed in the hope that it will be useful,
 // but WITHOUT ANY WARRANTY; without even the implied warranty of
 // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 // GNU General Public License for more details.
 // 
 // You should have received a copy of the GNU General Public License
 // along with this program; if not, write to the Free Software
 // Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 // MA 02110-1301, USA.
#include "average.h"
#include <iostream>

//Simple Programm to test the functions

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
	
	//Test if dev is 0 with only one element
	Average<int> a_f2;
	a_f2.add(3.0);
	assert(a_f2.getDeviation()==0);
	
	a_f2.clear();
	
	return 0;
}
