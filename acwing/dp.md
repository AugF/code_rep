# DP解题思路

1. 状态表示 f[i,j]
    - 集合：所有只从前i个物品中选，总体积不超过j的集合
    - 集合的值属性：Max, Min, 数量
2. 状态计算，集合划分（要求不重不漏）
    - 所有选法中不包含i, f[i-1][j]
    - 所有选法中包含i, f[i-1][j-v] + w

动态规划考虑三个问题：
1. 状态方程表达式
2. 基本情况
3. 结果如何表示？

## 1. 背包问题

### 01背包, 每件物品选1次
1. 状态方程
f[i][j]: 选择前i件物品，总体积不超过j的最大价值
f[i][j] = max(f[i - 1][j], f[i - 1][j - v] + w); 包含第i件物品和不包含第i件物品
2. 基本情况
f[0][i] = 0
3. 结果
f[n][m]

```
#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
int f[N];

int main() {
    cin >> n >> m;
    
    while (n --) {
        int v, w;
        cin >> v >> w;
        for (int i = m; i >= v; i --)
            f[i] = max(f[i], f[i - v] + w);
    }
    cout << f[m] << endl;
    return 0;
}
```
### 完全背包问题：每件物品可以选任意次
f[i][j]: 从前i件物品中选，总体积不超过j的集合的最大值
f[i][j] = max(f[i - 1][j], f[i - 1][j - v] + w, f[i - 1][j - 2v] + 2w, ...)
f[i][j-v] = max(f[i - 1][j - v], f[i - 1][j - 2v] + w)

即 f[i][j] = max(f[i - 1][j], f[i][j-v] + w)
```
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N], f[N];

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++) scanf("%d%d", &v[i], &w[i]);
    
    // 完全背包问题
    // f[i,j] 取前i个物品，总质量为j的集合的最大值
    // 按照是否取第i个物品， f[i, j] = max(f[i-1, j], f[i-1, j-v]+w)  f[i, j-v]=max(f[i-1,j-v], f[i-1][j-2v]+w)
    // 于是f[i, j] = max(f[i-1, j), f[i, j-v] + w) // 算j时需要用到j-v， 所以从小到大
    // 初始值不用考虑
    
    for (int i = 1; i <= n; i ++)
        for (int j = v[i]; j <= m; j ++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            
    printf("%d\n", f[m]);
    return 0;
}
```

### 多重背包问题：每件物品只能选k次

枚举第i件物品选1..s个的最大值
f[i,j] = max(f[i-1,j-kv]+kw)  k=0,1,2,...,s[i]

1. basic O(NVK), O(NV)
```
#include<iostream>

using namespace std;

const int N=110;

int n,m;
int v[N],w[N],s[N];
int f[N][N];

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];

    for(int i=1;i<=n;i++)  // 100^3
        for(int j=0;j<=m;j++)
            for(int k=0;k<=s[i] && k*v[i]<=j;k++){
                f[i][j]=max(f[i][j], f[i-1][j-v[i]*k]+w[i]*k);
            }

    cout<<f[n][m]<<endl;
    return 0;
}
```

2. 二进制优化 O(NlogS V), O(VNlogS)
假设第i件物品可以选s次，则可以转换为选1次，选2次，选4次，..., 选c次的01背包问题
1,2,4,8,..,2^k,c
c=s-(2^{k+1}-1)

```
// 一种优化的想法就是把选择s个物品，s用二进制位来表示。 s->logs  nvlogs
// 这里思想很牛逼的想法是，将多重背包问题，选一个物品7次，可以看作 1w, 2w, 4w的均进行选择
// 于是每个背包选k次的问题就转变为01背包问题
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25000, M = 2010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;
    
    int cnt = 0;
    
    for (int i = 1; i <= n; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        while (k <= s) {
            cnt ++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;  // 1, 2, 4,     0 ~ 2^{k-1}, n \in 2^k ~ 2^{k-1}, so 2^k <= s  
        }
        if (s > 0) {
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    n = cnt;
    for (int i = 1; i <= n; i ++)
        for (int j = m; j >= v[i]; j --)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    printf("%d\n", f[m]);
    return 0;
}
```

