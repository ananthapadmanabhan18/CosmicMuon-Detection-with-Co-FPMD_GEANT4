import matplotlib.pyplot as plt
import ROOT as root
import calculations as cal

    

file=open("data/output_4GeV.txt", "r")



inc_E=[0.08,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,1.1,2,4]


MPV_E_gas=[0.0008889,0.0006009,0.0003588,0.0003268,0.0003265,0.0003402,0.0003490,0.0003591,0.0003711,0.0003831,0.0003877,0.0003941,0.0004594,0.0005360]



calc_ED_gas=[]

for i in range(len(inc_E)):
    calc_ED_gas.append(cal.get_tot_ED(inc_E[i]))




ED_sc=[]



plt.scatter(inc_E,MPV_E_gas,color='red',s=20,label='Most Probable Energy Deposit Obtained From the Histograms')
plt.plot(inc_E,MPV_E_gas,color='red',)

plt.scatter(inc_E,calc_ED_gas,color='green',s=20,label='Energy Deposit Calculated from bethe-bloch Formula')
plt.plot(inc_E,calc_ED_gas,color='green',)

plt.xlabel('Energy of the Incident Muon (GeV)')
plt.ylabel('Most Probable Value of Energy Deposit (MeV)')
plt.title("Most Probable Energy Deposit vs Incident Energy")
plt.legend(loc="lower right")
plt.show()





