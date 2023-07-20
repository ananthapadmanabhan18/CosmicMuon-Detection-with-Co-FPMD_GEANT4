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


# flist=["data/wsoutput_80MeV.txt","data/wsoutput_100MeV.txt","data/wsoutput_200MeV.txt","data/wsoutput_300MeV.txt","data/wsoutput_400MeV.txt","data/wsoutput_500MeV.txt","data/wsoutput_600MeV.txt","data/wsoutput_700MeV.txt","data/wsoutput_800MeV.txt","data/wsoutput_900MeV.txt","data/wsoutput_1GeV.txt","data/wsoutput_1.1GeV.txt","data/wsoutput_2GeV.txt","data/wsoutput_4GeV.txt",]


# mpv_ed_scint=[]

# for filep in flist:
#     mpv_ed_scint.append(get_mpv(0.00001,0.001,filep))


x=[0.08,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,1.1,2,4]
y_gas_with_sci=[0.0008889,0.0006009,0.0003588,0.0003268,0.0003265,0.0003402,0.0003490,0.0003591,0.0003711,0.0003831,0.0003877,0.0003941,0.0004594,0.0005360]
y_gas_without_sci=[0.000897756,0.0003572,0.00035724,0.0003335,0.000328244,0.0003370560,0.00036100,0.000376721,0.000381228,0.000462474,0.00039820,0.000462474,0.0005282,0.000564]

y_calculated=[]
for i in range(len(x)):
    y_calculated.append(get_tot_ED(x[i]))



plt.scatter(x,y_gas_with_sci,color='red',s=20,label='MPV values observed for Gas')
plt.plot(x,y_gas_with_sci,color='red',)


plt.scatter(x,y_gas_without_sci,color='blue',s=20,label='MPV without scintillation')
plt.plot(x,y_gas_without_sci,color='Blue',)



plt.scatter(x,y_calculated,color='green',s=20,label='MPV values Theoretical')
plt.plot(x,y_calculated,color='green',)

plt.xlabel('incident Energy (GeV)')
plt.ylabel('Most Probable Value (MeV)')
plt.title("Most Probable Energy Deposit vs Incident Energy")
plt.legend(loc="lower right")
plt.show()