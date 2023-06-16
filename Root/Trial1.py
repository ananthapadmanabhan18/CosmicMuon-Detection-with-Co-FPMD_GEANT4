import ROOT

# Create a TGraph from data file
g = ROOT.TGraph("data.txt")

# Define the function
f = ROOT.TF1("f", "[0]/(sin((x-[1])/2))^4", -0.523, 0.523)

# Fit the function to the graph
g.Fit(f)

# Set marker style and size
g.SetMarkerStyle(21)
g.SetMarkerSize(1)

# Set title
g.SetTitle("Plot of f vs theta")

# Draw the graph
g.Draw("AP")

# Optionally, you can set the line color and width:
# g.SetLineColor(ROOT.kRed)
# g.SetLineWidth(1)

# Run the event loop
ROOT.gApplication.Run()
