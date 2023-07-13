import numpy as np

def dEdx(energy):
    Z=0.018
    z=1
    A=36
    Na=6.022*(10**23)
    r=2.56*(10**(-13)) #m
    rho=1720 #Kg/m3
    m=1.883*10**-28
    c=3*10**8
    g=(energy*(10**9)*1.6*10**-19)/(m*c*c) #energy in GeV
    b=np.sqrt(1-(1/(g*g)))
    v=b*c
    T=2*m*b*b*g*g*c*c
    I=15.75*1.6*10**-19
    K=2*np.pi*Na*m*((r*c)**2)*rho*((z*Z*z)/(A*b*b))  
    dedx=K*((np.log((2*m*g*g*v*v*T)/(I*I)))-(2*b*b))  
    return (dedx/100)/(1.6*10**-13)


print(dEdx(1)*0.5)