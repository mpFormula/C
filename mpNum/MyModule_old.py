#
#class MyClass:
#	def __init__(self):
#		pass

#    def __init__(self):
#        print sys.path


import sys

for arg in sys.argv:
	sys.path.append(arg);
	
from mpmath import *

import clr

clr.AddReference('MatrixClass2')
from MatrixClass2 import mp as mp2, mpNum

class MyClass:
    def __init__(self):
        pass

    def pygetmp(self):
    	return mp

    def pygetmp2(self):
    	return mp2
    	
    def pympf(self, x):
    	return mpf(x)
    	
    def pympc(self, z):
    	return mpc(z)

    def mpmathToString(self, x, n):
        return nstr(x, n)
    	
    def pyeval(self, s):
    	return eval(s)

    def pyexec(self, s):
    	Result = 0;
    	exec(s);
    	return Result

    def pyexec2(self, s1, s2):
    	Result = 0;
    	exec(s1);
    	exec(s2);
    	return Result

    def somemethod(self):
        print "in some method"

    def isodd(self, n):
        return 1 == n % 2
       
    def mp2func(self, a, b):
    	mp2.FloatingPointType = 3;
        mp2.Prec10 = 60;
        x1 = mp2.CNum(a);
        x2 = mp2.CNum(b);
        x3 = x1 / x2;
        return x3.Str()

