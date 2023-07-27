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



#From Simulation#From Simulation#From Simulation#From Simulation#From Simulation#From Simulation#From Simulation#From Simulation#
yobs=[2.23347e-03,6.22615e-04,5.31900e-04,5.30453e-04,5.379379e-04,
    5.38996e-04,5.39097e-04,5.51859e-04,5.88838e-04,6.21229e-04,
    6.78881e-04,6.98291e-04,7.28788e-04,7.38014e-04,7.42980e-04,
    7.64237e-04,8.11232e-04,8.35784e-04,8.43543e-04,8.47351e-04]

#From Simulation#From Simulation#From Simulation#From Simulation#From Simulation#From Simulation#From Simulation#From Simulation#






#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical
x=[0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,2,3,4,5,6,10,25,50,75,100]
xev=[np.log(x[i]*(10**9)) for i in range(len(x))]
calc_energy=[]
for i in range(len(x)):
    calc_energy.append(get_tot_ED(x[i]))
#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical#Theorectical




#Calculated Plot#Calculated Plot#Calculated Plot#Calculated Plot#Calculated Plot#Calculated Plot#Calculated Plot#Calculated Plot
plt.scatter(xev,calc_energy,color='green',s=20,label='Energy Deposit Calculated from bethe-bloch Formula')
plt.plot(xev,calc_energy,color='green',)
#Calculated Plot#Calculated Plot#Calculated Plot#Calculated Plot#Calculated Plot#Calculated Plot#Calculated Plot#Calculated Plot



#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed
plt.scatter(xev,yobs,color='blue',s=20,label='Energy Deposit Observed From Geant4')
plt.plot(xev,yobs,color='blue',)
#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed#observed




#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting
plt.xlabel('Energy of the Incident Muon (Log(E_d (eV) ))')
plt.ylabel('Most Probable Value of Energy Deposit (MeV)')
plt.title("Most Probable Energy Deposit vs Incident Energy")
plt.legend(loc="upper right")
plt.show()
#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting#Plotting
