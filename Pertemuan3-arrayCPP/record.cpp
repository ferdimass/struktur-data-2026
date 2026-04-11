#include <bits/stdc++.h>
using namespace std;

struct mahasiswa{
    string nim, nama, prodi;
    float ipk;
};

int main(){
    mahasiswa mhs1, mhs2;
    mhs1.nim = "11223344";
    cin >> mhs1.nama;  

    mhs2.nim = "11335577";
    cin >> mhs2.ipk;

    cout <<"NIM mhs 1: " << mhs1.nim << endl;
    cout <<"IPK mhs 2: " <<mhs2.ipk;
    return 0;
}