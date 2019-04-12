#include<iostream>

using namespace std;

//硬币 1 5 11
//状态转移：f(n) = min(f(n - 1), f(n - 5), f(n - 11))
int main(){
    int f[100];  //方程值
    int cost = INT_MAX;
    int n;
    cin >> n;
    f[0] = 0;
    for(int i = 1; i <= n; i++){
        cost = INT_MAX;
        if(i >= 1) cost = min(cost, f[i - 1] + 1);
        if(i >= 5) cost = min(cost, f[i - 5] + 1);
        if(i >= 11) cost = min(cost, f[i - 11] + 1);
        f[i] = cost;
    }
            cout << n << ":" << f[n] << endl;

    return 0;
}
