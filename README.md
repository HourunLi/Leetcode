# Note

这里只是我简单的一些好题总结，数量比较少。

之后很多数据结构和算法技巧我会在个人博客上更新，敬请关注。



41 原地hash，根据题目取第一个未出现的正数，取巧处理

84 单调栈：在一维数组中对每一个数找到第一个比自己小的元素。这类“在一维数组中找第一个满足某种条件的数”的场景就是典型的单调栈应用场景

146 **Hash搭配链表**实现实现O(1)的删除查找添加并且利用链表的顺序记录表示一定的意义。`LRU`替换算法|分配和释放空间是很慢的操作，尽量避免

212 字典树的建立以及**删除**，以及对字符串的查找应用

297 Serialize and Deserialize Binary Tree. Where is the performance bottleneck??? How to improve. <font color = red> TLE </font>

316 单调栈pop特定元素，搭配贪心，需要判断何时出栈和入栈，比较难。

321 **固定元素个数的单调栈**，用数组实现

380 同146 **Hash搭配vector**。顺序容器可以任意下标访问，非顺序容器不可以(unordered_map/set)

652 serialization，use memo to find duplicate elements

710 Hash搭配vector，数组元素的swap应用

853 就是简单地单调栈应用，但是排序的方式需要进一步深入研究，探究方式的多样性。python方法对zip的使用

1414 贪心算法 用最少的斐波拉契数字组成K， 如何证明？

1425 用单调队列搭配动态规划。单调队列求解区间范围内的最大值，一道很好的题目。

1696 sliding window解法：有序队列，用位置记录信息。

