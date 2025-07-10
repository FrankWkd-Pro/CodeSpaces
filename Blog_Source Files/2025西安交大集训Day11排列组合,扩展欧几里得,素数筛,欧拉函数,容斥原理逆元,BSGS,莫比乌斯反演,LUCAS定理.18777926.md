### 快速幂
快速幂是我们解决中数论问题的基石让我们能以 $O(logn)$ 的复杂度计算 $a^n$
快速幂的思想简单而言就是将 $n$ 的二进制中所有的 $1$ 代表的次幂乘起来比如计算 $3^5,5=(101)_2$ ,则使用快速幂计算 $3^5$ 的过程就是 $3^{(1)_2}\times 3^{(100)_2}$
参考代码如下：
```cpp
int fp(int x, int y) {
	int res = 1;
	for (; y; y >>= 1, x = 1ll * x * x % mod) {
		if (y & 1) {
			res = 1ll * res * x % mod;
		}
	}
}
```
### 同余
设整数 $m\mid(a-b)$ ,则我们称 $\alpha$ 同余于 $b$ 模 $m$ ,记作 $a\equiv b\pmod m.$
同余可以理解为模意义下的相等.
同余满足如下性质：
- 线性运算：若 $a \equiv b \pmod{m}$，$ c \equiv d \pmod{m} $ ，则 $a \pm c \equiv b \pm d \pmod{m}$，$a \times c \equiv b \times d \pmod{m}$。
- 若 $a \equiv b \pmod{m}$，$k \in \mathbb{N}_{+}$，则 $ak \equiv bk \pmod{mk}$。
- 若 $a \equiv b \pmod{m}$，$d | m$，则 $\frac{a}{d} \equiv \frac{b}{d} \pmod{\frac{m}{d}}$。
同余类：设 $m\in\mathbb{N}_+$ ,则可以将全体整数分为 $m$ 个划分，每个集合满足其中的数模 $m$ 均同
余，将这 $m$ 个集合称为模 $m$ 的剩余类，用 $r\bmod m$ 表示含有 $r$ 的模 $m$ 的剩余类。
完全剩余系：对 $m$ 个整数 $a_1,a_2,\ldots,a_m$ ,若对任意整数 $x$ ,有且仅有一个数满足 $a_i\equiv x({\mathrm{mod~}}m)$ ,则称这 $m$ 个数为模 $m$ 的完全剩余系.在 OI 中常用最小非负剩余系，即：
$$0,1,\ldots,m-1.$$
### 最大公约数（$gcd$）
$a$ 和 $b$ 的最大公约数 $\gcd(a,b)$ 定义为所有满足 $c\mid a,c\mid b^1$ 的 $c$ 的最大值($c$ 为 $a,b$ 的公约数).最大公约数有
如下性质：
- 结合律：$\gcd(a_1,a_2,\ldots,a_n)=\gcd(\gcd(a_1,a_2),\ldots,a_n)$
- 分配律：$\gcd(ma_1,ma_2,\ldots,ma_n)=m\gcd(a_1,a_2,\ldots,a_n).$

最大公约数 $gcd$ 与最小公倍数 $lcm$ 有如下关系：
$$\gcd(a,b)\cdot\operatorname{lcm}(a,b)=ab$$

在 OI 中，我们通过辗转相除法的方法来求最大公约数.即 $\gcd(a,b)=\gcd(b,a$ mod $b)^3.$
这个算法的时间复杂度是 $O(\log a).$
证明略.
代码如下：
```cpp
int gcd(int a, int b) {
	reutrn b ? gcd(b, a % b) : a;
}
```
扩展欧几里得算法(Extended Euclidean Algorithm, **Exgcd**)，常用于求不定方程 $ax + by = gcd(a, b)$ 的一组解。具体流程如下:

设
$$\begin{cases}
    ax_1 + by_1 = \text{gcd}(a, b) \\
    bx_2 + (a \mod b)y_2 = \text{gcd}(b, a \mod b)
\end{cases}$$
由于 $\text{gcd}(a, b) = \text{gcd}(b, a \mod b)$，于是
$$\begin{aligned}
& ax_1 + by_1 = bx_2 + (a \mod b)y_2 \\
&= bx_2 + ay_2 - \left\lfloor \frac{a}{b} \right\rfloor y_2 \times b \\
&= ay_2 + b\left(x_2 - \left\lfloor \frac{a}{b} \right\rfloor y_2\right)
\end{aligned}$$

于是 $x_1 = y_2$, $y_1 = x_2 - \left\lfloor \frac{a}{b} \right\rfloor y_2$.

