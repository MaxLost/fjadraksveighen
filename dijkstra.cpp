#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
int main(){
    
    int n = 4;
    int start = 0;

    vector<vector<int >> w;
    w.resize(n);
    
    bool visited[n];
    int opt_path[n];

    for (int i = 0; i < n; i++){
        w[i].resize(n);
    }
    
    /* Инициализация графа */
    w[0][0] = 0;
    w[0][1] = 3;
    w[0][2] = 6;
    w[0][3] = INT_MAX;
    w[1][0] = INT_MAX;
    w[1][1] = 0;
    w[1][2] = 2;
    w[1][3] = 10;
    w[2][0] = 6;
    w[2][3] = 4;

    for(int i = 0; i < n; i++){
        opt_path[i] = w[start][i];
        visited[i] = false;
    }
    
    opt_path[start]=0;
    int index = 0, u = 0;
    
    for (int i = 0; i < n; i++){
        
        int min = INT_MAX;
        
        for (int j = 0; j < n; j++){
            if (!visited[j] && opt_path[j] < min){
                min = opt_path[j]; 
                index = j;
            }
        }
        
        u = index;
        visited[u] = true;
        
        for(int j=0; j < n; j++){
            if (!visited[j] && w[u][j]!=INT_MAX && opt_path[u]!=INT_MAX && (opt_path[u] + w[u][j] < opt_path[j]))
            {
                opt_path[j] = opt_path[u] + w[u][j];
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        if (opt_path[i]!=INT_MAX)
            cout << start << " -> " << i << " = " << opt_path[i] << endl;
        else 
            cout << start << " -> " << i<< " = " << "маршрут недоступен" << endl;
    }
    
}