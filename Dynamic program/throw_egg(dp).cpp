#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int getMinStep(int floor, int egg){
    /*
        ���������������һ������ һ��û��
        ����û��������F(floor - x, egg)
        �������˵������F(x - 1, egg - 1)
        ���� ����Ҫ�ҵľ�����С������Դ����Ľ�
        F(floor, egg) = min(max(f(floor - x, egg) + 1, f(x - 1, egg - 1) + 1))
    */
    //����¼���洢egg�������� floor���������µ����Ż����Դ���
    //int cache[egg + 1][floor + 1];
    //��һ�㱸��¼
    int preCache[floor + 1];
    //���㱸��¼
    int curCache[floor + 1];
    //���Ȱѱ���¼��ÿ��Ԫ�س�ʼ��Ϊ���ĳ��Դ���
    for(int j = 1; j <= floor; j++)
        curCache[j] = j;

    //����״̬ת�Ʒ���
    for(int n = 2; n <= egg; n++){
        //��pre = cur �����¸���cur
        for(int j = 1; j <= floor; j++)
            preCache[j] = curCache[j];
        for(int j = 1; j <= floor; j++)
            curCache[j] = j;
        for(int m = 1; m <= floor; m++)
             for(int k = 1; k < m; k++)  //����X
                curCache[m] = min(curCache[m], 1 + max(curCache[m - k], preCache[k - 1]));

    }
    return curCache[floor];

}

int main(){
    cout << getMinStep(100, 100) << endl;
}
