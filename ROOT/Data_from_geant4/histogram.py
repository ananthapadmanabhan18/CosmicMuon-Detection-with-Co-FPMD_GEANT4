import ROOT
canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)




histo500 = ROOT.TH1F("histo500", "Plot of Frequency vs Energy (MeV)", 500, 0, 0.01)
histo500.SetXTitle("Energy (MeV)")
histo500.SetYTitle("Frequency")
histo500.SetLineColor(ROOT.kRed)
file = open("data/wsoutput_4GeV.txt", "r")
for line in file:
    value = float(line.strip())
    histo500.Fill(value)
file.close()







histo500.Draw()
canvas.Update()
ROOT.gApplication.Run()






# integral = histogram.Integral()
# histogram.Scale(1/integral)
# landau_func = ROOT.TF1("landau_func", "landau", 0.000001, 0.01)
# landau_func.SetParameters(0.000001,0.01)
# histogram.Fit(landau_func, "R")
# fit_result = histogram.GetFunction("landau_func")
# mpv = fit_result.GetParameter(1)
# sigma = fit_result.GetParameter(2)
# print("Fit Parameters:")
# print("MPV:", mpv)