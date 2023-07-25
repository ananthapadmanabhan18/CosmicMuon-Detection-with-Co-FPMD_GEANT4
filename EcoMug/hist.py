import ROOT

data_file = "p_data.txt"

data_values = []

with open(data_file, "r") as file:
    for line in file:
        value = float(line)
        data_values.append(value)


canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)
histogram = ROOT.TH1F("histogram", "Data Histogram", 500, min(data_values), max(data_values))


for value in data_values:
    histogram.Fill(value)


histogram.SetLineColor(ROOT.kBlue)
histogram.Draw()
histogram.GetXaxis().SetTitle("Theta")
histogram.GetYaxis().SetTitle("Frequency")
canvas.Draw()
ROOT.gApplication.Run()
