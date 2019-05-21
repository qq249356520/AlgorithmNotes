#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

//泰勒公式
int main(){
    double n = 1;
    double pi = 0;

    double item = 1;
    int num = 1000000;
    int flag = 1;
    while(num){
        pi += item;
        n += 2;
        flag = -flag;
        item = (flag / n);
        num--;
    }
    cout << fixed << setprecision(35) << 4 * pi << endl;
    return 0;
}
