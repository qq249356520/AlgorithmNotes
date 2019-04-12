#include<iostream>
#include<vector>

#define MAX_NUM 9

using namespace std;
int chessBoard[MAX_NUM][MAX_NUM] = {0};

//bool eightQueens(int chessBoard[MAX_NUM][MAX_NUM], int n);
void eightQueens(int chessBoard[MAX_NUM][MAX_NUM], int n);
bool check(int chessBoard[MAX_NUM][MAX_NUM], int x, int y);
void print(int chessBoard[MAX_NUM][MAX_NUM]);
int num = 0;
int main(){
    eightQueens(chessBoard, 0);

    cout << endl << "共" << num << "种解法!!" << endl;
    return 0;
}

//一种解法
/*
bool eightQueens(int chessBoard[MAX_NUM][MAX_NUM], int n){
    if(n == MAX_NUM) //如果行数超过8，说明已经找出答案了
        return true;
    //遍历当前行，注意格子验证
    for(int j = 0; j < MAX_NUM; j++){
        for(int k = 0; k < MAX_NUM; k++)
            chessBoard[n][k] = 0;
        if(check(chessBoard, n, j)){  //如果可以放在当前行
            chessBoard[n][j] = 1;
            if(eightQueens(chessBoard, n + 1))
                return true;
        }
    }
    return false;
}
*/

//多种解法
void eightQueens(int chessBoard[MAX_NUM][MAX_NUM], int n){
    //从当前行开始操作
    for(int j = 0; j < MAX_NUM; j++){ //遍历当前列
        chessBoard[n][j] = 1;
        if(check(chessBoard, n, j)){  //如果可以放在当前位置
            if(n + 1 == MAX_NUM) //当n为7 即最后一行时
                print(chessBoard);
            else
                eightQueens(chessBoard, n + 1);
        }

        chessBoard[n][j] = 0;
    }
}

//判断上下左右是否棋子（即其他棋子是否在本棋子的攻击范围内）
bool check(int chessBoard[MAX_NUM][MAX_NUM], int x, int y){
    for(int i = 0; i < x; i++){
        //纵向检查
        if(chessBoard[i][y]) return false;
        //左斜线
        if(x - 1 - i >= 0 && y - 1 - i >= 0 && chessBoard[x - 1 - i][y - 1 - i]) return false;
        //右斜线
        if(x - 1 - i >= 0 && y + 1 + i < MAX_NUM && chessBoard[x - 1 - i][y + 1 + i]) return false;
    }
//    int m = x - 1, n = y - 1;
//    while(m >= 0 && n >= 0){
//        if(chessBoard[m][n]) return false;
//        --m; --n;
//    }
//    m = x - 1;
//    n = y + 1;
//    while(m >= 0 && n < MAX_NUM){
//        if(chessBoard[m][n]) return false;
//        --m; ++n;
//    }
    return true;
}


void print(int chessBoard[MAX_NUM][MAX_NUM]){
    ++num;
    cout << "第" << num << "种解法" << endl;
    for(int i = 0; i < MAX_NUM; i++){
        for(int j = 0; j < MAX_NUM; j++){
            cout << chessBoard[i][j] << " " ;
        }
        cout << endl;
    }
    cout << "******************************" << endl;
}


