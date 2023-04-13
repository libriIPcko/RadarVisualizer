import os
import sys
import numpy as np
import matplotlib.pyplot as plt

length = 5
data_y = np.random.rand(length)
data_x = np.linspace(0,length,length)
print(data_y)
print(data_x)
data = np.column_stack((data_x,data_y))
#data = np.hstack(data_y)
print(data)

data_y_mixed = np.random.rand(length);
for i in range(data.shape[1]):
    data[:,1] = data_y_mixed[i] - data[:,1]
    print(data[:,i])

fit1 = sys.argv[1]
fit2 = sys.argv[2]
fit3 = sys.argv[3]

plt.title('Test figure')
plt.scatter(data[:,0],data[:,1])
plt.plot(data[:,0],np.polyval(np.polyfit(data[:,0],data[:,1],int(fit1)),data[:,0]),color='red')
plt.plot(data[:,0],np.polyval(np.polyfit(data[:,0],data[:,1],int(fit2)),data[:,0]),color='blue')
plt.plot(data[:,0],np.polyval(np.polyfit(data[:,0],data[:,1],int(fit3)),data[:,0]),color='green')

plt.plot()
plt.tight_layout()
plt.show()