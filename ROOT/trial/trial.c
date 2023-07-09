{
// TFile* file = new TFile("output.root", "RECREATE");
g=new TGraph("data.txt");
f=new TF1("f","[0]/(sin((x-[1])/2))^4",-0.523,0.523);
g->Fit(f);
g->SetMarkerStyle(21);
g->SetMarkerSize(1);
g->SetLineColor(kRed);
g->SetLineWidth(1);
g->SetTitle("Plot of f vs /theta");
g->Draw("AP"); 
// g->Write();
// file->Close()
}
