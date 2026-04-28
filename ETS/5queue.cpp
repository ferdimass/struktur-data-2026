#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<pair<int,string>> q, temp;
    int nomor = 1;

    while (1) {
        cout << "\n1. Ambil Antrian \n2. Layani \n3. Tampilkan Antrian \n4. Lihat Front \n5. Lihat Rear \n6. Keluar \nPilih: ";
        int option;
        cin >> option;

        if (option == 1) {
            string nama;
            cout << "\nNama: ";
            cin >> nama;
            q.push({nomor, nama});
            nomor++;
        }
        else if (option == 2) {
            if (q.empty()) cout << "\nAntrian kosong\n";
            else {
                cout << "\nMahasiswa dilayani: " << q.front().first << " " << q.front().second << endl;
                q.pop();
            }
        }
        else if (option == 3) {
            if (q.empty()) cout << "\nAntrian kosong\n";
            else {
                cout << "\nAntrian Mahasiswa\n";
                temp = q;
                while (!temp.empty()) {
                    cout << endl << temp.front().first << " " << temp.front().second << endl;
                    temp.pop();
                }
            }
        }
        else if (option == 4) {
            if (q.empty()) cout << "\nKosong\n";
            else cout << "\nFront: " << q.front().first << " " << q.front().second << endl;
        }
        else if (option == 5) {
            if (q.empty()) cout << "\nKosong\n";
            else cout << "\nRear: " << q.back().first << " " << q.back().second << endl;
        }
        else if (option == 6) {
            break;
        }
    }

    return 0;
}