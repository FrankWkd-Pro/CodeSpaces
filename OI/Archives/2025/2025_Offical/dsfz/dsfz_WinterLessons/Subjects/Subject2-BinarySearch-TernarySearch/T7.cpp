#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
}a[1010101];
int f[1010101][2];
int n;

int find(int x){
    if(f[x][0] != x) return f[x][0] = find(f[x][0]);
    return x;
}

void merge(int x,int y){
    f[find(x)][0] = f[find(y)][0];
    f[find(y)][1] += f[find(x)][1];
}

bool check(int x){
    for(int i = 1;i <= n;i++){
        for(int j = i+1;j <= n;j++){
            if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y) <= x*2 and find(i) != find(j)) merge(i,j);
        }
    }
    int k = find(1);
    for(int i = 2;i <= n;i++){
        if(find(i) != k) return false;
    }
    return true;
}

int main(){
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i].x>>a[i].y;
    }
    int l = 0,r = 1e9;
    while(l <= r){
        for(int i = 1;i <= n;i++) f[i][0] = i,f[i][1] = 1;
        int mid = l+r>>1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }
    cout<<l<<endl;
}