3. 单调队列优化
```
// f[j] = f[j - v]+w, f[j - 2*v] + 2w, ..., f[j - k*v] + kw  
// f[j-v] = f[j - 2*v]+w, f[j - 3*v] + 2w, ..., f[j - (k+1)*v] + kw  
// 实际上是动态地求前k-1个的最大值
// 
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 20010;

int n, m;
int f[M], g[M], q[M];

int main() {
    cin >> n >> m;
    
    while (n --) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = 0; j < v; j ++) {
            int hh = 0, tt = -1;
            memcpy(g, f, sizeof f);
            // 求区间的最大值
            for (int k = j; k <= m; k += v) {
                if (hh <= tt && q[hh] < k - s * v) hh ++; // q[hh]是实际的体积，实际的体积小于承受的体积
                if (hh <= tt) {
                    f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w);
                    // (k - q[hh]) / v * w 中间空余了多少体积个w. 
                    // 这里很妙，实际上w的个数是跟与当前点的关系来看的
                    // 如果q[hh]是直接前一个点，就加一个。
                }
                while (hh <= tt && g[q[tt]] + (k - q[tt]) / v * w <= g[k]) tt -- ;
                // 这里其实是对当前的维护
                // g[q[tt]] + (k - q[tt])/v * w 队中元素的值
                // g[k] - (k - j) * w 当前元素的值
                q[++ tt] = k;
            }
        }
    }
    
    cout << f[m] << endl;
    return 0;
}
```

### 分组背包问题：每组只能选一个
枚举选组内哪个最好
f[i][j] = max(f[i][j], f[i-v[i][k]] + w[i][k])
```
#include <iostream>
using namespace std;

const int N = 110, M = 110, S = 110;

int n, m;
int w[N][S], v[N][S], s[N];
int f[M];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j ++)
            cin >> v[i][j] >> w[i][j];
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = m; j >= 0; j --)
            for (int k = 0; k <= s[i]; k ++) 
            // 有k种选择
                if (j >= v[i][k])
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
    }
    cout << f[m] << endl;
    return 0;
}
```

### 二维背包问题
```
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, V, M;
int f[N][N];

int main() {
    
    cin >> n >> V >> M;
    
    for (int i = 0; i < n; i ++) {
        int v, m, w;
        cin >> v >> m >> w;
        
        for (int j = V; j >= v; j --)
            for (int k = M; k >= m; k --)
                f[j][k] = max(f[j][k], f[j - v][k - m] + w);
    }
    
    cout << f[V][M] << endl;
    return 0;
}
```
### 有依赖的背包

f[u, j]: 所有从以u为根的子树中选，且总体积不超过j的方案
属性：Max

集合划分：（注意可以考虑多种方案）
1. 子树, 每个子树可以选或者不选
2. 体积 f[u][j] = max(f[u][j], f[u][j-k] + f[son][k]) 
```
// 注意一定要抽象出来模型，这里实际是每一组选什么模型
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;

int n, m;
int v[N], w[N];
int h[N]; // 头插法，实际上存储的是尾节点
int e[N], ne[N], idx;
int f[N][N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

// f[u, j]: 所有以u为根的子树中，且总体积不超过j的方案
// 问题抽象：从儿子节点的角度出发和从父亲节点的角度出发
void dfs(int u) {
    
    for (int i = h[u]; i != -1; i = ne[i]) { // 注意这里的遍历条件
        int son = e[i];
        dfs(son);
        
        // 分组背包，解决可以选多个
        // 因为要求是多个儿子节点对应一个父亲节点
        for (int j = m - v[u]; j >= 0; j --)
            // 这里必须要选，所以要把当前位置空出来
            for (int k = 0; k <= j; k ++) // 这里把类别转化为了体积
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
    }
    
    // 再将儿子算完后，更新当前
    for (int i = m; i >= v[u]; i --) f[u][i] = f[u][i - v[u]] + w[u];
    // 因为根节点不能选，所有都不能选
    for (int i = 0; i < v[u]; i ++) f[u][i] = 0;
}

int main() {
    cin >> n >> m;
    
    int root;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++) {
        int q;
        cin >> v[i] >> w[i] >> q;
        if (q == -1) root = i;
        else add(q, i);
    }
    
    dfs(root);
    cout << f[root][m] << endl;
    return 0;
}
```

### 背包问题求方案数
求最优选法的方案数
f[i,j] = max(f[i-1,j], f[i-1,j-v]+w);
if (f[i,j] == f[i-1,j]) g[i,j] += g[i-1,j];
if (f[i,j] == f[i-1][j-v]+w) g[i,j] += g[i-1,j-v];

