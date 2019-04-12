#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<vector>
using namespace std;

//二倍均值法
vector<double> divideRedPacket(double totalAmount, double totalPeopleNum){
    vector<double> res(totalPeopleNum);

    srand(double(time(0)));
    double restAmo = totalAmount;
    double restPeople = totalPeopleNum;

    for(int i = 0; i < totalPeopleNum - 1; i++){
        double tmp = double(rand()) % (restAmo / restPeople) * 2 + 0.01;
        restAmo -= tmp;
        restPeople--;
        res[i] = tmp;
    }
    res[totalPeopleNum - 1] = restAmo;

    return res;
}

int main(){
    vector<double> res;
    res = divideRedPacket(100.0, 10.0);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}
