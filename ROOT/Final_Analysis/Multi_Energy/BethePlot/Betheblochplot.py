import matplotlib.pyplot as plt
import numpy as np

def get_tot_ED(energy):
    d=0.00172
    z=-1
    Z=18
    A=39.948
    g=energy/(105.658*0.001)
    b=np.sqrt(abs(1-(1/(g*g))))
    c=3*10**8
    v=b*c
    eta=b*g
    m=9.108*(10**-31)
    I=Z*(9.76+(58.8*(Z**(-1.19))))*1.6*10**-19
    M=1.883*10**-28
    s=m/M
    W=(2*m*eta*eta*c*c)/(1+(s*s)+(2*s*np.sqrt(1+(eta*eta))))
    E=0.1535*((d*z*z*Z)/(A*b*b))*(np.log((2*m*g*g*v*v*W)/(I*I))-(2*b*b))*(0.5)
    return E

ienergy=[0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,2,3,4,5,6,10,25,50,75,100]
iev=[np.log(ienergy[i]*(10**9)) for i in range(len(ienergy))]
calc_energy=[]
for i in range(len(ienergy)):
    calc_energy.append(get_tot_ED(ienergy[i]))



#Calculated Plot
plt.scatter(iev,calc_energy,color='black',s=20,label='Energy Deposit Calculated from bethe-bloch Formula')
plt.plot(iev,calc_energy,color='red',)

plt.xlabel('Energy of the Incident Muon (Log(eV))')
plt.ylabel('Most Probable Value of Energy Deposit (MeV)')
plt.title("Most Probable Energy Deposit vs Incident Energy")
plt.legend(loc="lower right")
plt.show()