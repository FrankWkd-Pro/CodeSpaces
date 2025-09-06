#include<bits/stdc++.h>
using namespace std;
const int ten[10]={1,10,100,1000,10000,100000,1000000,10000000};
struct node{int key,step,previd,way;}k[100000];
inline int A(int k){return (k/10000)+(k%10000)*10000;}
inline int B(int k){
	int ll=k/10000,rr=k%10000;
	ll=(ll%10)*1000+ll/10;
	rr=(rr%10)*1000+rr/10;
	return ll*10000+rr;
}
inline int C(int k){
	int a=k/ten[7]%10;
	int b=k/ten[6]%10;
	int c=k/ten[5]%10;
	int d=k/ten[4]%10;
	int e=k/ten[3]%10;
	int f=k/ten[2]%10;
	int g=k/ten[1]%10;
	int h=k/ten[0]%10;
	return a*ten[7]+f*ten[6]+b*ten[5]+d*ten[4]+e*ten[3]+g*ten[2]+c*ten[1]+h;
}
map<int,int> st;
char ans[2009];
int cnt=0;
void show(int id){
	if(k[id].previd==-1)return;
	show(k[id].previd);
	ans[++cnt]=(char)k[id].way;
}
void bfs(int sx,int fx){
	int ff=1,tt=0;
	k[++tt]={sx,0,-1,-1};
	st[sx]=114514;
	while(ff<=tt){
		int key=k[ff].key,previd=ff,step=k[ff++].step+1;
		int a=A(key),b=B(key),c=C(key);
		if(st[a]!=114514){
			st[a]=114514;
			k[++tt]={a,step,previd,(int)'A'};
			if(a==fx){
				printf("%d\n",step);
				show(tt);
				return;
			}
		}
		if(st[b]!=114514){
			st[b]=114514;
			k[++tt]={b,step,previd,(int)'B'};
			if(b==fx){
				printf("%d\n",step);
				show(tt);
				return;
			}
		}
		if(st[c]!=114514){
			st[c]=114514;
			k[++tt]={c,step,previd,(int)'C'};
			if(c==fx){
				printf("%d\n",step);
				show(tt);
				return;
			}
		}
	}
}
int main(){
	st.clear();
	int t=0,x,lable[10];
	for(int i=1;i<=8;i++)scanf("%d",&lable[i]);
	t=lable[1]*ten[7]+lable[2]*ten[6]+lable[3]*ten[5]+lable[4]*ten[4]+lable[8]*ten[3]+lable[7]*ten[2]+lable[6]*ten[1]+lable[5]*ten[0];
	if(t==12348765)puts("0"),exit(0);
	bfs(12348765,t);
	for(int i=1,it=1;i<=cnt;i++,it++){
		putchar(ans[i]);
		if(it==60)it=0,puts("");
	}
	return 0;
} 
