#pragma once

// === Thêm phần tử vào danh sách ===
template <typename T>
void LinkedList<T>::insert(T x) {
    Node<T>* newNode = new Node<T>{x, nullptr};
    if (!head)
        head = newNode;
    else {
        Node<T>* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// === Xóa phần tử theo ID ===
template <typename T>
void LinkedList<T>::remove(string id) {
    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    while (temp) {
        if (getId(temp->data) == id) {
            if (prev)
                prev->next = temp->next;
            else
                head = temp->next;
            delete temp;
            cout << "Da xoa.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Khong tim thay doi tuong can xoa.\n";
}

// === Cập nhật thông tin theo ID ===
template <typename T>
void LinkedList<T>::update(string id) {
    Node<T>* temp = head;
    while (temp) {
        if (getId(temp->data) == id) {
            cout << "Cap nhat thong tin:\n";
            updateObject(temp->data);
            return;
        }
        temp = temp->next;
    }
    cout << "Khong tim thay.\n";
}

// === In toàn bộ danh sách ===
template <typename T>
void LinkedList<T>::print() {
    Node<T>* temp = head;
    while (temp) {
        printObject(temp->data);
        temp = temp->next;
    }
}

// === In một đối tượng ===
template <typename T>
void LinkedList<T>::printOne(const T& obj) {
    printObject(obj);
}

// === Lưu danh sách vào file ===
template <typename T>
void LinkedList<T>::saveToFile(string filename) {
    ofstream file(filename);
    Node<T>* temp = head;
    while (temp) {
        saveObject(file, temp->data);
        temp = temp->next;
    }
    file.close();
}

// === Đọc danh sách từ file ===
template <typename T>
void LinkedList<T>::loadFromFile(string filename) {
    ifstream file(filename);
    T obj;
    while (loadObject(file, obj)) {
        insert(obj);
    }
    file.close();
}

// === Sắp xếp danh sách theo các tiêu chí ===
template <typename T>
void LinkedList<T>::sortList(int type) {
    vector<T> vec = toVector();
    switch (type) {
        case 1:
            sort(vec.begin(), vec.end(), [](T a, T b) {
                return getName(a) < getName(b);
            });
            break;
        case 2:
            sort(vec.begin(), vec.end(), [](T a, T b) {
                return getAge(a) < getAge(b);
            });
            break;
        case 3:
            sort(vec.begin(), vec.end(), [](T a, T b) {
                return getId(a) < getId(b);
            });
            break;
        case 4:
            sort(vec.begin(), vec.end(), [](T a, T b) {
                return getCustom(a) < getCustom(b);
            });
            break;
    }
    fromVector(vec);
}

// === Trả về phần tử có tuổi lớn nhất ===
template <typename T>
T LinkedList<T>::getMaxAge() {
    Node<T>* temp = head;
    T max = temp->data;
    while (temp) {
        if (getAge(temp->data) > getAge(max))
            max = temp->data;
        temp = temp->next;
    }
    return max;
}

// === Trả về phần tử có tuổi nhỏ nhất ===
template <typename T>
T LinkedList<T>::getMinAge() {
    Node<T>* temp = head;
    T min = temp->data;
    while (temp) {
        if (getAge(temp->data) < getAge(min))
            min = temp->data;
        temp = temp->next;
    }
    return min;
}

// === Tính tuổi trung bình ===
template <typename T>
double LinkedList<T>::getAvgAge() {
    int count = 0, sum = 0;
    Node<T>* temp = head;
    while (temp) {
        sum += getAge(temp->data);
        count++;
        temp = temp->next;
    }
    return count ? (double)sum / count : 0;
}

// === Đếm số phần tử thỏa điều kiện ===
template <typename T>
int LinkedList<T>::countByCondition(function<bool(T)> cond) {
    int count = 0;
    Node<T>* temp = head;
    while (temp) {
        if (cond(temp->data))
            count++;
        temp = temp->next;
    }
    return count;
}

// === Chuyển danh sách liên kết thành vector ===
template <typename T>
vector<T> LinkedList<T>::toVector() {
    vector<T> v;
    Node<T>* temp = head;
    while (temp) {
        v.push_back(temp->data);
        temp = temp->next;
    }
    return v;
}

// === Tạo danh sách từ vector ===
template <typename T>
void LinkedList<T>::fromVector(const vector<T>& vec) {
    head = nullptr;
    for (const auto& item : vec)
        insert(item);
}

// === Xóa toàn bộ danh sách ===
template <typename T>
void LinkedList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// ==== Các hàm hỗ trợ xử lý Doctor/Patient (dạng static hoặc overload) ====
template <typename T>
string LinkedList<T>::getId(Doctor d) { return d.id; }

template <typename T>
string LinkedList<T>::getId(Patient p) { return p.id; }

template <typename T>
string LinkedList<T>::getName(Doctor d) { return d.name; }

template <typename T>
string LinkedList<T>::getName(Patient p) { return p.name; }

template <typename T>
int LinkedList<T>::getAge(Doctor d) { return d.age; }

template <typename T>
int LinkedList<T>::getAge(Patient p) { return p.age; }

template <typename T>
string LinkedList<T>::getCustom(Doctor d) { return d.specialization; }

template <typename T>
string LinkedList<T>::getCustom(Patient p) { return p.disease; }

// === In thông tin Doctor ===
template <typename T>
void LinkedList<T>::printObject(Doctor d) {
    cout << left << setw(10) << d.id << setw(20) << d.name << setw(20) << d.specialization << d.age << endl;
}

// === In thông tin Patient ===
template <typename T>
void LinkedList<T>::printObject(Patient p) {
    cout << left << setw(10) << p.id << setw(20) << p.name << setw(10) << p.age << setw(20) << p.disease << p.doctorId << endl;
}

// === Ghi Doctor ra file ===
template <typename T>
void LinkedList<T>::saveObject(ofstream& file, Doctor d) {
    file << d.id << "," << d.name << "," << d.specialization << "," << d.age << "\n";
}

// === Ghi Patient ra file ===
template <typename T>
void LinkedList<T>::saveObject(ofstream& file, Patient p) {
    file << p.id << "," << p.name << "," << p.age << "," << p.disease << "," << p.doctorId << "\n";
}

// === Đọc Doctor từ file ===
template <typename T>
bool LinkedList<T>::loadObject(ifstream& file, Doctor& d) {
    return getline(file, d.id, ',') && getline(file, d.name, ',') && getline(file, d.specialization, ',') && (file >> d.age).ignore();
}

// === Đọc Patient từ file ===
template <typename T>
bool LinkedList<T>::loadObject(ifstream& file, Patient& p) {
    string ageStr;
    return getline(file, p.id, ',') && getline(file, p.name, ',') && getline(file, ageStr, ',') && getline(file, p.disease, ',') && getline(file, p.doctorId) && (p.age = stoi(ageStr), true);
}

// === Cập nhật thông tin Doctor ===
template <typename T>
void LinkedList<T>::updateObject(Doctor& d) {
    cout << "Ten moi: ";
    getline(cin, d.name);
    cout << "Chuyen khoa moi: ";
    getline(cin, d.specialization);
    cout << "Tuoi moi: ";
    cin >> d.age;
    cin.ignore();
}

// === Cập nhật thông tin Patient ===
template <typename T>
void LinkedList<T>::updateObject(Patient& p) {
    cout << "Ten moi: ";
    getline(cin, p.name);
    cout << "Tuoi moi: ";
    cin >> p.age;
    cin.ignore();
    cout << "Benh moi: ";
    getline(cin, p.disease);
    cout << "ID Bac si moi: ";
    getline(cin, p.doctorId);
}
