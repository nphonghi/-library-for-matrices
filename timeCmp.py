
import matplotlib.pyplot as plt
import numpy as np

# Du lieu thoi gian tu chuong trinh nhan ma tran C++.
sizes = [(100, 200), (200, 500), (500, 700), (500, 1000), (700, 1000)]  # Kich thuoc ma tran(rows, cols).
singleThreadTimes = [0.0561184, 0.314672, 1.54117, 3.52641, 4.97129]
multiThreadTimes = [1.21686, 0.984837, 1.17869, 1.78747, 2.55441]

# Tach kich thuoc ma tran thanh cac truc X va Y.
rows = np.array([size[0] for size in sizes])
cols = np.array([size[1] for size in sizes])

# Ve bieu do so sanh.
fig = plt.figure(figsize=(12, 6))
ax = fig.add_subplot(projection='3d')

# Noi cac diem lai voi nhau thanh duong.
ax.plot(rows, cols, singleThreadTimes, label='Single Thread', marker='o', linestyle='-', linewidth=2)  
ax.plot(rows, cols, multiThreadTimes, label='Multi Thread', marker='o', linestyle='-', linewidth=2)

# Thiet lap nhan truc.
ax.set_xlabel('Số hàng (rows)')
ax.set_ylabel('Số cột (cols)')
ax.set_zlabel('Thời gian (s)')
ax.set_title('So sánh thời gian nhân ma trận giữa việc sử dụng đa luồng và sử dụng đơn luồng')
ax.legend()

# Xoay bieu do 3D.
ax.view_init(elev=20, azim=45) 

plt.show()