import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
import matplotlib as mpl


# 逻辑回归类
class LR:

    def __init__(self):
        self.coef = None  # 维度
        self.intercept = None  # 截距
        self.theta = None

    def sigmoid(self, z):
        return 1 / (1 + np.exp(-z))

    def fit(self, xtrain, ytrain, eta=0.01, n=1e4):
        assert xtrain.shape[0] == ytrain.shape[0]

        # 计算损失函数
        def J(theta, X_b, y):
            p_predict = self.sigmoid(X_b.dot(theta))
            try:
                return -np.sum(y * np.log(p_predict) +
                               (1 - y) * np.log(1 - p_predict)) / len(
                                   y)  # 不加正则化
            except:
                return float('inf')

        # 求sigmoid梯度的倒数
        def dJ(theta, X_b, y):
            x = self.sigmoid(X_b.dot(theta))
            return X_b.T.dot(x - y) / len(X_b)

        # 模拟梯度下降
        def gradient_descent(X_b, y, initial_theta, eta, n=1e4, epsilon=1e-8):
            theta = initial_theta
            i_iter = 0
            while i_iter < n:
                gradient = dJ(theta, X_b, y)
                last_theta = theta
                theta = theta - eta * gradient
                i_iter += 1
                if (abs(J(theta, X_b, y) - J(last_theta, X_b, y)) < epsilon):
                    break
            return theta

        X_b = np.hstack([np.ones((len(xtrain), 1)), xtrain])
        initial_theta = np.zeros(X_b.shape[1])  # 列向量
        self.theta = gradient_descent(X_b, ytrain, initial_theta, eta, n)
        self.intercept = self.theta[0]  # 截距
        self.coef = self.theta[1:]  # 维度
        return self

    def predict_proba(self, X_predict):
        X_b = np.hstack([np.ones((len(X_predict), 1)), X_predict])
        return self.sigmoid(X_b.dot(self.theta))

    def predict(self, X_predict):
        proba = self.predict_proba(X_predict)
        return np.array(proba > 0.5, dtype='int')


# 绘制sigmoid函数
# plot_x=np.linspace(-10,10,100)
# plot_y=1/(1+np.exp(-plot_x))
# plt.plot(plot_x,plot_y)
# plt.title('sigmoid function')
# plt.show()
# plt.pause(1)
# plt.close()
# 可视化数据，分析数据
iris = load_iris()  # 该函数返回一个Bunch对象，它直接继承自Dict类，与字典类似，由键值对组成
print(iris.feature_names, '\n', iris.target_names)
# 取前两列特征，花萼长度和宽度
x = iris.data[0:150, 0:2]
y = iris.target[0:150]
samples_0 = x[y == 0, :]  # 将y=0的样本取出来
samples_1 = x[y == 1, :]
samples_2 = x[y == 2, :]

# 散点图可视化
plt.scatter(samples_0[:, 0], samples_0[:, 1], marker='o', color='r')
plt.scatter(samples_1[:, 0], samples_1[:, 1], marker='x', color='g')
plt.scatter(samples_2[:, 0], samples_2[:, 1], marker='*', color='b')
plt.legend(labels=['山鸢尾', '杂色鸢尾', '维吉尼亚鸢尾'])
mpl.rcParams['font.sans-serif'] = ['SimHei']
plt.xlabel("花萼长度")
plt.ylabel("花萼宽度")
# plt.show()
# plt.pause(1)
# plt.close()

# 划分数据集
# 训练集
xtrain = np.vstack([x[0:40, :], x[50:90], x[100:140]])
ytrain = np.concatenate([y[:40], y[60:100], y[100:140]])
xtest = np.vstack([x[40:50], x[90:110], x[140:]])
ytest = np.concatenate([y[40:50], y[90:100], y[140:]])

# 创建逻辑回归对象，训练3个模型
z_proba = []
lr = []
for i in range(3):
    lr.insert(i, LR())
    lr[i].fit(xtrain, np.where(ytrain == i, 1, 0), n=1e5)

# 测试
for i in range(3):
    z_proba.insert(i, lr[i].predict_proba(xtest))
numtest = xtest.shape[0]
prediction = np.argmax(z_proba, axis=0)
acc = np.sum(prediction == ytest) / numtest
print(f'The accuracy of prediction is:', acc)

# 预测值显示
nx, ny = 1000, 500
xMin, xMax = plt.xlim()  # 确定坐标轴范围，x,y轴分别表示两个特征
yMin, yMax = plt.ylim()
t1, t2 = np.linspace(xMin, xMax, nx), np.linspace(yMin, yMax, ny)
X, Y = np.meshgrid(t1, t2)  # 生成网络采样点，横轴为属性X1，纵轴为属性X2

for i in range(3):
    z_proba[i] = lr[i].predict_proba(np.c_[X.ravel(), Y.ravel()])

z_prediction = np.argmax(z_proba, axis=0)
z_prediction = z_prediction[:].reshape(X.shape)
plt.contourf(X, Y, z_prediction, 2, alpha=0.3, colors=['r', 'g', 'b'])
plt.grid()  # 显示网格
plt.show()
