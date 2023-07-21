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
file_paths= ["data/output_80MeV.txt"]
legend_labels = ["0.08GeV"]
# file_paths= ["data/output_80MeV.txt","data/output_100MeV.txt","data/output_200MeV.txt","data/output_300MeV.txt","data/output_400MeV.txt","data/output_500MeV.txt","data/output_600MeV.txt","data/output_700MeV.txt","data/output_800MeV.txt","data/output_900MeV.txt","data/output_1GeV.txt","data/output_1.1GeV.txt","data/output_2GeV.txt","data/output_4GeV.txt",]
# legend_labels = ["0.08GeV", "0.1GeV", ".2GeV", "0.3GeV", "0.4GeV", "0.5GeV", "0.6GeV", "0.7GeV", "0.8GeV", "0.9GeV","1GeV","2GeV","4GeV"]
colors = [ROOT.kBlack]
canvas, histograms = plot_histograms(file_paths, legend_labels, colors)
ROOT.gApplication.Run()
