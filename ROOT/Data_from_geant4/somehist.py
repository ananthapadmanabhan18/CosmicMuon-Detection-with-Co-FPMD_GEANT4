import ROOT

# Function to normalize histogram
def normalize_histogram(hist):
    hist.Scale(1.0 / hist.Integral())

# List of file paths for the 4 text files
file_paths = ["data/output_1GeV.txt","data/output_1.1GeV.txt","data/output_2GeV.txt","data/output_4GeV.txt"]  # Replace with actual file paths

# Create a TCanvas to display histograms
canvas = ROOT.TCanvas("canvas", "Histograms", 1600, 900)

# Create a THStack to stack histograms on the same graph
stack = ROOT.THStack("hist_stack", "Normalized Histograms")

# Create a TLegend to add legends to the plot
legend = ROOT.TLegend(0.65, 0.65, 0.85, 0.85)  # (x1, y1, x2, y2) coordinates for the legend

# List to store the histograms and their corresponding names
histograms = []
hist_names = file_paths[:]
pyroot_colors = [ROOT.kBlue, ROOT.kGreen, ROOT.kRed, ROOT.kCyan,ROOT.kBlack]
# Loop through each file and create histograms
i=0
for idx, file_path in enumerate(file_paths):
    # Read data from the text file
    data = []
    with open(file_path, 'r') as file:
        for line in file:
            data.append(float(line.strip()))

    # Create histogram and fill with data
    hist = ROOT.TH1D("hist", hist_names[idx], 600, 0,0.01)  # Adjust the range as needed
    for value in data:
        hist.SetLineColor(pyroot_colors[i])
        hist.Fill(value)


    # Normalize the histogram
    # normalize_histogram(hist)
    
    # Add histogram to the stack
    stack.Add(hist)
    histograms.append(hist)

    # Add histogram name to the legend
    legend.AddEntry(hist, hist_names[idx], 'f')  # 'f' option for filled bars
    i=i+1


canvas.cd()

# Draw the THStack on the canvas
stack.Draw("nostack")  # "nostack" option to prevent histograms from stacking on top of each other



# Customize the plot
stack.SetTitle("Histograms for Incident Energies 1-4 GeV")
stack.GetXaxis().SetTitle("Energy Deposited (GeV)")
stack.GetYaxis().SetTitle("Frequency (Number of Particles in Each Energy Range)")
stack.GetXaxis().CenterTitle()
stack.GetYaxis().CenterTitle()
stack.GetYaxis().SetTitleOffset(1.2)
stack.SetMaximum(stack.GetMaximum() * 1.2)


legend.SetBorderSize(0)
legend.SetTextSize(0.04)
legend.Draw()

# Display the plot
canvas.Update()
canvas.Modified()
# canvas.Print("histograms_stacked_with_legend.png")  # Save the plot as a PNG file


# output_file = ROOT.TFile("1-2.root", "RECREATE")
# for hist in histograms:
#     hist.Write()
# stack.Write()
# output_file.Close()

ROOT.gApplication.Run()