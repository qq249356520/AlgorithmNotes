#include<iostream>
#include<vector>

using namespace std;

int findLIS(vector<int> nums);

int main(){
    int n;
    vector<int> nums;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        nums.push_back(x);
    }

    cout << findLIS(nums) << endl;
    return 0;
}
    /*
        如给定1，5，3，4，6，9，7，8，找到其中得最长上升子序列
        最长上升子序列为1，3，4，6，7，8

        那么 关键还是如何设计状态（我是谁）？
        我们可以令f（x）为以下标x的数结尾的LIS长度。
        那么最终答案就是max(f(x))
        那么状态转移方程（我从哪来）？
        对于数字8来说，它的长度就是7的长度+1 f（index(7)） + 1
        即
           考虑比x小的每一个p，我们把nums[x]接在nums[p]的后面，肯定能构造
            一个以nums[x]结尾的LIS，如此便可写出状态转移方程：
            f(x) = max{f(p)} + 1

    */
int findLIS(vector<int> nums){
    int f[105];
    for(int i = 0; i < nums.size(); i++){
        f[i] = 1;
        for(int p = 0; p < i; p++){
            if(nums[i] > nums[p]){
                f[i] = max(f[i], f[p] + 1); //状态转移
            }
        }
        cout << nums[i] << ": " << f[i] << endl;
    }
    int ans = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        ans = max(f[i], ans);
    }
    return ans;
}
