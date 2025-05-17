#include "../include/patient.h"
#include <iostream>
#include <iomanip>
using namespace std;

Patient::Patient() : age(0), fee(0), next(nullptr) {}
Patient::Patient(string id, string name, int age, string gender, string address, float fee, string admissionDate)
    : id(id), name(name), age(age), gender(gender), address(address), fee(fee), admissionDate(admissionDate), next(nullptr) {}

// Nhập thông tin bệnh nhân và thêm vào danh sách
void inputPatient(Patient*& head) {
    Patient* newNode = new Patient();
    cout << "Nhap ma benh nhan: "; getline(cin, newNode->id);
    cout << "Nhap ten: "; getline(cin, newNode->name);
    cout << "Nhap tuoi: "; cin >> newNode->age; cin.ignore();
    cout << "Nhap gioi tinh: "; getline(cin, newNode->gender);
    cout << "Nhap dia chi: "; getline(cin, newNode->address);
    cout << "Nhap chi phi kham: "; cin >> newNode->fee; cin.ignore();
    cout << "Nhap ngay nhap vien: "; getline(cin, newNode->admissionDate);
    newNode->next = nullptr;
    if (!head) head = newNode;
    else {
        Patient* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// In danh sách bệnh nhân
void printPatients(Patient* head) {
    cout << left << setw(10) << "MaBN" << setw(20) << "Ten" << setw(5) << "Tuoi" << setw(10) << "GioiTinh" << setw(20) << "DiaChi" << setw(10) << "ChiPhi" << setw(12) << "NgayNV" << endl;
    while (head) {
        cout << left << setw(10) << head->id << setw(20) << head->name << setw(5) << head->age << setw(10) << head->gender << setw(20) << head->address << setw(10) << head->fee << setw(12) << head->admissionDate << endl;
        head = head->next;
    }
}

// Sửa thông tin bệnh nhân theo mã
void editPatient(Patient* head, const string& id) {
    Patient* p = findPatientById(head, id);
    if (!p) {
        cout << "Khong tim thay benh nhan!\n";
        return;
    }
    cout << "Nhap lai thong tin (bo qua neu khong sua):\n";
    string tmp;
    cout << "Ten (" << p->name << "): "; getline(cin, tmp); if (!tmp.empty()) p->name = tmp;
    cout << "Tuoi (" << p->age << "): "; getline(cin, tmp); if (!tmp.empty()) p->age = stoi(tmp);
    cout << "Gioi tinh (" << p->gender << "): "; getline(cin, tmp); if (!tmp.empty()) p->gender = tmp;
    cout << "Dia chi (" << p->address << "): "; getline(cin, tmp); if (!tmp.empty()) p->address = tmp;
    cout << "Chi phi kham (" << p->fee << "): "; getline(cin, tmp); if (!tmp.empty()) p->fee = stof(tmp);
    cout << "Ngay nhap vien (" << p->admissionDate << "): "; getline(cin, tmp); if (!tmp.empty()) p->admissionDate = tmp;
    cout << "Da cap nhat thong tin.\n";
}

// Xóa bệnh nhân theo mã
void deletePatient(Patient*& head, const string& id) {
    Patient* prev = nullptr;
    Patient* curr = head;
    while (curr && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        cout << "Khong tim thay benh nhan!\n";
        return;
    }
    if (!prev) head = curr->next;
    else prev->next = curr->next;
    delete curr;
    cout << "Da xoa benh nhan.\n";
}

// Tìm bệnh nhân theo mã
Patient* findPatientById(Patient* head, const string& id) {
    while (head) {
        if (head->id == id) return head;
        head = head->next;
    }
    return nullptr;
}

// Tìm bệnh nhân theo tên (tìm gần đúng)
Patient* findPatientByName(Patient* head, const string& name) {
    while (head) {
        if (head->name.find(name) != string::npos) return head;
        head = head->next;
    }
    return nullptr;
}

void sortPatientsByName(Patient*& head) {
    for (Patient* i = head; i && i->next; i = i->next) {
        Patient* minNode = i;
        for (Patient* j = i->next; j; j = j->next) {
            if (j->name < minNode->name) minNode = j;
        }
        if (minNode != i) {
            swap(i->id, minNode->id);
            swap(i->name, minNode->name);
            swap(i->age, minNode->age);
            swap(i->gender, minNode->gender);
            swap(i->address, minNode->address);
            swap(i->fee, minNode->fee);
            swap(i->admissionDate, minNode->admissionDate);
        }
    }
}

void sortPatientsByAge(Patient*& head) {
    for (Patient* i = head; i && i->next; i = i->next) {
        Patient* minNode = i;
        for (Patient* j = i->next; j; j = j->next) {
            if (j->age < minNode->age) minNode = j;
        }
        if (minNode != i) {
            swap(i->id, minNode->id);
            swap(i->name, minNode->name);
            swap(i->age, minNode->age);
            swap(i->gender, minNode->gender);
            swap(i->address, minNode->address);
            swap(i->fee, minNode->fee);
            swap(i->admissionDate, minNode->admissionDate);
        }
    }
}

void sortPatientsByFee(Patient*& head) {
    for (Patient* i = head; i && i->next; i = i->next) {
        Patient* minNode = i;
        for (Patient* j = i->next; j; j = j->next) {
            if (j->fee < minNode->fee) minNode = j;
        }
        if (minNode != i) {
            swap(i->id, minNode->id);
            swap(i->name, minNode->name);
            swap(i->age, minNode->age);
            swap(i->gender, minNode->gender);
            swap(i->address, minNode->address);
            swap(i->fee, minNode->fee);
            swap(i->admissionDate, minNode->admissionDate);
        }
    }
}

void sortPatientsByAdmissionDate(Patient*& head) {
    for (Patient* i = head; i && i->next; i = i->next) {
        Patient* minNode = i;
        for (Patient* j = i->next; j; j = j->next) {
            if (j->admissionDate < minNode->admissionDate) minNode = j;
        }
        if (minNode != i) {
            swap(i->id, minNode->id);
            swap(i->name, minNode->name);
            swap(i->age, minNode->age);
            swap(i->gender, minNode->gender);
            swap(i->address, minNode->address);
            swap(i->fee, minNode->fee);
            swap(i->admissionDate, minNode->admissionDate);
        }
    }
}

Patient* getOldestPatient(Patient* head) {
    if (!head) return nullptr;
    Patient* maxNode = head;
    for (Patient* p = head->next; p; p = p->next) {
        if (p->age > maxNode->age) maxNode = p;
    }
    return maxNode;
}
Patient* getYoungestPatient(Patient* head) {
    if (!head) return nullptr;
    Patient* minNode = head;
    for (Patient* p = head->next; p; p = p->next) {
        if (p->age < minNode->age) minNode = p;
    }
    return minNode;
}
Patient* getHighestFeePatient(Patient* head) {
    if (!head) return nullptr;
    Patient* maxNode = head;
    for (Patient* p = head->next; p; p = p->next) {
        if (p->fee > maxNode->fee) maxNode = p;
    }
    return maxNode;
}
Patient* getLowestFeePatient(Patient* head) {
    if (!head) return nullptr;
    Patient* minNode = head;
    for (Patient* p = head->next; p; p = p->next) {
        if (p->fee < minNode->fee) minNode = p;
    }
    return minNode;
}
int countPatients(Patient* head) {
    int cnt = 0;
    while (head) { cnt++; head = head->next; }
    return cnt;
}
float totalFee(Patient* head) {
    float sum = 0;
    while (head) { sum += head->fee; head = head->next; }
    return sum;
}
float averageAge(Patient* head) {
    int cnt = 0, sum = 0;
    for (Patient* p = head; p; p = p->next) { sum += p->age; cnt++; }
    return cnt ? (float)sum / cnt : 0;
}
float averageFee(Patient* head) {
    int cnt = 0; float sum = 0;
    for (Patient* p = head; p; p = p->next) { sum += p->fee; cnt++; }
    return cnt ? sum / cnt : 0;
}
int countByGender(Patient* head, const string& gender) {
    int cnt = 0;
    for (Patient* p = head; p; p = p->next) if (p->gender == gender) cnt++;
    return cnt;
}
void statisticsByAge(Patient* head) {}
void statisticsByAddress(Patient* head) {}
void statisticsByGender(Patient* head) {}