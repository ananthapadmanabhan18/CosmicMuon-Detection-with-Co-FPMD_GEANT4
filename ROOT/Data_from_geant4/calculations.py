import numpy as np

import matplotlib.pyplot as plt
import ROOT as root

def get_MPV_1(file):
    hist=histogram = root.TH1F("histogram", "Plot of Frequency vs Energy (MeV)", 500, 0, 4)
    for line in file:
        value = float(line.strip())
        histogram.Fill(value)
    file.close()
    landau_func = root.TF1("landau_func", "landau", histogram.GetXaxis().GetXmin(), histogram.GetXaxis().GetXmax())
    histogram.Fit(landau_func, "R")
    fit_result = histogram.GetFunction("landau_func")
    mpv = fit_result.GetParameter(1)
    return mpv


def get_MPV_2(file):
    hist=histogram = root.TH1F("histogram", "Plot of Frequency vs Energy (MeV)", 500, 0, 4)
    for line in file:
        value = float(line.strip())
        histogram.Fill(value)
    file.close()
    max=hist.GetMaximumBin()
    mpv=hist.GetBinCenter(max)

    return mpv


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




file=open("data/soutput_500MeV.txt")


# ED_sc=[0.916,3.108,1.492,1.748,1.644,]


print(get_MPV_2(file))


