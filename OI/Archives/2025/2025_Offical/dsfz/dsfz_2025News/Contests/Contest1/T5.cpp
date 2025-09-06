#include<bits/stdc++.h>
using namespace std;
//笑死这数据范围，顺序是：' '->'+'->'-' , 调了半个点才发现和为零
int a[100];
int n;
void fun(string s, int ans, int i, int pre,char op) { //pre: 前面的累加值
	// Hack数据： 1-2 3 4 待定：5 ，那么就应该减去234再加上2345！！！
	//cout << s << endl;
	if (i > n) {
		if(ans == 0) cout << s <<endl;
		return ;
	}
	if(op == '-'){
		fun(s + " " + to_string(i), ans + pre - (10 * pre + i), i + 1, pre * 10 + i,op);//op需要继承
	}else{
		fun(s + " " + to_string(i), ans - pre + (10 * pre + i), i + 1, pre * 10 + i,op);//op需要继承
	}
	
	fun(s + '+' + to_string(i), ans + i, i + 1, i,'+');
	fun(s + '-' + to_string(i), ans - i, i + 1, i,'-');
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) a[i] = i;
	fun("1", 1, 2, 1,'+');
	return 0;
}
