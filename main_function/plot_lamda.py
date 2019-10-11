import numpy as np
import matplotlib.pyplot as plt

r = np.linspace(0, 6, 1000)
i = np.ones(1000)

plt.plot(r, np.exp(-2*r))
plt.plot(r, 0.01*i)

plt.show()
