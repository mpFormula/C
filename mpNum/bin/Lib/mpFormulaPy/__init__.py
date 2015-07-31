
import sys
s=sys.executable
pos = s.find('\\bin\\SharpDevelop.exe')
s2 = s[:pos]
s3 = "\\AddIns\\BackendBindings\\PythonBinding\\Lib"
sys.path.append(s2)
sys.path.append(s2 + s3)
from decimal import *
from fractions import *
from cmath import *

import clr
clr.AddReference("mpFormulaNET")
from mpFormulaNET import *

#plot = mp.plot
#cplot = mp.cplot
#splot = mp.splot

#mpi = iv._mpi


extraprec = mp.extraprec
extradps = mp.extradps
workprec = mp.workprec
workdps = mp.workdps
autoprec = mp.autoprec
maxcalls = mp.maxcalls
memoize = mp.memoize

mag = mp.mag

bernfrac = mp.bernfrac

qfrom = mp.qfrom
mfrom = mp.mfrom
kfrom = mp.kfrom
taufrom = mp.taufrom
qbarfrom = mp.qbarfrom
ellipfun = mp.ellipfun
jtheta = mp.jtheta
kleinj = mp.kleinj

qp = mp.qp
qhyper = mp.qhyper
qgamma = mp.qgamma
qfac = mp.qfac

nint_distance = mp.nint_distance

isinf = mp.isinf
isnan = mp.isnan
isnormal = mp.isnormal
isint = mp.isint
isfinite = mp.isfinite
almosteq = mp.almosteq
nan = mp.nan
rand = mp.rand

fraction = mp.fraction

linspace = mp.linspace
arange = mp.arange

mpmathify = convert = mp.convert
mpc = mp.mpc

nstr = mp.nstr
chop = mp.chop

fneg = mp.fneg
fadd = mp.fadd
fsub = mp.fsub
fmul = mp.fmul
fdiv = mp.fdiv
fprod = mp.fprod


mpf = mp.mpf
j = mp.j()
exp = mp.exp
expj = mp.expj
expjpi = mp.expjpi
ln = mp.ln
im = mp.im
re = mp.re
inf = mp.inf()
sign = mp.sign


ln2 = mp.ln2
ln10 = mp.ln10

eps = mp.eps()
pi = mp.pi()
phi = mp.phi()
e = mp.e()
euler = mp.euler()
catalan = mp.catalan()
khinchin = mp.khinchin()
glaisher = mp.glaisher()
apery = mp.apery()
degree = mp.degree()
twinprime = mp.twinprime()
mertens = mp.mertens()



ldexp = mp.ldexp
frexp = mp.frexp

fsum = mp.fsum
fdot = mp.fdot

