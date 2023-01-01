# Remove target from array
直接for loop，判断是否continue，稍复杂点就是continue的逻辑里再加点判断。
# Plus One
从后向前遍历+`vec.insert(vec.begin(), 1)`
# 杨辉三角
找规律，第i行有i个元素。第i行计算依赖第i-1行的结果，需要设置类似如下的临时变量来存：
```c++
int tmp = ret[i];
ret[i] = ret[i] + pre_val;
pre_val = ret[i]
```
# Merge Sorted Array
a有m个元素，b有n个元素，但a有m+n这么长，要求原地合并到a。
trick就是从后向前填充。
# KSum

