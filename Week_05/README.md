# 学习总结

这周时间比较紧张，只学习了位运算以及AVL树、红黑树等知识点。

位运算的常见的操作，最基本的一个是判断奇偶，和1做与运算就行了；然后是把一个数的最后一个1清空n &= (n - 1)；不清楚优先级的情况下最好加个括号；n & (-n)把n的最低位的1拿出来（带权重）。

N皇后的位运算解法堪称精彩，只能先背下来了....

AVL树是一种平衡二叉搜索树，左右子树的平衡因子相差不超过1；平衡因子指的是左右子树的高度差；它维护起来比较麻烦，因为得反复调整平衡因子，这就涉及到众多旋转操作：左左子树右旋，右右子树左旋，左右子树左右旋，右左子树右左旋

红黑树是一种近似平衡的二叉搜索树，它维护起来相对来说好一点，只要保证左右子树的高度差不超过一倍就行了，也就是从根到叶子的最长的可能路径不多于最短的可能路径的两倍长 。

