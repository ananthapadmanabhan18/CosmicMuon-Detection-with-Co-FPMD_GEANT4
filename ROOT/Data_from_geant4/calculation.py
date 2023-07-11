import numpy as np
import math as m


def dEdx():
    r=2.56*pow(10,13)
    m=1.8835327*pow(10,-28)
    c=3*pow(10,8)
    Na=6.022*(pow(10,23))
    rho=1720

    dEdx=2*np.pi()*Na*r*r*m*c*c*rho
    return dEdx

print(dEdx())