sqrt = mp.sqrt
cbrt = mp.cbrt
exp = mp.exp
ln = mp.ln
log = mp.log
log10 = mp.log10
power = mp.power
cos = mp.cos
sin = mp.sin
tan = mp.tan
cosh = mp.cosh
sinh = mp.sinh
tanh = mp.tanh
acos = mp.acos
asin = mp.asin
atan = mp.atan
asinh = mp.asinh
acosh = mp.acosh
atanh = mp.atanh
sec = mp.sec
csc = mp.csc
cot = mp.cot
sech = mp.sech
csch = mp.csch
coth = mp.coth
asec = mp.asec
acsc = mp.acsc
acot = mp.acot
asech = mp.asech
acsch = mp.acsch
acoth = mp.acoth
cospi = mp.cospi
sinpi = mp.sinpi
sinc = mp.sinc
sincpi = mp.sincpi
cos_sin = mp.cos_sin
cospi_sinpi = mp.cospi_sinpi
fabs = mp.fabs
conj = mp.conj
floor = mp.floor
ceil = mp.ceil
nint = mp.nint
frac = mp.frac
root = mp.root
nthroot = mp.nthroot
hypot = mp.hypot
fmod = mp.fmod
arg = mp.arg
phase = mp.phase
polar = mp.polar
rect = mp.rect
degrees = mp.degrees
radians = mp.radians
atan2 = mp.atan2
fib = mp.fib
fibonacci = mp.fibonacci
lambertw = mp.lambertw
zeta = mp.zeta
altzeta = mp.altzeta
gamma = mp.gamma
rgamma = mp.rgamma
factorial = mp.factorial
fac = mp.fac
fac2 = mp.fac2
beta = mp.beta
betainc = mp.betainc
psi = mp.psi
polygamma = mp.polygamma
digamma = mp.digamma
harmonic = mp.harmonic
bernoulli = mp.bernoulli
bernfrac = mp.bernfrac
stieltjes = mp.stieltjes
hurwitz = mp.hurwitz
dirichlet = mp.dirichlet
bernpoly = mp.bernpoly
eulerpoly = mp.eulerpoly
eulernum = mp.eulernum
polylog = mp.polylog
clsin = mp.clsin
clcos = mp.clcos
gammainc = mp.gammainc
gammaprod = mp.gammaprod
binomial = mp.binomial
rf = mp.rf
ff = mp.ff
hyper = mp.hyper
hyp0f1 = mp.hyp0f1
hyp1f1 = mp.hyp1f1
hyp1f2 = mp.hyp1f2
hyp2f1 = mp.hyp2f1
hyp2f2 = mp.hyp2f2
hyp2f0 = mp.hyp2f0
hyp2f3 = mp.hyp2f3
hyp3f2 = mp.hyp3f2
hyperu = mp.hyperu
hypercomb = mp.hypercomb
meijerg = mp.meijerg
appellf1 = mp.appellf1
appellf2 = mp.appellf2
appellf3 = mp.appellf3
appellf4 = mp.appellf4
hyper2d = mp.hyper2d
bihyper = mp.bihyper
erf = mp.erf
erfc = mp.erfc
erfi = mp.erfi
erfinv = mp.erfinv
npdf = mp.npdf
ncdf = mp.ncdf
expint = mp.expint
e1 = mp.e1
ei = mp.ei
li = mp.li
ci = mp.ci
si = mp.si
chi = mp.chi
shi = mp.shi
fresnels = mp.fresnels
fresnelc = mp.fresnelc
airyai = mp.airyai
airybi = mp.airybi
airyaizero = mp.airyaizero
airybizero = mp.airybizero
scorergi = mp.scorergi
scorerhi = mp.scorerhi
ellipk = mp.ellipk
ellipe = mp.ellipe
ellipf = mp.ellipf
ellippi = mp.ellippi
elliprc = mp.elliprc
elliprj = mp.elliprj
elliprf = mp.elliprf
elliprd = mp.elliprd
elliprg = mp.elliprg
agm = mp.agm
jacobi = mp.jacobi
chebyt = mp.chebyt
chebyu = mp.chebyu
legendre = mp.legendre
legenp = mp.legenp
legenq = mp.legenq
hermite = mp.hermite
pcfd = mp.pcfd
pcfu = mp.pcfu
pcfv = mp.pcfv
pcfw = mp.pcfw
gegenbauer = mp.gegenbauer
laguerre = mp.laguerre
spherharm = mp.spherharm
besselj = mp.besselj
j0 = mp.j0
j1 = mp.j1
besseli = mp.besseli
bessely = mp.bessely
besselk = mp.besselk
besseljzero = mp.besseljzero
besselyzero = mp.besselyzero
hankel1 = mp.hankel1
hankel2 = mp.hankel2
struveh = mp.struveh
struvel = mp.struvel
angerj = mp.angerj
webere = mp.webere
lommels1 = mp.lommels1
lommels2 = mp.lommels2
whitm = mp.whitm
whitw = mp.whitw
ber = mp.ber
bei = mp.bei
ker = mp.ker
kei = mp.kei
coulombc = mp.coulombc
coulombf = mp.coulombf
coulombg = mp.coulombg
lambertw = mp.lambertw
barnesg = mp.barnesg
superfac = mp.superfac
hyperfac = mp.hyperfac
loggamma = mp.loggamma
siegeltheta = mp.siegeltheta
siegelz = mp.siegelz
grampoint = mp.grampoint
zetazero = mp.zetazero
riemannr = mp.riemannr
primepi = mp.primepi
primepi2 = mp.primepi2
primezeta = mp.primezeta
bell = mp.bell
polyexp = mp.polyexp
expm1 = mp.expm1
powm1 = mp.powm1
unitroots = mp.unitroots
cyclotomic = mp.cyclotomic
mangoldt = mp.mangoldt
secondzeta = mp.secondzeta
nzeros = mp.nzeros
backlunds = mp.backlunds
lerchphi = mp.lerchphi
stirling1 = mp.stirling1
stirling2 = mp.stirling2
pslq = mp.pslq
identify = mp.identify
findpoly = mp.findpoly


polyval = mp.polyval
polyroots = mp.polyroots

findroot = mp.findroot

nsum = mp.nsum
nsum2d = mp.nsum2d
nsum3d = mp.nsum3d
sumem = mp.sumem
sumap = mp.sumap
nprod = mp.nprod
limit = mp.limit
richardson = mp.richardson
shanks = mp.shanks
levin = mp.levin
cohen_alt = mp.cohen_alt

##difference = mp.difference  # unknown function
diff = mp.diff
diffs = mp.diffs
diffs_prod = mp.diffs_prod
diffs_exp = mp.diffs_exp
##diffun = mp.diffun  # unknown function
differint = mp.differint

quad = mp.quad
quad2d = mp.quad2d
quad3d = mp.quad3d
quadosc = mp.quadosc

quadgl = mp.quadgl # these are classes, not functions
quadts = mp.quadts # these are classes, not functions


odefun = mp.odefun
taylor = mp.taylor
pade = mp.pade
chebyfit = mp.chebyfit
fourier = mp.fourier
fourierval = mp.fourierval



matrix = mp.matrix
eye = mp.eye
diag = mp.diag
zeros = mp.zeros
ones = mp.ones
hilbert = mp.hilbert
randmatrix = mp.randmatrix
#swap_row = mp.swap_row
#extend = mp.extend
norm = mp.norm
mnorm = mp.mnorm

unitvector = mp.unitvector

det = mp.det
cond = mp.cond
inverse = mp.inverse
#residual = mp.residual

lu = mp.lu
qr = mp.qr
cholesky = mp.cholesky

lu_solve = mp.lu_solve
qr_solve = mp.qr_solve
cholesky_solve = mp.cholesky_solve


svd_r = mp.svd_r
svd_c = mp.svd_c
svd = mp.svd


hessenberg = mp.hessenberg
schur = mp.schur

eig = mp.eig
eig_sort = mp.eig_sort
eigsy = mp.eigsy
eighe = mp.eighe
eigh = mp.eigh
#gauss_quadrature = mp.gauss_quadrature

expm = mp.expm
sqrtm = mp.sqrtm
logm = mp.logm
sinm = mp.sinm
cosm = mp.cosm

powm = mp.powm
