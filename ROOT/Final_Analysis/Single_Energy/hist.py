
import numpy as np
from scipy.interpolate import UnivariateSpline
import matplotlib.pyplot as plt

file = open("Single_Energy/datas/Final_cosmic_data.txt", "r")
i=0
count=0
ylist2=[]
for line in file:
    value = float(line.strip())
    i=i+value
    count+=1
    if value!=0:
        ylist2.append(value*0.001)
file.close()


xlist = [0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,2,3,4,5,6,10,25,50,75,100]  
ylist = [2.23347e-03,6.22615e-04,5.31900e-04,5.30453e-04,5.379379e-04,
    5.38996e-04,5.39097e-04,5.51859e-04,5.88838e-04,6.21229e-04,
    6.78881e-04,6.98291e-04,7.28788e-04,7.38014e-04,7.42980e-04,
    7.64237e-04,8.11232e-04,8.35784e-04,8.43543e-04,8.47351e-04]  



xlist = np.array(xlist)
ylist = np.array(ylist)
ylist2 = np.array(ylist2)

# Perform spline fitting on the given data
spline = UnivariateSpline(xlist, ylist, s=0)  # You can adjust the smoothing factor 's' as needed

# Estimate x coordinates for y values in ylist2
x_estimated = spline(ylist2)

# Print the results
# for y, x in zip(ylist2, x_estimated):
#     print(f"For y = {y}, estimated x = {x}")



plt.plot(xlist,ylist)
plt.plot(x_estimated,ylist2,color='r')
plt.show()    