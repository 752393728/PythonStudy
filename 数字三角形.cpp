#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    int n,a[105][105];
    scanf("%d",&n);
    // ���� 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            scanf("%d",&a[i][j]);
        }
    }
    // ˼·��һ��״̬����״̬�����ҽڵ���ɣ������һ��û���ӽڵ㣬�����Ե����ϸ���
	// ״̬���̣��ܺ��뵽����״̬������״̬ȡ���� 
    for(int i = n-1; i >=0; i--){
        for(int j = 0; j < i+1; j++){
            a[i][j] = max((a[i][j]+a[i+1][j]),(a[i][j]+a[i+1][j+1]));
        }
    }
    // ���ջὫa[0][0]����Ϊȫ������ 
    printf("%d",a[0][0]);
}
