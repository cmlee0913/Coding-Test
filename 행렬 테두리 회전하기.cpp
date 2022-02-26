#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int a[100][100];
    int number = 1;
    vector<int> answer;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            a[i][j] = number;
            ++number;
        }
    }

    for (vector<int> b : queries) {
        vector<int> container;

        for (int i = b[1]; i < b[3]; ++i) {
            if (i != 0) {
                a[b[0]-1][i] = a[b[0]-1][i-1]; 
            }
            else {
                a[b[0]][i-1] = a[b[0]-1][i-1];
            }
            container.push_back(a[b[0]-1][i-1]);
            container.push_back(a[b[2]-1][i-1]);
        } 
        for (int i = b[0]; i < b[2]; ++i) {
            container.push_back(a[i-1][b[1]-1]);
            container.push_back(a[i-1][b[3]-1]);
        }

        int minimum = container[0];

        for (int i = 0; i < container.size(); ++i) {
            minimum = min(minimum, container[i]);
        }

        answer.push_back(minimum);
    }
    
    return answer;
}

// answer

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int arr[100][100];
int mini;

void comp(int val){
    mini = min(mini,val);
}

vector<int> solution(int row, int col, vector<vector<int>> queries) {
    vector<int> answer;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            arr[i][j] = i*col+j+1;
    
    for(int k=0;k<queries.size();k++){
        mini = row*col;
        int y1 = queries[k][0]-1;
        int x1 = queries[k][1]-1;
        int y2 = queries[k][2]-1;
        int x2 = queries[k][3]-1;
        int temp = arr[y1][x1];
        comp(temp);
        for(int i=y1;i<y2;i++){
            arr[i][x1]=arr[i+1][x1];
            comp(arr[i+1][x1]);
        }
        for(int j=x1;j<x2;j++){
            arr[y2][j] = arr[y2][j+1];
            comp(arr[y2][j+1]);
        }
        for(int i=y2;i>y1;i--){
            arr[i][x2] = arr[i-1][x2];
            comp(arr[i-1][x2]);
        }
        for(int j=x2;j>x1+1;j--){
            arr[y1][j] = arr[y1][j-1];
            comp(arr[y1][j-1]);
        }
        arr[y1][x1+1]=temp;
        answer.push_back(mini);
    }
    return answer;
}