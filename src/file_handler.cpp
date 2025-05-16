// Ghi danh sách bệnh nhân ra file
void savePatientsToFile(Patient* head, const string& filename) {
    ofstream file(filename);
    while (head) {
        file << head->id << "," << head->name << "," << head->age << "," << head->gender << "\n";
        head = head->next;
    }
    file.close();
    cout << "Da ghi danh sach benh nhan vao file.\n";
}

// Đọc danh sách bệnh nhân từ file
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

void savePatientsToFile(Patient* head, const string& filename) {
    ofstream file(filename);
    while (head) {
        file << head->id << "," << head->name << "," << head->age << "," << head->gender << "\n";
        head = head->next;
    }
    file.close();
    cout << "Da ghi danh sach benh nhan vao file.\n";
}

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
