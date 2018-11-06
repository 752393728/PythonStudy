#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,a[9000005],q,flag;
//二分搜索 
void bi(int begin,int end,int v){
	//min为中间数的下标 
    int min = (begin+end)/2;
    //终止判断 
    if(begin>=end) return;
    //为了找最近的数，这里判断题目给的数是在两个数之间的情况，二分搜到相邻两个数 
    if(begin+1==end){
    	//定义与前一个数和后一个数的差值 f 和 e 
        int e,f;
        e = a[end]-v;
        f = v-a[begin];
        //找出最近的数并记录在flag中 
        if(e>=f){
            flag = a[begin];
            return;
        }else {
            flag = a[end];
            return;
        }
    } 
    //给的值与中间值进行判断，然后继续二分 
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
        //调用封装好的二分搜索的函数，最终结果保留在 flag 中 
        bi(0,n-1,q);
        printf("%d\n",flag);
    }
}
