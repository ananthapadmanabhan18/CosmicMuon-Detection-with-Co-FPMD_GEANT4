# import root.bin.ROOT as poi
import ROOT as poi


# Set ROOT to run in batch mode
poi.gROOT.SetBatch(True)

# Create a TGraph from data file
g = poi.TGraph("data.txt")

# Define the function
f = poi.TF1("f", "[0]/(sin((x-[1])/2))^4", -0.523, 0.523)

# Fit the function to the graph
g.Fit(f)

# Set marker style and size
g.SetMarkerStyle(21)
g.SetMarkerSize(1)

# Set title
g.SetTitle("Plot of f vs theta")
# # Optionally, you can set the line color and width:
# g.SetLineColor(ROOT.kRed)
# g.SetLineWidth(1)
# Create a canvas and draw the graph
canvas = poi.TCanvas("canvas", "Graph", 1600, 900)
g.Draw("AP")
g.Show("AP")



# Save the graph as a PNG image
# canvas.SaveAs("graph.png")
