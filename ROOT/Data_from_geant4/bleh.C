#include <iostream>
#include <fstream>
#include <vector>

void plotHistogram(const std::string& filename, const std::string& histTitle, int binCount, double xMin, double xMax) {
    // Create a TCanvas to display the histogram
    TCanvas* canvas = new TCanvas("canvas", "Histogram Canvas", 1600, 900);

    // Create a TH1F histogram
    TH1F* hist = new TH1F("histogram", histTitle.c_str(), binCount, xMin, xMax);
	//hist->SetX
    // Read data from the file
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    double value;
    std::vector<double> data;

    while (inputFile >> value) {
        data.push_back(value);
    }

    inputFile.close();

    // Fill the histogram with data
    for (const auto& entry : data) {
        hist->Fill(entry);
    }

    // Draw the histogram
    hist->Draw();

    // Run the event loop
    canvas->Update();
    canvas->Modified();
    canvas->SetWindowSize(1600, 900);
    canvas->SetCanvasSize(1600, 900);
    canvas->SetWindowSize(1600, 900);
    canvas->ToggleEventStatus();
    canvas->ToggleToolBar();
    canvas->ToggleEditor();

    gApplication->Run();
}

void histogram() {
    std::string filename = "output.txt"; // Replace with your input file name
    std::string histTitle = "Plot of Frequency vs Energy (MeV)";
    int binCount = 500; // Number of bins in the histogram
    double xMin = 0.0; // Minimum value on the x-axis
    double xMax = 0.01; // Maximum value on the x-axis

    plotHistogram(filename, histTitle, binCount, xMin, xMax);
}

