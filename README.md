# ACM-Solutions

记录，并整理题目类型

慢慢补，暂时补到表格里的第20项

## 基础算法

### 搜索

打OI的时候很喜欢暴力加剪枝。 打ICPC的时候有点不太敢了，不太熟。
[GYM104821A](https://codeforces.com/gym/104821/problem/A)将每个袋鼠可行的运动方案通过某种方式爆搜实现即可。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-25/Cool%2C%20It%27s%20Yesterday%20Four%20Times%20More.cpp)

### 位运算

往往同时用于01字典树。
[abc337E](https://atcoder.jp/contests/abc337/tasks/abc337_e)注意到我们是想要让状态的数量最少。显然用0和1表示状态是最优的，所以想到使用二进制。（我没想到）[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/ABC337/E.cpp)
[CF1918C](https://codeforces.com/contest/1918/problem/C)位运算加贪心[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/CF1918/C_XOR_distance.cpp)

### 二分答案

一般来说，题目要求满足某种条件的最大（小）值的时候，就可以优先考虑二分答案。
[HDU7405](https://acm.hdu.edu.cn/showproblem.php?pid=7405)正解是线性的dp，但是我赛时用的二分答案加二进制优化背包把这题水过去了。 [code-solution](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/%E2%80%9C%E5%8D%8E%E4%B8%BA%E6%9D%AF%E2%80%9D%E6%9D%AD%E5%B7%9E%E7%94%B5%E5%AD%90%E7%A7%91%E6%8A%80%E5%A4%A7%E5%AD%A62023%E6%96%B0%E7%94%9F%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/1004%E6%99%BA%E8%83%BD%E8%BD%A6%EF%BC%88solution%E7%9A%84%E5%81%9A%E6%B3%95%EF%BC%89.cpp)/[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/%E2%80%9C%E5%8D%8E%E4%B8%BA%E6%9D%AF%E2%80%9D%E6%9D%AD%E5%B7%9E%E7%94%B5%E5%AD%90%E7%A7%91%E6%8A%80%E5%A4%A7%E5%AD%A62023%E6%96%B0%E7%94%9F%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/1004%E6%99%BA%E8%83%BD%E8%BD%A6%EF%BC%88%E6%88%91%E7%9A%84%E5%81%9A%E6%B3%95%EF%BC%89.cpp)
[HDU7409](https://acm.hdu.edu.cn/showproblem.php?pid=7409)二分答案。可以在排序后用双指针O(N)的check。我赛时没想到，就用的O(Nlog^2(N))[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/%E2%80%9C%E5%8D%8E%E4%B8%BA%E6%9D%AF%E2%80%9D%E6%9D%AD%E5%B7%9E%E7%94%B5%E5%AD%90%E7%A7%91%E6%8A%80%E5%A4%A7%E5%AD%A62023%E6%96%B0%E7%94%9F%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/1008%E5%A4%A7%E9%9B%AA%E7%90%83.cpp)

## 数据结构

### 字典树

[HDU7406](https://acm.hdu.edu.cn/showproblem.php?pid=7406)比较经典的01trie树的运用。再加上位运算经常要用到从高位到地位确定的一个特点。 [code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/%E2%80%9C%E5%8D%8E%E4%B8%BA%E6%9D%AF%E2%80%9D%E6%9D%AD%E5%B7%9E%E7%94%B5%E5%AD%90%E7%A7%91%E6%8A%80%E5%A4%A7%E5%AD%A62023%E6%96%B0%E7%94%9F%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/1005%E6%A0%91.cpp)

### 珂朵莉树

喜欢暴力。
[GYM104821M](https://codeforces.com/gym/104821/problem/M)可以说感觉就是珂朵莉树的操作。（或者说分块？）

### 可持久化数据结构

一般用的应该都是可持久化线段树。
有时候也许可以尝试转为使用离线操作？
[luogu-P3919](https://www.luogu.com.cn/problem/P3919)模板题。EI有一种离线做法。[code-model](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-27/P3919%20%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%8F%AF%E6%8C%81%E4%B9%85%E5%8C%96%E7%BA%BF%E6%AE%B5%E6%A0%91%201%EF%BC%88%E6%A8%A1%E7%89%88%E5%81%9A%E6%B3%95%EF%BC%89.cpp)[code-EI](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-27/P3919%20%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%8F%AF%E6%8C%81%E4%B9%85%E5%8C%96%E7%BA%BF%E6%AE%B5%E6%A0%91%201%EF%BC%88EI%E6%8F%90%E5%87%BA%E7%9A%84%E7%A6%BB%E7%BA%BF%E5%81%9A%E6%B3%95%EF%BC%89.cpp)
[luogu-P3834](https://www.luogu.com.cn/problem/P3834)可持久化线段树求区间第K大模板题。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/luogu/P3834%20%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%8F%AF%E6%8C%81%E4%B9%85%E5%8C%96%E7%BA%BF%E6%AE%B5%E6%A0%91%202.cpp)
[luogu-P1972](https://www.luogu.com.cn/problem/P1972)典题，主席树/树状数组离线/莫队[code-online](https://github.com/unclezhou486/ACM-Solutions/blob/main/luogu/P1972%20%5BSDOI2009%5D%20HH%E7%9A%84%E9%A1%B9%E9%93%BE(%E4%B8%BB%E5%B8%AD%E6%A0%91).cpp) /[code-not online](https://github.com/unclezhou486/ACM-Solutions/blob/main/luogu/P1972%20%5BSDOI2009%5D%20HH%E7%9A%84%E9%A1%B9%E9%93%BE(%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84%E7%A6%BB%E7%BA%BF).cpp)

## 图论

### 分层图

[HDU7408](https://acm.hdu.edu.cn/showproblem.php?pid=7408)纯的板子几乎是。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/%E2%80%9C%E5%8D%8E%E4%B8%BA%E6%9D%AF%E2%80%9D%E6%9D%AD%E5%B7%9E%E7%94%B5%E5%AD%90%E7%A7%91%E6%8A%80%E5%A4%A7%E5%AD%A62023%E6%96%B0%E7%94%9F%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/1007%E9%80%83%E7%A6%BB%E8%8A%82%E5%A5%8F%E9%9D%A2.cpp)

## 动态规划
这个说实话我不是很会，出现在这里的题目可能都是我抄的题解。
动态规划一般都是通过某种顺序的枚举来减少状态的数量以达到优化的效果。
### 无严格分类

[GYM104076J](https://codeforces.com/gym/104076/problem/J) 有点卡常[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-23/J_Skills.cpp)

### 决策单调性优化dp


[luogu-P7962](https://www.luogu.com.cn/problem/P7962)，差分，决策单调性dp。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/luogu/P7962%20%5BNOIP2021%5D%20%E6%96%B9%E5%B7%AE.cpp)

## 计算几何

注意到这里的题目应该是参加wls的winter camp的时候做的，我应该也是不会的。

### 叉积

叉积我只会用来求面积，以及利用它进行顺时针或逆时针的排序。
[QOJ-6676](https://qoj.ac/problem/6676)叉积求面积[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-24/Computational%20Geometry.cpp) 
[QOJ-7653](https://qoj.ac/problem/7653)使用叉积判断共线[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-24/Balloon%20Darts.cpp)

### 凸包

[QOJ-7730](https://qoj.ac/problem/7730)凸包模板题[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-24/Convex%20Checker.cpp)

## 猜结论

[GYM104901A](https://codeforces.com/gym/104901/problem/A)，看着像拓号匹配的东西我就头疼[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-25/Many%20Many%20Heads.cpp)
