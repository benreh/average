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
#ifndef AVERAGE_H
#define AVERAGE_H
#include <assert.h>
#include <list>
#include <cmath>

// can be specialized to for example comopent wise calculation
//  if y you have other classes
template <class T>
T square(T v) {
	return v*v;
}

template <class T>
T square_root(T v) {
	return sqrt(v);
}


template <class T>
class Average {
public:
//Initialisation
Average(): n(0), cacheValid(false) {}
~Average(){}

//Add a value to the list
void add(T value) {
	table.push_back(value);
	//initialize sum value
	if (n==0)
		sum=value;
	else
		sum+=value;
	n++;
	cacheValid=false;
}
//get the number of elements
int getNumberOfElements() {
	return n;
}

//get the average
T getAverage() {
	assert(n!=0);
	return sum * (1.0/((double) n));
}

//get the deviation
T getDeviation() {
	assert(n!=0);
	if (cacheValid)
		return deviationCache;
	T avg = getAverage();
	//Only one Element, deviation is 0, prevent div-by-zero
	if (n==1) {
		return (*table.begin()-(*table.begin()));
	}
	T dev;
	//Fancy way to write a 0 (zero).
	//  T can be anything so we can't simply write '=0'
	dev=*table.begin()-(*table.begin());
	for (typename std::list<T>::iterator it= table.begin(); it!=table.end(); it++) {
		T d=*table.begin()-avg;
		dev+=square(d);
	}
	dev=dev*(1.0/((double)n*(n-1)));
	dev=square_root(dev);
	deviationCache=dev;
	cacheValid=true;
	return dev;
}

private:
T sum;
int n;
std::list<T> table;
T deviationCache;
bool cacheValid;

};
#endif //AVERAGE_H
