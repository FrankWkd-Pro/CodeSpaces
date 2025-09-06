#include<bits/stdc++.h>
using namespace std;
const int N=10,sqrtN=4,squN=82,Size=9,Max=511;
int mp[N][N],one[520],line[N],colume[N],square[sqrtN][sqrtN];
int moni_lowbit_hanshu(int x){
    if(x==1)return 1;
    if(x==2)return 2;
    if(x==4)return 3;
    if(x==8)return 4;
    if(x==16)return 5;
    if(x==32)return 6;
    if(x==64)return 7;
    if(x==128)return 8;
    if(x==256)return 9;
    return -1;
}
void place(int value,int x,int y,int on){
    if(abs(on)!=1){
        return;
    }
    if(on==1) mp[x][y]=value; else mp[x][y]=-1;
    line[x]-=on*(1<<(value-1));
    colume[y]-=on*(1<<(value-1));
    square[(x-1)/3+1][(y-1)/3+1]-=on*(1<<(value-1));
}
int lowbit(int x){
    return x&-x;
}
bool dfs(int tmpror){
    if(tmpror==0){
        for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)printf("%d",mp[i][j]);
        puts("");
        return true;
    }
    int minx=-1,miny=-1,minnum=10,lim,key;
    for(int i=1;i<=9;i++)for(int j=1;j<=9;j++){
    	if(mp[i][j]!=-1)continue;
        lim=line[i]&colume[j]&square[(i-1)/3+1][(j-1)/3+1];
        if(one[lim]==0)return false;
        if(one[lim]<minnum)minnum=one[lim],minx=i,miny=j,key=lim;
    }
    while(key){
        place(moni_lowbit_hanshu(lowbit(key)),minx,miny,1);
        if(dfs(tmpror-1))return true;
        place(moni_lowbit_hanshu(lowbit(key)),minx,miny,-1);
        key-=lowbit(key);
    }
    return false;
}
int main(){
    int tmpror;
    for(int i=0,tmp;i<=Max;i++){
        tmp=i;
        while(tmp){
            if(tmp&1)one[i]++;
            tmp>>=1;
        }
    }
    char input_data[squN];
    while(true){
        for(int i=1;i<=9;i++) line[i]=Max,colume[i]=Max;
        for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) square[i][j]=Max;
        tmpror=0;
        scanf("%s",input_data);
        if(input_data[0]=='e') exit(0);
        for(int i=0;i<=80;i++)
            if(isdigit(input_data[i])) place(input_data[i]-'0',i/9+1,i%9+1,1);//place num
            else ++tmpror,mp[i/9+1][i%9+1]=-1;
        dfs(tmpror);
    }
}
