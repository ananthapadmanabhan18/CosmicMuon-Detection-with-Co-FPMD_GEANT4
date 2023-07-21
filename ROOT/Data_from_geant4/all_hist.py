import matplotlib.pyplot as plt
import numpy as np

# Step 1: Read data from the text file
file_path = 'data/all.txt'  # Replace with the actual file path
data = np.loadtxt(file_path)  # Assuming your data is tabular with 14 columns

# Step 2: Create a single plot with 14 subplots
fig, axes = plt.subplots(2, 7, figsize=(14, 7))  # 2 rows, 7 columns for 14 subplots

# Step 3: Plot a histogram for each column
for i in range(14):
    row = i // 7
    col = i % 7
    axes[row, col].hist(data[:, i], bins=30, alpha=0.5, edgecolor='black')
    axes[row, col].set_title(f'Column {i + 1}')

# Step 4: Display the plot
plt.tight_layout()
plt.show()
