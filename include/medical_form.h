// ------------------- Cấu trúc phiếu khám -------------------
struct MedicalForm {
    string ;
    string patientId;
    string date;
    string diagnosis;
    MedicalForm* next;
};
// ------------------- Hàm nhập phiếu khám -------------------
void inputForms(MedicalForm*& head, int n) {
    for (int i = 0; i < n; ++i) {
        MedicalForm* newNode = new MedicalForm;
        cout << "Nhap thong tin phieu kham thu " << i + 1 << ":\n";
        cout << "Ma phieu: "; getline(cin, newNode->formId);
        cout << "Ma benh nhan: "; getline(cin, newNode->patientId);
        cout << "Ngay kham: "; getline(cin, newNode->date);
        cout << "Chuan doan: "; getline(cin, newNode->diagnosis);
        newNode->next = nullptr;

        if (!head) head = newNode;
        else {
            MedicalForm* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
}