f[0,0]=0, g[0,0]=1;

res=max(res, f[n][j]);
cnt += sum(g[n][j]) if f[n][j] == res;
```
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n, m;
int f[N], g[N];

int main() {
    cin >> n >> m;
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;
    
    while(n --) {
        int v;
        cin >> v;
        
        for (int j = m; j >= v; j --) {
            int maxv = max(f[j], f[j - v] + v);
            int cnt = 0;
            
            if (maxv == f[j]) cnt += g[j];
            if (maxv == f[j - v] + v) cnt += g[j - v];
            
            g[j] = cnt % mod;
            f[j] = maxv;
        }
    }
    
    int res = 0;
    for (int i = 0; i <= m; i ++) res = max(res, f[i]);
    int cnt = 0;
    for (int i = 0; i <= m; i ++) {
        if (res == f[i])
            cnt = (cnt + g[i]) % mod;
    }
    int ans = 0;
    for (int i = 0; i <= m; i ++) ans += g[i];
    cout << ans << endl;
    
    return 0;
}
```

### 背包问题求具体方案
输出字典序最小的方案

如何输出字典序最小的方案？DP倒序做
f[i,j] = max(f[i+1,j], f[i+1][j-v[i]] + w[i]);

f[1][m]即最终解;
int j = m;
for (int i = 1; i <= n; i ++)
    if (j >= v[i] && f[i][j] == f[i+1][j-v[i]] + w[i]) {
        cout << i << ' ';
        j -= v[i];
    }
```
#include <iostream>
using namespace std;

const int N = 1010, M = 1010;

int n, m;
int f[N][M], w[N], v[N];

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];
    
    for (int i = n; i >= 1; i --)
        for (int j = 0; j <= m; j ++) {
            f[i][j] = f[i + 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    int j = m;
    for (int i = 1; i <= n; i ++)
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i]) {
            cout << i << ' ';
            j -= v[i];
        }
    return 0;
}
```

### 三种集合的表示方式的区别
1. 体积最多是j，见常见的背包问题
2. 体积至少是j，潜水员问题 **
3. 体积恰好是j，数的划分问题
初始化都是f[0][0][0]=0, f[i][j][k]=+inf

潜水员问题：
有一定数量的气缸，有一定量的氧气和氮气
求满足工作所需气缸的总重最低限度是多少？
> 注意背包问题，体积不能超过总体积；这里是体积必须超过总体积

f[i,j,k]: 表示选择前i个气缸，体积不超过j的重量
f[i,j,k] = min(f[i-1,j,k], f[i-1,j-v1,k-v2]+w); j>v1, k>v2
划分方法：假设左边也是合法状态，即子问题f[i,j,k]; 而右边相等; 这里唯一的就是f[i,j]初始情况不同。

> 为什么01背包，j<v1, k<v2 f[i,j]不能取值, 因为背包容量只有i,j, 放不下
> 至少为i,j, 把它们装进背包不会有什么问题，此时f[i,j,k]直接是min(f[j][k], w[i])

## 2. 线性DP
### 数字三角形

1. basic 
    - 采花生问题
        > 从集合角度来考虑问题, 一个集合就代替了暴搜中的一个元素
        - 状态表示 f[i, j]
            - 集合： 所有从(1, 1)走到(i, j)的路线
            - 属性： Max/Min/数量： 集合中所有集合的每个元素的最大值；
                > 于是f(n, m)就是目标值;  计算该值实际上就是寻找一个拓扑排序
        - 状态计算： 集合划分  分而治之
            > 依据最后一步来划分
            - 划分依据
                - 不重复（最值无所谓，数量必须要）
                - 不漏（所有的都必须考虑）
                > 本题图的连通性
    - 最低通行费： 最大值往往不需要初始化，最小值需要进行考虑

