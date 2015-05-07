### Welcome to mpFormulaC!
The mpFormulaC library is based on a number of well-established libraries, which implement or support multiprecision arithmetic: [GMP](https://gmplib.org/), [MPFR](http://www.mpfr.org/), [FLINT](http://flintlib.org/), [ARB](http://fredrikj.net/arb/), [libmpdec](http://www.bytereef.org/mpdecimal/), [MPFRC++](http://www.holoborodko.com/pavel/mpfr/), [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page), [Boost Math Toolkit](http://www.boost.org/doc/libs/1_58_0/libs/math/doc/html/index.html) and [Boost Random](http://www.boost.org/doc/libs/1_58_0/doc/html/boost_random.html). Additional planned functionality includes integration in  [LibreOffice Calc](https://www.libreoffice.org/) (Windows, Mac OSX, GNU/Linux), with multiprecision support for the numerical functions of this spreadsheet programs.


### Manual
The manual is also available separately as pdf file: [mpFormulaC.pdf](https://github.com/mpFormula/C/raw/master/Manual/mpFormulaC.pdf).


### Quick start under Windows.
System requirements: Windows (Desktop) with [.NET Framework 4.x (Full)](http://www.microsoft.com/en-us/download/details.aspx?id=17718).

Download the .zip file and unzip it into a directory for which you have write access.
Within the unzipped directory double-click on `mpFormulaC.bat`. This will start the Python Console of the  [SharpDevelop](http://www.icsharpcode.net/OpenSource/SD/) IDE.
To confirm that mpFormulaC is working, type the following within the Python Console:

```
>>> from mpFormulaC import *
>>> pi
﻿mpf('3.141592653589793238462643402')
>>>
```
Still in the Sharpdevelop IDE, click on `Tools -> mpFormulaC Manual`, to open the manual in your default pdf viewer.

Within the manual, navigate to `Getting Started - Tutorials`, and follow the examples.
You can copy and paste the Python code of the examples from the manual into the Python Console.


### Quick start with LibreOffice Calc (Windows, Mac OSX, GNU/Linux)
To use the mpFormulaC functions from within LibreOffice Calc, you need to install the mpFormulaC add-in for LibreOffice.


### License
The mpFormulaC Library and Toolbox is free software. It is licensed under the GNU General Public License, Version 3 ([GPLv3](https://www.gnu.org/licenses/gpl.html)).






