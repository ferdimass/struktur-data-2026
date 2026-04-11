#include <iostream>
using namespace std;

int main(){
    int matriks[3][4] = {{255, 255, 250, 240}, 
                        {150, 200, 255, 255}, 
                        {0, 50 , 150, 200}};
    
    for (int baris = 0; baris < 3; baris++)
    {
        for (int kolom = 0; kolom < 4; kolom++)
        {
            cout << matriks[baris][kolom] << endl;
        }
    }
    
}