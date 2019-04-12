#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> v_str;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        v_str.push_back(str);
    }
    for(int i = 0; i < n; i++){
        string res = "";
        if(v_str[i].size() < 3)
            res = v_str[i];
        else{
            for(int j = 0; j < v_str[i].size(); j++){
                if(res.size() > 1 && v_str[i][j] == res[res.size() - 1] && v_str[i][j] == res[res.size() - 2])
                    continue;
                else if(res.size() > 2 && v_str[i][j] == res[res.size() - 1] && res[res.size() - 2] == res[res.size() - 3])
                    continue;
                else
                    res += v_str[i][j];
            }
        }
        cout << res << endl;
    }
    return 0;
}
