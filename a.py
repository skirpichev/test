from mpmath import *
mp.prec = 64
r = libmp.normalize(0, libmp.MPZ(993433593741030721587), -70, 70, 64, 'n')
print(r)
r = libmp.normalize(0, libmp.MPZ(993433593741030721601), -70, 70, 64, 'n')
print(r)
