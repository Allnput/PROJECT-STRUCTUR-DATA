#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

struct Pelanggan {
    string waktuKedatangan;
    string nik;
    string nama;
    string tempatTanggalLahir;
    string jenisKelamin;
    string alamat;
    string rtRw;
    string kelDesa;
    string kecamatan;
    string agama;
    string statusPerkawinan;
    string pekerjaan;
    string kewarganegaraan;
    string berlakuHingga;

};
    int jumlah = 0;
void saveData(Pelanggan& p) {
	    
    ofstream data("data_ktp_admin.txt", ios::app);

    if (data.is_open()) {
        data << "===== Data KTP Admin =====\n";
        data << "NIK              : " << p.nik << endl;
        data << "Nama             : " << p.nama << endl;
        data << "Tempat/Tgl Lahir : " << p.tempatTanggalLahir << endl;
        data << "Jenis Kelamin    : " << p.jenisKelamin << endl;
        data << "Alamat           : " << p.alamat << endl;
        data << "RT/RW            : " << p.rtRw << endl;
        data << "Kel/Desa         : " << p.kelDesa << endl;
        data << "Kecamatan        : " << p.kecamatan << endl;
        data << "Agama            : " << p.agama << endl;
        data << "Status Perkawinan: " << p.statusPerkawinan << endl;
        data << "Pekerjaan        : " << p.pekerjaan << endl;
        data << "Kewarganegaraan  : " << p.kewarganegaraan << endl;
        data << "Berlaku Hingga   : " << p.berlakuHingga << endl;
        data << "===========================\n" << endl;

        data.close();
    } else {
        cerr << "Gagal membuka file data_ktp.txt. Pastikan Anda memiliki izin akses.\n";
    }
}

void tampilkanData(const Pelanggan& p) {
	system("cls");
	
    cout << "\n===== Data KTP Anda =====\n";
    cout << "NIK               : " << p.nik << endl;
    cout << "Nama              : " << p.nama << endl;
    cout << "Tempat/Tgl Lahir  : " << p.tempatTanggalLahir << endl;
    cout << "Jenis Kelamin     : " << p.jenisKelamin << endl;
    cout << "Alamat            : " << p.alamat << endl;
    cout << "RT/RW             : " << p.rtRw << endl;
    cout << "Kel/Desa          : " << p.kelDesa << endl;
    cout << "Kecamatan         : " << p.kecamatan << endl;
    cout << "Agama             : " << p.agama << endl;
    cout << "Status Perkawinan : " << p.statusPerkawinan << endl;
    cout << "Pekerjaan         : " << p.pekerjaan << endl;
    cout << "Kewarganegaraan   : " << p.kewarganegaraan << endl;
    cout << "Berlaku Hingga    : " << p.berlakuHingga << endl;
    cout << "===========================\n";
}

void ktp_admin(Pelanggan& p) {
    cout << "Masukkan NIK: ";
    cin >> p.nik;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, p.nama);
    cout << "Masukkan Tempat dan Tanggal Lahir (contoh: Jakarta, 01 Januari 1990): ";
    getline(cin, p.tempatTanggalLahir);

    while (true) {
        cout << "Masukkan Jenis Kelamin (P/L): ";
        char gender;
        cin >> gender;
        cin.ignore();

        if (gender == 'P' || gender == 'p') {
            p.jenisKelamin = "Perempuan";
            break;
        } else if (gender == 'L' || gender == 'l') {
            p.jenisKelamin = "Laki-laki";
            break;
        } else {
            cout << "Input tidak valid. Harap masukkan P atau L.\n";
        }
    }

    cout << "Masukkan Alamat: ";
    getline(cin, p.alamat);
    cout << "Masukkan RT/RW (contoh: 01/02): ";
    getline(cin, p.rtRw);
    cout << "Masukkan Kel/Desa: ";
    getline(cin, p.kelDesa);
    cout << "Masukkan Kecamatan: ";
    getline(cin, p.kecamatan);
    cout << "Masukkan Agama: ";
    getline(cin, p.agama);
    cout << "Masukkan Status Perkawinan (Belum Kawin/Kawin): ";
    getline(cin, p.statusPerkawinan);
    cout << "Masukkan Pekerjaan: ";
    getline(cin, p.pekerjaan);
    cout << "Masukkan Kewarganegaraan: ";
    getline(cin, p.kewarganegaraan);
    cout << "Masukkan Berlaku Hingga (contoh: SEUMUR HIDUP): ";
    getline(cin, p.berlakuHingga);

    jumlah++;
    saveData(p);
    tampilkanData(p);
}

