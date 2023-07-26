import ROOT
filepathlist   = [['Multi_Energy/datas/100MeV.txt','Multi_Energy/datas/200MeV.txt','Multi_Energy/datas/300MeV.txt', 'Multi_Energy/datas/400MeV.txt', 'Multi_Energy/datas/500MeV.txt'], 
                ['Multi_Energy/datas/600MeV.txt', 'Multi_Energy/datas/700MeV.txt', 'Multi_Energy/datas/800MeV.txt', 'Multi_Energy/datas/900MeV.txt', 'Multi_Energy/datas/1000MeV.txt'], 
                ['Multi_Energy/datas/2000MeV.txt', 'Multi_Energy/datas/3000MeV.txt', 'Multi_Energy/datas/4000MeV.txt', 'Multi_Energy/datas/5000MeV.txt', 'Multi_Energy/datas/6000MeV.txt'],
                ['Multi_Energy/datas/10GeV.txt','Multi_Energy/datas/25GeV.txt','Multi_Energy/datas/50GeV.txt','Multi_Energy/datas/75GeV.txt','Multi_Energy/datas/100GeV.txt']]
flist500=filepathlist[0][:]
flist1000=filepathlist[1][:]
flist6000=filepathlist[2][:]
flist100000=filepathlist[3][:]

legend500 = ["100MeV","200MeV","300MeV","400MeV","500MeV"]
legend1000 = ["600MeV","700MeV","800MeV","900MeV","1000MeV"]
legend6000 = ["2GeV","3GeV","4GeV","5GeV","6GeV"]
legend100000 = ["10GeV","25GeV","50GeV","75GeV","100GeV"]

colors = [ROOT.kBlack,ROOT.kBlue,ROOT.kRed,ROOT.kGreen,ROOT.kCyan]




def plot_histograms(file_paths, legends):
    canvas = ROOT.TCanvas("canvas", "Histograms",1600,900)
    legend = ROOT.TLegend(0.7, 0.7, 0.9, 0.9)
    histograms = []
    for i, (file_path, legend_text) in enumerate(zip(file_paths, legends)):
        with open(file_path, 'r') as file:
            data = [float(line.strip()) for line in file]
        hist = ROOT.TH1F(f'hist_{i}', legend_text,500, min(data), max(data))
        for value in data:
            hist.Fill(value)
        color = 50 + 10 * i
        hist.SetLineColor(color)
        histograms.append(hist)
        legend.AddEntry(hist, legend_text, "l")
    for i, hist in enumerate(histograms):
        if i == 0:
            hist.Draw()
            hist.SetXTitle("Total Energy Deposit (MeV)")
            hist.SetYTitle("Frequency (No of Particles)")
        else:
            hist.Draw("SAME")
    legend.Draw()
    canvas.Update()
    ROOT.gApplication.Run()


plot_histograms(flist100000, legend100000)
