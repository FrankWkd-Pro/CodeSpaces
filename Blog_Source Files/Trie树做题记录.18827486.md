# Trie树
# 字典树
- 本质上就是树上路径字符串版本
- 特定的路径表示完整的字符串，同层的相同字母合并为一个一样的字母。
### B. 数字串前缀匹配 || 【一本通提高篇Trie字典树】Phone List
这题看似简单，但是调了好久。
我们正常建树，如果在遍历到某一个结点的过程中检测到当前作为一个字符串的末尾 $(cnt[p] ≠ 0)$ 。我们就认定该字符串有前缀在给出数据中。
要注意的细节：
- 多测清空。建议手动清空，~~$memset$ 出题人卡常专用~~
- 数组大小谨慎开，动不动就MLE。
- 记得判断：两个串相同也要输出`NO`!
```cpp
#include <bits/stdc++.h>
using namespace std;
int n, a[101010][70], cnt[101010], idx;
bool f = false;
char s[101010];

void insert() {
	int p = 0, x;
	int old = idx;
	for (int i = 0; s[i]; i++) {
		x = s[i] - '0';
		if (a[p][x] == 0) a[p][x] = ++idx;
		if (cnt[p] != 0) {
			f = true;
			return ;
		}
		p = a[p][x];
	}
	if(old == idx){
		f = true;
		return ;//没有新建任何结点
	}
	cnt[p]++;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		f = 0;
		memset(a,0,sizeof a);
		memset(cnt,0,sizeof cnt);
		idx = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> s;
			insert();
		}
		if (!f) puts("YES");
		else puts("NO");
	}
}
```
### P8306 【模板】字典树
- 板子。我们在插入字符串的时候每添加（遍历）到一个字符，就将它对应的节点编号++，这样我们就能在一个位置得到有多少个单词到现在为止的前缀与它到现在为止的前缀相同。当前单词结尾时就能得到他相同前缀单词的数量。
```cpp
#include <bits/stdc++.h>
using namespace std;
char s[3000010];
int a[3000010][90];
int idx;//节点编号
int cnt[3000010];
void insert(char s[]) {
	int p = 0, c;
	for (int i = 0; s[i]; i++) {
		c = s[i] - '0';
		if (a[p][c] == 0) a[p][c] = ++idx;
		p = a[p][c];
		cnt[p]++;
	}

}
int query(char s[]) {
	int d = 0, c;
	for (int i = 0; s[i]; i++) {
		c = s[i] - '0';//恶心题，字符串包含数字
		if (a[d][c] == 0) return 0;
		else d = a[d][c];
	}
	return cnt[d];
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i <= idx; i++) {
			for (int j = 0; j < 90; j++) {
				a[i][j] = 0;
			}
		}

		for (int i = 0; i <= idx; i++) {
			cnt[i] = 0;
		}
		idx = 0;
		int n;
		cin >> n;

		int m;
		cin >> m;
		for (int i = 1; i <= n; i++) {
			cin >> s;
			insert(s);
		}


		for (int i = 1; i <= m; i++) {
			cin >> s;
			cout << query(s) << "\n";
		}
	}
}
```

### A. 三年二班的投票
板子。
```cpp
#include <bits/stdc++.h>
using namespace std;
int n, ch[1000010][30], cnt[1000010];
char s[1000010];
int idx;
void insert() {
	int p = 0;
	for (int i = 0; s[i]; i++) {
		int x = s[i] - 'a';
		if (ch[p][x] == 0) ch[p][x] = ++idx;
		p = ch[p][x];//下移到当前节点(下一次起点)
	}
	cnt[p]++;//节点编号++
}
int query() {
	int x, p = 0;
	for (int i = 0; s[i]; i++) {
		x = s[i] - 'a';
		if (ch[p][x] == 0) return 0;
		p = ch[p][x];
	}
	return cnt[p];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		insert();
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		printf("%d\n", query());
	}

	return 0;
}
```

### F. 字典树I
纯唐板子。
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,a[1010010][30],cnt[1010101],op;
char s[1001010];
int idx;//节点编号
void insert(char s[]){
	int x,p = 0;
	for(int i= 0;s[i];i++){
		x = s[i]-'a';
		if(a[p][x] == 0) a[p][x] = ++idx;
		p = a[p][x];
	}
	cnt[p]++;
}
int query(char s[]){
	int x,p = 0;
	for(int i = 0;s[i];i++){
		x = s[i]-'a';
		if(a[p][x] == 0) return 0;
		p = a[p][x];
	}
	return cnt[p];
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>op>>s;
		if(op == 1){
			insert(s);
		}else cout<<(query(s) ? "Yes" : "No")<<"\n";
	}	
}
```

### G. 字典树II
弱化版本P8306 【模板】字典树，对数组大小和 $memset$ 常数没有特殊卡常。
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,a[101010][30],cnt[1010101],op;
char s[101010];
int idx;//节点编号
void insert(char s[]){
	int x,p = 0;
	for(int i= 0;s[i];i++){
		x = s[i]-'a';
		if(a[p][x] == 0) a[p][x] = ++idx;
		p = a[p][x];
		cnt[p]++;
	}
	
}
int query(char s[]){
	int x,p = 0;
	for(int i = 0;s[i];i++){
		x = s[i]-'a';
		if(a[p][x] == 0) return 0;
		p = a[p][x];
	}
	return cnt[p];
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>op>>s;
		if(op == 1){
			insert(s);
		}else cout<<query(s)<<"\n";
	}	
}
```