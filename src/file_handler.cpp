#include "../include/file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

// Ghi danh sách phiếu khám ra file
void saveFormsToFile(MedicalForm* head, const string& filename) {
    ofstream file(filename);
    while (head) {
        file << head->formId << "," << head->patientId << ","
             << head->date << "," << head->diagnosis << "\n";
        head = head->next;
    }
    file.close();
    cout << "Da ghi danh sach phieu kham vao file.\n";
}

// Đọc danh sách phiếu khám từ file
void loadFormsFromFile(MedicalForm*& head, const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        MedicalForm* newNode = new MedicalForm;
        getline(ss, newNode->formId, ',');
        getline(ss, newNode->patientId, ',');
        getline(ss, newNode->date, ',');
        getline(ss, newNode->diagnosis);
        newNode->next = nullptr;

        if (!head) head = newNode;
        else {
            MedicalForm* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
    file.close();
    cout << "Da doc danh sach phieu kham tu file.\n";
}

// Ghi danh sách bệnh nhân ra file
void savePatientsToFile(Patient* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Khong mo duoc file de ghi!\n";
        return;
    }
    while (head) {
        file << head->id << "," << head->name << "," << head->age << "," << head->gender << "," << head->address << "," << head->fee << "," << head->admissionDate << "\n";
        head = head->next;
    }
    file.close();
    cout << "Da ghi danh sach benh nhan vao file.\n";
}

// Đọc danh sách bệnh nhân từ file
void loadPatientsFromFile(Patient*& head, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Khong mo duoc file de doc!\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, ageStr, gender, address, feeStr, admissionDate;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, gender, ',');
        getline(ss, address, ',');
        getline(ss, feeStr, ',');
        getline(ss, admissionDate);
        Patient* newNode = new Patient(id, name, stoi(ageStr), gender, address, stof(feeStr), admissionDate);
        newNode->next = nullptr;
        if (!head) head = newNode;
        else {
            Patient* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
    file.close();
    cout << "Da doc danh sach benh nhan tu file.\n";
}

void saveMedicalFormsToFile(MedicalForm* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Khong mo duoc file de ghi!\n";
        return;
    }
    while (head) {
        file << head->formId << "," << head->patientId << "," << head->date << "," << head->diagnosis << "," << head->fee << "\n";
        head = head->next;
    }
    file.close();
    cout << "Da ghi danh sach phieu kham vao file.\n";
}

void loadMedicalFormsFromFile(MedicalForm*& head, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Khong mo duoc file de doc!\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string formId, patientId, date, diagnosis, feeStr;
        getline(ss, formId, ',');
        getline(ss, patientId, ',');
        getline(ss, date, ',');
        getline(ss, diagnosis, ',');
        getline(ss, feeStr);
        MedicalForm* newNode = new MedicalForm(formId, patientId, date, diagnosis, stof(feeStr));
        newNode->next = nullptr;
        if (!head) head = newNode;
        else {
            MedicalForm* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
    file.close();
    cout << "Da doc danh sach phieu kham tu file.\n";
}
