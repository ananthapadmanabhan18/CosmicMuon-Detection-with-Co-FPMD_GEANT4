
import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

# Your data
# xlist = [0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,2,3,4,5,6,10,25,50,75,100]  
# ylist = [2.23347e-03,6.22615e-04,5.31900e-04,5.30453e-04,5.379379e-04]
#     5.38996e-04,5.39097e-04,5.51859e-04,5.88838e-04,6.21229e-04,
#     6.78881e-04,6.98291e-04,7.28788e-04,7.38014e-04,7.42980e-04,
#     7.64237e-04,8.11232e-04,8.35784e-04,8.43543e-04,8.47351e-04]  



def model_function(x, a, b, c):
    return (a/(x*x))*(np.log(b*(x**4)*(1/np.sqrt(1-(x/(3*10**8)))))-(2*x*x/(9*10**16))) + c


ylist = np.array([0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,2,3,4,5,6,10,25,50,75,100])
xlist = np.array([2.23347e-03,6.22615e-04,5.31900e-04,5.30453e-04,5.379379e-04,5.38996e-04,5.39097e-04,5.51859e-04,5.88838e-04,6.21229e-04,6.78881e-04,6.98291e-04,7.28788e-04,7.38014e-04,7.42980e-04,7.64237e-04,8.11232e-04,8.35784e-04,8.43543e-04,8.47351e-04])
def l_interpolation(xlist,ylist,x):
    s=0
    for i in range(0,len(xlist)):
        p=1
        for k in range(0,len(xlist)):
            if i==k:
                p=p
            else:    
               p=p*(((x-xlist[k])/(xlist[i]-xlist[k])))
        p=p*ylist[i]       
        s=s+p
    return s



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


ylist1=[l_interpolation(xlist,ylist,ylist2[i]) for i in range(len(xlist))]
plt.scatter(xlist, ylist1, label='Original Data')
# plt.plot(xlist, y_fit, label='Fitted Curve', color='red')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()
plt.show()
# print("Fitted Parameters:")
# print(f"a: {a_fit}")
# print(f"b: {b_fit}")
# print(f"c: {c_fit}")



def bethefn(x):
    return ((-1.665179153997467e-05)/(x*x))*(np.log(40.364180576082084 * x*x)-2*x*x) + 0.0007043300392805913