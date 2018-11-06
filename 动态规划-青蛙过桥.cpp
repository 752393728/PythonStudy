#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
// 动态规划：从后往前更新，最后三个坐标情况特殊，可以一步跳出
// 状态方程： dp[n-1] = a[n-1]  dp[n-2] = a[n-2]  dp[n-3] = a[n-3]（i>n-4）
//            dp[i] = min(min(a[i]+dp[i+1],a[i]+dp[i+2]),a[i]+dp[i+3])  （i<=n-4）
int main(){
	//定义dp数组，因为是线性的，所以定义一维数组 
    int n,a[155],dp[105];
    scanf("%d",&n);
    // n+1个坐标 
    n = n+1;
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    if(n>3){ 
    	//从后向前更新 
    	//最后三个坐标的最小为三个坐标本身具有的石头数 
        dp[n-1] = a[n-1];
        dp[n-2] = a[n-2];
        dp[n-3] = a[n-3];
        //当 i<=n-4 的时候，当前的最优解为其后一个，后两个和后三个坐标记录的最优解与其本身坐标的石头数相加的三个值中取最小值
		//当前状态的子状态为  坐标+1时的状态，坐标+2时的状态和坐标+3时的状态 
        for(int i = n-4; i >= 0; i--){
            dp[i] = min(min(a[i]+dp[i+1],a[i]+dp[i+2]),a[i]+dp[i+3]);
        }
        // 自右向左，全局最优为 dp[0] 
        printf("%d",dp[0]);
    }else{
    	//如果只有三个或者三个一下的坐标点的话，青蛙是可以直接跳过去的，所以直接输出0坐标 
        printf("%d",a[0]);
    }
}
