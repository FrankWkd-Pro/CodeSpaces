#include<bits/stdc++.h>
using namespace std;
int nextl[1001]={0};//�������������ֱ����next,���ױ��� 
string a,b;
int KMP(){
    int i=0,j=0,we=0;
    int as=a.size(),bs=b.size();
    while(i<as){
        if(a[i]==b[j]||j==-1){//�������ַ�ƥ��ɹ���ǰ��û���� 
            i++;
            j++;//i,j����ǰŲ 
            if(j==bs){//�ַ���ƥ��ɹ� 
                we++; 
                j=0;//�Ӵ���0 
            }
        }else{
            j=nextl[j];//��next���飬�ƶ�����һ��λ�� 
        }
    }
    return we;
}
void Next(){//����next����ֵ 
    int bs=b.size();
    nextl[0]=-1;//����ǰ��û���� 
    int j=0,k=-1;
    while(j<bs){
        if(k==-1||b[j]==b[k]){//��ǰ��û�ж�����j��k��Ӧ���ַ�һ�� 
            nextl[j++]=k++;//ֱ������Ųһλ����Ϊǰ��λ�ַ�=��λ�ַ���ǰ��ɶҲû�� 
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
