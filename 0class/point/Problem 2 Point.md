### Problem 2 Point

**问题描述**

按照输入输出要求，编程实现类 Point、Triangle、Circle，要求：

- 定义一个类 Point ，数据成员包括 x 坐标 和 y 坐标，均为 `double` 类型，成员函数包括构造函数和析构函数;
- **组合** 类 Point 得到三角形类 Triangle，成员函数包括 构造函数，析构函数，计算周长函数 girth()，计算面积函数 area()。
- **继承** 类 Point 得到圆形类 Circle，继承自 Point 的 x 和 y 作为圆心，新建成员变量 x 和 y 作为圆上一点，均为 `double` 类型，成员函数包括 构造函数，析构函数，计算周长函数 girth()，计算面积函数 area()。

**输入描述**

输入共 2 行。

第 1 行依次输入 Triangle 的三组 x 和 y 坐标，数据间以空格相隔； 第 2 行依次输入 Circle 的两组 x 和 y 坐标，数据间以空格相隔。

**输出描述**

输出共 2 行，

第 1 行依次输出 Triangle 的周长和面积，结果以空格相隔； 第 2 行依次输出 Circle 的周长和面积，结果以空格相隔。

> **注意1**：代码输入输出逻辑中请勿添加多余空行和多余输出内容；
> 
> **注意2**：建议使用 `<<` 输出，对于带有小数的结果，会整体保留6位非零数字；
> 
> **注意3**：π 取 3.14；
> 
> **注意4**：不考虑三点共线。

**输入举例**

```
0 0 0 1 1 0
0 0 1 0
```

**输出举例**

```
3.41421 0.5
6.28 3.14
```

**需要提交的文件**

需要提交实现完毕的`main.cpp`，`point.cpp`， `point.h`三个文件。