void ktp_display(Pelanggan& p) {
    int pilih_ktp;
    cout << "---SELAMAT DATANG DI INVENTARIS GUDANG---\n\n";
    cout << "1. SIGN UP ADMIN \n";
    cout << "2. SIGN IN ADMIN \n";
    cout << "Masukan pilihan : ";
    cin >> pilih_ktp;
	cout <<endl;
	
    switch (pilih_ktp) {
        case 1:
            ktp_admin(p);
            cout <<endl;
			ktp_display(p);
            break;
        case 2: {
           string inputNama, inputNIK;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, inputNama);
            cout << "Masukkan NIK: ";
            getline(cin, inputNIK);

            ifstream data("data_ktp.txt");
            string line;
            bool found = false;
            while (getline(data, line)) {
                if (line.find("NIK              : " + inputNIK) != string::npos) {
                    getline(data, line);
                    if (line.find("Nama             : " + inputNama) != string::npos) {
                        found = true;
                        break;
                    }
                }
            }

            if (found) {
            	cout <<endl;
                cout << "Login berhasil\n";
                cout << "Tekan apa saja untuk masuk ke gudang---";
                getch();
                system("cls");
                cout <<"--- SELAMAT DATANG " << inputNama <<" ---\n\n";
            } else {
                cout << "Login gagal. NIK atau Nama yang dimasukkan tidak sesuai.\n";
                ktp_display(p);
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }
}

//=================================================================================================================================================================

struct Node {
	string namabarang;
    string kodebarang;
    string tanggalbarang;
    string data;
    Node* next;
    Pelanggan p;
    string antrian;
	string jamDatang;
};

struct Queue {
    Node* front;
    Node* rear;
};

struct Stack {
    Node* top;
};

void initializeQueue(Queue &q) {
    q.front = NULL;
    q.rear = NULL;
}

void initializeStack(Stack &s) {
    s.top = NULL;
}

bool isEmpty(Queue &q) {
    return q.front == NULL;
}

bool isEmpty(Stack &s) {
    return s.top == NULL;
}

bool enqueue(Queue &q,Pelanggan& p, string antrian, string jamDatang, string nama, string nik) {
    Node* newNode = new Node;
    newNode->antrian = antrian;
    newNode->jamDatang = jamDatang;
    newNode->p.nama = nama;
    newNode->p.nik = nik;
    newNode->next = nullptr;

    if (q.rear == nullptr) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }

    return true;
}

bool dequeue(Queue &q, string &removedValue) {
    if (isEmpty(q)) {
        cout << "Queue kosong!\n";
        return false;
    }
    
    Node* temp = q.front;
    removedValue = temp->data;
    q.front = q.front->next;
    if (q.front == NULL) {
        q.rear = NULL;
    }
    delete temp;
    return true;
}

bool push(Stack &s, string namabarang, string kodebarang, string tanggalbarang) {
    Node* newNode = new Node;
    if (newNode == nullptr) {
        cout << "Memori penuh!\n";
        return false;
    }

    newNode->namabarang = namabarang;
    newNode->kodebarang = kodebarang;
    newNode->tanggalbarang = tanggalbarang;

    newNode->next = s.top;

    s.top = newNode;

    return true;
}

bool pop(Stack &s, string &removedValue) {
    if (isEmpty(s)) {
        cout << "Stack kosong!\n";
        return false;
    }
    Node* temp = s.top;
    removedValue = temp->data;
    s.top = s.top->next;
    delete temp;
    return true;
}

