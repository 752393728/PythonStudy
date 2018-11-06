#include <iostream>
#include <cstdio>
using namespace std;
// 时间复杂度计算： 第一次排序需要遍历一遍，时间 O(n)，取最坏情况，例如：5,4,3,2,1 排序一次为 1 4 3 2 5
// 最坏情况取 左边部分 则第二次时间为 O(n)+O(4*n/5)，依次取最坏情况并类推得最坏情况下的时间约为 O((n+1)/2)，为 O(n)级时间 
//划分 
int partition(int a[], int left, int right)  
{
    if(left < right)  
    {
    	//用flag记录第一个数的值作为哨兵，使一次排序后哨兵左侧的数都小于哨兵，哨兵右侧的数大于哨兵 
        int l = left,r = right,flag = a[l];
        while(l<r)
        {
        	// 循环判断最右端下标对应的数如果大于哨兵下标向左移 
            while(l < r && a[r] >= flag) r--;
            // 不满足右侧大于哨兵条件跳出循环把它和left下标右边一位的数交换，并且下标加一 
            if (l<r) a[l++] = a[r];
            // 循环判断最左端下标对应的数如果小于哨兵下标向右移 
            while(l < r && a[l] < flag) l++;
            // 不满足左侧大于哨兵条件跳出循环把它和right下标左边一位的数交换，并且下标减一 
            if (l<r) a[r--] = a[l];  
        }
        // 最终将哨兵放在中间 
        a[l] = flag;
        // 返回哨兵位置
        return l;
    }
    return -1;  
}
//分治
int find(int a[], int left, int right, int k)  
{  
    if (left > right) return -1;
    // left等于right返回当前值 
    if (left == right) return a[left];  
    // i为哨兵（中间的数）的下标
    int i = partition(a, left, right);  
    // j为左区间长度，用来判断 k位于什么位置   
    int j = i - left + 1;  
    // k比j小就在左区间找，否则就在右区间找 ,如果相等直接返回 
    if (j == k){
    	return a[i];
    }else if (k < j) {
    	return find(a, left, i, k); 
    }else {
    	// 去掉了左边 k取 k-j 
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
