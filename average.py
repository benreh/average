#!/usr/bin/python
# Copyright 2012 Benjamin Reh <benjamin.reh@iwr.uni-heidelberg.de>
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.

# This is more or less the little brother of the C++-Class
# It's not really efficient or well coded, but it's python!
 
import numpy as np

def average(arr):
	#Some workaround to initialize with the correct datatype
	avg=arr[0]
	avg=avg-arr[0]
	dev=avg
	
	for v in arr:
		avg=avg+v
	avg=avg*1.0/float(len(arr))

	for v in arr:
		dev=dev+np.square(avg-v)
	dev=dev*1.0/(len(arr)-1)
	np.sqrt(dev)
	return (avg,dev)
		
def main():
	print average([2.,3.,5])
	print average([np.array([2.,0.2]),np.array([3.,.3])])

if __name__ == "__main__":
	main()
