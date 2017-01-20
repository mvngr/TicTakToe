#include <iostream>
#include <vector>

using namespace std;

void nullA(vector<vector<int>> & a) {
    if (a[0].empty())
        for (int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                a[i].push_back(0);
    else
        for (int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                a[i][j] = 0;
    return;
}
char changeIntToChar(int o) {
    switch (o) {
    case 1: return 'X'; break;
    case 2: return 'O'; break;
    default: return ' '; break;
    }
}

void print(vector<vector<int>> & a) {
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (j !=2) cout << changeIntToChar(a[i][j]) << '|';
            else cout << changeIntToChar(a[i][j]);

        }
        cout << endl;
    }
    return;
}

void moveA(vector<vector<int>> & a, int player, int pI, int pJ) {
    while (a[pI][pJ] != 0) {
        cout << "In this position " << a[pI][pJ] << ", try again" << endl;
        cin >> pI >> pJ;
    }
    a[pI][pJ] = player;
    return;
}
bool equal3Num(int q, int w, int e) {
    if (q == w && w == e && e != 0)
        return true;
    else
        return false;
}

int checkWin(vector<vector<int>> & a, int lastMoveI, int lastMoveJ) {
    if (equal3Num(a[lastMoveI][0], a[lastMoveI][1], a[lastMoveI][2])) return a[lastMoveI][2];
    if (equal3Num(a[0][lastMoveJ], a[1][lastMoveJ], a[2][lastMoveJ])) return a[2][lastMoveJ];
    if ((lastMoveI + lastMoveJ == 2) && equal3Num(a[0][2], a[1][1], a[2][0])) return a[2][0];
    if (lastMoveI == lastMoveJ && equal3Num(a[0][0], a[1][1], a[2][2])) return a[2][2];
    return 0;
}

int getPlayerFromMove(int move) {
    if (move % 2 == 0)
        return 1;
    else return 2;
}

void rules(vector<vector<int>> & a) {

    int moveCount = 0;
    while(true) {
        int I, J;
        cin >> I >> J;
        moveA(a, getPlayerFromMove(moveCount), I, J);
        moveCount++;
        print(a);
        int temp = checkWin(a,I,J);
        if (temp != 0) {
            cout << "Win: " << changeIntToChar(temp) << endl;
            nullA(a);
            moveCount = 0;
        }
        if (moveCount == 9) {
            cout << "Nobody win" << endl;
            nullA(a);
        }

    }

    return;
}

int main()
{
    vector<vector<int>> a(3);

    nullA(a);
    rules(a);

    return 0;
}
