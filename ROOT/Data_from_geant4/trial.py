import ROOT
import numpy as np

canvas = ROOT.TCanvas("canvas", "Sine Curve", 800, 600)


graph = ROOT.TGraph()


num_points = 50


for i in range(num_points):
    x = (i/num_points)*np.pi
    y = ROOT.TMath.Sin(x)  
    graph.SetPoint(i, x, y)  


graph.SetLineColor(ROOT.kRed)
graph.SetLineWidth(2)

# Set the axis titles
graph.GetXaxis().SetTitle("x")
graph.GetYaxis().SetTitle("sin(x)")

area = graph.Integral()

print(area)

# Draw the graph on the canvas
graph.Draw("AL")

# Update the canvas
canvas.Update()

# Wait for user input to close the canvas
canvas.WaitPrimitive()
