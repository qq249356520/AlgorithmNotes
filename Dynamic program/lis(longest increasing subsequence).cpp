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
        �����1��5��3��4��6��9��7��8���ҵ����е������������
        �����������Ϊ1��3��4��6��7��8

        ��ô �ؼ�����������״̬������˭����
        ���ǿ�����f��x��Ϊ���±�x������β��LIS���ȡ�
        ��ô���մ𰸾���max(f(x))
        ��ô״̬ת�Ʒ��̣��Ҵ���������
        ��������8��˵�����ĳ��Ⱦ���7�ĳ���+1 f��index(7)�� + 1
        ��
           ���Ǳ�xС��ÿһ��p�����ǰ�nums[x]����nums[p]�ĺ��棬�϶��ܹ���
            һ����nums[x]��β��LIS����˱��д��״̬ת�Ʒ��̣�
            f(x) = max{f(p)} + 1

    */
int findLIS(vector<int> nums){
    int f[105];
    for(int i = 0; i < nums.size(); i++){
        f[i] = 1;
        for(int p = 0; p < i; p++){
            if(nums[i] > nums[p]){
                f[i] = max(f[i], f[p] + 1); //״̬ת��
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
