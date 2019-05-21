#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int cmp(string s1, string s2){
    return s1 + s2 > s2 + s1;
}

int main(){
    int N; //n个整数
    cin >> N;
    vector<string> nums;
    string tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        nums.push_back(tmp);
    }
    string res = "";

    sort(nums.begin(), nums.end(), cmp);
    for(int i = 0; i < N; i++){
        res += nums[i];
    }

    cout << res << endl;
}
