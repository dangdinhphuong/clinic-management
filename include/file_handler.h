#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include "patient.h"
#include "medical_form.h"
#include <string>
using namespace std;

// Hàm đọc/ghi file cho bệnh nhân
void savePatientsToFile(Patient* head, const string& filename);
void loadPatientsFromFile(Patient*& head, const string& filename);

// Hàm đọc/ghi file cho phiếu khám
void saveMedicalFormsToFile(MedicalForm* head, const string& filename);
void loadMedicalFormsFromFile(MedicalForm*& head, const string& filename);

#endif // FILE_HANDLER_H
