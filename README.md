# ACM-Solutions

记录，并整理题目类型

慢慢补，暂时补到表格里的第20项

放在这里提醒自己自己补一下团队队友打的题[1](https://codeforces.com/gym/105053/problem/E)/[2](https://codeforces.com/gym/105053/problem/F)

## 基础算法

### 模拟

[牛客80186H](https://ac.nowcoder.com/acm/contest/80186/H)/[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E4%BA%94%E4%B8%80(1)/Stammering_Chemists.cpp)

[牛客80186B](https://ac.nowcoder.com/acm/contest/80186/B)需要注意到题目中的k的范围。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E4%BA%94%E4%B8%80(1)/Coffee_Chicken.cpp)

[牛客小白93D](https://ac.nowcoder.com/acm/contest/82401/D)题解说是可以运用二进制的相关知识，但是我是模拟的。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E5%B0%8F%E7%99%BD93/%E5%B9%BB%E5%85%BD%E5%B8%95%E9%B2%81.cpp)

[牛客81509H](https://ac.nowcoder.com/acm/contest/81509/H) 分成最少个导弹拦截的序列[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E5%B1%B1%E4%B8%9C%E7%90%86%E5%B7%A5/%E6%88%91%E6%9C%80%E5%96%9C%E6%AC%A2%E5%90%83%E9%A5%AD%E4%BA%86.cpp)

[牛客81509J](https://ac.nowcoder.com/acm/contest/81509/J) 易发现只可能取同一列[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E5%B1%B1%E4%B8%9C%E7%90%86%E5%B7%A5/%E8%BF%99%E4%B8%8D%E6%98%AFRMQ%E9%97%AE%E9%A2%98%E6%8D%8F.cpp)

[牛客81509K](https://ac.nowcoder.com/acm/contest/81509/K) 带点思维的模拟，我赛时不会，抄的题解代码。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E5%B1%B1%E4%B8%9C%E7%90%86%E5%B7%A5/%E7%8C%9C%E7%8C%9C%E6%95%B0.cpp)

### 贪心

[GYM105053K](https://codeforces.com/gym/105053/problem/K) [code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/GYM/GYM105053/K_KMOP.cpp)

### 离散化

[牛客82526D](https://ac.nowcoder.com/acm/contest/82526/D) 注意到因子个数的种类不超过70，所以分开做前缀和计算即可。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E5%91%A8%E8%B5%9B44/%E5%9B%A0%E5%AD%90%E5%8C%BA%E9%97%B4.cpp)

### DFS

打OI的时候很喜欢暴力加剪枝。 打ICPC的时候有点不太敢了，不太熟。

[GYM104821A](https://codeforces.com/gym/104821/problem/A)将每个袋鼠可行的运动方案通过某种方式爆搜实现即可。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-25/Cool%2C%20It%27s%20Yesterday%20Four%20Times%20More.cpp)

[牛客80743D](https://ac.nowcoder.com/acm/contest/80743/D) 一个dfs解决[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E5%91%A8%E8%B5%9B42/%E5%B0%8F%E7%BA%A2%E7%9A%84%E6%A0%91%E4%B8%8A%E5%88%A0%E8%BE%B9.cpp)

[CF1375G](https://codeforces.com/problemset/problem/1375/G) 把操作看成染色之后的操作，之后就是dfs。



### BFS

[ECNU819C](https://acm.ecnu.edu.cn/contest/819/problem/C/) bfs [code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/ECNU%E9%82%80%E8%AF%B7%E8%B5%9B/C_%E5%AE%81%E4%BD%9C%E5%90%BE.cpp)


### 位运算

往往同时用于01字典树。

[abc337E](https://atcoder.jp/contests/abc337/tasks/abc337_e)注意到我们是想要让状态的数量最少。显然用0和1表示状态是最优的，所以想到使用二进制。（我没想到）[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/ABC337/E.cpp)

[CF1918C](https://codeforces.com/contest/1918/problem/C)位运算加贪心[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/CF1918/C_XOR_distance.cpp)

[CF875D](https://codeforces.com/problemset/problem/875/D) 类似贡献法做。

### 二分答案

一般来说，题目要求满足某种条件的最大（小）值的时候，就可以优先考虑二分答案。

[HDU7405](https://acm.hdu.edu.cn/showproblem.php?pid=7405)正解是线性的dp，但是我赛时用的二分答案加二进制优化背包把这题水过去了。 [code-solution](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/%E2%80%9C%E5%8D%8E%E4%B8%BA%E6%9D%AF%E2%80%9D%E6%9D%AD%E5%B7%9E%E7%94%B5%E5%AD%90%E7%A7%91%E6%8A%80%E5%A4%A7%E5%AD%A62023%E6%96%B0%E7%94%9F%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/1004%E6%99%BA%E8%83%BD%E8%BD%A6%EF%BC%88solution%E7%9A%84%E5%81%9A%E6%B3%95%EF%BC%89.cpp)/[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/%E2%80%9C%E5%8D%8E%E4%B8%BA%E6%9D%AF%E2%80%9D%E6%9D%AD%E5%B7%9E%E7%94%B5%E5%AD%90%E7%A7%91%E6%8A%80%E5%A4%A7%E5%AD%A62023%E6%96%B0%E7%94%9F%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/1004%E6%99%BA%E8%83%BD%E8%BD%A6%EF%BC%88%E6%88%91%E7%9A%84%E5%81%9A%E6%B3%95%EF%BC%89.cpp)

[HDU7409](https://acm.hdu.edu.cn/showproblem.php?pid=7409)二分答案。可以在排序后用双指针O(N)的check。我赛时没想到，就用的O(Nlog^2(N))[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/%E2%80%9C%E5%8D%8E%E4%B8%BA%E6%9D%AF%E2%80%9D%E6%9D%AD%E5%B7%9E%E7%94%B5%E5%AD%90%E7%A7%91%E6%8A%80%E5%A4%A7%E5%AD%A62023%E6%96%B0%E7%94%9F%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/1008%E5%A4%A7%E9%9B%AA%E7%90%83.cpp)

### 差分

[牛客小白93E](https://ac.nowcoder.com/acm/contest/82401/E) 如果刚开始考虑分块，那么注意到只需要维护一些区间的前后缀和和数的个数即可计算合并区间造成的答案。接下来发现这些需要维护的值都可以用前缀和维护。因此我们可以将求答案的过程转为上面合并操作的逆过程，计算出来即可。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E5%B0%8F%E7%99%BD93/%E5%A5%8F%E7%BB%9D.cpp)

### STL

[牛客81509D](https://ac.nowcoder.com/acm/contest/81509/D) 题解说是双指针，但是我不会，我用的是map套vector的做法，感觉有点暴力，但是能过。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E5%B1%B1%E4%B8%9C%E7%90%86%E5%B7%A5/%E4%BC%9A%E7%BC%96%E7%A8%8B%E7%9A%84%E8%80%81%E5%B8%88.cpp)



## 数据结构

### 树状数组

一般都是用在处理某个范围内的东西的时候用。

[ECNU819D](https://acm.ecnu.edu.cn/contest/819/problem/D/) 离散化，树状数组 [code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/ECNU%E9%82%80%E8%AF%B7%E8%B5%9B/D_%E4%BD%A0%E9%A1%BB%E5%81%BF%E8%BF%98.cpp)



### 字典树

[HDU7406](https://acm.hdu.edu.cn/showproblem.php?pid=7406)比较经典的01trie树的运用。再加上位运算经常要用到从高位到地位确定的一个特点。 [code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/%E2%80%9C%E5%8D%8E%E4%B8%BA%E6%9D%AF%E2%80%9D%E6%9D%AD%E5%B7%9E%E7%94%B5%E5%AD%90%E7%A7%91%E6%8A%80%E5%A4%A7%E5%AD%A62023%E6%96%B0%E7%94%9F%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/1005%E6%A0%91.cpp)


### 珂朵莉树

喜欢暴力。

[GYM104821M](https://codeforces.com/gym/104821/problem/M)可以说感觉就是珂朵莉树的操作。（或者说分块？）[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-25/Trapping%20Rain%20Water.cpp)

### 可持久化数据结构

一般用的应该都是可持久化线段树。

有时候也许可以尝试转为使用离线操作？

[luogu-P3919](https://www.luogu.com.cn/problem/P3919)模板题。EI有一种离线做法。[code-model](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-27/P3919%20%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%8F%AF%E6%8C%81%E4%B9%85%E5%8C%96%E7%BA%BF%E6%AE%B5%E6%A0%91%201%EF%BC%88%E6%A8%A1%E7%89%88%E5%81%9A%E6%B3%95%EF%BC%89.cpp)/[code-EI](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-27/P3919%20%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%8F%AF%E6%8C%81%E4%B9%85%E5%8C%96%E7%BA%BF%E6%AE%B5%E6%A0%91%201%EF%BC%88EI%E6%8F%90%E5%87%BA%E7%9A%84%E7%A6%BB%E7%BA%BF%E5%81%9A%E6%B3%95%EF%BC%89.cpp)

[luogu-P3834](https://www.luogu.com.cn/problem/P3834)可持久化线段树求区间第K大模板题。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/luogu/P3834%20%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%8F%AF%E6%8C%81%E4%B9%85%E5%8C%96%E7%BA%BF%E6%AE%B5%E6%A0%91%202.cpp)

[luogu-P1972](https://www.luogu.com.cn/problem/P1972)典题，主席树/树状数组离线/莫队[code-online](https://github.com/unclezhou486/ACM-Solutions/blob/main/luogu/P1972%20%5BSDOI2009%5D%20HH%E7%9A%84%E9%A1%B9%E9%93%BE(%E4%B8%BB%E5%B8%AD%E6%A0%91).cpp) /[code-not online](https://github.com/unclezhou486/ACM-Solutions/blob/main/luogu/P1972%20%5BSDOI2009%5D%20HH%E7%9A%84%E9%A1%B9%E9%93%BE(%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84%E7%A6%BB%E7%BA%BF).cpp)

[GYM104849](https://codeforces.com/gym/104849/problem/E) 可持久化线段树加逆序对，场上思路是一下就出来了，就是我对于这个算法运用不熟练（完全没有想到要怎么用这个算法），但是队友ov_vo实力在线，听完我的思路一下就打出来了。 让我更深刻的认识到这个算法该用的地方。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/GYM104849/E_Incredibly_Cute_Penguin_Chicks.cpp)

[LOJ 535](https://loj.ac/p/535) 整体二分加上可持久化权值线段树[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/LOJ/535_LibreOJ_Round_6_%E8%8A%B1%E7%81%AB.cpp)，/或者用扫描线

## 图论

### 树上最近公共祖先（LCA）

这个一般在数的题目中或多或少都会用到一点。

[GYM105167A](https://codeforces.com/gym/105167/problem/A) LCA加树上前缀和

### 树的直径

[GYM105143E](https://codeforces.com/gym/105143/problem/E)动态求树的直径[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E6%AD%A6%E6%B1%89%E9%82%80%E8%AF%B7%E8%B5%9B/E_Boomerang.cpp)

[LuoguP10238](https://www.luogu.com.cn/problem/P10238)动态求森林中树的直径[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/luogu/P_10238_yLCPC_2024_F_PANDORA_PARADOXXX.cpp)

[GYM105139I](https://codeforces.com/gym/105139/problem/I) 动态求树的直径，加上并查集的应用[code-copy-jiangly](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/2024%E6%B9%96%E5%8C%97%E7%9C%81%E8%B5%9B/I_Colorful_Tree.cpp)



### 分层图

[HDU7408](https://acm.hdu.edu.cn/showproblem.php?pid=7408)纯的板子几乎是。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2023/%E2%80%9C%E5%8D%8E%E4%B8%BA%E6%9D%AF%E2%80%9D%E6%9D%AD%E5%B7%9E%E7%94%B5%E5%AD%90%E7%A7%91%E6%8A%80%E5%A4%A7%E5%AD%A62023%E6%96%B0%E7%94%9F%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/1007%E9%80%83%E7%A6%BB%E8%8A%82%E5%A5%8F%E9%9D%A2.cpp)

### 二分图

[CF1592F2](https://codeforces.com/problemset/problem/1592/F2) [code-my]()

## 网络流

### 最大流

[LuoguP2762](https://www.luogu.com.cn/problem/P2762)把题目转化成经典的网络流模型即可[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/luogu/P_2762_%E5%A4%AA%E7%A9%BA%E9%A3%9E%E8%A1%8C%E8%AE%A1%E5%88%92%E9%97%AE%E9%A2%98.cpp)

## 动态规划

这个说实话我不是很会，出现在这里的题目可能都是我抄的题解。

动态规划一般都是通过某种顺序的枚举来减少状态的数量以达到优化的效果。

### 无严格分类

[ECNU819F](https://acm.ecnu.edu.cn/contest/819/problem/F/) 简单dp[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/ECNU%E9%82%80%E8%AF%B7%E8%B5%9B/F_%E6%BA%90%E7%9F%B3%E8%99%AB.cpp)

[GYM104076J](https://codeforces.com/gym/104076/problem/J) 有点卡常[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-23/J_Skills.cpp)

[牛客81509C](https://ac.nowcoder.com/acm/contest/81509/C) 发现图比较小，有重复的点，所以用dp转移。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E5%B1%B1%E4%B8%9C%E7%90%86%E5%B7%A5/%E9%9C%87%E6%83%8A_%E6%9C%80%E5%A5%BD%E7%9A%84%E8%B5%B0%E4%BD%8D%E7%AB%9F%E7%84%B6%E6%98%AF.cpp)

### 期望dp

[牛客80743](https://ac.nowcoder.com/acm/contest/80743/F) 听说是常见的期望dp。好好研究一下。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E5%91%A8%E8%B5%9B42/%E5%B0%8F%E7%BA%A2%E7%9A%84%E6%89%94%E9%AA%B0%E5%AD%90.cpp)



### 背包

[GYM103688G](https://codeforces.com/gym/103688/problem/G) 背包求方案数，思考的时候可以用断环成链的方式辅助一下？[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/train/2024-05-09/G_Chevonne_s_Necklace.cpp)



### 决策单调性优化dp

[luogu-P7962](https://www.luogu.com.cn/problem/P7962)，差分，决策单调性dp。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/luogu/P7962%20%5BNOIP2021%5D%20%E6%96%B9%E5%B7%AE.cpp)

## 计算几何

注意到这里的题目应该是参加wls的winter camp的时候做的，我应该也是不会的。

### 叉积

叉积我只会用来求面积，以及利用它进行顺时针或逆时针的排序。

[牛客82394E](https://ac.nowcoder.com/acm/contest/82394/E) 叉积求面积，加上平行四边形中点平分对角线 [code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E5%91%A8%E8%B5%9B43/%E5%B0%8F%E7%BA%A2%E7%9A%84%E5%B9%B3%E8%A1%8C%E5%9B%9B%E8%BE%B9%E5%BD%A2.cpp)

[QOJ-6676](https://qoj.ac/problem/6676)叉积求面积[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-24/Computational%20Geometry.cpp) 

[QOJ-7653](https://qoj.ac/problem/7653)使用叉积判断共线[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-24/Balloon%20Darts.cpp)

### 凸包

[QOJ-7730](https://qoj.ac/problem/7730)凸包模板题[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-24/Convex%20Checker.cpp)

## 猜结论

[GYM104901A](https://codeforces.com/gym/104901/problem/A)，看着像拓号匹配的东西我就头疼[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/namo/1-25/Many%20Many%20Heads.cpp)

[LuoguP3951](https://www.luogu.com.cn/problem/P3951)，打表找规律好题，当然还可以用数论做，但是我暂时只会找规律。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/train/2024-05-09/B_%E5%B0%8F%E5%87%AF%E7%9A%84%E7%96%91%E6%83%91_%E8%93%9D%E6%A1%A5%E6%9D%AF_2013_%E7%9C%81_%E4%B9%B0%E4%B8%8D%E5%88%B0%E7%9A%84%E6%95%B0%E7%9B%AE.cpp)

## 构造

[牛客825226E](https://ac.nowcoder.com/acm/contest/82526/E)要构造出合数，显然构造出大于2的偶数更为方便，往这方面想。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E5%91%A8%E8%B5%9B44/%E5%B0%8F%E8%8B%AF%E7%9A%84%E6%8E%92%E5%88%97%E6%9E%84%E9%80%A0.cpp)

## 数论

数论我只会gcd和快速幂

### 乘法逆元

[牛客82401C](https://ac.nowcoder.com/acm/contest/82401/C)简单的求期望[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E5%B0%8F%E7%99%BD93/%E8%80%81%E8%99%8E%E6%9C%BA.cpp)

### 因数

[牛客81509E](https://ac.nowcoder.com/acm/contest/81509/E)我用的方法是枚举因子的次数加上剪枝，题解暂时没看懂。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E5%B1%B1%E4%B8%9C%E7%90%86%E5%B7%A5/%E4%B8%8D%E6%98%AF_%E5%93%A5%E4%BB%AC.cpp)

### 组合数学

[牛客80743E](https://ac.nowcoder.com/acm/contest/80743/E) 贡献法，计算每一个数字的贡献即可。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E5%91%A8%E8%B5%9B42/%E5%B0%8F%E7%BA%A2%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97%E6%B1%82%E5%92%8C.cpp)

[牛客82394F](https://ac.nowcoder.com/acm/contest/82394/F) [code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/%E7%89%9B%E5%AE%A2%E5%91%A8%E8%B5%9B43/%E5%B0%8F%E7%BA%A2%E5%B0%8F%E7%B4%AB%E7%94%BB%E7%BA%BF.cpp)





## 交互

[CF1713D](https://codeforces.com/contest/1713/problem/D) 带点贪心的交互？想了一会时间，感觉也蛮好玩的。[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/train/2024-05-09/D_Tournament_Countdown.cpp)

## 字符串

### 回文树

[ECNU819G](https://acm.ecnu.edu.cn/contest/819/problem/G/) 计算本质不同的回文子串个数，回文树板子[code-my](https://github.com/unclezhou486/ACM-Solutions/blob/main/2024/ECNU%E9%82%80%E8%AF%B7%E8%B5%9B/G_%E4%BF%83%E8%9E%8D%E5%85%B1%E7%AB%9E.cpp)

### 哈希

[GYM103688L](/https://codeforces.com/gym/103688/problem/L) 注意到操作的最终效果，之后用哈希判断是否相同
