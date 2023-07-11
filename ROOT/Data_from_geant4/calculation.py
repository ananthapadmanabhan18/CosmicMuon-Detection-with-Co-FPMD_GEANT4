import numpy as np
import math as m


def dEdx(energy):
    r=2.56*10**(-13)
    m=1.8835327*pow(10,-28)
    c=3*10**8
    Na=6.022*10**23
    rho=1720
    g=(energy*1.6*10**(-10))/(m*c*c)
    b=np.sqrt(1-(1/(g*g)))
    v=c*b
    A=36
    Z=18
    z=-1.6*pow(10,-19)
    W=2*m*c*c*(b*g)*(b*g)
    I=Z*(9.76+58.8*(Z**(-1.19)))*1.6*pow(10,-19)

    dEdx=((2*(np.pi)*Na*r*r*m*c*c*rho)/(b*b))*(np.log(2*m*g*g*v*v*W/(I*I))-(2*b*b))*(Z*z/A)
    return dEdx

print(dEdx(1))