#include<iostream>
using namespace std;
char map[120][120];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
bool bool_[120][120];
int n,m;
void dfs(int x,int y){
    if(x<0||x>=n||y<0||y>=m||map[x][y]=='0'||bool_[x][y]||map[x][y] == '*'){
        return;
    }
    bool_[x][y]= true;
    //留下每一组细胞最后一个细胞
    int k=0;
    for (int i = 0; i < 4; ++i) {
        int X=x+dir[i][0];
        int Y=y+dir[i][1];
        if(X>=0&&Y>=0&&X<n&&Y<m) {
            if (map[X][Y] == '*' || bool_[X][Y])
                k++;
        }
    }
    if(k!=0){
        map[x][y]='*';
    }
    //深度优先遍历
    for (int i = 0; i < 4; ++i) {
            dfs(x+dir[i][0],y+dir[i][1]);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            dfs(i, j);
        }
    }
    int number = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] != '0' && map[i][j] != '*')
            number++;
        }
    }
    cout << number << endl;
    return 0;
}
