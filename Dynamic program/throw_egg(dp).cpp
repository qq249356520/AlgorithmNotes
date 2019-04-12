#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int getMinStep(int floor, int egg){
    /*
        鸡蛋有两种情况，一种碎了 一种没碎
        对于没碎的情况有F(floor - x, egg)
        对于碎了的情况有F(x - 1, egg - 1)
        所以 我们要找的就是最小的最大尝试次数的解
        F(floor, egg) = min(max(f(floor - x, egg) + 1, f(x - 1, egg - 1) + 1))
    */
    //备忘录，存储egg个鸡蛋， floor层数条件下的最优化尝试次数
    //int cache[egg + 1][floor + 1];
    //上一层备忘录
    int preCache[floor + 1];
    //本层备忘录
    int curCache[floor + 1];
    //首先把备忘录的每个元素初始化为最大的尝试次数
    for(int j = 1; j <= floor; j++)
        curCache[j] = j;

    //构造状态转移方程
    for(int n = 2; n <= egg; n++){
        //让pre = cur 并重新复制cur
        for(int j = 1; j <= floor; j++)
            preCache[j] = curCache[j];
        for(int j = 1; j <= floor; j++)
            curCache[j] = j;
        for(int m = 1; m <= floor; m++)
             for(int k = 1; k < m; k++)  //代表X
                curCache[m] = min(curCache[m], 1 + max(curCache[m - k], preCache[k - 1]));

    }
    return curCache[floor];

}

int main(){
    cout << getMinStep(100, 100) << endl;
}
