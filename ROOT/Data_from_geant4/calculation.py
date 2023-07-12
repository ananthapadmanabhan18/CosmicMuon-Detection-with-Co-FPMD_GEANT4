import numpy as np

def dEdx(energy,A,Z,z,I):
    K = 63.4194 #MeV
    g=energy/(0.106) #energy in GeV
    b=np.sqrt(1-(1/(g*g)))
    m=1.883*10**s-28
    return ((K*(z**2)*Z)/(A*b*b))*((0.5*np.log(()/()))-(b*b))