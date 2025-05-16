// ------------------- Hàm ghi bệnh nhân ra file -------------------
void savePatientsToFile(Patient* head, const string& filename) {
    ofstream file(filename);
    while (head) {
        file << head->id << "," << head->name << "," << head->age << "," << head->gender << "\n";
        head = head->next;
    }
    file.close();
    cout << "Da ghi danh sach benh nhan vao file.\n";
}

// ------------------- Hàm đọc bệnh nhân từ file -------------------
void loadPatientsFromFile(Patient*& head, const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Patient* newNode = new Patient;
        string ageStr;
        getline(ss, newNode->id, ',');
        getline(ss, newNode->name, ',');
        getline(ss, ageStr, ',');
        newNode->age = stoi(ageStr);
        getline(ss, newNode->gender);
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
// ------------------- Hàm ghi phiếu khám ra file -------------------
void saveFormsToFile(MedicalForm* head, const string& filename) {
    ofstream file(filename);
    while (head) {
        file << head->formId << "," << head->patientId << "," << head->date << "," << head->diagnosis << "\n";
        head = head->next;
    }
    file.close();
    cout << "Da ghi danh sach phieu kham vao file.\n";
}

// ------------------- Hàm đọc phiếu khám từ file -------------------
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