void ktp_pelanggan(Pelanggan& p, Queue& q) {
    static int antrian_pelanggan = 1;
    char tambahlagi;
    string jamDatang;
    
    do {
    	cin.ignore();
    	cout << endl;
        string antrian = "ATR-00" + to_string(antrian_pelanggan);
        cout << "Antrian : " << antrian << endl;
        
    	cout << "Masukkan Jam Datang (contoh: 08:30): ";
        cin >> jamDatang;
        
        cout << "Masukkan NIK: ";
        cin >> p.nik;
        cin.ignore();
        cout << "Masukkan Nama: ";
        getline(cin, p.nama);
        cout << "Masukkan Tempat dan Tanggal Lahir (contoh: Jakarta, 01 Januari 1990): ";
        getline(cin, p.tempatTanggalLahir);

        while (true) {
            cout << "Masukkan Jenis Kelamin (P/L): ";
            char gender;
            cin >> gender;
            cin.ignore();

            if (gender == 'P' || gender == 'p') {
                p.jenisKelamin = "Perempuan";
                break;
            } else if (gender == 'L' || gender == 'l') {
                p.jenisKelamin = "Laki-laki";
                break;
            } else {
                cout << "Input tidak valid. Harap masukkan P atau L.\n";
            }
        }

        cout << "Masukkan Alamat: ";
        getline(cin, p.alamat);
        cout << "Masukkan RT/RW (contoh: 01/02): ";
        getline(cin, p.rtRw);
        cout << "Masukkan Kel/Desa: ";
        getline(cin, p.kelDesa);
        cout << "Masukkan Kecamatan: ";
        getline(cin, p.kecamatan);
        cout << "Masukkan Agama: ";
        getline(cin, p.agama);
        cout << "Masukkan Status Perkawinan (Belum Kawin/Kawin): ";
        getline(cin, p.statusPerkawinan);
        cout << "Masukkan Pekerjaan: ";
        getline(cin, p.pekerjaan);
        cout << "Masukkan Kewarganegaraan: ";
        getline(cin, p.kewarganegaraan);
        cout << "Masukkan Berlaku Hingga (contoh: SEUMUR HIDUP): ";
        getline(cin, p.berlakuHingga);


        if (enqueue(q, p,antrian, jamDatang, p.nama, p.nik)) {
            cout << "Pelanggan " << p.nama << " telah masuk dalam antrian.\n";
        }
        antrian_pelanggan++;
        
        cout << "\nApakah ingin memasukkan pelanggan lain? (Y/N): ";
        cin >> tambahlagi;
    } while (toupper(tambahlagi) == 'Y');
}



void displayQueue(Queue &q, Pelanggan& p) {
    if (isEmpty(q)) {
        cout << "--- ANTRIAN KOSONG ---!" << endl;
        return;
    }

    Node* temp = q.front;

    cout << left;
    cout << "\n                    DATA ANTRIAN PEMBELI\n";
    cout << "--------------------------------------------------------------\n";
    cout << "|  ANTRIAN  | JAM DATANG |        NIK        |      NAMA     |\n";
    cout << "--------------------------------------------------------------\n";

    while (temp != nullptr) {
        cout << "| " << setw(10) << temp->antrian << "| " 
             << setw(11) << temp->jamDatang << "| "
             << setw(18) << temp->p.nik << "| "
             << setw(14) << temp->p.nama << "|\n";
    cout << "--------------------------------------------------------------\n";
        temp = temp->next;
    }
}

void displayStack(Stack &s) {
    if (isEmpty(s)) {
        cout << "\nBARANG KOSONG!\n";
        return;
    }

    Node* temp = s.top;
    cout << "\n                  DATA BARANG DI GUDANG \n";
    cout << "--------------------------------------------------------------\n";
    cout << "|    Kode    |        Nama Barang         |      Tanggal     |\n";
    cout << "--------------------------------------------------------------\n";

    while (temp != nullptr) {
        cout << "| " << setw(11) << temp->kodebarang
             << "| " << setw(27) << temp->namabarang
             << "| " << setw(17) << temp->tanggalbarang
             << "|\n";
        cout << "--------------------------------------------------------------\n";
        temp = temp->next;
    }
}

