# 🏥 MedicalClinicManager

## 📌 Mô tả dự án
**MedicalClinicManager** là một chương trình quản lý phòng khám đơn giản viết bằng **C++**. Chương trình hỗ trợ:
- Quản lý bệnh nhân và phiếu khám bệnh.
- Thao tác tìm kiếm, thống kê.
- Lưu trữ và xử lý dữ liệu.

---

## 📁 Cấu trúc thư mục

    MedicalClinicManager/
    │
    ├── include/
    │   ├── patient.h           ← Định nghĩa class Patient
    │   ├── medical_form.h      ← Định nghĩa class MedicalForm
    │   ├── list.h              ← Cấu trúc danh sách liên kết đơn dùng chung
    │   ├── file_handler.h      ← Hàm đọc/ghi file
    │   ├── operations.h        ← Thêm/xoá/sửa/tìm/sắp xếp
    │   ├── statistics.h        ← Phân tích, thống kê
    │   └── menu.h              ← Khai báo hàm menu
    │
    ├── src/
    │   ├── main.cpp            ← Gọi menu, tích hợp toàn bộ
    │   ├── patient.cpp         ← Cài đặt class Patient
    │   ├── medical_form.cpp    ← Cài đặt class MedicalForm
    │   ├── list.cpp            ← Cài đặt danh sách liên kết đơn
    │   ├── file_handler.cpp    ← Cài đặt đọc/ghi file
    │   ├── operations.cpp      ← Cài đặt thêm/sửa/xoá/tìm/sắp xếp
    │   ├── statistics.cpp      ← Cài đặt phần tính toán thống kê
    │   └── menu.cpp            ← Hiển thị và xử lý menu
    │
    ├── data/
    │   ├── patients.txt        ← Dữ liệu bệnh nhân
    │   └── medical_forms.txt   ← Dữ liệu phiếu khám
    │
    └── README.md

---

## ✅ Quy định khi phát triển

👉 **Tất cả các thành viên bắt buộc tuân thủ đúng cấu trúc thư mục trên.**

- **Header files**: Đặt trong thư mục `include/`.
- **Source code (.cpp)**: Đặt trong thư mục `src/`.
- **Dữ liệu lưu trữ**: Đặt trong thư mục `data/`.
- **Chương trình chính (`main.cpp`)**: Chỉ dùng để gọi menu và tích hợp các thành phần.

---

## 📜 Hướng dẫn sử dụng

1. **Biên dịch chương trình**:
   - Nếu sử dụng `Makefile`, chạy lệnh:
     ```bash
     make
     ```
   - Nếu không, biên dịch thủ công bằng lệnh:
     ```bash
     g++ -o MedicalClinicManager src/*.cpp -I include/
     ```

2. **Chạy chương trình**:
   ```bash
   ./MedicalClinicManager
   ```