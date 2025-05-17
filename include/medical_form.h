#ifndef MEDICAL_FORM_H
#define MEDICAL_FORM_H

#include <string>
using namespace std;

class MedicalForm {
public:
    string formId;
    string patientId;
    string date;
    string diagnosis;
    float fee;
    MedicalForm* next;

    MedicalForm();
    MedicalForm(string formId, string patientId, string date, string diagnosis, float fee);
};

// Các hàm thao tác với danh sách phiếu khám
void inputMedicalForm(MedicalForm*& head);
void printMedicalForms(MedicalForm* head);
void editMedicalForm(MedicalForm* head, const string& formId);
void deleteMedicalForm(MedicalForm*& head, const string& formId);
MedicalForm* findMedicalFormById(MedicalForm* head, const string& formId);
MedicalForm* findMedicalFormByPatientId(MedicalForm* head, const string& patientId);
void sortMedicalFormsByDate(MedicalForm*& head);
void sortMedicalFormsByFee(MedicalForm*& head);
void sortMedicalFormsByFormId(MedicalForm*& head);
void sortMedicalFormsByPatientId(MedicalForm*& head);
MedicalForm* getHighestFeeForm(MedicalForm* head);
MedicalForm* getLowestFeeForm(MedicalForm* head);
int countMedicalForms(MedicalForm* head);
float totalMedicalFormFee(MedicalForm* head);
float averageMedicalFormFee(MedicalForm* head);
void statisticsFormsByDate(MedicalForm* head);
void statisticsFormsByDiagnosis(MedicalForm* head);

#endif