2. improve
    - 方格取数：难点在于如何考虑走两次
        - 走两次： 同时走
            > f[i1, j1, i2, j2]表示所有从(1,1), (1,1)分别走向(i1,j1),(i2,j2)的路径的最大值。 
            - 如何处理“同一个格子不能被重复选择”
                > 只有在i1+j1=i2+j2时，两条路径的格子才可能重合；一开始考虑使用f[i1, j1, i2, j2], 但是发现可以少一维的变量!!!
                > f[k, i1, i2]表示所有从(1,1), (1,1)分别走到(i1, k-i1), (i2, k-i2)的路径的最大值， k表示两条路线当前走到的格子的横纵坐标之和
            - 状态计算： 集合划分=下+下， 下+右， 
                > (1,1)-> (i1-1, j1), (i2-1,j2) -> (i1, j1), (i2, j2)
                - 集合划分
                    > 将(1,1)到(k, i1, i2)的路分为两种
                    > (1,1)--> (i1-1, j1) -> (i1, j1)
                    > (1,1)--> (i2-1, j2) -> (i2, j2)
                    > f(k-1, i1-1, i2-1), 根据(i1,j1),(i2,j2)是否是同一个格子，重合 w(i1, j1); 不重合， w(i1, j1)+w(i2, j2)
                    - 1： 下， 2： 下
                    - 1： 下， 2： 右
                    - 1： 右， 2： 下
                    - 1： 右， 2:  右
1. 摘花生               
```
#include<iostream>
#include<algorithm>
using namespace std;
const int N=110;

int n, m;
int w[N][N];
int f[N][N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                scanf("%d", &w[i][j]);

        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                f[i][j] = max(f[i-1][j], f[i][j-1]) + w[i][j];

        printf("%d\n", f[n][m]);
    }
    return 0;
}
```

2. 方格取数
方格取数取两次
只走一次：
f[i,j]表示所有从(1,1)做到(i,j)的路径的最大值

走两次：
f[i1,j1,i2,j2]表示所有从(1,1),(1,1)走到(i1,j1),(i2,j2)的路径的最大值

x->x->x->x
x->x->x->x
因为当格子走两次时，实际上关心的格子就是重复的格子，它的权重只能加一次。如何在动态规划中进行考虑呢？因为我们发现，两条路径格子重合，它们的横纵坐标是相等的，所以这里用k表示这个状态
如何处理“同一个格子不能被重复选择”？
只有在i1+j1 == i2+j2, 两条路径的格子才可能重合
f[k, i1, i2]表示所有从(1,1),(1,1)分别走到(i1,k-i2),(i2,k-i2)的最大值

集合划分（枚举每条路径如何走？）

```
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;

int n;
int w[N][N];
int f[N * 2][N][N];

int main() {
    scanf("%d", &n);
    
    int a, b, c;
    while(cin >> a >> b >> c, a || b || c) w[a][b] = c;
    
    for (int k = 2; k <= n + n; k ++) {
        for (int i1 = 1; i1 <= n; i1 ++) {
            for (int i2 = 1; i2 <= n; i2 ++) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
                    int t = w[i1][j1];
                    if (i1 != i2) t += w[i2][j2];
                    int &x = f[k][i1][i2];
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1][i2] + t);
                }
            }
        }
    }
    
    printf("%d\n", f[n + n][n][n]);
    return 0;
}
```

### 最长上升子序列 
f[i]: 所有以a[i]为结尾的严格单调上升子序列
集合划分：
最后一个不同的点的位置

```
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10;

int n;
int a[N], f[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    int res = -1e8;
    for (int i = 1; i <= n; i ++) {
        f[i] = a[i];
        for (int j = 1; j < i; j ++) {
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + a[i]);
        }
        res = max(res, f[i]);
    }

    printf("%d\n", res);

    return 0;
}
```

### 最长公共上升子序列

- 集合表示f[i, j]： 所有由第一个序列的前i个字母，第二个序列的前j个字母, 且以b[j]结尾的构成的公共子序列，Max
    > 注意这里要加条件
- 状态计算： 
    1. 所有包含a[i]的公共上升子序列 a[i]==b[j]
        > 按照倒数第2类划分， 序列倒数第1个数时null, b[1], b[2], .., b[j-1]
        > 进行枚举  f[i,k] + 1 因为b[j]大于，所以实际上就是
    2. 所有不包含a[i]的公共上升子序列 f[i-1, j]

1. O(n^3)
```
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3010;

int n;
int a[N], b[N];
int f[N][N];

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j], 1);
                for (int k = 1; k < j; k ++)
                   if (b[k] < b[j]) f[i][j] = max(f[i][j], f[i][k] + 1);
            } // else 只剩下一种
        }
        
    int res = 1;
    for (int i = 1; i <= n; i ++) res = max(res, f[n][i]);
    
    printf("%d\n", res);
    return 0;
}
```

