/*
Rules: 一次切一条线段使得部分树枝失去联系。感染人群下放一层。建树解决。
accoders吐槽，输入n没做解释啊。。。这里默认n是节点数1-n
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
const int P = 131;
int n, p, maxdep;
struct node {
	int fath, kids, dep;
	vector<int> kid_pos;
	bool relaxed = 0;//是否被释放。
} f[10010];
int tot, noww, ans; //tot是当前潜在感染人数。noww病毒下放节点
priority_queue <int> q;

void merge(int x, int y) {
	f[y].fath = x;//y父亲是x
	f[x].kid_pos.push_back(y);
}
void make_first(int pos, int pre) { //返回节点数
	f[pos].dep = f[pre].dep + 1;
	maxdep = max(maxdep, f[pos].dep);
	if (f[pos].kid_pos.size() == 0) {
		return ;
	}
	for (int i = 0; i < f[pos].kid_pos.size(); i++) {
		make_first(f[pos].kid_pos[i], pos) ; //kids算上father
	}
}
void make_relax(int pos) {
	tot--;
	f[pos].relaxed = 1;
	if (f[pos].kid_pos.size() == 0) return ;
	for (int i = 0; i < f[pos].kid_pos.size(); i++) {
		make_relax(f[pos].kid_pos[i]);
	}
}
int max(int xxx, int yyy) {
	return xxx > yyy ? xxx : yyy;
}
int main() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) f[i].fath = i; //并查集初始化
	for (int i = 1; i <= p; i++) {
		int x, y;
		cin >> x >> y;
		merge(x, y);
	}
//	for (int i = n; i >= n; i--) {
//		//预处理每个树的kids数量
//		f[i].dep = max(1,f[i].dep);
//		f[i].kids = max(1,f[i].kids);
//		f[f[i].fath].dep = f[i].dep+1;
//		maxdep = max(maxdep, f[i].dep);
//		f[f[i].fath].kids += f[i].kids + 1; //kids算上father自己
//	}
	noww = 1;
	tot = n - 1; //要实现把节点1排除掉
	ans = 1;//同上一行
	make_first(1, 0); //以1为根节点的节点数量（节点总数）（n）
	while (tot > 0) {
		int maxx_pos = 0, maxx_kids = 0;
		for (int i = 1; i <= n; i++) {
			if (f[i].dep != noww + 1) continue;
			//noww表示已经生病的最大深度
			if (maxx_kids <= f[i].kid_pos.size() and f[i].relaxed == 0) {//小于等于真的很重要啊
				maxx_kids = f[i].kid_pos.size();
				maxx_pos = i;
			}
		}
		
		make_relax(maxx_pos);//释放节点
//		for(int i = 1;i <= n;i++){
//			cout<<"F"<<i<<" "<<f[i].fath<<" "<<f[i].dep<<" "<<f[i].relaxed<<" "<<f[i].kid_pos.size()<<endl;
//		}
		noww++;
		for (int i = 1; i <= n; i++) {
			if (f[i].relaxed == 1) continue;
			if (f[i].dep == noww) ans++, tot--, f[i].relaxed = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
