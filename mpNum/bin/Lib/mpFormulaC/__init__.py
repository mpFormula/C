
import sys
s=sys.executable
pos = s.find('\\bin\\SharpDevelop.exe')
s2 = s[:pos]
s3 = "\\AddIns\\BackendBindings\\PythonBinding\\Lib"
s4 = "\\Win32"
sys.path.append(s2)
sys.path.append(s2 + s3)
sys.path.append(s2 + s4)

from fractions import *
from cmath import *

import clr
clr.AddReference("mpNumerix2.dll")
from mpNumerix2 import *

