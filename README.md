# week_8
第8周的学习 数据结构初阶 后1/3
**********************
1.二叉树oj :翻转二叉树(二叉树的镜像),另一棵树的子树,相同的树,平衡二叉树
二叉树的前序遍历     二叉树的中序遍历     二叉树的后序遍历   二叉树的最大深度
二叉树的层序遍历(队列)	单值二叉树   二叉树的深度   判断对称二叉树
复制二叉树   销毁复制的树(销毁二叉树)	二叉树遍历(字符串转二叉树)   二叉树查找
判断一颗树是否是完全二叉树     二叉树第k层节点个数
**********************
2.问题拆分,把问题转化为左子树和右子树的问题,然后画图分析+代码;
在画图和代码框架的过程中,理解递归的思想,实现代码;
当问题不能在拆分下去,就是递归结束的条件;
**********************
3.排序
插入排序:直接插入排序 	希尔排序
选择排序:直接选择排序	堆排序
交换排序:冒泡排序		快速排序
以上再内存上排序;
归并排序:可以再内存和外存上排序 
************************
4.笔记整理,知识点细节有点多,在博客上梳理核心+1

*************************
5.开始linux和cpp的并行学习,服务器centos7

linux基础指令学习:ls cd nano grep find tree cal echo | < >> cat tac adduser passwd 
yum zip unzip tar more less head tail history touch mkdir rm rmdir xargs ./ dc date ssh su - gcc 
***********************
6.cpp基础学习:命名空间,函数重载,引用学习
内联函数inline auto 类(对象)struct class 访问限定符:public private protected
头文件:extern int a;//声明 static int a;//定义,链接属性仅当前文件,不同文件各自一个
extern "C"配合条件编译==>CPP和C互相调用
**********************
7.类(对象):
构造函数->对象实例化时初始化成员变量(全缺省/无参数构造);
析构函数->对象销毁时清除成员变量(比如释放malloc,fopen指针)
拷贝构造函数->拷贝对象(传引用,防止无穷递归)
自定义拷贝构造,赋值运算符重载;默认生成==>只能浅拷贝;自己写==>可以深拷贝
运算符重载,日期类练习,代码优化
频繁使用,放类里,inline,注意inline定义和声明不能分离
