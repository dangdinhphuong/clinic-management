#include "../include/patient.h"
#include "../include/medical_form.h"
#include <iostream>

using namespace std;

int main() {
    Patient* patientHead = nullptr;
    MedicalForm* formHead = nullptr;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach benh nhan\n";
        cout << "2. In danh sach benh nhan\n";
        cout << "3. Ghi danh sach benh nhan vao file\n";
        cout << "4. Doc danh sach benh nhan tu file\n";
        cout << "5. Nhap danh sach phieu kham\n";
        cout << "6. In danh sach phieu kham\n";
        cout << "7. Ghi danh sach phieu kham vao file\n";
        cout << "8. Doc danh sach phieu kham tu file\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice; cin.ignore();

        int n;
        switch (choice) {
            case 1:
                cout << "So benh nhan: "; cin >> n; cin.ignore();
                inputPatients(patientHead, n);
                break;
            case 2:
                printPatients(patientHead);
                break;
            case 3:
                savePatientsToFile(patientHead, "data/patients.txt");
                break;
            case 4:
                loadPatientsFromFile(patientHead, "data/patients.txt");
                break;
            case 5:
                cout << "So phieu kham: "; cin >> n; cin.ignore();
                inputForms(formHead, n);
                break;
            case 6:
                printForms(formHead);
                break;
            case 7:
                saveFormsToFile(formHead, "data/forms.txt");
                break;
            case 8:
                loadFormsFromFile(formHead, "data/forms.txt");
                break;
        }
    } while (choice != 0);

    return 0;
}
