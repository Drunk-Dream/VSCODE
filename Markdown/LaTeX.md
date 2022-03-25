```latex
%导言区
\documentclass{article}     %文件类型:article,book,report,letter

\usepackage{ctex}           %中文包

\title{}
\author{}
\date{}

%正文区
\begin{document}

    \maketitle      %letter类型不可用

%字体族设置（罗马字体，无衬线字体，打字机字体）
    \textrm{Roman Family}    \textrm{Sans Serif Family}    \textrm{Typewriter Family}
    \rmfamily Roman Family    \
\end{document}
```
### 字体属性：
1. 字体编码
   1. 正文字体编码：OT1、T1、EU1等
   2. 数学字体编码：OML、OMS、OMX等
2. 字体族
   1. 罗马字体：笔画起始处有装饰
   2. 无衬线字体：笔画起始处无装饰
   3. 打字机字体：每个字符宽度相同，又称等宽字体
3. 字体系列
   1. 粗细
   2. 宽度
4. 字体形状
   1. 直立
   2. 斜体
   3. 伪斜体
   4. 小型大写
5. 字体大小