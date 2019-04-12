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

    cout << endl << "��" << num << "�ֽⷨ!!" << endl;
    return 0;
}

//һ�ֽⷨ
/*
bool eightQueens(int chessBoard[MAX_NUM][MAX_NUM], int n){
    if(n == MAX_NUM) //�����������8��˵���Ѿ��ҳ�����
        return true;
    //������ǰ�У�ע�������֤
    for(int j = 0; j < MAX_NUM; j++){
        for(int k = 0; k < MAX_NUM; k++)
            chessBoard[n][k] = 0;
        if(check(chessBoard, n, j)){  //������Է��ڵ�ǰ��
            chessBoard[n][j] = 1;
            if(eightQueens(chessBoard, n + 1))
                return true;
        }
    }
    return false;
}
*/

//���ֽⷨ
void eightQueens(int chessBoard[MAX_NUM][MAX_NUM], int n){
    //�ӵ�ǰ�п�ʼ����
    for(int j = 0; j < MAX_NUM; j++){ //������ǰ��
        chessBoard[n][j] = 1;
        if(check(chessBoard, n, j)){  //������Է��ڵ�ǰλ��
            if(n + 1 == MAX_NUM) //��nΪ7 �����һ��ʱ
                print(chessBoard);
            else
                eightQueens(chessBoard, n + 1);
        }

        chessBoard[n][j] = 0;
    }
}

//�ж����������Ƿ����ӣ������������Ƿ��ڱ����ӵĹ�����Χ�ڣ�
bool check(int chessBoard[MAX_NUM][MAX_NUM], int x, int y){
    for(int i = 0; i < x; i++){
        //������
        if(chessBoard[i][y]) return false;
        //��б��
        if(x - 1 - i >= 0 && y - 1 - i >= 0 && chessBoard[x - 1 - i][y - 1 - i]) return false;
        //��б��
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
    cout << "��" << num << "�ֽⷨ" << endl;
    for(int i = 0; i < MAX_NUM; i++){
        for(int j = 0; j < MAX_NUM; j++){
            cout << chessBoard[i][j] << " " ;
        }
        cout << endl;
    }
    cout << "******************************" << endl;
}


