#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int n;
    int k;
    
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> n;
        string str = "";
        int counter = 0;
        vector <int> ans;
        ans.clear();
        while ((n > 1) && (counter <= 5)){
            for (int i = round(sqrt(n)); i >= 1; i--){
                // cout << round(sqrt(n)) << endl;
                while (n - (i * i) >= 0){
                    if (i != 0){
                        n = n - i*i;
                        //cout << n << endl;
                        ans.push_back(i);
                        counter++;
                    }
                }
            }
        }
        if (n == 1){
            ans.push_back(1);
            counter++;
        }

        cout << counter << endl;
        str = to_string(ans[0]);
        for (int i = 1; i < ans.size(); i++){
            str = str + " " + to_string(ans[i]);
        }
        cout << str << endl;
    }
};