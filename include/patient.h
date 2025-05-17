#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;

class Patient {
public:
    string id;
    string name;
    int age;
    string gender;
    string address;
    float fee;
    string admissionDate;
    Patient* next;

    Patient();
    Patient(string id, string name, int age, string gender, string address, float fee, string admissionDate);
};

// Các hàm thao tác với danh sách bệnh nhân
void inputPatient(Patient*& head);
void printPatients(Patient* head);
void editPatient(Patient* head, const string& id);
void deletePatient(Patient*& head, const string& id);
Patient* findPatientById(Patient* head, const string& id);
Patient* findPatientByName(Patient* head, const string& name);
void sortPatientsByName(Patient*& head);
void sortPatientsByAge(Patient*& head);
void sortPatientsByFee(Patient*& head);
void sortPatientsByAdmissionDate(Patient*& head);
Patient* getOldestPatient(Patient* head);
Patient* getYoungestPatient(Patient* head);
Patient* getHighestFeePatient(Patient* head);
Patient* getLowestFeePatient(Patient* head);
int countPatients(Patient* head);
float totalFee(Patient* head);
float averageAge(Patient* head);
float averageFee(Patient* head);
int countByGender(Patient* head, const string& gender);
void statisticsByAge(Patient* head);
void statisticsByAddress(Patient* head);
void statisticsByGender(Patient* head);

#endif // PATIENT_H