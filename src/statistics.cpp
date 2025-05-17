#include "../include/statistics.h"
#include <iostream>
#include <map>
using namespace std;

void statisticsByAge(Patient* head) {
    int below18 = 0, from18to40 = 0, above40 = 0;
    for (Patient* p = head; p; p = p->next) {
        if (p->age < 18) below18++;
        else if (p->age <= 40) from18to40++;
        else above40++;
    }
    cout << "<18 tuoi: " << below18 << " | 18-40 tuoi: " << from18to40 << " | >40 tuoi: " << above40 << endl;
}

void statisticsByAddress(Patient* head) {
    map<string, int> addrCount;
    for (Patient* p = head; p; p = p->next) addrCount[p->address]++;
    cout << "Thong ke theo dia chi:\n";
    for (auto& kv : addrCount) cout << kv.first << ": " << kv.second << endl;
}

void statisticsByGender(Patient* head) {
    int male = 0, female = 0, other = 0;
    for (Patient* p = head; p; p = p->next) {
        if (p->gender == "Nam") male++;
        else if (p->gender == "Nu") female++;
        else other++;
    }
    cout << "Nam: " << male << " | Nu: " << female << " | Khac: " << other << endl;
}

void statisticsPatients(Patient* head) {
    cout << "--- Thong ke benh nhan ---\n";
    cout << "Tong so: " << countPatients(head) << endl;
    cout << "Trung binh tuoi: " << averageAge(head) << endl;
    cout << "Tong chi phi: " << totalFee(head) << endl;
    cout << "Trung binh chi phi: " << averageFee(head) << endl;
    statisticsByGender(head);
    statisticsByAge(head);
    statisticsByAddress(head);
}

void statisticsFormsByDate(MedicalForm* head) {
    map<string, int> dateCount;
    for (MedicalForm* f = head; f; f = f->next) dateCount[f->date]++;
    cout << "Thong ke so phieu theo ngay:\n";
    for (auto& kv : dateCount) cout << kv.first << ": " << kv.second << endl;
}

void statisticsFormsByDiagnosis(MedicalForm* head) {
    map<string, int> diagCount;
    for (MedicalForm* f = head; f; f = f->next) diagCount[f->diagnosis]++;
    cout << "Thong ke theo chan doan:\n";
    for (auto& kv : diagCount) cout << kv.first << ": " << kv.second << endl;
}

void statisticsMedicalForms(MedicalForm* head) {
    cout << "--- Thong ke phieu kham ---\n";
    cout << "Tong so: " << countMedicalForms(head) << endl;
    cout << "Tong chi phi: " << totalMedicalFormFee(head) << endl;
    cout << "Trung binh chi phi: " << averageMedicalFormFee(head) << endl;
    statisticsFormsByDate(head);
    statisticsFormsByDiagnosis(head);
}
