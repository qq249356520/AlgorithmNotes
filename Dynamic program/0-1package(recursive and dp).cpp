#include<iostream>
#include<vector>

using namespace std;

/*
    根据递归公式F(i, c) = max{F(i - 1, c), vi + F(i, c - wi)}
    其中i为第i个物品，c为背包重量，vi为第i个物品的价值，wi为第i个物品的重量

    推导：使用自顶向下的思想，假如我们已经进行到最后一步（即求解将第n个物品放到背包里获得的最大价值），
    此时我们有两种选择：
        1.不放第n个物品：此时总价值为F（n - 1， C）
        2.放置第n个物品：此时总价值为vn + F（n, c - wn）

    Args:
        w 物品的重量数组
        v 物品的价值数组
        index 当前带选择的物品的索引
        capacity 当前背包有效容量
    return：
        最大价值
*/
int findMaxValue(vector<int> w, vector<int> v,int index, int capacity);

int dp[1000][1000] = {0};

int main(){
    vector<int> w;
    w.push_back(1);
    w.push_back(2);
    w.push_back(3);


    vector<int> v;
    v.push_back(6);
    v.push_back(10);
    v.push_back(12);
    int capacity = 5;

    //初始化备忘录第一行,只考虑第一个物品的情况
    for(int i = 0; i <= capacity; i++)
        dp[0][i] = w[0] <= i ? v[0] : 0;

    for(int i = 1; i < w.size(); i++){ //id 因为第一行已经确定 所以从1开始
        for(int j = 0; j <= capacity; j++){ //capa
            dp[i][j] = dp[i - 1][j];
            if(w[i] <= j) //可以将新物品装下
                dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]); //dp[i][j]为上一个
            //dp[i - 1][j - w[i]]为考虑上一物品能否装下 因为dp[i - 1][j]本来就是上一物品
        }
    }
    cout << dp[w.size() - 1][capacity];
    return 0;
}

int findMaxValue(vector<int> w, vector<int> v, int index, int capacity){
    if(capacity<= 0 || index < 0) //递归返回条件，若背包容量不足或者已经遍历结束
        return 0;

    //如果子问题已经求解过，直接返回子问题的解
    if(dp[index][capacity] != 0)
        return dp[index][capacity];
    //不放第i个物品
    int res = findMaxValue(w, v, index - 1, capacity);
    if(w[index] <= capacity)
        res = max(res, v[index] + findMaxValue(w, v, index - 1, capacity - w[index]));
    //添加子问题的解，下次直接使用
    dp[index][capacity] = res;
    return res;

}
