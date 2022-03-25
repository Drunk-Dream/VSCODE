from matplotlib import colors
import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import load_iris
from LogisticRegressionSelf import LogisticRegressionSelf

iris = load_iris()
# iris.feature_names,
# iris.target_names
# iris.data  #能特征数据的具体信息
# iris.target  #能看每行数据的标签值

##取100个样本，取前两列特征，花萼长度和宽度
x = iris.data[0:100, 0:2]
y = iris.target[0:100]
##分别取前两类样本，0和1
samples_0 = x[y == 0, :]  #把y=0的样本取出来
samples_1 = x[y == 1, :]
# samples_2 = x[y == 2, :]
# 散点图可视化
p1 = plt.scatter(samples_0[:, 0], samples_0[:, 1], marker='o', color='g')
p2 = plt.scatter(samples_1[:, 0], samples_1[:, 1], marker='o', color='r')
# p3 = plt.scatter(samples_2[:, 0], samples_2[:, 1], marker='o', color='b')
plt.xlabel(iris.feature_names[0])
plt.ylabel(iris.feature_names[1])
plt.legend([p1, p2], iris.target_names[0:2], loc='upper left')

################################################################
#划分测试/训练数据，80个训练数据，20个测试数据
x_train = np.vstack([x[:40, :], x[60:100, :]])  #取钱40和后40的数据
y_train = np.concatenate([y[:40], y[60:100]])
x_test = x[40:60, :]
y_test = y[40:60]

################################
#创建逻辑回归对象，训练
lr = LogisticRegressionSelf()

lr.fit(x_train, y_train)

###############################
#测试
num_test = x_test.shape[0]
prediction = lr.predict(x_test)
accuracy = np.sum(prediction == y_test) / num_test
print(r'the accuracy of prediction is :', accuracy)
print(prediction)

nx, ny = 200, 100
x_min, x_max = plt.xlim()
y_min, y_max = plt.ylim()
x_grid, y_grid = np.meshgrid(np.linspace(x_min, x_max, nx),
                             np.linspace(y_min, y_max, ny))

z_proba = lr.predict_proba(np.c_[x_grid.ravel(), y_grid.ravel()])
z_proba = z_proba[:].reshape(x_grid.shape)

plt.contour(x_grid, y_grid, z_proba, [0.5])
plt.contourf(x_grid, y_grid, z_proba, 1, alpha=0.1)
plt.grid()
plt.show()