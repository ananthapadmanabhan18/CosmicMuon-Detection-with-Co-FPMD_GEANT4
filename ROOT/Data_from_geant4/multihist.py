import ROOT

def plot_histograms(file_paths, legend_labels, colors):
    # Create a canvas to display the histograms
    canvas = ROOT.TCanvas("canvas", "Histograms", 800, 600)
    canvas.SetGrid()

    # Create a legend to display the labels
    legend = ROOT.TLegend(0.7, 0.7, 0.9, 0.9)
    legend.SetBorderSize(0)

    histograms = []

    for i, file_path in enumerate(file_paths):
        # Read data from the file
        data = []
        with open(file_path, 'r') as file:
            for line in file:
                data.append(float(line.strip()))

        # Create a histogram from the data
        histogram = ROOT.TH1F(f"histogram_{i}", "", 100, min(data), max(data))
        for value in data:
            histogram.Fill(value)

        # Set the histogram color
        histogram.SetLineColor(colors[i])

        # Add the histogram and label to the legend
        legend.AddEntry(histogram, legend_labels[i], "l")

        # Draw the histogram
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
file_paths = ["output_1GeV.txt", "output_2GeV.txt", "output_4GeV.txt"]
legend_labels = ["1GeV", "2GeV", "3GeV"]
colors = [ROOT.kRed, ROOT.kBlue, ROOT.kGreen]

canvas, histograms = plot_histograms(file_paths, legend_labels, colors)



# Keep the program running to display the canvas (optional)
ROOT.gApplication.Run()
