#include <iostream>
#include "../structures/LinkedList.h"
#include "../models/Doctor.h"
#include "../models/Patient.h"

using namespace std;

void menu() {
    LinkedList<Doctor> doctors;
    LinkedList<Patient> patients;
    int choice;
    do {
        cout << "\n====== MENU ======" << endl;
        cout << "1. Nhap bac si\n2. Nhap benh nhan\n3. In danh sach\n4. Luu doc file\n5. Them/Sua/Xoa\n6. Tim kiem\n7. Sap xep\n8. Lon nho\n9. Tong/TB/Dem\n10. Thong ke\n0. Thoat\nChon: ";
        cin >> choice;
        cin.ignore();
        string id;
        switch (choice) {
        case 1: {
            Doctor d;
            cout << "ID: ";
            getline(cin, d.id);
            cout << "Ten: ";
            getline(cin, d.name);
            cout << "Chuyen khoa: ";
            getline(cin, d.specialization);
            cout << "Tuoi: ";
            cin >> d.age;
            cin.ignore();
            doctors.insert(d);
            doctors.saveToFile("doctors.txt");
            break;
        }
        case 2: {
            Patient p;
            cout << "ID: ";
            getline(cin, p.id);
            cout << "Ten: ";
            getline(cin, p.name);
            cout << "Tuoi: ";
            cin >> p.age;
            cin.ignore();
            cout << "Benh: ";
            getline(cin, p.disease);
            cout << "ID bac si: ";
            getline(cin, p.doctorId);
            patients.insert(p);
            patients.saveToFile("patients.txt");
            break;
        }
        case 3:
            doctors.print();
            patients.print();
            break;
        case 4:
            doctors.loadFromFile("doctors.txt");
            doctors.saveToFile("doctors.txt");

            patients.loadFromFile("patients.txt");
            patients.saveToFile("patients.txt");

            doctors.clear();
            patients.clear();

            cout << "Luu + doc lai file hoan tat.\n";
            break;
        case 5:
            cout << "Nhap ID can sua/xoa: ";
            getline(cin, id);
            doctors.update(id);
            doctors.remove(id);
            patients.update(id);
            patients.remove(id);
            break;
        case 6:
            cout << "Tim kiem ID: ";
            getline(cin, id);
            // Tìm kiếm có thể triển khai thêm
            break;
        case 7:
            doctors.sortList(1);
            patients.sortList(2);
            break;
        case 8:
            cout << "Doctor max tuoi:\n";
            doctors.printOne(doctors.getMaxAge());
            cout << "Patient min tuoi:\n";
            patients.printOne(patients.getMinAge());
            break;
        case 9:
            cout << "TB tuoi BS: " << doctors.getAvgAge() << endl;
            cout << "So BN > 60: " << patients.countByCondition([](Patient p) {
                return p.age > 60;
            }) << endl;
            break;
        case 10:
            cout << "BN benh tieu duong: " << patients.countByCondition([](Patient p) {
                return p.disease == "tieu duong";
            }) << endl;
            break;
        }
    } while (choice != 0);
}
