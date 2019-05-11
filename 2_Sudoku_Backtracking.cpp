#include <bits/stdc++.h>
using namespace std;

bool isSafe(int grid[][9], int i, int j, int no, int n){
    for(int k=0;k<n;k++)
        if(grid[k][j] == no || grid[i][k] == no)
            return false;
    
    int sq = sqrt(n);
    int sx = (i/sq)*sq, sy = (j/sq)*sq;

    for(int x=sx;x<sx+sq;x++)
        for(int y=sy;y<sy+sq;y++)
            if(grid[x][y] == no)
                return false;
    return true;
}

bool SudokuSolver(int grid[][9], int i, int j, int n){
    if(i==n){
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++)
                cout << grid[k][l] << " ";
            cout << "\n";
        }
        return true;
    }
    if(j==n)
        return SudokuSolver(grid, i+1, 0, n);
    
    if(grid[i][j] != 0)
        return SudokuSolver(grid, i, j+1, n);
    
    if(grid[i][j] == 0){
        for(int no=1;no<=n;no++){
            if(isSafe(grid, i, j, no, n)){
                grid[i][j] = no;
                if(SudokuSolver(grid, i, j+1, n))
                    return true;
            }
        }
    }
    grid[i][j] = 0;
    return false;
}

int main()  
{  
    int n = 9;
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  

    if (!SudokuSolver(grid, 0, 0, n))
        cout << "There is no solution" << endl;
  
    return 0;  
}  