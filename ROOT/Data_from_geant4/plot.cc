#include <iostream>
#include <TFile.h>
#include <TCanvas.h>
#include <TH1D.h>
#include <TTree.h>

void plotHistograms() {
    // Step 1: Open the ROOT file and retrieve the TTree
    TFile *file = TFile::Open("data");  // Replace with the actual ROOT file path
    TTree *tree = dynamic_cast<TTree *>(file->Get("tree_name"));  // Replace "tree_name" with the name of your TTree

    // Step 2: Create a TCanvas to display histograms
    TCanvas *canvas = new TCanvas("canvas", "Histograms", 1200, 800);
    canvas->Divide(7, 2);  // 2 rows, 7 columns for 14 subplots

    // Step 3: Plot a histogram for each column
    for (int i = 0; i < 14; ++i) {
        canvas->cd(i + 1);
        TH1D *hist = new TH1D(Form("hist%d", i), Form("Column %d", i + 1), 30, 0, 100);  // Assuming range from 0 to 100
        tree->Draw(Form("Column%d>>hist%d", i, i));
        hist->Draw();
    }

    // Step 4: Display the plot
    canvas->Update();
    canvas->Modified();
}
