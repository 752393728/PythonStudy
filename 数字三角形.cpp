#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    int n,a[105][105];
    scanf("%d",&n);
    // 输入 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            scanf("%d",&a[i][j]);
        }
    }
    // 思路：一个状态的子状态由左右节点组成，最底下一层没有子节点，所以自底向上更新
	// 状态方程：很好想到左子状态和右子状态取最优 
    for(int i = n-1; i >=0; i--){
        for(int j = 0; j < i+1; j++){
            a[i][j] = max((a[i][j]+a[i+1][j]),(a[i][j]+a[i+1][j+1]));
        }
    }
    // 最终会将a[0][0]更新为全局最优 
    printf("%d",a[0][0]);
}
