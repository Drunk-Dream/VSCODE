import matplotlib.pyplot as plt  # 可视化用
import numpy as np
from sklearn.datasets import load_iris  # 训练和测试所用数据
from LogisticRegressionSelf import LogisticRegressionSelf  # 逻辑回归类

iris = load_iris()
# iris.feature_names,
# iris.target_names
# iris.data  #能特征数据的具体信息
# iris.target  #能看每行数据的标签值

# 取100个样本，取前两列特征，花萼长度和宽度
x = iris.data[0:150, 0:2]
y = iris.target[0:150]
# 分别取前两类样本，0和1
samples_0 = x[y == 0, :]  # 把y=0的样本取出来
samples_1 = x[y == 1, :]
samples_2 = x[y == 2, :]
# 散点图可视化
p1 = plt.scatter(samples_0[:, 0], samples_0[:, 1], marker='o', color='g')
p2 = plt.scatter(samples_1[:, 0], samples_1[:, 1], marker='o', color='r')
p3 = plt.scatter(samples_2[:, 0], samples_2[:, 1], marker='o', color='b')
plt.xlabel(iris.feature_names[0])
plt.ylabel(iris.feature_names[1])
plt.legend([p1, p2, p3], iris.target_names[0:3], loc='upper right')

################################
# 划分测试/训练数据，120个训练数据，30个测试数据
x_train = np.vstack([x[:40, :], x[50:90], x[100:140]])
y_train = np.concatenate([y[:40], y[60:100], y[100:140]])
x_test = np.vstack([x[40:50], x[90:100], x[140:]])
y_test = np.concatenate([y[40:50], y[90:100], y[140:]])

################################
# 创建逻辑回归对象，训练3个模型
z_proba = []
lr = []
for i in range(3):
    lr.insert(i, LogisticRegressionSelf())
    lr[i].fit(x_train, np.where(y_train == i, 1, 0), n_iters=1e5)

################################
# 测试
for i in range(3):
    z_proba.insert(i, lr[i].predict_proba(x_test))

num_test = x_test.shape[0]
prediction = np.argmax(z_proba, axis=0)  # 返回每一列最大值的索引
accuracy = np.sum(prediction == y_test) / num_test
print(r'the accuracy of prediction is :', accuracy)

###############################
# 可视化
nx, ny = 1000, 500
x_min, x_max = plt.xlim()
y_min, y_max = plt.ylim()
x_grid, y_grid = np.meshgrid(np.linspace(x_min, x_max, nx),
                             np.linspace(y_min, y_max, ny))

for i in range(3):
    z_proba[i] = lr[i].predict_proba(np.c_[x_grid.ravel(), y_grid.ravel()])

z_prediction = np.argmax(z_proba, axis=0)
z_prediction = z_prediction[:].reshape(x_grid.shape)

# plt.contour(x_grid,y_grid,z_prediction,colors=['k'])
plt.contourf(x_grid,
             y_grid,
             z_prediction,
             2,
             alpha=0.3,
             colors=['g', 'r', 'b'])
plt.show()
