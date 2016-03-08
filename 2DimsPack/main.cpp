//
//  main.cpp
//  2DimsPack
//
//  Created by Trinity on 16/3/8.
//  Copyright © 2016年 Trinity. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define MAX 1000000
using namespace std;

int W[MAX];
int C[MAX];
int D[MAX];
int DP[MAX][MAX];

int N, V, U;

void square() {
    for (int i = 0; i <= V; i++) {
        for (int j = 0; j <= U; j++) {
            if(j != 0) cout.width(4);
            cout<<DP[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void genDp(){
    for (int i = 0; i <= V; i++) {
        for (int j = 0; j <= U; j++) {
            DP[i][j] = 0;
        }
    }
    square();
    
    for (int i = 1; i <= N; i++) {
        for (int j = V; j >= C[i]; j--) {
            for (int k = U; k >= D[i]; k--) {
                int a = DP[j][k];
                int b = DP[j - C[i]][k - D[i]] + W[i];
                DP[j][k] = a > b ? a : b;
            }
        }
        
        square();
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i<N; i++) cin >> W[i + 1];
    cin >> V;
    for (int i = 0; i<N; i++) cin >> C[i + 1];
    cin >> U;
    for (int i = 0; i<N; i++) cin >> D[i + 1];
    
    genDp();
    
    return 0;
}


// USER CASE: 3 4 2 3 4 3 2 1 5 3 2 2

















