# 基于matlab的时域分析

## 2.8-2.11

**题目：**
![题目](pic/e476fd5f8ff4805172862704edd5371.jpg)

### 2.8

**微分方程**：$u'_R(t)=2u_R(t)=2i_s(t)$  
**源代码**：

```matlab
clear;
a=[0.5, 1];
b=1;
sys=tf(b,a);

figure;
subplot(2, 1, 1); 
impulse(sys);
subplot(2, 1, 2);
step(sys);
```

**波形图**：
![波形图](pic/T2_8.png)

### 2.9

**微分方程**：$u'_C(t)+u_C(t)=0.5u_S(t)$  
**源代码**：

```matlab
clear;
a=[2, 2];
b=1;
sys=tf(b,a);

figure;
subplot(2, 1, 1); 
impulse(sys);
subplot(2, 1, 2);
step(sys);
```

**波形图**：
![波形图](pic/T2_9.png)

### 2.10

**微分方程**：$i'_C(t)+2i_C=i'_S(t)$  
**源代码**：

```matlab
clear;
a=[1, 2];
b=[1, 0];
sys=tf(b,a);

figure;
subplot(2, 1, 1); 
impulse(sys);
subplot(2, 1, 2);
step(sys);
```

**波形图**：
![波形图](pic/T2_10.png)

### 2.11

**微分方程**：$u'_R(t)+u_R(t)=u'_S(t)+0.5u_S(t)$
**源代码**：

```matlab
clear;
a=[1, 1];
b=[1, 0.5];
sys=tf(b,a);

figure;
subplot(2, 1, 1); 
impulse(sys);
subplot(2, 1, 2);
step(sys);
```

**波形图**：
![波形图](pic/T2_11.png)

## 2.35-2.36

**题目：**
![题目](pic/7fd6b7401f66ba40d939f8b7eca1070.jpg)

### 2.35

**源代码：**

```matlab
clear;
a=[1, 6, 5];
b=[3, 2];
sys=tf(b,a);

figure;
subplot(2, 1, 1); 
impulse(sys);
subplot(2, 1, 2);
step(sys);
```

**波形图：**
![波形图](pic/T2_35.png)

### 2.36

**源代码：**

```matlab
clear;
a=[1, 4, 3];
b=[2, 1];
t=0:0.01:10;
e=exp(-t);

sys=tf(b,a);
lsim(sys,e,t);
```

**波形图：**
![波形图](pic/T2_36.png)
