import ROOT
import numpy as np

def bethefn(x):
    return ((-1.665179153997467e-05)/(x*x))*(np.log(40.364180576082084 * x*x)-2*x*x) + 0.0007043300392805913


canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)
histogram = ROOT.TH1F("histogram", "Plot of Cosmic Muon Flux  vs Energy Deposit", 25, 0, 5000000)

histogram.SetXTitle("Total Energy Deposit of the Cosmic Muons (MeV)")
histogram.SetYTitle("Cosmic Muon Flux (no of particles cm^{-2}min^{-1})")
# histogram.SetLogy()
histogram.SetLineColor(ROOT.kRed)



file = open("Single_Energy/datas/Final_cosmic_data.txt", "r")


i=0
count=0
for line in file:
    value = float(line.strip())
    i=i+value
    count+=1
    if value!=0:
        histogram.Fill(bethefn(value*0.001))
        print(bethefn(value*0.001))
file.close()


integral = histogram.Integral()
histogram.Scale(1/(49.45*(76.63/60)))
canvas.SetLogy()

# landau_func = ROOT.TF1("landau_func", "landau", 0.0004,0.004)
# landau_func.SetParameters(0.0001,0.0007)
# histogram.Fit(landau_func, "R")
# fit_result = histogram.GetFunction("landau_func")

# mpv = fit_result.GetParameter(1)
# sigma = fit_result.GetParameter(2)
# print("Fit Parameters:")
# print("MPV:", mpv)
# print("Sigma:", sigma)


histogram.Draw()
canvas.Update()
ROOT.gApplication.Run()

