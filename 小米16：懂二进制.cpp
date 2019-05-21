#include<iostream>

using namespace std;

int main(){
        int tmp = 3892;
        int res = 0;
        while(tmp){
            if(tmp & 1)
                res++;
            tmp >>= 1;
            cout << tmp << endl;
        }
        cout << res << endl;
}
