#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,a[9000005],q,flag;
//�������� 
void bi(int begin,int end,int v){
	//minΪ�м������±� 
    int min = (begin+end)/2;
    //��ֹ�ж� 
    if(begin>=end) return;
    //Ϊ������������������ж���Ŀ����������������֮�������������ѵ����������� 
    if(begin+1==end){
    	//������ǰһ�����ͺ�һ�����Ĳ�ֵ f �� e 
        int e,f;
        e = a[end]-v;
        f = v-a[begin];
        //�ҳ������������¼��flag�� 
        if(e>=f){
            flag = a[begin];
            return;
        }else {
            flag = a[end];
            return;
        }
    } 
    //����ֵ���м�ֵ�����жϣ�Ȼ��������� 
    if(v<a[min]){
        bi(begin,min,v);
    }else if(v>a[min]){
        bi(min,end,v);
    }else{
        flag = a[min];
        return;
    }
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i < m;i++){
        scanf("%d",&q);
        //���÷�װ�õĶ��������ĺ��������ս�������� flag �� 
        bi(0,n-1,q);
        printf("%d\n",flag);
    }
}
