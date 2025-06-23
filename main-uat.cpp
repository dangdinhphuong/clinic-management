#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

struct Doctor
{
    string id;
    string name;
    string specialization;
    int age;
};

struct Patient
{
    string id;
    string name;
    int age;
    string disease;
    string doctorId;
};

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head = nullptr;

    void insert(T x)
    {
        Node<T> *newNode = new Node<T>{x, nullptr};
        if (!head)
            head = newNode;
        else
        {
            Node<T> *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void remove(string id)
    {
        Node<T> *temp = head;
        Node<T> *prev = nullptr;
        while (temp)
        {
            if (getId(temp->data) == id)
            {
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

    void update(string id)
    {
        Node<T> *temp = head;
        while (temp)
        {
            if (getId(temp->data) == id)
            {
                cout << "Cap nhat thong tin:\n";
                updateObject(temp->data);
                return;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay.\n";
    }

    void print()
    {
        Node<T> *temp = head;
        while (temp)
        {
            printObject(temp->data);
            temp = temp->next;
        }
    }

    void printOne(const T &obj)
    {
        printObject(obj);
    }

    void saveToFile(string filename)
    {
        ofstream file(filename);
        Node<T> *temp = head;
        while (temp)
        {
            saveObject(file, temp->data);
            temp = temp->next;
        }
        file.close();
    }

    void loadFromFile(string filename)
    {
        ifstream file(filename);
        T obj;
        while (loadObject(file, obj))
        {
            insert(obj);
        }
        file.close();
    }

    void sortList(int type)
    {
        vector<T> vec = toVector();
        switch (type)
        {
        case 1:
            sort(vec.begin(), vec.end(), [](T a, T b)
                 { return getName(a) < getName(b); });
            break;
        case 2:
            sort(vec.begin(), vec.end(), [](T a, T b)
                 { return getAge(a) < getAge(b); });
            break;
        case 3:
            sort(vec.begin(), vec.end(), [](T a, T b)
                 { return getId(a) < getId(b); });
            break;
        case 4:
            sort(vec.begin(), vec.end(), [](T a, T b)
                 { return getCustom(a) < getCustom(b); });
            break;
        }
        fromVector(vec);
    }

    T getMaxAge()
    {
        Node<T> *temp = head;
        T max = temp->data;
        while (temp)
        {
            if (getAge(temp->data) > getAge(max))
                max = temp->data;
            temp = temp->next;
        }
        return max;
    }

    T getMinAge()
    {
        Node<T> *temp = head;
        T min = temp->data;
        while (temp)
        {
            if (getAge(temp->data) < getAge(min))
                min = temp->data;
            temp = temp->next;
        }
        return min;
    }

    double getAvgAge()
    {
        int count = 0, sum = 0;
        Node<T> *temp = head;
        while (temp)
        {
            sum += getAge(temp->data);
            count++;
            temp = temp->next;
        }
        return count ? (double)sum / count : 0;
    }

    int countByCondition(function<bool(T)> cond)
    {
        int count = 0;
        Node<T> *temp = head;
        while (temp)
        {
            if (cond(temp->data))
                count++;
            temp = temp->next;
        }
        return count;
    }

    vector<T> toVector()
    {
        vector<T> v;
        Node<T> *temp = head;
        while (temp)
        {
            v.push_back(temp->data);
            temp = temp->next;
        }
        return v;
    }

    void fromVector(const vector<T> &vec)
    {
        head = nullptr;
        for (const auto &item : vec)
            insert(item);
    }

    void clear()
    {
        while (head)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    static string getId(Doctor d) { return d.id; }
    static string getId(Patient p) { return p.id; }

    static string getName(Doctor d) { return d.name; }
    static string getName(Patient p) { return p.name; }

    static int getAge(Doctor d) { return d.age; }
    static int getAge(Patient p) { return p.age; }

    static string getCustom(Doctor d) { return d.specialization; }
    static string getCustom(Patient p) { return p.disease; }

    void printObject(Doctor d)
    {
        cout << left << setw(10) << d.id << setw(20) << d.name << setw(20) << d.specialization << d.age << endl;
    }

    void printObject(Patient p)
    {
        cout << left << setw(10) << p.id << setw(20) << p.name << setw(10) << p.age << setw(20) << p.disease << p.doctorId << endl;
    }

    void saveObject(ofstream &file, Doctor d)
    {
        file << d.id << "," << d.name << "," << d.specialization << "," << d.age << "\n";
    }

    void saveObject(ofstream &file, Patient p)
    {
        file << p.id << "," << p.name << "," << p.age << "," << p.disease << "," << p.doctorId << "\n";
    }

    bool loadObject(ifstream &file, Doctor &d)
    {
        return getline(file, d.id, ',') && getline(file, d.name, ',') && getline(file, d.specialization, ',') && (file >> d.age).ignore();
    }

    bool loadObject(ifstream &file, Patient &p)
    {
        string ageStr;
        return getline(file, p.id, ',') && getline(file, p.name, ',') && getline(file, ageStr, ',') && getline(file, p.disease, ',') && getline(file, p.doctorId) && (p.age = stoi(ageStr), true);
    }

    void updateObject(Doctor &d)
    {
        cout << "Ten moi: ";
        getline(cin, d.name);
        cout << "Chuyen khoa moi: ";
        getline(cin, d.specialization);
        cout << "Tuoi moi: ";
        cin >> d.age;
        cin.ignore();
    }

    void updateObject(Patient &p)
    {
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
};

void menu()
{
    LinkedList<Doctor> doctors;
    LinkedList<Patient> patients;
    int choice;
    do
    {
        cout << "\n====== MENU ======" << endl;
        cout << "1. Nhap bac si\n2. Nhap benh nhan\n3. In danh sach\n4. Luu doc file\n5. Them/Sua/Xoa\n6. Tim kiem\n7. Sap xep\n8. Lon nho\n9. Tong/TB/Dem\n10. Thong ke\n0. Thoat\nChon: ";
        cin >> choice;
        cin.ignore();
        string id;
        switch (choice)
        {
        case 1:
        {
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
            doctors.saveToFile("doctors.txt"); // Ghi luôn sau khi thêm
            break;
        }
        case 2:
        {
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
            patients.saveToFile("patients.txt"); // Ghi luôn sau khi thêm
            break;
        }
        case 3:
            doctors.print();
            patients.print();
            break;
        case 4:

            // Đọc lại dữ liệu từ file doctors.txt và chèn thêm vào danh sách bác sĩ hiện tại
            // ⚠️ Nếu không xóa danh sách trước đó, sẽ gây lặp dữ liệu
            doctors.loadFromFile("doctors.txt");

            // Ghi toàn bộ danh sách bác sĩ hiện tại (trong RAM) vào file doctors.txt
            doctors.saveToFile("doctors.txt");


            // Đọc lại dữ liệu từ file patients.txt và thêm vào danh sách bệnh nhân
            // Vì đã gọi clear() trước đó nên dữ liệu mới sẽ không bị lặp
            patients.loadFromFile("patients.txt");
            // Ghi toàn bộ danh sách bệnh nhân hiện tại (sau khi đã insert) vào file patients.txt
            patients.saveToFile("patients.txt");

            // Xóa toàn bộ danh sách bác sĩ đang có trong RAM (giải phóng bộ nhớ)
            // Giúp tránh bị trùng lặp dữ liệu khi gọi loadFromFile() sau này
            doctors.clear();

            // Xóa toàn bộ danh sách bệnh nhân hiện tại trong RAM (nếu có)
            // Tương tự như với bác sĩ, để chuẩn bị đọc lại từ file mà không bị trùng
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
            // Có thể bổ sung tìm kiếm in ra sau
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
            cout << "So BN > 60: " << patients.countByCondition([](Patient p)
                                                                { return p.age > 60; })
                 << endl;
            break;
        case 10:
            cout << "BN benh tieu duong: " << patients.countByCondition([](Patient p)
                                                                        { return p.disease == "tieu duong"; })
                 << endl;
            break;
        }
    } while (choice != 0);
}

int main()
{
    menu();
    return 0;
}