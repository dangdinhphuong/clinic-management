#include "../include/medical_form.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

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

MedicalForm::MedicalForm() : fee(0), next(nullptr) {}
MedicalForm::MedicalForm(string formId, string patientId, string date, string diagnosis, float fee)
    : formId(formId), patientId(patientId), date(date), diagnosis(diagnosis), fee(fee), next(nullptr) {}

// Nhập thông tin phiếu khám và thêm vào danh sách
void inputMedicalForm(MedicalForm*& head) {
    MedicalForm* newNode = new MedicalForm();
    cout << "Nhap ma phieu: "; getline(cin, newNode->formId);
    cout << "Nhap ma benh nhan: "; getline(cin, newNode->patientId);
    cout << "Nhap ngay kham: "; getline(cin, newNode->date);
    cout << "Nhap chan doan: "; getline(cin, newNode->diagnosis);
    cout << "Nhap chi phi: "; cin >> newNode->fee; cin.ignore();
    newNode->next = nullptr;
    if (!head) head = newNode;
    else {
        MedicalForm* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// In danh sách phiếu khám
void printMedicalForms(MedicalForm* head) {
    cout << left << setw(10) << "MaPhieu" << setw(12) << "MaBN" << setw(12) << "NgayKham" << setw(20) << "ChanDoan" << setw(10) << "ChiPhi" << endl;
    while (head) {
        cout << left << setw(10) << head->formId << setw(12) << head->patientId << setw(12) << head->date << setw(20) << head->diagnosis << setw(10) << head->fee << endl;
        head = head->next;
    }
}

// Sửa thông tin phiếu khám theo mã
void editMedicalForm(MedicalForm* head, const string& formId) {
    MedicalForm* f = findMedicalFormById(head, formId);
    if (!f) {
        cout << "Khong tim thay phieu kham!\n";
        return;
    }
    cout << "Nhap lai thong tin (bo qua neu khong sua):\n";
    string tmp;
    cout << "Ma benh nhan (" << f->patientId << "): "; getline(cin, tmp); if (!tmp.empty()) f->patientId = tmp;
    cout << "Ngay kham (" << f->date << "): "; getline(cin, tmp); if (!tmp.empty()) f->date = tmp;
    cout << "Chan doan (" << f->diagnosis << "): "; getline(cin, tmp); if (!tmp.empty()) f->diagnosis = tmp;
    cout << "Chi phi (" << f->fee << "): "; getline(cin, tmp); if (!tmp.empty()) f->fee = stof(tmp);
    cout << "Da cap nhat thong tin.\n";
}

// Xóa phiếu khám theo mã
void deleteMedicalForm(MedicalForm*& head, const string& formId) {
    MedicalForm* prev = nullptr;
    MedicalForm* curr = head;
    while (curr && curr->formId != formId) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        cout << "Khong tim thay phieu kham!\n";
        return;
    }
    if (!prev) head = curr->next;
    else prev->next = curr->next;
    delete curr;
    cout << "Da xoa phieu kham.\n";
}

// Tìm phiếu khám theo mã phiếu
MedicalForm* findMedicalFormById(MedicalForm* head, const string& formId) {
    while (head) {
        if (head->formId == formId) return head;
        head = head->next;
    }
    return nullptr;
}

// Tìm phiếu khám theo mã bệnh nhân
MedicalForm* findMedicalFormByPatientId(MedicalForm* head, const string& patientId) {
    while (head) {
        if (head->patientId == patientId) return head;
        head = head->next;
    }
    return nullptr;
}

void sortMedicalFormsByDate(MedicalForm*& head) {
    for (MedicalForm* i = head; i && i->next; i = i->next) {
        MedicalForm* minNode = i;
        for (MedicalForm* j = i->next; j; j = j->next) {
            if (j->date < minNode->date) minNode = j;
        }
        if (minNode != i) {
            swap(i->formId, minNode->formId);
            swap(i->patientId, minNode->patientId);
            swap(i->date, minNode->date);
            swap(i->diagnosis, minNode->diagnosis);
            swap(i->fee, minNode->fee);
        }
    }
}

void sortMedicalFormsByFee(MedicalForm*& head) {
    for (MedicalForm* i = head; i && i->next; i = i->next) {
        MedicalForm* minNode = i;
        for (MedicalForm* j = i->next; j; j = j->next) {
            if (j->fee < minNode->fee) minNode = j;
        }
        if (minNode != i) {
            swap(i->formId, minNode->formId);
            swap(i->patientId, minNode->patientId);
            swap(i->date, minNode->date);
            swap(i->diagnosis, minNode->diagnosis);
            swap(i->fee, minNode->fee);
        }
    }
}

void sortMedicalFormsByFormId(MedicalForm*& head) {
    for (MedicalForm* i = head; i && i->next; i = i->next) {
        MedicalForm* minNode = i;
        for (MedicalForm* j = i->next; j; j = j->next) {
            if (j->formId < minNode->formId) minNode = j;
        }
        if (minNode != i) {
            swap(i->formId, minNode->formId);
            swap(i->patientId, minNode->patientId);
            swap(i->date, minNode->date);
            swap(i->diagnosis, minNode->diagnosis);
            swap(i->fee, minNode->fee);
        }
    }
}

void sortMedicalFormsByPatientId(MedicalForm*& head) {
    for (MedicalForm* i = head; i && i->next; i = i->next) {
        MedicalForm* minNode = i;
        for (MedicalForm* j = i->next; j; j = j->next) {
            if (j->patientId < minNode->patientId) minNode = j;
        }
        if (minNode != i) {
            swap(i->formId, minNode->formId);
            swap(i->patientId, minNode->patientId);
            swap(i->date, minNode->date);
            swap(i->diagnosis, minNode->diagnosis);
            swap(i->fee, minNode->fee);
        }
    }
}

MedicalForm* getHighestFeeForm(MedicalForm* head) {
    if (!head) return nullptr;
    MedicalForm* maxNode = head;
    for (MedicalForm* p = head->next; p; p = p->next) {
        if (p->fee > maxNode->fee) maxNode = p;
    }
    return maxNode;
}
MedicalForm* getLowestFeeForm(MedicalForm* head) {
    if (!head) return nullptr;
    MedicalForm* minNode = head;
    for (MedicalForm* p = head->next; p; p = p->next) {
        if (p->fee < minNode->fee) minNode = p;
    }
    return minNode;
}
int countMedicalForms(MedicalForm* head) {
    int cnt = 0;
    while (head) { cnt++; head = head->next; }
    return cnt;
}
float totalMedicalFormFee(MedicalForm* head) {
    float sum = 0;
    while (head) { sum += head->fee; head = head->next; }
    return sum;
}
float averageMedicalFormFee(MedicalForm* head) {
    int cnt = 0; float sum = 0;
    for (MedicalForm* p = head; p; p = p->next) { sum += p->fee; cnt++; }
    return cnt ? sum / cnt : 0;
}
void statisticsFormsByDate(MedicalForm* head) {}
void statisticsFormsByDiagnosis(MedicalForm* head) {}
