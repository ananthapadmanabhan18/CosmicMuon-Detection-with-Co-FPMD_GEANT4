import ROOT

def plot_histograms(file_paths, legend_labels, colors):
    canvas = ROOT.TCanvas("canvas", "Histograms", 1600, 900)
    canvas.SetGrid()

    legend = ROOT.TLegend(0.7, 0.7, 0.9, 0.9)
    legend.SetBorderSize(1)


    histograms = []

    for i, file_path in enumerate(file_paths):
        data = []
        with open(file_path, 'r') as file:
            for line in file:
                data.append(float(line.strip()))

        histogram = ROOT.TH1F(f"histogram_{i}", "", 100, min(data), max(data))
        for value in data:
            histogram.Fill(value)


        histogram.SetLineColor(colors[i])
        histogram.SetStats(0)


        legend.AddEntry(histogram, legend_labels[i], "l")

        # Draw the histogram
        legend.SetX1NDC(0.7)
        legend.SetY1NDC(0.7)
        legend.SetX2NDC(0.9)
        legend.SetY2NDC(0.9)
        if i == 0:
            histogram.Draw()
        else:
            histogram.Draw("same")

        histograms.append(histogram)

    # Draw the legend
    legend.Draw()

    # Update the canvas
    canvas.Update()

    # Return the canvas and histograms (optional)
    return canvas, histograms

# Example usage
file_paths = ["data/output_1GeV.txt", "data/output_2GeV.txt", "data/output_4GeV.txt","data/output_40GeV.txt","data/output_50GeV.txt","data/output_60GeV.txt","data/output_70GeV.txt","data/output_80GeV.txt","data/output_90GeV.txt","data/output_100GeV.txt",]
legend_labels = ["1GeV", "2GeV", "4GeV", "40GeV", "50GeV", "60GeV", "70GeV", "80GeV", "90GeV", "100GeV"]
colors = [ROOT.kBlack, ROOT.kBlue, ROOT.kRed,ROOT.kGreen,ROOT.kYellow,ROOT.kOrange,ROOT.kViolet,ROOT.kTeal,ROOT.kPink,ROOT.kAzure]
canvas, histograms = plot_histograms(file_paths, legend_labels, colors)
ROOT.gApplication.Run()
