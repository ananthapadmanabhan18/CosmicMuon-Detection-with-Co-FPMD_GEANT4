import matplotlib.pyplot as plt
import ROOT as root

def get_MPV(file):
    hist=histogram = root.TH1F("histogram", "Plot of Frequency vs Energy (MeV)", 500, 0, 0.01)
    for line in file:
        value = float(line.strip())
        histogram.Fill(value)
    file.close()
    landau_func = root.TF1("landau_func", "landau", histogram.GetXaxis().GetXmin(), histogram.GetXaxis().GetXmax())
    histogram.Fit(landau_func, "R")
    fit_result = histogram.GetFunction("landau_func")
    mpv = fit_result.GetParameter(1)
    return mpv
    

file=open("data/output_4GeV.txt", "r")



inc_E=[0.08,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,1.1,2,4]


MPV_E=[0.0008889,
       0.0006009,
       0.0003588,
       0.0003268,
       0.0003265,
       0.0003402,
       0.0003490,
       0.0003591,
       0.0003711,
       0.0003831,
       0.0003877,
       0.0003941,
       0.0004594,
       0.0005360
       ]

plt.scatter(inc_E,MPV_E,color='black',s=20,label='MPV values')
plt.plot(inc_E,MPV_E,color='red',)
plt.xlabel('incident Energy (GeV)')
plt.ylabel('Most Probable Value (MeV)')
plt.title("Most Probable Energy Deposit vs Incident Energy")
plt.legend(loc="upper right")
plt.show()





