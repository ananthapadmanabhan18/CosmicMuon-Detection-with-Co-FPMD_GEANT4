import ROOT
canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)
histogram = ROOT.TH1F("histogram", "Plot of Frequency vs Energy (MeV)", 500, 0, 0.01)

histogram.SetXTitle("Energy (MeV)")
histogram.SetYTitle("Frequency")

file = open("output.txt", "r")

for line in file:
    value = float(line.strip())
    histogram.Fill(value)
file.close()


histogram.Draw()
canvas.Update()

totalno = histogram.Integral()
print("Total Area of the curve:", totalno)

area = histogram.Integral("width")
print("Area under curve:", area)

print("The Area/Muon is:", totalno/area)

ROOT.gApplication.Run()
