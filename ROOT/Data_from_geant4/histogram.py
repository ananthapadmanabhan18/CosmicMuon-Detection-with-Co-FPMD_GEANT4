import ROOT
canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)
histogram = ROOT.TH1F("histogram", "Plot of Frequency vs Energy (MeV)", 500, 0, 0.01)

histogram.SetXTitle("Energy (MeV)")
histogram.SetYTitle("Frequency")

file = open("ROOT/Data_from_geant4/output.txt", "r")


i=0
count=0
for line in file:
    value = float(line.strip())
    i=i+value
    count+=1
    histogram.Fill(value)
file.close()


totalno = histogram.Integral()
area = histogram.Integral("width")

print("Total Number of particles = ", totalno)



histogram.Scale(1.0 / totalno)
area = histogram.Integral("width")
print("Total Energy of 1 Muon = ", area*pow(10,6), "eV")
print("Avg=", (i/count)*1000000)


histogram.Draw()
canvas.Update()
ROOT.gApplication.Run()