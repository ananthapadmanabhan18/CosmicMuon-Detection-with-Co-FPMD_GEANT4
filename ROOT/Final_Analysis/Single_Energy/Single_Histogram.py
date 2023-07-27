import ROOT
canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)
histogram = ROOT.TH1F("histogram", "Plot of Frequency  vs Energy Deposit  (GeV)", 100, 0, 0.005)

histogram.SetXTitle("Incident Energy of the Muons on the Gas Mixture (GeV)")
histogram.SetYTitle("Frequency (No of Particles in the Energy Range)")
histogram.SetLineColor(ROOT.kRed)



file = open("datas/Final_cosmic_data.txt", "r")


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
