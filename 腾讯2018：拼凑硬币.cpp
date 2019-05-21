#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long n; //输入整数
    cin >> n;

    //动态规划 使用dp[n][i] 表示得到n块钱，使用2^i可以组合出n的方案数
    /*
        init:
        dp[0][i] = 1 即当需要0块钱时，所有硬币面值均为0，随便取一个即可
        dp[1][1] = 1 所有面值都为1，同理
        dp[2][0] = 1 只取两个一元硬币
        dp[n][i] = sum(dp[n-2^j*m][j-1])  其中m为0 || 1 ||２即当前面值取一张或者取两张或者不要
        即是否用当前硬币由之前的硬币决定。
    */

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }


    double lo = log(n) / log(2);
    int length = (int)lo + 1;

    int dp[n + 1][length] = {0};
    for(int i = 0; i < length; i++){
        dp[0][i] = 1;
        dp[1][i] = 1;
    }
    dp[1][0] = dp[2][0] = 1;

    //构建dp数组
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < length; j++){
            int sum = 0;
            for(int m = 0; m < 3; m++){
                int tmp = i - pow(2, j) * m;  //能否使用当前钞票 以及能用几张
                if(tmp >= 0)
                    sum += dp[tmp][j - 1]; //若能用面值为tmp的硬币，则加上tmp的情况
            }
            dp[i][j] = sum;
        }
    }

    cout << dp[n][length - 1] << endl;
    return 0;
}