将 $x_2, y_2$ 递归，直至 $\text{gcd}$ 为 $0$ 时将 $x = 1, y = 0$ 代入计算即可。
参考代码如下：
```cpp
int exgcd(int a, int b, int& x, int& y) {
	cout << x << " " << y << "\n";
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int ans = exgcd(b, a % b, x, y);
	int tmp = x;
	x = y;
	y = tmp - a / b * y;
	return ans;
}
```
### 费马小定理
·对素数$p$以及任意自然数 $a$ ,有 $a^p\equiv a\pmod{p}.$
·对素数$p$以及与其互素的自然数 $a$ ,有 $a^{p-1}\equiv1\pmod{p}.$
我们使用数学归纳法证明这一定理，对于 $\alpha=1$ ,显然结论成立.假设 $p\mid(a^p-a)$ ,现在讨论
$a+1$ 时的情况，即要证明 $p\mid((a+1)^p-(a+1)).$
将右侧使用二项式定理展开，则
$$(a+1)^p-(a+1)=\sum\limits_{k=1}^{p-1}\binom{p}{k}a^k+(a^p-a)$$
由于 $p$ 是素数，故而对任意的 $k,p\mid\binom pk.$ 由假设的结论可以得到 $p\mid(a+1)^p-(a+1).$ 故费马小定理成立.
费马定理是欧拉定理：$a^\varphi(m)\equiv1 \pmod m)(\gcd(a,m)=1)$ 的一个特殊情况，其中 $\varphi(m)$ 是欧拉函数.
若 $x$ 满足 $ax \equiv 1 \pmod{b}$，则称 $x$ 是在模 $b$ 意义下 $a$ 的乘法逆元，记作 $a^{-1}$.

- 求逆元的方法：
	- **Exgcd 求逆元**：相当于求 $ax + by = 1$，要求 $\gcd(a,b) = 1$。
	- **费马小定理求逆元**：由 $a^{p-1} \equiv 1 \pmod{p}$ 有 $a^{-1} \equiv a^{p-2} \pmod{p}$，快速幂即可。要求 $p$ 是素数。
	- **线性求 $1 \sim n$ 的逆元**：令 $p = kx + y$，则 $k = \left\lfloor \frac{p}{x} \right\rfloor$。有 $kx + y \equiv 0 \pmod{p}$。两边同时乘 $x^{-1} \times y^{-1}$。得到 $x^{-1} \equiv -ky^{-1} \pmod{p}$。递推即可。
```cpp
void Inv(int n, int p) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    }
}
```
### 中国剩余定理
对一组互质的整数 $\{a_n\}$，求  
$\begin{cases}
x \equiv b_1 \pmod{a_1}\\
x \equiv b_2 \pmod{a_2}\\
\vdots\\
x \equiv b_n \pmod{a_n}
\end{cases}$ 
的解.
令 $a=\prod a_{i},m_{i}=\frac{\alpha}{a_{i}}$,求出 $m_{i}$ 在 $a_{i}$ 下的逆元，记作  $m_{i}^{-1}.$ 令 $c=m_{i}m_{i}^{-1}$ (不取模).则
$$x=\sum_{i=1}^nb_ic_i\pmod{a}$$
是上述方程在模 $a$ 意义下的唯一解.
现在我们要证明 $x$ 在模 $a_i$ 的意义下同余 $b_i:$ 因为当 $j\neq i$ 时，$b_jc_j\equiv0$ (mod $a_i)$,于是
$$\begin{aligned}\text{x}&\equiv\sum_{i=1}^{n}b_{i}c_{i}\quad(\mathrm{mod~}a_{i})\\&\equiv b_{i}c_{i}\quad(\mathrm{mod~}a_{i})\\&\equiv b_{i}m_{i}m_{i}^{-1}\quad(\mathrm{mod~}a_{i})\\&\equiv b_{i}\quad(\mathrm{mod~}a_{i})\end{aligned}$$
### LUCAS定理
Lucas 定理是在素数剩余系下求组合数的常用方法.具体地，对正整数 $n,m$ 以及质数 $p$ ,有
$$\begin{pmatrix}n\\m\end{pmatrix}\equiv\begin{pmatrix}\lfloor n/p\rfloor\\\lfloor m/p\rfloor\end{pmatrix}\cdot\begin{pmatrix}n\bmod p\\m\bmod p\end{pmatrix}\pmod p$$
证明略.
### BSGS
$\mathbf{BSGS}$ 算法，常用来求解 $a^x\equiv b$ (mod $p)$ ,其中 $a\perp p$,且要求 $x\in[0,p).$
$令$ $x= A\sqrt {p}- B( A, B< \sqrt {p})$,则方程变为

$$a^{A\sqrt{p}}\equiv ba^{B}\pmod{p}$$

枚举 $B$ ,将所有的 $ba^B$ 存下来，然后再枚举 $A$ ,计算 $a^{A\sqrt{p}}$ ,检查是否有相等的值，若有则可以通过 $A,B $求出 $x.$

