少有的被自己气笑了。记录一下武汉邀请赛的D题，我在赛场上是怎么想的。



很好很好，这一题看完题解发现代码真的是相当的简单啊。但是赛时的时候应该是因为没怎么见过这种类型的题目，所以当时没有想到最直接的方法，我先讲一下我当时用的傻方法。



## 题目大意

有$n$个食物，每个食物各有$a_{i}$的价值，1秒可以向左或者向右移动1步，当你移动到某一点时，会把这个点的食物吃掉。设$F_{s,t}$为起点是$s$点，移动了$t$秒，你能吃的食物总和的最大值。

让你快速求出对于$1 \leq s \leq n , 1 \leq t \leq 2n$的所有$F_{i,j}$，在最后用某种形式输出。



$1 \leq n \leq 5000 ,1 \leq a_{i} \leq 10^{9} $

---



**前排提醒，my solution 实际上只是本人的胡言乱语，官方的solution相当的简单。**

---



## my solution

这个题目看着题意就相当的简单啊。我们也可以显然的想出，想让$F_{i,j}$最大，这个人最多只需要转向一次。（否则的话重复的转向是没有必要的）

显然，在我们要计算一段路径中可以吃的食物的总和时可以使用前缀和进行优化，所以我们在下面用$pre_{i}$来表示$\sum^{i}_{1}a_{i}$

接下来就很显然了。一共就两种情况：

### 不转向

你知道的，向左和向右没有本质的区别。

所以我们就只讨论其中一种情况，另一种情况可以你在手算一遍或者直接把数组翻转一遍之后再进行一次原操作即可。

所以我们在下面只讨论先向左移动的情况。

设起点为$s$，所花时间为$t$。

显然 $F_{s,t}=pre_{s}-pre_{max(0,s-t-1)}$。

### 转向

我们假设在$l$点进行转向，然后最后到达$r$点。

显然$F_{s,t}=pre_{max(r,s)}-pre_{l-1}$

对于$l$和$r$之间的关系，我们画个图就可以轻松的得出：

$$2 \times (s-l) + (r-s)=t$$

$$r=2l+t-s$$

那么我们再把式子变一下：
$$
F_{s,t} =
\begin{cases}
\max(pre_{s}-pre_{l-1}), & s-t \leq l \leq s-\frac{t}{2} \\
\max(pre_{2l+t-s}-pre_{l-1}), & s-\frac{t}{2} < l \leq s
\end{cases}
$$
很好，推到这里的时候考场上的我陷入了沉思，接下来要怎么做呢。我们这时候观察一下题目的数据范围，这一题肯定是要用$O(N^{2})$的方法来解决这一道题的。

所以说，按常理来说，$F_{s,t}$肯定是与它相邻的几项之间有着某种联系，或者说肯定是由别的$F$转移而来的，不然的话就做不到$O(N^{2})$了。

那么我们显然就是要对$s,t$这两个变量进行观察。

然后，我又突然想到，一般与前缀和有关的题目都是把某个相同的东西放在一起，这样最后就可以用取最大值的方式来快速求解。（类似树状数组求逆序对？）

所以开始观察题目的式子里有什么东西是在$s,t$变化之后仍可以保持不变的。

我们注意到，对于分段函数上面的那种情况，在转向后没有吃掉新的食物，肯定是不如不转向的情况的，所以我们可以忽略这种情况。但是同时，为了方便下面的讨论，我们已经知道当$l$属于那一段数据范围的时候是肯定不如不转向的请款的。所以为了下面讨论的方便，我们不妨使得

$$F_{i,j}=max(pre_{2l+t-s}-pre_{l-1}) \quad s-t \leq l \leq s $$

接下来，结合我们前面的所有因素一起思考（对于$s,t$进行观察，找到相邻的数据之间的关系）。

那么我们通过对$s,t$ 分别进行$-1,+0,+1$的处理发现：

当$s=s+1,t=t+1$的时候函数中的$pre_{2l+t-s}-pre_{l-1}$与$s=s,t=t$时的式子是相同的，并且$l$的取值范围在左半边也是完全相同的，两者之间只多增加了一个$l=s+1$的情况。

那么，答案就很显然了$F_{s,t}=max(F_{s-1,t-1},pre_{s+t}-pre_{s-1})$，我们又发现了，右边这个实际上就是不转向的情况（好像这里讨论的明明是不转向的情况，数据范围本就不该这么写，但是为了讨论的方便，我这里就这么表达了，如果不便，请谅解）。

所以说，实际上，当我们需要转向时$F_{s,t}$就是等于$F_{s-1,t-1}$。

好了，结束了，对于先向右走的情况你可以用同样的方法推一遍，但实际上也可以通过把数组翻转一遍的方式重复上述过程（好像上面提过了？）。



很好，最后的结论很简单，但是为什么我在场上没做出来呢？其实是因为我在场上的时候首先是没有考虑到先走右边的情况可以不用考虑（翻转一遍即可）。

毕竟，你知道的，做得越多，错的越多。就是因为这种情况，导致我在思考的时候陷入了僵局（因为另一种我推导的时候推错了），结果就是导致另一种我的处理方式多了一个$log$级别的运算，并且把需要的步骤变得略显复杂。

同时，我在上面讨论的数据范围边界的讨论中，出了一点小瑕疵，导致转向时的$F_{s,t}$还是需要进行一个取最大值的操作才可以得到。所以我当时对自己是否能在最后打出来抱有很大的怀疑态度。

同时，你知道的，这个结论看起来也太抽象了，因为这个我纯通过数学的公式观察出来的（找规律？），虽然式子推导的没有问题，但是我无法从直观上感知出这个做法的正确性在哪里（这应该是我的问题）。所以我无法保证自己的思路就是对的。并且当时队友都在分别调题，他们写得题又碰巧都是我一点都不会的地方（树的直径，数论），并且都差一点了的样子。中途我上过机，但是由于我在上面讨论的过程中的种种问题，导致我无法快速的写出这个代码。后来队友要调题，自然只能交给队友。因为我自知这个做法本就不一定对，并且我因为错误的讨论，还多需要一个log的层数，导致我思绪越来越乱。但至少最后队友的题目调出来了。



好了，上面我的长篇大论（）完了，接下来是官方的做法。



## 官方solution

![](https://unclezhou.top/wp-content/uploads/2024/05/Snipaste_2024-05-06_23-22-26.png)

这个说实话大家稍微思考一下，或者说手动稍微模拟一下应该就能看出来正确性了，和我最后得出的结论是完全等价的。

是不是非常简单。但是我当时没有做出来。



## code

最后附上我看完题解才补的代码：

```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;

int n;
int a[N];
long long s[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    vector<vector<long long > > dp( (n+2) ,vector<long long > ((n<<1)+1) );
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+(long long )a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            dp[i][j]=max(s[i]-s[max(0,i-j-1)],s[min(n,i+j)]-s[i-1]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=2*n;j++){
            dp[i][j]=max(dp[i][j],dp[i+1][j-1]);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long res=0;
        for(int j=1;j<=2*n;j++){
            res^=j*dp[i][j];
        }
        res+=i;
        ans^=res;
    }
    cout<<ans<<'\n';
}
```