void penjualan(Queue &q, Stack &s) {
    if (isEmpty(q)) {
        cout << "\nTIDAK ADA PEMBELI\n";
        return;
    }

    if (isEmpty(s)) {
        cout << "Tidak ada barang di gudang untuk dijual!\n";
        return;
    }

    cout << "---------------------------------------------------------------------------------\n";	
    cout << "| ANTRIAN | JAM DATANG |    NIK    | NAMA PELANGGAN  | KODE BRG | NAMA BARANG   |\n";
    cout << "---------------------------------------------------------------------------------\n";	

    while (!isEmpty(q) && !isEmpty(s)) {
        string namapembeli, nik, namabarang, kodebarang, tglbarang;
        string hapusbarang, hapusantrian;

        Node* pembeli = q.front;
        namapembeli = pembeli->p.nama;
        nik = pembeli->p.nik;

        Node* barang = s.top;
        namabarang = barang->namabarang;
        kodebarang = barang->kodebarang;
        tglbarang = barang->tanggalbarang;

        pop(s, hapusbarang);
        dequeue(q, hapusantrian);

        cout << "| " << setw(7) << pembeli->antrian
             << " | " << setw(10) << pembeli->jamDatang
             << " | " << setw(9) << nik
             << " | " << setw(15) << namapembeli
             << " | " << setw(8) << kodebarang
             << " | " << setw(13) << namabarang << " |\n";
    }

    cout << "---------------------------------------------------------------------------------\n";	

    if (isEmpty(q) && !isEmpty(s)) {
        cout << "\nTERIMAKASIH TELAH BERBELANJA DI TOKO KAMI\nnote : masih ada barang digudang\n";
    } else if (!isEmpty(q) && isEmpty(s)) {
        cout << "TERIMAKASIH TELAH BERBELANJA DI TOKO KAMI\nnote : mohon maaf pelanggan, kami kehabisan barang\n";
    } else {
        cout << "TERIMAKASIH TELAH BERBELANJA DI TOKO KAMI\n";
    }
}


int main() {
    Queue q;
    Stack s;
    initializeQueue(q);
    initializeStack(s);
	Pelanggan p;
    int pilihan;
    string namabarang, tanggalbarang;
    char tambahLagi;
	static int codebarang = 1;
	
	int jumlahStock;

	ktp_display(p);
    do {
        cout << "\n--- SISTEM GUDANG ---"<<endl <<endl;
        cout << "1. Restock Barang\n";
        cout << "2. Data Antrian\n";
        cout << "3. Penjualan\n";
        cout << "4. Informasi Antrian\n";
        cout << "5. Informasi Gudang\n";
        cout << "0. Keluar"<< endl<< endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
             do {
                    cin.ignore(); 
                    string kodebarang = "BRG-00" + to_string(codebarang);
                    cout << "\nKode Barang                : " << kodebarang << endl;
                    cout << "Nama Barang                : ";
                    getline(cin, namabarang);
                    cout << "Tanggal Masuk (dd/mm/yyyy) : ";
                    getline(cin, tanggalbarang);

                    if (push(s, namabarang, kodebarang, tanggalbarang)) {
                        cout << "Barang berhasil ditambahkan ke gudang.\n";
                        codebarang++;
                    }
					cout <<"\n";
                    cout << "Apakah ingin menambah barang lagi (Y/N)? ";
                    cin >> tambahLagi;
                    cout << "\n";
                } while (toupper(tambahLagi) == 'Y');
                break;
            case 2:
            	ktp_pelanggan(p,q);
            	cout << "Tekan apa saja untuk kembali ke gudang---";
                getch();
            	system("cls");
                break;
            case 3:
				penjualan(q, s);
                break;
            case 4:
                displayQueue(q,p);
                break;
            case 5:
                displayStack(s);
                break;
            case 0:
            	cout << "TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI"<<endl;
            	cout << "        -- HAVE A NICE DAY --"<<endl;
            	return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan >= 1 && pilihan <= 5);

    return 0;
}