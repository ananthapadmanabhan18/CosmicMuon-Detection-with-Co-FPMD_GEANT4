import ROOT
file = open("ROOT\Data_from_geant4\output.txt", "r")

data = []
for line in file:
    value = float(line.strip())
    data.append(value)

file.close()

canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)
histogram = ROOT.TH1F("histogram", "Histogram Title", 200, 0, 0.01)

for value in data:
    histogram.Fill(value)

# histogram.SetFillColor(ROOT.kBlue)
histogram.Draw()
canvas.Update()
ROOT.gApplication.Run()
