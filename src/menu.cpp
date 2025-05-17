#include "../include/menu.h"
#include "../include/patient.h"
#include "../include/medical_form.h"
#include "../include/file_handler.h"
#include "../include/statistics.h"
#include <iostream>
using namespace std;

void patientMenu(Patient*& patientHead) {
    int choice;
    do {
        cout << "\n--- MENU BENH NHAN ---\n";
        cout << "1. Nhap benh nhan\n";
        cout << "2. In danh sach\n";
        cout << "3. Luu file\n";
        cout << "4. Doc file\n";
        cout << "5. Sua benh nhan\n";
        cout << "6. Xoa benh nhan\n";
        cout << "7. Tim theo ma\n";
        cout << "8. Tim theo ten\n";
        cout << "9. Sap xep theo ten\n";
        cout << "10. Sap xep theo tuoi\n";
        cout << "11. Sap xep theo chi phi\n";
        cout << "12. Sap xep theo ngay nhap vien\n";
        cout << "13. Thong ke\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: "; cin >> choice; cin.ignore();
        string id, name;
        switch (choice) {
            case 1: inputPatient(patientHead); break;
            case 2: printPatients(patientHead); break;
            case 3: savePatientsToFile(patientHead, "data/patients.txt"); break;
            case 4: loadPatientsFromFile(patientHead, "data/patients.txt"); break;
            case 5: cout << "Nhap ma: "; getline(cin, id); editPatient(patientHead, id); break;
            case 6: cout << "Nhap ma: "; getline(cin, id); deletePatient(patientHead, id); break;
            case 7: cout << "Nhap ma: "; getline(cin, id); { Patient* p = findPatientById(patientHead, id); if (p) printPatients(p); else cout << "Khong tim thay!\n"; } break;
            case 8: cout << "Nhap ten: "; getline(cin, name); { Patient* p = findPatientByName(patientHead, name); if (p) printPatients(p); else cout << "Khong tim thay!\n"; } break;
            case 9: sortPatientsByName(patientHead); cout << "Da sap xep theo ten.\n"; break;
            case 10: sortPatientsByAge(patientHead); cout << "Da sap xep theo tuoi.\n"; break;
            case 11: sortPatientsByFee(patientHead); cout << "Da sap xep theo chi phi.\n"; break;
            case 12: sortPatientsByAdmissionDate(patientHead); cout << "Da sap xep theo ngay nhap vien.\n"; break;
            case 13: statisticsPatients(patientHead); break;
        }
    } while (choice != 0);
}

void medicalFormMenu(MedicalForm*& formHead) {
    int choice;
    do {
        cout << "\n--- MENU PHIEU KHAM ---\n";
        cout << "1. Nhap phieu kham\n";
        cout << "2. In danh sach\n";
        cout << "3. Luu file\n";
        cout << "4. Doc file\n";
        cout << "5. Sua phieu kham\n";
        cout << "6. Xoa phieu kham\n";
        cout << "7. Tim theo ma phieu\n";
        cout << "8. Tim theo ma benh nhan\n";
        cout << "9. Sap xep theo ngay\n";
        cout << "10. Sap xep theo chi phi\n";
        cout << "11. Sap xep theo ma phieu\n";
        cout << "12. Sap xep theo ma benh nhan\n";
        cout << "13. Thong ke\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: "; cin >> choice; cin.ignore();
        string id;
        switch (choice) {
            case 1: inputMedicalForm(formHead); break;
            case 2: printMedicalForms(formHead); break;
            case 3: saveMedicalFormsToFile(formHead, "data/medical_forms.txt"); break;
            case 4: loadMedicalFormsFromFile(formHead, "data/medical_forms.txt"); break;
            case 5: cout << "Nhap ma phieu: "; getline(cin, id); editMedicalForm(formHead, id); break;
            case 6: cout << "Nhap ma phieu: "; getline(cin, id); deleteMedicalForm(formHead, id); break;
            case 7: cout << "Nhap ma phieu: "; getline(cin, id); { MedicalForm* f = findMedicalFormById(formHead, id); if (f) printMedicalForms(f); else cout << "Khong tim thay!\n"; } break;
            case 8: cout << "Nhap ma benh nhan: "; getline(cin, id); { MedicalForm* f = findMedicalFormByPatientId(formHead, id); if (f) printMedicalForms(f); else cout << "Khong tim thay!\n"; } break;
            case 9: sortMedicalFormsByDate(formHead); cout << "Da sap xep theo ngay.\n"; break;
            case 10: sortMedicalFormsByFee(formHead); cout << "Da sap xep theo chi phi.\n"; break;
            case 11: sortMedicalFormsByFormId(formHead); cout << "Da sap xep theo ma phieu.\n"; break;
            case 12: sortMedicalFormsByPatientId(formHead); cout << "Da sap xep theo ma benh nhan.\n"; break;
            case 13: statisticsMedicalForms(formHead); break;
        }
    } while (choice != 0);
}

void showMainMenu() {
    Patient* patientHead = nullptr;
    MedicalForm* formHead = nullptr;
    int choice;
    do {
        cout << "\n===== MENU CHINH =====\n";
        cout << "1. Quan ly benh nhan\n";
        cout << "2. Quan ly phieu kham\n";
        cout << "3. Thong ke benh nhan\n";
        cout << "4. Thong ke phieu kham\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice; cin.ignore();
        switch (choice) {
            case 1:
                patientMenu(patientHead);
                break;
            case 2:
                medicalFormMenu(formHead);
                break;
            case 3:
                statisticsPatients(patientHead);
                break;
            case 4:
                statisticsMedicalForms(formHead);
                break;
        }
    } while (choice != 0);
}
