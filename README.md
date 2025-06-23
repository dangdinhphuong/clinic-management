# 🏥 MedicalClinicManager

## 📌 Mô tả dự án
**MedicalClinicManager** là một chương trình quản lý phòng khám đơn giản viết bằng **C++**. Chương trình hỗ trợ:
- Quản lý bệnh nhân và phiếu khám bệnh.
- Thao tác tìm kiếm, thống kê.
- Lưu trữ và xử lý dữ liệu.

---

## 📁 Cấu trúc thư mục

/project
│
├── models/
│ ├── Doctor.h ← Định nghĩa struct Doctor
│ └── Patient.h ← Định nghĩa struct Patient
│
├── structures/
│ ├── Node.h ← Định nghĩa template Node<T>
│ └── LinkedList.h ← Khai báo & triển khai template LinkedList<T>
│
├── core/
│ └── Menu.h ← Khai báo & xử lý menu chính
│
├── main.cpp ← Hàm main(), gọi menu()
├── doctors.txt ← Dữ liệu bác sĩ lưu dạng văn bản
├── patients.txt ← Dữ liệu bệnh nhân lưu dạng văn bản
└── README.md

<pre><code>## 📁 Cấu trúc thư mục ``` /project │ ├── models/ │ ├── Doctor.h ← Định nghĩa struct Doctor │ └── Patient.h ← Định nghĩa struct Patient │ ├── structures/ │ ├── Node.h ← Định nghĩa template Node&lt;T&gt; │ └── LinkedList.h ← Khai báo & triển khai template LinkedList&lt;T&gt; │ ├── core/ │ └── Menu.h ← Khai báo & xử lý menu chính │ ├── main.cpp ← Hàm main(), gọi menu() ├── doctors.txt ← Dữ liệu bác sĩ lưu dạng văn bản ├── patients.txt ← Dữ liệu bệnh nhân lưu dạng văn bản └── README.md ``` </code></pre>

---

## 🧠 Công nghệ sử dụng

- 🧾 Ngôn ngữ: **C++17**
- 💾 Lưu trữ: File `.txt`
- 🧩 Cấu trúc dữ liệu: Template **Linked List**

---

## 📜 Hướng dẫn sử dụng

1. **Biên dịch chương trình**:
   ```bash
      g++ main.cpp core/Menu.cpp -o app -std=c++17

2. **Chạy chương trình**:
   ```bash
   ./app