#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include "../models/Doctor.h"
#include "../models/Patient.h"
#include "Node.h"
using namespace std;

// Class template cho danh sách liên kết đơn
template <typename T>
class LinkedList {
public:
    Node<T>* head = nullptr;

    void insert(T x);
    void remove(string id);
    void update(string id);
    void print();
    void printOne(const T& obj);
    void saveToFile(string filename);
    void loadFromFile(string filename);
    void sortList(int type);
    T getMaxAge();
    T getMinAge();
    double getAvgAge();
    int countByCondition(function<bool(T)> cond);
    vector<T> toVector();
    void fromVector(const vector<T>& vec);
    void clear();

private:
    static string getId(Doctor d);
    static string getId(Patient p);
    static string getName(Doctor d);
    static string getName(Patient p);
    static int getAge(Doctor d);
    static int getAge(Patient p);
    static string getCustom(Doctor d);
    static string getCustom(Patient p);
    void printObject(Doctor d);
    void printObject(Patient p);
    void saveObject(ofstream& file, Doctor d);
    void saveObject(ofstream& file, Patient p);
    bool loadObject(ifstream& file, Doctor& d);
    bool loadObject(ifstream& file, Patient& p);
    void updateObject(Doctor& d);
    void updateObject(Patient& p);
};

// Triển khai chi tiết các hàm trong file .h này để thuận tiện
#include "LinkedList.tpp"
