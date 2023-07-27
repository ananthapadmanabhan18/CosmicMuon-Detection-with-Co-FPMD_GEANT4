import numpy as np

file = open("gun_data.txt", "r")
output_file = open("cosmic_muons.mac", "w")  # Open a new file for writing the output
datalist = []

for line in file:
    values = line.strip().split("\t")
    datalist.extend(map(float, values))


    if 2.498091<datalist[4]<np.pi:
        if datalist[6] < 0:
            output_file.write("/gun/particle mu-\n")
        else:
            output_file.write("/gun/particle mu+\n")
        output_file.write(f"/gun/position {datalist[0]} {datalist[1]} {datalist[2]/2} m\n")
        output_file.write(f"/gun/momentum {datalist[3]*np.sin(datalist[4])*np.cos(datalist[5])} {datalist[3]*np.sin(datalist[4])*np.sin(datalist[5])} {datalist[3]*np.cos(datalist[4])} GeV\n")
        output_file.write("/run/beamOn 1\n")

    datalist.clear()

file.close()  # Close the input file
output_file.close()  # Close the output file
