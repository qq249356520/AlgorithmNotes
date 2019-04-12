#include<iostream>
#include<vector>

using namespace std;


int Partition_Fillpit(vector<int>& arr, int left, int right){
    //填坑法寻找基准元素
    //坑可以使用多个方法选择，此处我们选择第一个元素，这种选择当逆序时对排序很不利，也可以随机选择
    int pivot = arr[left];
    int index = left; //坑的位置
    while(left <= right){ //此处使用小于等于因为quicksort时使用了-1， -1位置也应该包含进来
        while(right >= left){
            if(arr[right] < pivot){
                arr[left] = arr[right]; //右边放到坑里
                index = right; //右边成为新的坑
                left++; //左边变为下一个元素
                break;
            }
            right--;
        }
        while(right >= left){
            if(arr[left] > pivot){
                arr[right] = arr[left]; //因为右边是新的坑，所以把左边放到坑里
                index = left;
                right--; //右边变为上一个元素
                break;
            }
            left++;
        }
    }
    arr[index] = pivot; //基准元素放到坑里
    return index; //最后的坑就是基准元素的位置
}

int Parttition_swappointer(vector<int>& arr, int left, int right){
    //找基准元素
    int pivot = arr[left];
    int index = left; //基准元素的位置
    /*
    采用双指针交换法 基本思路：从right指针开始，把指针指向的元素和基准元素做比较。
    如果right>= pivot则向前移动，直到right小于pivot，此时right停止移动，切换到left指针

    找到第一个left > pivot的情况。然后交换left和right指向的元素

    就这样进行一轮循环 每一个都和基准元素比较
    直到left = right ，此时我们让这个位置和基准元素交换。
    */
    while(left < right){
        while(left < right && arr[right] >= pivot) right--;
        while(left < right && arr[left] <= pivot) left++;
        if(left < right)
            swap(arr[left], arr[right]);
    }
    swap(arr[left], arr[index]);
    return left;
}


void quick_sort(vector<int>& arr, int left, int right){
    if(left < right){
        //寻找基准元素.每次确定一个元素的位置
        int pivotPos = Parttition_swappointer(arr, left, right);
        //递归寻找基准元素,最后确认所有位置,使用分治思想
        quick_sort(arr, left, pivotPos - 1);
        quick_sort(arr, pivotPos + 1, right);
    }
}

int main(){
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(3);


    quick_sort(arr, 0, arr.size() - 1);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}
