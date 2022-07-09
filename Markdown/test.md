# 这是个一级标题

## 目录

[TOC]

## 可以试试的

第一次尝试markdown

```C++
std::cout<<a<<"asd";
```

- [ ] the first one
- [x] the second one
$$
\sum_{i=1}^{n}{a_i+1}
$$
$$
\int_{x}^{y}\int_x^y\cos(xy)dxdy
$$
其实也可以
一个段落

![](https://cdn.jsdelivr.net/gh/Drunk-Dream/pic@main/2022-5-9/pic2133244151652103203698.png)
![](https://cdn.jsdelivr.net/gh/Drunk-Dream/pic@main/2022-5-9/1748281111652089707580.png)
![](https://cdn.jsdelivr.net/gh/Drunk-Dream/pic@main/2022/5-9/pic223542_2511652106941848.png)
![](https://api.onedrive.com/v1.0/shares/s!AkrJR1bBQkBboTnrXsnu8mBOLp4o/root/content)
![](https://api.onedrive.com/v1.0/shares/s!AkrJR1bBQkBboTnrXsnu8mBOLp4o/root/content)

``` mermaid
gantt
    dateFormat  YYYY-MM-DD
    title 使用mermaid语言定制甘特图
    section 任务1
    已完成的任务           :done,    des1, 2014-01-06,2014-01-08
    正在进行的任务               :active,  des2, 2014-01-09, 3d
    待完成任务1               :         des3, after des2, 5d
    待完成任务2              :         des4, after des3, 5d
```

```mermaid
sequenceDiagram
    participant 企业
    participant 下游
    企业->>移动: 调度
    loop 心跳检测
        移动->>移动: SDK
    end
    Note right of 移动: 详见文档 <br/>资料
    移动-->>企业: 接单
    移动->>下游: 推送
    下游-->>移动: 流程结束
```

```mermaid
graph TD;
A-->B;
A-->X;
A-->C;
B-->D;
C-->D;
```

```mermaid
gantt
    title 安排
    dateFormat YYYY-MM-DD
    section 姚晓彤
    动量(基础+经典题目):des11,2022-07-11,2d
    排列组合:des12,2022-07-13,1d
    磁场(安培力洛伦兹力题目):des13,2022-07-14,1d
    概率:des14,2022-07-15,1d
    section 姚蕴芳
    基础概念:des21,2022-07-11,1d
    运算法则，规律:des22,2022-07-12,2d
    分数:des23,after des22,2d
    section 姚楚钘
    section 张曦予
```
