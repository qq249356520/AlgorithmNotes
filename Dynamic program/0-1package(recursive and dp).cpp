#include<iostream>
#include<vector>

using namespace std;

/*
    ���ݵݹ鹫ʽF(i, c) = max{F(i - 1, c), vi + F(i, c - wi)}
    ����iΪ��i����Ʒ��cΪ����������viΪ��i����Ʒ�ļ�ֵ��wiΪ��i����Ʒ������

    �Ƶ���ʹ���Զ����µ�˼�룬���������Ѿ����е����һ��������⽫��n����Ʒ�ŵ��������õ�����ֵ����
    ��ʱ����������ѡ��
        1.���ŵ�n����Ʒ����ʱ�ܼ�ֵΪF��n - 1�� C��
        2.���õ�n����Ʒ����ʱ�ܼ�ֵΪvn + F��n, c - wn��

    Args:
        w ��Ʒ����������
        v ��Ʒ�ļ�ֵ����
        index ��ǰ��ѡ�����Ʒ������
        capacity ��ǰ������Ч����
    return��
        ����ֵ
*/
int findMaxValue(vector<int> w, vector<int> v,int index, int capacity);

int dp[1000][1000] = {0};

int main(){
    vector<int> w;
    w.push_back(1);
    w.push_back(2);
    w.push_back(3);


    vector<int> v;
    v.push_back(6);
    v.push_back(10);
    v.push_back(12);
    int capacity = 5;

    //��ʼ������¼��һ��,ֻ���ǵ�һ����Ʒ�����
    for(int i = 0; i <= capacity; i++)
        dp[0][i] = w[0] <= i ? v[0] : 0;

    for(int i = 1; i < w.size(); i++){ //id ��Ϊ��һ���Ѿ�ȷ�� ���Դ�1��ʼ
        for(int j = 0; j <= capacity; j++){ //capa
            dp[i][j] = dp[i - 1][j];
            if(w[i] <= j) //���Խ�����Ʒװ��
                dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]); //dp[i][j]Ϊ��һ��
            //dp[i - 1][j - w[i]]Ϊ������һ��Ʒ�ܷ�װ�� ��Ϊdp[i - 1][j]����������һ��Ʒ
        }
    }
    cout << dp[w.size() - 1][capacity];
    return 0;
}

int findMaxValue(vector<int> w, vector<int> v, int index, int capacity){
    if(capacity<= 0 || index < 0) //�ݹ鷵��������������������������Ѿ���������
        return 0;

    //����������Ѿ�������ֱ�ӷ���������Ľ�
    if(dp[index][capacity] != 0)
        return dp[index][capacity];
    //���ŵ�i����Ʒ
    int res = findMaxValue(w, v, index - 1, capacity);
    if(w[index] <= capacity)
        res = max(res, v[index] + findMaxValue(w, v, index - 1, capacity - w[index]));
    //���������Ľ⣬�´�ֱ��ʹ��
    dp[index][capacity] = res;
    return res;

}
