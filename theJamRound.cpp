#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<char>> &mat) {
    for(int i=0;i<mat.size();i++) {
        for(int j=0;j<mat[0].size();j++){
            cout << mat[i][j];
        }cout << "\n";
    }
}

void solve1(int r,int c,int m) {
    vector<vector<char>> ans(r,vector<char>(c,'.'));
    int i=r-1,j=c-1;
    while(m) {
        for(int x=i;x>=0;x--) {
            if(m==0) break;
            ans[x][j] = '*';
            m--;
        }
        j--;
        for(int x=j;x>=0;x--) {
            if(m==0) break;
            ans[i][x] = '*';
            m--;
        }
        i--;
    }
    int dotCount = 0;
    for(int i=0;i<r;i++) {
        dotCount = 0;
        for(int j=0;j<c;j++) {
            if(ans[i][j] =='.') dotCount++;
        }
        if(dotCount == 1 && c > 1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for(int j=0;j<c;j++) {
        dotCount = 0;
        for(int i=0;i<r;i++) {
            if(ans[i][j] == '.') dotCount++;
        }
        if(dotCount == 1 && r > 1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    printMatrix(ans);
}

void solve2(int r,int c,int m) {
    vector<vector<char>> ans(r,vector<char>(c,'.'));
    int i=r-1,j=c-1;
    while(m) {
        for(int x=j;x>=0;x--) {
            if(m==0) break;
            ans[i][x] = '*';
            m--;
        }
        i--;
        for(int x=i;x>=0;x--) {
            if(m==0) break;
            ans[x][j] = '*';
            m--;
        }
        j--;
    }
    int dotCount = 0;
    for(int i=0;i<r;i++) {
        dotCount = 0;
        for(int j=0;j<c;j++) {
            if(ans[i][j] =='.') dotCount++;
        }
        if(dotCount == 1 && c > 1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for(int j=0;j<c;j++) {
        dotCount = 0;
        for(int i=0;i<r;i++) {
            if(ans[i][j] == '.') dotCount++;
        }
        if(dotCount == 1 && r > 1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    printMatrix(ans);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    int i = 1;
    while(t--) {
        int r,c,m;
        cin >> r >> c >> m;
        cout << "Case #" << i << ":\n";
        i++;
        if(r < c) {
            solve2(r,c,m);
        }
        else {
            solve1(r,c,m);
        }
    }
    return 0;
}
