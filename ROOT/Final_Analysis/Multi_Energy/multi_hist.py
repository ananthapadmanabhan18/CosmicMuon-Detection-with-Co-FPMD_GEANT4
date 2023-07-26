import ROOT

canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)


energylist=[100,200,300,400,500,600,700,800,900,1000,2000,3000,4000,5000,6000,10000,25000,50000,75000,100000]
filepathlist   = [['Multi_Energy/datas/100MeV.txt','Multi_Energy/datas/200MeV.txt','Multi_Energy/datas/300MeV.txt', 'Multi_Energy/datas/400MeV.txt', 'Multi_Energy/datas/500MeV.txt'], 
                ['Multi_Energy/datas/600MeV.txt', 'Multi_Energy/datas/700MeV.txt', 'Multi_Energy/datas/800MeV.txt', 'Multi_Energy/datas/900MeV.txt', 'Multi_Energy/datas/1000MeV.txt'], 
                ['Multi_Energy/datas/2000MeV.txt', 'Multi_Energy/datas/3000MeV.txt', 'Multi_Energy/datas/4000MeV.txt', 'Multi_Energy/datas/5000MeV.txt', 'Multi_Energy/datas/6000MeV.txt'],
                ['Multi_Energy/datas/10GeV.txt','Multi_Energy/datas/25GeV.txt','Multi_Energy/datas/50GeV.txt','Multi_Energy/datas/75GeV.txt','Multi_Energy/datas/100GeV.txt']]
flist500=filepathlist[0][:]
flist1000=filepathlist[1][:]
flist6000=filepathlist[2][:]
flist100000=filepathlist[3][:]

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
        histogram = ROOT.TH1F(f"histogram_{i}", "",500, min(data), max(data))
        for value in data:
            histogram.Fill(value)
        histogram.SetLineColor(colors[i])
        histogram.SetStats(0)
        legend.AddEntry(histogram, legend_labels[i], "l")
        legend.SetX1NDC(0.7)
        legend.SetY1NDC(0.7)
        legend.SetX2NDC(0.9)
        legend.SetY2NDC(0.9)
        if i == 0:
            histogram.Draw()
        else:
            histogram.Draw("same")
        histograms.append(histogram)
    legend.Draw()
    canvas.Update()
    return canvas, histograms



flist500=filepathlist[0][:]
flist1000=filepathlist[1][:]
flist6000=filepathlist[2][:]
flist100000=filepathlist[3][:]

legend500 = ["100MeV","200MeV","300MeV","400MeV","500MeV"]
legend1000 = ["600MeV","700MeV","800MeV","900MeV","1000MeV"]
legend6000 = ["2GeV","3GeV","4GeV","5GeV","6GeV"]
legend100000 = ["10GeV","25GeV","50GeV","75GeV","100GeV"]

colors = [ROOT.kBlack,ROOT.kBlue,ROOT.kRed,ROOT.kGreen,ROOT.kCyan]



canvas, histograms = plot_histograms(flist500, legend500, colors)
ROOT.gApplication.Run()