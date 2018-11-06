#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
// 在数字三角形基础上用flag数组从下至上记录路径，并从上至下输出路径 
int main(){
    int n,a[105][105],u[105][105];
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            scanf("%d",&a[i][j]);
            // 求最优路径的时候会更新三角形中的数，为了把路径输出来需要用u数组记录原来三角形的数字 
            u[i][j] = a[i][j];
        }
    }
    // flag数组用于记录一路上的节点选了哪个子状态 
    int flag[105][105],p;
    // 由于记录了每个节点会选择左边还是右边，但是根节点没有父节点，所以单独记录 
    p = a[0][0];
    for(int i = n-1; i >=0; i--){
        for(int j = 0; j < i+1; j++){
        	// c记录和左边子节点的最优状态的和，d记录和右边子节点的最优状态的和
            int c,d;
            c = (a[i][j]+a[i+1][j]);
            d = (a[i][j]+a[i+1][j+1]);
            // 判断并取最优的子状态 
            if(c>d){
            	// flag数组记录当前的节点选了左子节点还是选了右子节点 
                flag[i][j] = 1;
                a[i][j] = c;
            }else if(c<d){
            	// 数字1代表左，数字2代表右 
                flag[i][j] = 2;
                a[i][j] = d; 
            }else{
            	// 如果两个节点都为最优，取左边节点（题目提到） 
                flag[i][j] = 1;
                a[i][j] = c;
            }
        }
    }
    // 首先输出根节点 
    printf("%d ",p);
    // 层数是固定的，从第一层到最后一层输出路径，第一层的时候根节点位于坐标 0，定义l为最优路径在每层时取的坐标
	// 坐标根据记录路径的flag数组来更新 
    int l = 0;
    for(int i = 0; i < n-1; i++){ 
        if(flag[i][l]==1){
        	// 若当前节点取的是左子节点，层数加一，坐标不动 
            printf("%d ",u[i+1][l]);
        }else if(flag[i][l]==2){
        	// 若当前节点取的是右子节点，层数加一，坐标加一 
            printf("%d ",u[i+1][l+1]);
            l = l+1;
        }
    }
}
