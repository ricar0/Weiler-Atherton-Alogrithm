# Weiler-Atherton-Alogrithm
计算机图形学【Weiler-Atherton算法】多边形裁剪算法

# 什么是多边形裁剪
通常来说就是利用多边形来裁剪多边形的一种方法，一般情况下是利用矩形来裁剪凹凸多边形

1. 凸多边形

![](https://img-blog.csdnimg.cn/b19368c7a97744c1b3d95e1ed6b1a89f.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAa2FrYTAwMTA=,size_13,color_FFFFFF,t_70,g_se,x_16)
2. 凹多边形


![](https://img-blog.csdnimg.cn/b9b0d9ba3ec742cc87149f9810cc398c.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAa2FrYTAwMTA=,size_15,color_FFFFFF,t_70,g_se,x_16)

上面红色划线部分就是裁剪出的部分

# 前置知识
1. OPENGL基础语法
基本上就是一些画线和画多边形的操作，难度较低
2. 求两直线交点
较为基础的数学知识
3. 求一个点是否落在多边形内/外
计算几何知识
4. Weiler-Atherton多边形裁剪算法

这里着重介绍Weiler-Atherton算法，其余不懂的可以先学会再看。

# 算法步骤
1. 首先绘制两个相交的多边形
2. 对于多边形1，我们从一个点出发，将所有经过的点（包含交点）存入新的数组中，对于多边形2也是同理
3. 对两个新数组中的相同点进行点对映射
4. 开始对裁剪多边形1进行遍历，从任意点出发，如果改点将从多边形2的内部穿越到外部，我们改变遍历点的对象，从多边形2开始遍历，依次类推...
5. 直到当前点被遍历过，那么之前肯定形成了一个回路，我们将当前回路绘制出来就是裁剪出的多边形。
6. 一直重复4和5操作，直到所有点都被遍历

接下来结合图片解释一下

![在这里插入图片描述](https://img-blog.csdnimg.cn/40caac91a1cc41deb7e1bae01818d309.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAa2FrYTAwMTA=,size_18,color_FFFFFF,t_70,g_se,x_16)
对于如下这个图，我们利用矩形裁剪凹多边形。
首先从E点出发，判断E到J是否为出点，发现不是。遍历到J点，判断JF是否是出点，发现是，这时候改变遍历的对象，通过映射关系从K点开始。判断发现KC又是出点，因此再次改变遍历对象，遍历多边形到E，发现J已经被遍历过，这时直接绘制出JKE...

# 程序框图
![在这里插入图片描述](https://img-blog.csdnimg.cn/c14beb0439894fa0861fae9c81c22f9d.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAa2FrYTAwMTA=,size_20,color_FFFFFF,t_70,g_se,x_16)
