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
# K数之和
2数之和：因为存在唯一答案，直接开个map存下，O(n)
以3数之和为例：双指针
    1. 先排序，`i`从0开始，`j`从`i+1`开始，`k`从`nums.size()-1`开始
    2. 当`nums[i] + nums[j] + nums[k] > target`时，想把三数之和调小，基于排好序的基础上，只能`--k`。反之，只能`++j`
    3. 当找到一组i,j,k的解时，如果题目要求`{nums[i], nums[j], nums[k]}`非重复，我们需要在i,j,k的对应位置跳过重复元素（已经排好序了）
        1. i来说，只有等j和k的维度都搜完，才说明当前i已经完事，可以跳过重复元素。
        2. 对于j和k来说，在`nums[i] + nums[j] + nums[k] == target`时，即可跳过重复元素。
        3. 跳过重复元素，可以一直loop到不等于pre_val的那个值。