时间复杂度：$O(\sqrt p).$
### 扩展欧拉定理
扩展欧拉定理拓宽了欧拉定理对于$a,p$互素的限制，有：
$$a^b\equiv\begin{cases}a^{b\mod\varphi(m)},&\gcd(a,m)=1\\a^b,&\gcd(a,m)\neq1,b<\varphi(m)\\a^{b\mod\varphi(m)+\varphi(m)},&\gcd(a,m)\neq1,b\geq\varphi(m)\end{cases}$$
证明略.
扩展欧拉定理主要用于降幂.
### 积性函数
设$f:\mathbb{Z}^{+}\rightarrow A\subseteq \mathbb{C}$, 则这样的函数 $f$ 称作数论函数.
若数论函数 $f$ 满足对于任意互素的两个数$a,b$, 都有$f(ab)=f(a)f(b)$, 且 $f(1)=1$. 则 $f$ 被称作积性函数.
若数论函数 $f$ 满足对任意两个数$a,b$ 都有 $f(ab)=f(a)f(b)$, 且 $f(1)=1$. 则 $f$ 被称作完全积性函数.
积性函数满足如下性质:
-  若 $f(x)$ 是积性函数, 则对于任意的素数$p,f(x^p)$ 也是积性函数;
-  若 $f,g$ 是积性函数, 则 $h=fg$ 也是积性函数;
-  若 $f,g$ 是积性函数, 则 $h=f*g=\sum_{d|x} f(d)g(\frac{x}{d})$ 也是积性函数.[7]
-  若$x=\prod p_i^{k_i}$ (即质因数分解), 则当$f(x)$ 是积性函数时, 有$f(x)=\prod f(p_i^{k_i}).$

[7]: 实际上是 $f,g$ 的迪利克雷卷积, 我们将在后面的课程仔细研究.

$\begin{aligned}
 & 接下来列举一些常见的积性函数: \\
 & 1.\text{ 单位函数: }\varepsilon(n)=[n=1]^{8}; \\
 & 2.\text{ 恒等函数:id}_k(n)=n^k,\mathrm{id}_1(n)\text{ 简记为 id}(n); \\
 & 3.\text{ 常数函数:}1\left(n\right)=1; \\
 & 4.\text{ 除数函数:}\sigma_k(n)=\sum_{d|n}d^k,\sigma_0(n)\text{ 常简记为 d}(n)\text{ 或 }\tau(n),\sigma_1(n)\text{ 常简记为 }\sigma(n);^9 \\
 & \text{5. 欧拉函数:}\varphi(n)=\sum_{k=1}^n[\gcd(k,n)=1],\text{即在 }1\sim n\text{ 中有多少数与其互素}; \\
 & \text{6. 莫比乌斯函数:}\mu(n)=
\begin{cases}
1,n=1 \\
0,\exists d>1:d^2\mid n \\
(-1)^{\omega(n)},\mathrm{otherwise} & 
\end{cases},\text{其中 }\omega(n)\text{表示 }n\text{的本质不同质因子个} \\
 & 我们将对\varphi\text{ 和 }\mu\text{ 做仔细研究}. \\
 & \overline{^8[]\text{ 代表艾佛森括号,括号内命题为真则为 }1,\text{否则为 }0} \\
 & ^9\tau(n)\text{ 表示 }n\text{ 的因子个数},\sigma(n)\text{ 表示 }n\text{ 的因数和}.
\end{aligned}$
### 欧拉函数
$\begin{aligned}
 & 欧拉函数有如下性质: \\
 & \bullet\varphi(2n)=\varphi(n)(\text{当 }n\text{ 是奇数时}); \\
 & \bullet n=\sum_{d|n}\varphi(d); \\
 &  \text{设}f(k)=\sum_{i=1}^n[\gcd(i,n)=k],\text{则}\sum f(k)=n,\text{又因为}f(k)=\varphi\left(\frac{n}{k}\right),\text{故上述命题得证}. \\
 &  \bullet\varphi\left(p^{k}\right)=p^{k}-p^{k-1}=\varphi\left(p^{k-1}\right)\times p; \\
 &  \bullet\text{设 }m=\prod_{p}p^{m_{p}},\text{则} \\
 & \varphi\left(m\right)=\varphi\left(\prod_{p}p^{m_{p}}\right)=\prod_{p}\varphi\left(p^{m_{p}}\right)=\prod_{p}(p^{m_{p}}-p^{m_{p}-1})=m\prod_{p}\left(1-\frac{1}{p}\right) \\
 &  \text{通过这个式子可以做到单点求 }\varphi,\text{时间复杂度为 }O(\sqrt{m}).
\end{aligned}$
