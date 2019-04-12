#include <iostream>
#include <string>
#include <vector>
using namespace std;

void getNext(string s);

int main()
{
    string str;
    while(cin >> str){
        vector<int>next(100000);
        int m = str.size();
        next[0] = -1;
        int j = 0;
        int k = -1;
        while(j < m) {
            if (k == -1 || str[j] == str[k])
                next[++j] = ++k;
            else
                k = next[k];
        }

        int ans = str.size() - next[str.size()];

        if (str.size() % ans){
            cout << str.size() << endl;
            return 0;
        }
        cout << ans << endl;
    }
    return 0;
}

void getNext(string str){

}
