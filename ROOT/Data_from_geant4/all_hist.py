import matplotlib.pyplot as plt
import os

# Function to plot and save histogram from a single file
def plot_and_save_histogram(file_path):
    # Read data from the text file
    with open(file_path, 'r') as file:
        data = [float(line.strip()) for line in file]

    # Create the histogram
    plt.hist(data, bins=600, alpha=0.5, edgecolor='black',density=True)

    # Customize the plot
    plt.title(os.path.basename(file_path).split('.')[0])
    plt.xlabel('Values')
    plt.ylabel('Frequency')

    # Set aspect ratio
    plt.gcf().set_size_inches(1600 / 100, 900 / 100)

    # Save the plot as PNG
    output_file = os.path.basename(file_path).split('.')[0] + '.png'
    plt.savefig(output_file, dpi=200, bbox_inches='tight')
    plt.clf()  # Clear the figure for the next plot

# List of file paths for 14 text files
file_paths = ["data/output_80MeV.txt","data/output_100MeV.txt","data/output_200MeV.txt","data/output_300MeV.txt","data/output_400MeV.txt","data/output_500MeV.txt","data/output_600MeV.txt","data/output_700MeV.txt","data/output_800MeV.txt","data/output_900MeV.txt","data/output_1GeV.txt","data/output_1.1GeV.txt","data/output_2GeV.txt","data/output_4GeV.txt"]


# Plot and save histogram for each file
for file_path in file_paths:
    plot_and_save_histogram(file_path)
