#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

int main(){
    int num; //需要裁剪的长度
    int n;  //绳子的个数
    double res, maxn = 0.0, minn = 0.0;
    int length[100001];
    cin >> n >> num;
    for(int i = 0; i < n; i++){
        cin >> length[i];
        if(maxn < length[i]) maxn = length[i];
    }
    while(maxn - minn >= 1e-4){
        int tmp = 0;
        double mid = (maxn + minn) / 2;
        //检查能剪裁完绳子的个数
        for(int i = 0; i < n; i++)
            tmp += int(length[i] / mid);
        //需求的比能剪裁的多, 说明需要剪裁的绳子还要短，绳子长 还要继续剪
        if(num > tmp)
            maxn = mid;
        //需求的比能减裁的少，说明需要剪裁的绳子长，绳子短了，要少剪几次
        else
            minn = mid;
    }
    cout << setprecision(2) << maxn << endl;
    return 0;
}
