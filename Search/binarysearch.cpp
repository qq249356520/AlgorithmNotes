#include<iostream>
#include<vector>
using namespace std;

//arr必须有序
int binarySearch_conventional(vector<int> arr, int key){
    int left = 0;
    int right = arr.size() - 1;

    while(left <= right){ //当right为size-1时（指向最后一个元素)，循环条件必须为<= 否则查找情况不完整。
    //如[1，3，5]中查找5，若使用< 当left指向5时直接退出循环。
        int mid = left + (right - left) / 2; //防止溢出
        if(arr[mid] == key) return mid;
        if(arr[mid] < key) left = mid + 1;
        else right = mid -1; //+1 -1的目的是保证循环结束，防止出现死循环
    }
    return -1;
}

int binarySearch_findTheFirstOneEqualsKey(vector<int> arr, int key){
    //查找第一个与key相等的元素,控制判断条件与返回条件，返回left，right处加等号
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] >= key) right = mid - 1; //右边加等号，表明如果相等继续往左 -1保证可以退出循环
        else left = mid + 1;
    }
    if(left < arr.size() && arr[left] == key)
        //只能返回left  right在left的前一个,因为 只要相等 right就-1，且退出循环条件为left > right left此时所指元素为最左key
        return left;
    return -1;
}

int binarySearch_findTheFirstOneEGKey(vector<int> arr, int key){
    //寻找第一个大于等于key的元素，控制判断条件与返回条件，返回left，right处加等号
     int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        //由findTheFirstOneEqualsKey分析可知，查找第一个相等元素条件：
        //当arr[mid] > key时加等号,便可得到大于等于
        if(arr[mid] >= key) right = mid - 1; //右边加等号，表明如果相等继续往左 -1保证可以退出循环
        else
            left = mid + 1;
    }
    //直接返回left，且right刚好是最后一个小于key的元素,left = right + 1
    if(left < arr.size() && arr[left] >= key)
        return left;
    return -1;
}

int binarySearch_findTheFirstOneGTKey(vector<int> arr, int key){
    //查找第一个大于key的元素，判断控制条件与返回条件，返回left，left处加等号
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] <= key) left = mid + 1;
        else right = mid - 1;
    }
    if(left < arr.size() && arr[left] > key)
        return left;
    return -1;
}

int binarySearch_findTheLastOneEqualsKey(vector<int> arr, int key){
    //查找最后一个与key相等的元素，判断控制条件与返回条件，返回right，left处加等号
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){ //注意循环结束条件为left > right
        int mid = left + (right - left) / 2;
        if(arr[mid] <= key) left = mid + 1; //保证能退出循环
        else right = mid - 1; //保证退出循环
    }
    if(right >= 0 && arr[right] == key)
        //只能返回right right在left的前一个，
        //因为只要想等 left 就+1 所以最后left 停的位置刚好为第一个大于相等元素的位置，而right为相等元素
        return right;
    return -1;
}

int binarySearch_findTheLastOneELKey(vector<int> arr, int key){
    //查找最后一个等于或小于key的元素，判断控制条件与返回条件，返回right，left处加等号
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        //由findTheLastOneEqualsKey分析可知，查找最后一个相等元素条件：
        //当arr[mid] < key时加等号,便可得到小于等于
        if(arr[mid] <= key) left = mid + 1;
        else
            right = mid - 1;
    }
    //此处不控制返回条件直接返回right，因为left刚好指向第一个大于key的值，right为left-1
    if(right >= 0 && arr[right] <= key)
        return right;
    return -1;
}

int binarySearch_findTheLastOneLTKey(vector<int> arr, int key){
    //查找最后一个小于key的元素，判断控制条件与返回条件，返回right，right处加等号
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        //
        if(arr[mid] >= key) right = mid - 1; //控制right时加等号 与之前不同
        else left = mid + 1;
    }
    if(right >= 0 && arr[right] < key)
        return right;
    return -1;
}

int main(){
    vector<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);

    cout << binarySearch_findTheFirstOneGTKey(arr, 5) << endl;
}
