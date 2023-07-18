import ROOT
canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)
histogram1 = ROOT.TH1F("histogram", "Plot of Frequency vs Energy (MeV)", 500, 0, 0.01)

histogram1.SetXTitle("Energy (MeV)")
histogram1.SetYTitle("Frequency")
histogram1.SetLineColor(ROOT.kRed)



file1 = open("/home/apmnair18/Documents/GitHub/Geant4_ROOT/Geant4/Simulation_lab/build/output.txt", "r")


i=0
count=0
for line in file1:
    value = float(line.strip())
    i=i+value
    count+=1
    histogram1.Fill(value)
file1.close()





histogram1.Draw()

canvas.Update()
ROOT.gApplication.Run()
