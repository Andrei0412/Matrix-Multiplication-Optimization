import matplotlib.pyplot as plt

N_values = [400, 800, 1200, 1600, 2000]

time_neopt = [0.803796, 8.518361, 28.436363, 84.640671, 144.384415]
time_opt_m = [0.207906, 2.140434, 7.979221, 26.738745, 44.753178]
time_blas = [0.034719, 0.229008, 0.743647, 1.720181, 3.306728]

plt.figure(figsize=(10, 6))

plt.plot(N_values, time_neopt, label='Neopt')
plt.plot(N_values, time_opt_m, label='Opt_m')
plt.plot(N_values, time_blas, label='BLAS')

plt.title('Performances Graphic')
plt.xlabel('N = Size of the Square Matrix')
plt.ylabel('Elapsed time(seconds)')

plt.ylim(bottom = -5, top = 100)
plt.yticks(range(-5, 101, 5))

plt.legend()
plt.show()