#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

int main(){
    int num; //��Ҫ�ü��ĳ���
    int n;  //���ӵĸ���
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
        //����ܼ��������ӵĸ���
        for(int i = 0; i < n; i++)
            tmp += int(length[i] / mid);
        //����ı��ܼ��õĶ�, ˵����Ҫ���õ����ӻ�Ҫ�̣����ӳ� ��Ҫ������
        if(num > tmp)
            maxn = mid;
        //����ı��ܼ��õ��٣�˵����Ҫ���õ����ӳ������Ӷ��ˣ�Ҫ�ټ�����
        else
            minn = mid;
    }
    cout << setprecision(2) << maxn << endl;
    return 0;
}
