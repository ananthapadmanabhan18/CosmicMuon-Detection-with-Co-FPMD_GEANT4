import matplotlib.pyplot as plt
import numpy as np



def get_mpv(min,max,filepath):
    file_path = filepath
    with open(file_path, 'r') as file:
        data = [float(line.strip()) for line in file]
    hist, bin_edges = np.histogram(data, bins=500, density=True)
    bin_centers = (bin_edges[:-1] + bin_edges[1:]) / 2
    range_min = min
    range_max = max
    mask = (bin_centers >= range_min) & (bin_centers <= range_max)
    max_bin_center = bin_centers[mask][np.argmax(hist[mask])]
    print("Bin center with the maximum value in the range [{}, {}]: {:.2f}".format(range_min, range_max, max_bin_center))
    plt.hist(data, bins=500, alpha=0.5, edgecolor='cyan', density=True)
    plt.title(filepath)
    plt.xlabel('Incident Energy (GeV)')
    plt.ylabel('Frequency')
    plt.axvline(max_bin_center, color='red', linestyle='dashed', linewidth=2, label='{} GeV'.format(max_bin_center))
    plt.legend()
    plt.show()
    return 


# flist=["data/output_800MeV.txt","data/output_900MeV.txt","data/output_1GeV.txt","data/output_1.1GeV.txt","data/output_2GeV.txt","data/output_4GeV.txt",]
# colors = ['orange', 'purple', 'brown', 'pink', 'gray', 'olive']

get_mpv(0,0.01,"data/output_500MeV.txt")


