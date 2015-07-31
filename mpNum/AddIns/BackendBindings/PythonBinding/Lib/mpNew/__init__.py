
import sys
s=sys.executable
print s
pos = s.find("\AddIns")
print pos
s2 = s[:pos]
print s2
sys.path.append(s2)

import clr
clr.AddReference("mpFormula")
from mpFormula import *

