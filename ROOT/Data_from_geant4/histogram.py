import ROOT

# Open the .txt file
file = open("data.txt", "r")

# Read the data from the file
data = []
for line in file:
    value = float(line.strip())
    data.append(value)

# Close the file
file.close()

# Create a ROOT canvas
canvas = ROOT.TCanvas("canvas", "Histogram", 800, 600)

# Create a histogram
histogram = ROOT.TH1F("histogram", "Histogram Title", 100, 0, 100)

# Fill the histogram with the data
for value in data:
    histogram.Fill(value)

# Set the histogram style
histogram.SetFillColor(ROOT.kBlue)

# Draw the histogram
histogram.Draw()

# Update the canvas
canvas.Update()

# Run the event loop
ROOT.gApplication.Run()