2. O(n^2)
```
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3010;

int n;
int a[N], b[N];
int f[N][N];

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    
    for (int i = 1; i <= n; i ++) {
        int maxv = 1;
        for (int j = 1; j <= n; j ++) {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            if (b[j] < a[i]) maxv = max(maxv, f[i][j] + 1);
        }
    }
    
    int res = 1;
    for (int i = 1; i <= n; i ++) res = max(res, f[n][i]);
    
    printf("%d\n", res);
    return 0;
}
```

### 最长公共子序列
```
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int n,m;
char a[N],b[N];
int f[N][N];

int main(){
    cin>>n>>m;
    cin>>a+1>>b+1;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j] = max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]) f[i][j]=max(f[i][j], f[i-1][j-1]+1);
        }
        
    cout<<f[n][m]<<endl;
    return 0;
}
```

### 最短编辑距离
- 状态表示
f[i,j]
集合：所有将a[1~i]变到b[1~j]的操作方式的集合,  操作方式有插入、删除、替换
属性：集合的长度的最小值

- 状态计算
f[i,j]
集合划分 
可以从集合的最后一步考虑:
    - 删除， a[1,i-1]与b[1,j]匹配    len(a)=len(b)-1, 但是这里是动态变化的，所以没有必要进行这个当前len的判断，f[i-1,j]+1
    - 添加一个新字母， a[i+1]=b[j], 添之前a[1,i]与b[1,j-1]匹配 len(a)=len(b)+1 f[i,j-1]+1
    - 改， a[i]!=b[j], f[i-1,j-1]+1

时间复杂度 n^2 *3

```
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;

int n,m;
char a[N],b[N];
int f[N][N];

int main(){
    scanf("%d%s", &n, a+1);
    scanf("%d%s", &m, b+1);
    
    for(int i=0;i<=m;i++) f[0][i]=i;
    for(int i=0;i<=n;i++) f[i][0]=i;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j]=min(f[i-1][j],f[i][j-1])+1;
            if(a[i]==b[j]) f[i][j]=min(f[i][j], f[i-1][j-1]);
            else f[i][j]=min(f[i][j], f[i-1][j-1]+1);
        }
        
    printf("%d\n", f[n][m]);
    return 0;
}
```

## 3. 区间DP

石子合并：
一堆位置固定顺序的石子，怎么合并才能代价最小

f[i,j]: 所有从起点为i，终点为j的方案的最小值

按最后一步的位置进行划分
f[i,j] = min(f[i,j], f[i,k] + f[k+1,j] + s[i,j])
> 注意DP最好

```
#include<iostream>

using namespace std;
const int N=310, INF=1e9;

int n;
int s[N]; // 前缀和
int f[N][N];

int main(){
    scanf("%d",&n);

    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    for(int i=1;i<=n;i++) s[i] +=s[i-1];

    // len=1, 不需要做什么
    for(int len=2;len<=n;len++)  // 长度
        for(int i=1;i+len-1<=n;i++)  // 起点
        { // i+len-1 终点不能超过边界
            int l=i, r=i+len-1;
            f[l][r]=INF;  // 凡是求min, 记得初始化为一个大的数
            for(int k=l;k<=r;k++)
                f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]+s[r]-s[l-1]);
        }

    printf("%d\n",f[1][n]);
    return 0;
}
```

## 4. 计数类DP

将正整数划分为若干个整数有多少种划分方法？
n = n1 + n2 + ... + nk
法1
f[i,j]: 从1-i中选择，和恰好为j的集合(注意这里不是排列)
不选第i个数，选第i个数k次
f[i,j] = f[i-1,j] + sum_k(f[i-1,j-k])
时间复杂度:

法2

**思路1**
无序的
物品：n
物体的体积：1,2,..,n
每个物品可以放任意次
-> 完全背包问题
把复杂的问题转化为简单的已知的问题

- 状态表示
集合：所有从1~i中选，和恰好是j的集合
属性：长度(直接进行相加)
- 状态计算
i-1 选多少个  j=n
f(i-1,j)+ sum_k f(i-1,j-k*i)
即： f[i,j]=f[i-1,j]+f[i,j-v[i]] (mod p)

时间复杂度
当体积是i是，k=n/i
k1+k2+...+kn = lnn+c;  时间复杂度为 nlogn

