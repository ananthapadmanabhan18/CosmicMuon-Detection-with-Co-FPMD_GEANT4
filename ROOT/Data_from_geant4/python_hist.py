import matplotlib.pyplot as plt
import numpy as np




def get_tot_ED(energy):
    d=0.00172
    z=-1
    Z=18
    A=39.948
    g=energy/(105.658*0.001)
    b=np.sqrt(1-(1/(g*g)))
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


def get_mpv(min,max,filepath):
    file_path = filepath
    with open(file_path, 'r') as file:
        data = [float(line.strip()) for line in file]
    hist, bin_edges = np.histogram(data, bins=500, density=True)
    bin_centers = (bin_edges[:-1] + bin_edges[1:]) / 2
    range_min = min
    range_max = max
    mask = (bin_centers >= range_min) & (bin_centers <= range_max)
    max_bin_center = bin_centers[mask][np.argmax(hist[mask])]
    # print("Bin center with the maximum value in the range [{}, {}]: {:.2f}".format(range_min, range_max, max_bin_center))
    # # Step 4: Plot the histogram
    # plt.hist(data, bins=500, alpha=0.5, edgecolor='black', density=True)
    # plt.title('Normalized Histogram')
    # plt.xlabel('Values')
    # plt.ylabel('Frequency (Normalized)')
    # plt.axvline(max_bin_center, color='red', linestyle='dashed', linewidth=2, label='Max in range')
    # plt.legend()
    # plt.show()
    return max_bin_center


flist=["data/soutput_80MeV.txt","data/soutput_100MeV.txt","data/soutput_200MeV.txt","data/soutput_300MeV.txt","data/soutput_400MeV.txt","data/soutput_500MeV.txt","data/soutput_600MeV.txt","data/soutput_700MeV.txt","data/soutput_800MeV.txt","data/soutput_900MeV.txt","data/soutput_1GeV.txt","data/soutput_1.1GeV.txt","data/soutput_2GeV.txt","data/soutput_4GeV.txt",]


mpv_ed_scint=[]

for filep in flist:
    mpv_ed_scint.append(get_mpv(1.1,4,filep)/1000)


inc_E=[0.08,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,1.1,2,4]
MPV_E_gas=[0.0008889,0.0006009,0.0003588,0.0003268,0.0003265,0.0003402,0.0003490,0.0003591,0.0003711,0.0003831,0.0003877,0.0003941,0.0004594,0.0005360]
calc_ED_gas=[]

for i in range(len(inc_E)):
    calc_ED_gas.append(get_tot_ED(inc_E[i]))



plt.scatter(inc_E,MPV_E_gas,color='red',s=20,label='MPV values observed for Gas')
plt.plot(inc_E,MPV_E_gas,color='red',)


tempx=inc_E[:]
tempx.pop(2)
tempy=mpv_ed_scint[:]
tempy.pop(2)
plt.scatter(tempx,tempy,color='blue',s=20,label='For the Scintillation')
plt.plot(tempx,tempy,color='Blue',)



plt.scatter(inc_E,calc_ED_gas,color='green',s=20,label='MPV values Theoretical')
plt.plot(inc_E,calc_ED_gas,color='green',)

plt.xlabel('incident Energy (GeV)')
plt.ylabel('Most Probable Value (MeV)')
plt.title("Most Probable Energy Deposit vs Incident Energy")
plt.legend(loc="lower right")
plt.show()