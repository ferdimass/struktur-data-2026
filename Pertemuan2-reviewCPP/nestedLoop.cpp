#include <iostream>
using namespace std;

int main(){
    int rows, column, number = 1, n = 5;
    for(rows=0; rows <=n; rows++){
        for(column=0; column <rows; column++){
            cout << number << " "; 
            number++;
        }
        cout << "\n";
    }
    return 0;
}