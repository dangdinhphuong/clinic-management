#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char maBenhNhan[10];
    char hoTen[50];
    int tuoi;
    char gioiTinh[10];
    char diaChi[100];
    float chiPhiKham;
    char ngayNhapVien[11];
} patients;

patients danhSach[MAX];
int soLuong = 0;

// Hàm nhập thông tin bệnh nhân
void nhapBenhNhan(patients *bn) {
    printf("Ma benh nhan: ");       scanf(" %9[^\n]", bn->maBenhNhan);
    printf("Ho ten: ");            scanf(" %49[^\n]", bn->hoTen);
    printf("Tuoi: ");              scanf("%d", &bn->tuoi);
    printf("Gioi tinh: ");         scanf(" %9[^\n]", bn->gioiTinh);
    printf("Dia chi: ");           scanf(" %99[^\n]", bn->diaChi);
    printf("Chi phi kham: ");     scanf("%f", &bn->chiPhiKham);
    printf("Ngay nhap vien: ");   scanf(" %10[^\n]", bn->ngayNhapVien);
}

// Hiển thị danh sách
void hienThiDanhSach() {
    printf("\n%-10s %-20s %-5s %-10s %-15s %-12s %-12s\n", "MaBN", "Ho Ten", "Tuoi", "Gioi Tinh", "Dia Chi", "Chi Phi", "Ngay NV");
    for (int i = 0; i < soLuong; i++) {
        patients bn = danhSach[i];
        printf("%-10s %-20s %-5d %-10s %-15s %-12.2f %-12s\n",
            bn.maBenhNhan, bn.hoTen, bn.tuoi, bn.gioiTinh,
            bn.diaChi, bn.chiPhiKham, bn.ngayNhapVien);
    }
}

// Thêm bệnh nhân
void themBenhNhan() {
    if (soLuong >= MAX) {
        printf("Danh sach day!\n");
        return;
    }
    patients bn;
    nhapBenhNhan(&bn);
    danhSach[soLuong++] = bn;
}

// Tìm vị trí theo mã
int timViTriTheoMa(char ma[]) {
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(danhSach[i].maBenhNhan, ma) == 0)
            return i;
    }
    return -1;
}

// Sửa thông tin
void suaBenhNhan() {
    char ma[10];
    printf("Nhap ma benh nhan can sua: ");
    scanf(" %9[^\n]", ma);
    int idx = timViTriTheoMa(ma);
    if (idx == -1) {
        printf("Khong tim thay benh nhan!\n");
        return;
    }
    printf("Nhap lai thong tin:\n");
    nhapBenhNhan(&danhSach[idx]);
}

// Xoá bệnh nhân
void xoaBenhNhan() {
    char ma[10];
    printf("Nhap ma benh nhan can xoa: ");
    scanf(" %9[^\n]", ma);
    int idx = timViTriTheoMa(ma);
    if (idx == -1) {
        printf("Khong tim thay benh nhan!\n");
        return;
    }
    for (int i = idx; i < soLuong - 1; i++) {
        danhSach[i] = danhSach[i + 1];
    }
    soLuong--;
    printf("Da xoa benh nhan.\n");
}

// Tìm kiếm theo tên
void timKiemBenhNhan() {
    char ten[50];
    printf("Nhap ten can tim: ");
    scanf(" %49[^\n]", ten);
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < soLuong; i++) {
        if (strstr(danhSach[i].hoTen, ten)) {
            printf("%s - %s\n", danhSach[i].maBenhNhan, danhSach[i].hoTen);
        }
    }
}

// Sắp xếp theo tên
void sapXepTheoTen() {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (strcmp(danhSach[i].hoTen, danhSach[j].hoTen) > 0) {
                patients temp = danhSach[i];
danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach theo ten.\n");
}

// Đọc từ file CSV
void docFileCSV(const char *tenFile) {
    FILE *f = fopen(tenFile, "r");
    if (!f) {
        printf("Khong mo duoc file!\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        patients bn;
        char *token = strtok(line, ",");
        if (!token) continue; strcpy(bn.maBenhNhan, token);

        token = strtok(NULL, ",");
        if (!token) continue; strcpy(bn.hoTen, token);

        token = strtok(NULL, ",");
        if (!token) continue; bn.tuoi = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue; strcpy(bn.gioiTinh, token);

        token = strtok(NULL, ",");
        if (!token) continue; strcpy(bn.diaChi, token);

        token = strtok(NULL, ",");
        if (!token) continue; bn.chiPhiKham = atof(token);

        token = strtok(NULL, ",\n");
        if (!token) continue; strcpy(bn.ngayNhapVien, token);

        if (soLuong < MAX) {
            danhSach[soLuong++] = bn;
        }
    }

    fclose(f);
    printf("Doc file thanh cong. Tong so benh nhan: %d\n", soLuong);
}

// Menu
void menuBenhNhan() {
    int chon;
    char fileCSV[] = "patients.csv";

    do {
        printf("\n--- MENU ---\n");
        printf("1. Doc tu file CSV\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Them benh nhan\n");
        printf("4. Sua benh nhan\n");
        printf("5. Xoa benh nhan\n");
        printf("6. Tim kiem benh nhan\n");
        printf("7. Sap xep theo ten\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);
        getchar(); // clear buffer

        switch (chon) {
            case 1: docFileCSV(fileCSV); break;
            case 2: hienThiDanhSach(); break;
            case 3: themBenhNhan(); break;
            case 4: suaBenhNhan(); break;
            case 5: xoaBenhNhan(); break;
            case 6: timKiemBenhNhan(); break;
            case 7: sapXepTheoTen(); break;
            case 0: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);
}