进一步简化
注意这里属性是长度，所以
f[j] = (f[j]+f[i-j]) mod p; 
这里就直接是相加，也就是为什么需要分类互斥了
```
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010, mod=1e9+7;

int n;
int f[N];

int main(){
    cin>>n;
    f[0]=1; // 一个数都没有, 注意初始化！！
    //f[1] 一个数都不选，体积是1的方案都是0
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            f[j]=(f[j]+f[j-i])%mod; // 就是要把所有情况的函数值进行相加才行
    cout<<f[n]<<endl;
    return 0;
}
```

**思路2**

f[i,j]
集合：所有总和是i，并且恰好表示为j个数的和的方案
属性：数量

集合划分
最小值是1 f[i-1,j-1]
最小值大于1 f[i-j,j]
> 这里不是考虑这个最小值为多少，而是不断去逼近这个最小值 f[i-j,j] 将每个数都减1,其方案数应该一样
f[i,j] = f[i-1,j-1] + f[i-j,j]
ans=f[n,1]+f[n,2]+f[n,3]+...+f[n,n]

```
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010, mod=1e9+7;

int n;
int f[N][N]; //f[i][j], 表示i用j个数

int main()
{
    cin>>n;
    f[0][0]=1;  // f[0][i]=0, f[i][0]=0
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++) // 最多用i个数
            f[i][j]=(f[i-1][j-1]+f[i-j][j])%mod;
    
    int res=0;
    for(int i=1;i<=n;i++) res= (res + f[n][i]) % mod;
    cout<<res<<endl;
    return 0;
}
```

## 5. 树形DP
没有上司的舞会：没有职员愿意和上司一起参会，在满足这个条件下，使得所有参会职员的快乐指数最大

f[u][1]: u节点参加的快乐值; f[u][0]: u节点不参加的快乐值
f[u][1] = sum(f[son][0]), f[u][0] = sum(max(f[son][1], f[son][0]))
init: f[i][j]=0
res=max(f[u][1], f[u][0]);

```
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=6010;

int n;
int f[N][2];
int w[N];
int e[N], h[N], ne[N], idx;
bool has_father[N];

void add(int a, int b)
{
    e[idx]=b, ne[idx]=h[a], h[a]=idx++;    
}

void dfs(int u)
{
    f[u][1]=w[u];
    
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        dfs(j);
        f[u][0] += max(f[j][1], f[j][0]);
        f[u][1] += f[j][0];
    }
}

int main(){
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    
    memset(h, -1, sizeof h);
    
    int a,b;
    while(cin>>a>>b, a||b){
        has_father[a]=true;
        add(b,a);
    }
    
    int root=1;
    while(has_father[root]) root++;
    
    dfs(root); // 从根开始递归
    printf("%d\n", max(f[root][1],f[root][0]));
    return 0;
}
```

## 6. 记忆化搜索
滑雪：求方格中的最长的递减的序列的长度

```
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=310;
int n,m;
int h[N][N];
int f[N][N];

int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

int dfs(int a, int b)
{
    int& v=f[a][b];
    if(v!=-1) return v;
    
    v=1;
    
    for(int i=0;i<4;i++)
    {
        int x=a+dx[i], y=b+dy[i];
        if(x>=1 && x<=n && y>=1 && y<=m && h[x][y] < h[a][b])
            v=max(v, dfs(x,y)+1);
    }
    return v;
}

int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d", &h[i][j]);
            
    memset(f, -1, sizeof f);
    
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            res=max(res, dfs(i,j)); // 这里每个地方可以重用，所以不需要再考虑
    printf("%d\n", res);
    return 0;
}
```

## 7. 数位统计DP

给定两个整数a和b, 求出a和b之间的所有数字0-9出现的次数
```
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_num(vector<int> num, int l, int r) {
    int res = 0;
    for (int i = l; i >= r; i --)
        res = res * 10 + num[i];
    return res;
}

int power10(int x) {
    int res = 1;
    while (x --) res *= 10;
    return res;
}

int count(int n, int x) {
    if (!n) return 0;
    
    vector<int> num;
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    
    int res = 0;
    for (int i = n - 1 - !x; i >= 0; i --) {
        if (i < n - 1) {
            res += get_num(num, n - 1, i + 1) * power10(i);
            if (!x) res -= power10(i);
        }
        if (num[i] == x) res += get_num(num, i - 1, 0) + 1;
        else if (num[i] > x) res += power10(i);
    }
    return res;
}

int main() {
    int a, b;
    
    while (cin >> a >> b, a || b) {
        if (a > b) swap(a, b);
        
        for (int i = 0; i < 10; i ++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }
    return 0;
}
```