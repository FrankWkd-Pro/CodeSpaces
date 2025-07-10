|  | 题目编号 | 标题 | 估分 | 正确 | 提交 |
| --- | --- | --- | --- | --- | --- |
| Y | 2076 Problem  A | [【一本通提高篇KMP】剪花布条](http://www.accoders.com/problem.php?cid=2333&pid=0) | \--- | 156 | 293 |
| Y | 2077 Problem  B | [【一本通提高篇KMP】Radio Transmission(BZOJ1355)](http://www.accoders.com/problem.php?cid=2333&pid=1) | \--- | 116 | 265 |
| Y | 2078 Problem  C | [【一本通提高篇KMP】OKR-Periods of Words](http://www.accoders.com/problem.php?cid=2333&pid=2) | \--- | 105 | 240 |
| Y | 2079 Problem  D | [【一本通提高篇KMP】似乎在梦中见过的样子](http://www.accoders.com/problem.php?cid=2333&pid=3) | \--- | 94 | 216 |
| Y | 2080 Problem  E | [Censoring](http://www.accoders.com/problem.php?cid=2333&pid=4) | \--- | 87 | 265 |

### Problem A
- 板子，水题一道。详见[2025dsfz-KMP学习笔记](https://www.cnblogs.com/FrankWKD/p/18765949)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
const int P = 131;

char p[N], s[N]; //p=Pattern
int nxt[N];
int n, m;
/*
abacdaba
00100123


*/
int main() {
	while (1) {
		scanf("%s",  s + 1);
		if (s[1] == '#') return 0;
		scanf("%s",p+1);
		int ans = 0;
		n = strlen(p + 1);
		m = strlen(s + 1);
		for (int i = 2, j = 0; i <= n; i++) {
			while (j and p[i] != p[j + 1]) j = nxt[j];
			if (p[i] == p[j + 1]) j++;
			nxt[i] = j;
		}
		for (int i = 1, j = 0; i <= m; i++) {
			while (j != 0 and s[i] != p[j + 1]) {//不匹配就根据next移动
				j = nxt[j];
			}
			if (s[i] == p[j + 1]) j++;
			if (j == n) {
				ans++;
				j = 0;//注意这里j为０，而KMP算法中这里是j=F[j-1]+1，因为一块花纹不能重复出现在多条小饰条上
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
```

### Problem B
- 利用 $next$ 数组性质可得


```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1010000, MOD = 1e9+7;
const int P = 131;

char p[N], s[N]; //p=Pattern
int nxt[N];
int n, m;
/*
abacdaba
00100123


*/
int main() {

	scanf("%d%s", &n, p + 1);
	for (int i = 2, j = 0; i <= n; i++) {
		while (j and p[i] != p[j + 1]) j = nxt[j];
		if (p[i] == p[j + 1]) j++;
		nxt[i] = j;
	}
	printf("%d\n", n-nxt[n]);

	return 0;
}
```

### Problem C
- 利用 $next$ 数组性质可得
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1010000, MOD = 1e9+7;
const int P = 131;
int n,m;
char p[N];
int ne[N];

int main() {
	scanf("%d%s",&n,p+1);
	for(int i = 2,j = 0;i <= n;i++){
		while(j and p[i] != p[j+1]) j = ne[j];
		if(p[i] == p[j+1]) j++;
		ne[i] = j;
//		cout<<ne[i]<<" ";
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		int j = i;
		while(ne[j] != 0) j = ne[j];
		ans += i-j;
//		cout<<i<<" ";
		if(ne[i]) ne[i] = j;
	}
	cout<<ans<<endl;
	return 0;
}
```

### Problem D
- 没懂。咕咕咕~
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 30010, MOD = 1e9+7;
const int P = 131;
char s[N];
int ne[N],ans,k,n;
void kmp(char s[]){
	int len = strlen(s+1);
	for(int i = 2,j = 0;i <= len;i++){
		while(j and s[i] != s[j+1]) j = ne[j];
		if(s[i] == s[j+1]) j++;
		int p = ne[i] = j;
		while(p and 2*p >= i) p = ne[p];
		if(p >= k) ans++;
	}
}
int main() {
	cin>>s+1>>k;
	n = strlen(s+1);
	for(int i = 0;i <= n;i++){
		kmp(s+i);
	}
	cout<<ans<<endl;
	return 0;
}
```

### Problem E
- ![](https://img2024.cnblogs.com/blog/3594125/202503/3594125-20250326140357189-1047391631.jpg)


```cpp
/*
思路：
从前到后遍历整个主串，一般情况下直接push到栈里，如果栈的大小大于等于模式串的大小而且
栈顶的前几个（确切的说，是模式串的大小）个字符的哈希值和模式串相同，就把这些值
pop掉。
该思路能够保证每次只有在栈中组成一个完整的模式串时才push掉它，不存在落下任何主串中
的模式串的情况。如果用系统栈的话最坏时间复杂度是O（2n）但是数组模拟栈的话就不需要
一个一个pop字符，直接将指向栈顶的变量调到pop所有模式串的位置即可。这样做的复杂度是
O(n).线性！

*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10,P = 131;
typedef unsigned long long ull;
char st[N];
ull h[N],p[N];
int n,s1,s2,tp;
char s[N];
char pattern[N];
ull get1(int l,int r){
	return h[r]-h[l-1]*p[r-l+1];
}
int main(){
	cin>>s+1>>pattern+1;
	s1 = strlen(s+1);
	s2 = strlen(pattern+1);
	p[0] = 1;
	for (int i = 1; i <= s1; i++) {
		p[i] = p[i - 1] * P;
	}
	ull hash_pattern = 0;
	for(int i = 1;i <= s2;i++) hash_pattern = hash_pattern*P+pattern[i];
	if(s1 < s2){
		for(int i = 1;i <= s1;i++) cout<<s[i];
		return 0;
	}
	for(int i = 1;i <= s1;i++){
		st[++tp] = s[i];
		h[tp] = h[tp-1]*P+st[tp];//同下一行
		
		if(tp >= s2 and get1(tp-s2+1,tp/*这里必须是tp！如果删除一次后i就不等于tp了，我们维护的是栈，不能使用i！这里计算的是栈中元素的哈希，如果用i的话就不同步了*/) == hash_pattern) tp = tp-s2;
	}
	for(int i = 1;i <= tp;i++) cout<<st[i];
	return 0;
}
```