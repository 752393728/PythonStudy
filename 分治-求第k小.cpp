#include <iostream>
#include <cstdio>
using namespace std;
// ʱ�临�Ӷȼ��㣺 ��һ��������Ҫ����һ�飬ʱ�� O(n)��ȡ���������磺5,4,3,2,1 ����һ��Ϊ 1 4 3 2 5
// ����ȡ ��߲��� ��ڶ���ʱ��Ϊ O(n)+O(4*n/5)������ȡ���������Ƶ������µ�ʱ��ԼΪ O((n+1)/2)��Ϊ O(n)��ʱ�� 
//���� 
int partition(int a[], int left, int right)  
{
    if(left < right)  
    {
    	//��flag��¼��һ������ֵ��Ϊ�ڱ���ʹһ��������ڱ���������С���ڱ����ڱ��Ҳ���������ڱ� 
        int l = left,r = right,flag = a[l];
        while(l<r)
        {
        	// ѭ���ж����Ҷ��±��Ӧ������������ڱ��±������� 
            while(l < r && a[r] >= flag) r--;
            // �������Ҳ�����ڱ���������ѭ��������left�±��ұ�һλ���������������±��һ 
            if (l<r) a[l++] = a[r];
            // ѭ���ж�������±��Ӧ�������С���ڱ��±������� 
            while(l < r && a[l] < flag) l++;
            // �������������ڱ���������ѭ��������right�±����һλ���������������±��һ 
            if (l<r) a[r--] = a[l];  
        }
        // ���ս��ڱ������м� 
        a[l] = flag;
        // �����ڱ�λ��
        return l;
    }
    return -1;  
}
//����
int find(int a[], int left, int right, int k)  
{  
    if (left > right) return -1;
    // left����right���ص�ǰֵ 
    if (left == right) return a[left];  
    // iΪ�ڱ����м���������±�
    int i = partition(a, left, right);  
    // jΪ�����䳤�ȣ������ж� kλ��ʲôλ��   
    int j = i - left + 1;  
    // k��jС�����������ң���������������� ,������ֱ�ӷ��� 
    if (j == k){
    	return a[i];
    }else if (k < j) {
    	return find(a, left, i, k); 
    }else {
    	// ȥ������� kȡ k-j 
    	return find(a, i+1, right, k-j);
    }
}
int main(){
	int n,k,a[10005];
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	printf("%d",find(a, 0, n-1, k));
} 
