#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>

// Khai báo hàm quản lý bệnh nhân từ module khác
void patients();

void showMainMenu();

int main() {
    int chon;

    do {
        printf("\n===== CHUONG TRINH QUAN LY BENH VIEN =====\n");
        printf("1. Quan ly benh nhan\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        getchar(); // Xoá ký tự newline

        switch (chon) {
            case 1:
                patients(); // Gọi menu quản lý bệnh nhân
                break;
            case 2:
                printf("");
                break;
            case 3:
                printf("");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (chon != 3);

    return 0;
}

#endif // MENU_H
