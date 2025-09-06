#include<bits/stdc++.h>
using namespace std;
int nextl[1001]={0};//这个数组名不能直接用next,容易报错 
string a,b;
int KMP(){
    int i=0,j=0,we=0;
    int as=a.size(),bs=b.size();
    while(i<as){
        if(a[i]==b[j]||j==-1){//当单个字符匹配成功或前面没东西 
            i++;
            j++;//i,j都往前挪 
            if(j==bs){//字符串匹配成功 
                we++; 
                j=0;//子串归0 
            }
        }else{
            j=nextl[j];//上next数组，移动到下一个位置 
        }
    }
    return we;
}
void Next(){//计算next数组值 
    int bs=b.size();
    nextl[0]=-1;//代表前面没东西 
    int j=0,k=-1;
    while(j<bs){
        if(k==-1||b[j]==b[k]){//当前面没有东西或j、k对应的字符一样 
            nextl[j++]=k++;//直接往后挪一位，因为前几位字符=后几位字符或前面啥也没有 
        }else{
            k=nextl[k];
        }
    }
}
int main(){
    while(cin>>a){
        if(a=="#"){
            break;
        }else{
            cin>>b;
            Next();
            cout<<KMP()<<endl;
        }
    }
}
