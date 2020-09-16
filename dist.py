import matplotlib.pyplot as plt
import numpy as np
import subprocess
import sys

filename = sys.argv[1]
myfile = open(filename,"r")
numbers = myfile.readlines()
numbers = np.array(numbers)
data = []
print(data)
for i in range(0,len(numbers)):
    num = int(numbers[i])
    data = np.append(data,num)

d = np.diff(np.unique(data)).min()
left_of_first_bin = data.min()-d
right_of_last_bin = data.max()+d
plt.hist(data,np.arange(left_of_first_bin,right_of_last_bin + d, d))
plt.show()

