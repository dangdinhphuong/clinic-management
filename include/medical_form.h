#include <string>
using namespace std;

// Cấu trúc phiếu khám bệnh
struct MedicalForm {
    string formId;
    string patientId;
    string date;
    string diagnosis;
    MedicalForm* next;
};

// Khai báo các hàm xử lý phiếu khám
void inputForms(MedicalForm*& head, int n);
void printForms(MedicalForm* head);
void saveFormsToFile(MedicalForm* head, const string& filename);
void loadFormsFromFile(MedicalForm*& head, const string& filename);

#endif
