#include "GiaPha.h"

void menu() {
    cout << "\n========== GIA PHA ==========\n";
    cout << "1. Them thanh vien\n";
    cout << "2. Sua thanh vien\n";
    cout << "3. Xoa thanh vien\n";
    cout << "4. Hien thi danh sach\n";
    cout << "5. Tim Cu to\n";
    cout << "6. Xem tat ca moi quan he\n";
    cout << "7. Chay kiem thu tu dong (Test case)\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "=============================\n";
    cout << "Nhap lua chon: ";
}

int main() {
    LinkedList list;
    initList(list);
    taoDuLieuMau(list);

    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, namSinh, namMat, idCha, idMe;
            string hoTen, gioiTinh, voChong;
            cout << "Nhap ID: ";
            cin >> id;
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            cout << "Nhap gioi tinh: ";
            getline(cin, gioiTinh);
            cout << "Nhap nam sinh: ";
            cin >> namSinh;
            cout << "Nhap nam mat (0 neu con song): ";
            cin >> namMat;
            cin.ignore();
            cout << "Nhap ten vo/chong (neu co): ";
            getline(cin, voChong);

            if (!kiemTraHopLe(list, id, namSinh, namMat)) {
                break;
            }

            Node* chaNode = nullptr;
            cout << "Nhap ID cha (0 neu khong co): ";
            cin >> idCha;
            if (idCha != 0) {
                chaNode = timKiemTheoID(list, idCha);
                if (chaNode == nullptr) {
                    cout << "[Loi] ID cha khong ton tai!\n";
                    break;
                }
            }

            Node* meNode = nullptr;
            cout << "Nhap ID me (0 neu khong co): ";
            cin >> idMe;
            if (idMe != 0) {
                meNode = timKiemTheoID(list, idMe);
                if (meNode == nullptr) {
                    cout << "[Loi] ID me khong ton tai!\n";
                    break;
                }
            }

            Node* p = taoNode(id, hoTen, gioiTinh, namSinh, namMat, voChong);
            p->cha = chaNode;
            p->me = meNode;

            if (themThanhVien(list, p)) {
                cout << "Them thanh cong!\n";
            }
            break;
        }
        case 2: {
            int id, namSinh, namMat;
            string hoTen, gioiTinh, voChong;
            cout << "Nhap ID can sua: ";
            cin >> id;
            cin.ignore();
            cout << "Nhap ho ten moi: ";
            getline(cin, hoTen);
            cout << "Nhap gioi tinh moi: ";
            getline(cin, gioiTinh);
            cout << "Nhap nam sinh moi: ";
            cin >> namSinh;
            cout << "Nhap nam mat moi: ";
            cin >> namMat;
            cin.ignore();
            cout << "Nhap vo/chong moi: ";
            getline(cin, voChong);

            if (namMat != 0 && namMat < namSinh) {
                cout << "[Loi] Nam mat khong duoc nho hon nam sinh!\n";
                break;
            }

            if (suaThanhVien(list, id, hoTen, gioiTinh, namSinh, namMat, voChong)) {
                cout << "Cap nhat thanh cong!\n";
            } else {
                cout << "Khong tim thay ID!\n";
            }
            break;
        }
        case 3: {
            int id;
            cout << "Nhap ID can xoa: ";
            cin >> id;
            if (xoaThanhVien(list, id)) {
                cout << "Xoa thanh cong!\n";
            } else {
                cout << "Khong tim thay ID!\n";
            }
            break;
        }
        case 4:
            printList(list);
            break;
        case 5:
            timCuTo(list);
            break;
        case 6: {
            int id;
            cout << "Nhap ID thanh vien: ";
            cin >> id;
            xemTatCaQuanHe(list, id);
            break;
        }
        case 7:
            chayTestCase();
            break;
        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    destroyList(list);
    return 0;
}
