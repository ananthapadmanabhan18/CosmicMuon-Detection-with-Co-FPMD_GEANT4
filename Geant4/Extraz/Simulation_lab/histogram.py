import ROOT
canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)
histogram1 = ROOT.TH1F("histogram", "Plot of Frequency vs Energy (MeV)", 500, 0, 0.01)

histogram1.SetXTitle("Energy (MeV)")
histogram1.SetYTitle("Frequency")
histogram1.SetLineColor(ROOT.kRed)

# histogram2= ROOT.TH1F("histogram", "Plot of Frequency vs Energy (MeV)", 500, 0, 0.01)


file1 = open("build/output.txt", "r")


i=0
count=0
for line in file1:
    value = float(line.strip())
    i=i+value
    count+=1
    histogram1.Fill(value)
file1.close()



# i=0
# count=0
# for line in file2:
#     value = float(line.strip())
#     i=i+value
#     count+=1
#     histogram2.Fill(value)
# file2.close()



histogram1.Draw()
# histogram2.Draw("same")
canvas.Update()
ROOT.gApplication.Run()
