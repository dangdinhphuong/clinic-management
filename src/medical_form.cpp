#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Hàm nhập n bệnh nhân, thêm vào danh sách liên kết đơn
void inputPatients(Patient*& head, int n) {
    for (int i = 0; i < n; ++i) {
        Patient* newNode = new Patient;
        cout << "Nhap thong tin benh nhan thu " << i + 1 << ":\n";
        cout << "Ma benh nhan: "; getline(cin, newNode->id);
        cout << "Ten: "; getline(cin, newNode->name);
        cout << "Tuoi: "; cin >> newNode->age; cin.ignore();
        cout << "Gioi tinh: "; getline(cin, newNode->gender);
        newNode->next = nullptr;

        if (!head) head = newNode;
        else {
            Patient* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
}

// Hàm in danh sách bệnh nhân
void printPatients(Patient* head) {
    cout << "\nDANH SACH BENH NHAN:\n";
    while (head) {
        cout << head->id << " | " << head->name << " | " << head->age << " | " << head->gender << endl;
        head = head->next;
    }
}
