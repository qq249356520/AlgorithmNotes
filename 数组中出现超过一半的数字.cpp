#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    leetcode169:Majority Element
    剑指offer：数组中出现次数超过一半的数
    腾讯2016真题：微信红包
*/

//寻找中位数法
int getValue_findMid(vector<int> arr) {
    // write code here
    if(arr.empty()) return 0;
    sort(arr.begin(), arr.end());
    int mid = (arr.size() - 1) / 2;
    int k = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == arr[mid]){
            k++;
            if(k > arr.size() / 2)
                break;
        }
    }
    return k > arr.size() / 2 ? arr[mid] : 0;
}

int getValue_useCount(vector<int> arr){
    if(arr.empty()) return 0;
    int len = arr.size();
    int count_k = 1;
    int key = arr[0];
    for(int i = 1; i < len; i++){
        if(arr[i] == key)
            count_k++;
        else
            count_k--;
        if(count_k == 0){
            key = arr[i];
            count_k = 1;
        }
    }
    int count_tmp = 0;
    for(int i = 0; i < len; i++){
        if(key == arr[i])
            count_tmp++;
    }
    return count_tmp > len / 2 ? key : 0;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);

    cout << getValue_useCount(arr) << endl;
}
