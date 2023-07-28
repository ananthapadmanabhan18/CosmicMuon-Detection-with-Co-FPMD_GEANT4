import ROOT
import numpy as np


canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)
histogram = ROOT.TH1F("histogram", "Distribution of Momentum Of Incident Cosmic Muons",500, 0,15)

histogram.SetXTitle(" Incident Muon Momentum (GeV/c) ")
histogram.SetYTitle("Frequency (No of Cosmic Muons in the Momentum range) ")
histogram.SetLineColor(ROOT.kRed)



file = open("EcoMug_Distributions/p_data.txt", "r")


i=0
count=0
for line in file:
    value = float(line.strip())
    i=i+value
    count+=1
    histogram.Fill(value)
file.close()


# integral = histogram.Integral()
# histogram.Scale(1/integral)


# landau_func = ROOT.TF1("landau_func", "landau",0,14)
# landau_func.SetParameters(0,3)
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
