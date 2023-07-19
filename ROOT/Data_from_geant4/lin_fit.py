import matplotlib.pyplot as plt
import numpy as np

x = []
y = []
errY=[]

with open("data/MPVdata.txt", 'r') as file:
    for line in file:
        values = line.strip("\t").split()
        x.append(float(values[0]))
        y.append(float(values[1]))
        errY.append(float(values[2]))


# for i in range(len(y)):
#     y[i]=np.log(y[i])


plt.errorbar(x, y, yerr=errY, color='red', ecolor='black', capsize=4)
# plt.scatter(x,y,color='black',s=20,label='MPV values')
# plt.plot(x,y,color='red',)
plt.xlabel('incident Energy (GeV)')
plt.ylabel('Most Probable Value (MeV)')
plt.title("MPV Energy Deposit vs Incident Energy")
plt.legend(loc="upper right")
plt.show()
