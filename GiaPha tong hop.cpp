#include "GiaPha.h"

Node* taoNode(int id, string hoTen, string gioiTinh, int namSinh, int namMat, string voChong) {
    Node* p = new Node;
    p->id = id;
    p->hoTen = hoTen;
    p->gioiTinh = gioiTinh;
    p->namSinh = namSinh;
    p->namMat = namMat;
    p->voChong = voChong;
    p->cha = nullptr;
    p->me = nullptr;
    p->next = nullptr;
    return p;
}

void initList(LinkedList& list) {
    list.head = nullptr;
}

void insertHead(LinkedList& list, Node* newNode) {
    newNode->next = list.head;
    list.head = newNode;
}

void insertTail(LinkedList& list, Node* newNode) {
    if (list.head == nullptr) {
        list.head = newNode;
        return;
    }
    Node* last = list.head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

Node* timKiemTheoID(const LinkedList& list, int id) {
    Node* cur = list.head;
    while (cur != nullptr) {
        if (cur->id == id) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

bool themThanhVien(LinkedList& list, Node* newNode) {
    if (timKiemTheoID(list, newNode->id) != nullptr) {
        cout << "[Loi] ID " << newNode->id << " da ton tai!\n";
        delete newNode;
        return false;
    }
    insertTail(list, newNode);
    return true;
}

bool suaThanhVien(LinkedList& list, int id, string hoTen, string gioiTinh, int namSinh, int namMat, string voChong) {
    Node* node = timKiemTheoID(list, id);
    if (node == nullptr) {
        return false;
    }
    node->hoTen = hoTen;
    node->gioiTinh = gioiTinh;
    node->namSinh = namSinh;
    node->namMat = namMat;
    node->voChong = voChong;
    return true;
}

bool xoaThanhVien(LinkedList& list, int id) {
    Node* prev = nullptr;
    Node* node = list.head;
    while (node != nullptr && node->id != id) {
        prev = node;
        node = node->next;
    }
    if (node == nullptr) {
        return false;
    }
    if (prev == nullptr) {
        list.head = node->next;
    } else {
        prev->next = node->next;
    }
    for (Node* cur = list.head; cur != nullptr; cur = cur->next) {
        if (cur->cha == node) {
            cur->cha = nullptr;
        }
        if (cur->me == node) {
            cur->me = nullptr;
        }
    }
    delete node;
    return true;
}

void printList(const LinkedList& list) {
    if (list.head == nullptr) {
        cout << "Gia pha rong.\n";
        return;
    }
    cout << left
         << setw(6)  << "ID"
         << setw(22) << "Ho ten"
         << setw(10) << "Gioi tinh"
         << setw(10) << "Nam sinh"
         << setw(10) << "Nam mat"
         << setw(20) << "Vo/Chong" << endl;
    cout << string(78, '-') << endl;
    int dem = 0;
    Node* cur = list.head;
    while (cur != nullptr) {
        cout << left
             << setw(6)  << cur->id
             << setw(22) << cur->hoTen
             << setw(10) << cur->gioiTinh
             << setw(10) << cur->namSinh
             << setw(10) << cur->namMat
             << setw(20) << cur->voChong << endl;
        cur = cur->next;
        ++dem;
    }
    cout << "Tong so thanh vien: " << dem << endl;
}

void destroyList(LinkedList& list) {
    Node* cur = list.head;
    while (cur != nullptr) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
    list.head = nullptr;
}

void timCuTo(const LinkedList& list) {
    cout << "\n=== DANH SACH CU TO ===\n";
    bool found = false;
    for (Node* cur = list.head; cur != nullptr; cur = cur->next) {
        if (cur->cha == nullptr && cur->me == nullptr) {
            cout << "- ID " << cur->id << ": " << cur->hoTen << " (Sinh nam " << cur->namSinh << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay Cu to!\n";
    }
}

void inConCai(const LinkedList& list, int id) {
    cout << "Con cai: ";
    bool found = false;
    for (Node* cur = list.head; cur != nullptr; cur = cur->next) {
        if ((cur->cha != nullptr && cur->cha->id == id) || (cur->me != nullptr && cur->me->id == id)) {
            if (found) cout << ", ";
            cout << cur->hoTen << " (ID " << cur->id << ")";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co";
    }
    cout << endl;
}

void inAnhChiEm(const LinkedList& list, int id) {
    Node* target = timKiemTheoID(list, id);
    cout << "Anh/Chi/Em: ";
    if (target->cha == nullptr && target->me == nullptr) {
        cout << "Khong co\n";
        return;
    }
    bool found = false;
    for (Node* cur = list.head; cur != nullptr; cur = cur->next) {
        if (cur->id != id) {
            bool cungCha = (target->cha != nullptr && cur->cha == target->cha);
            bool cungMe = (target->me != nullptr && cur->me == target->me);
            if (cungCha || cungMe) {
                if (found) cout << ", ";
                cout << cur->hoTen << " (ID " << cur->id << ")";
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Khong co";
    }
    cout << endl;
}

void xemTatCaQuanHe(const LinkedList& list, int id) {
    Node* target = timKiemTheoID(list, id);
    if (target == nullptr) {
        cout << "Khong tim thay thanh vien!\n";
        return;
    }
    cout << "\n=== QUAN HE GIA DINH CUA " << target->hoTen << " ===\n";
    cout << "Cha: " << (target->cha != nullptr ? target->cha->hoTen : "Chua xac dinh") << endl;
    cout << "Me: " << (target->me != nullptr ? target->me->hoTen : "Chua xac dinh") << endl;
    cout << "Vo/Chong: " << target->voChong << endl;
    inAnhChiEm(list, id);
    inConCai(list, id);
}

bool kiemTraHopLe(const LinkedList& list, int id, int namSinh, int namMat) {
    if (id <= 0) {
        cout << "[Loi] ID phai lon hon 0!\n";
        return false;
    }
    if (timKiemTheoID(list, id) != nullptr) {
        cout << "[Loi] ID " << id << " da ton tai!\n";
        return false;
    }
    if (namSinh <= 0) {
        cout << "[Loi] Nam sinh khong hop le!\n";
        return false;
    }
    if (namMat != 0 && namMat < namSinh) {
        cout << "[Loi] Nam mat khong duoc nho hon nam sinh!\n";
        return false;
    }
    return true;
}

void taoDuLieuMau(LinkedList& list) {
    Node* n1 = taoNode(1, "Nguyen Van An", "Nam", 1940, 2010, "Tran Thi Hoa");
    Node* n2 = taoNode(2, "Tran Thi Hoa", "Nu", 1945, 2018, "Nguyen Van An");

    Node* n3 = taoNode(3, "Nguyen Van Binh", "Nam", 1965, 0, "Le Thi Mai");
    n3->cha = n1;
    n3->me = n2;

    Node* n4 = taoNode(4, "Le Thi Mai", "Nu", 1968, 0, "Nguyen Van Binh");

    Node* n5 = taoNode(5, "Nguyen Thi Yen", "Nu", 1970, 0, "Khong co");
    n5->cha = n1;
    n5->me = n2;

    Node* n6 = taoNode(6, "Nguyen Van Cuong", "Nam", 1990, 0, "Tran Thi Ly");
    n6->cha = n3;
    n6->me = n4;

    Node* n7 = taoNode(7, "Tran Thi Ly", "Nu", 1993, 0, "Nguyen Van Cuong");

    Node* n8 = taoNode(8, "Nguyen Thi Lan", "Nu", 1993, 0, "Khong co");
    n8->cha = n3;
    n8->me = n4;

    Node* n9 = taoNode(9, "Nguyen Van Duc", "Nam", 2020, 0, "Khong co");
    n9->cha = n6;
    n9->me = n7;

    themThanhVien(list, n1);
    themThanhVien(list, n2);
    themThanhVien(list, n3);
    themThanhVien(list, n4);
    themThanhVien(list, n5);
    themThanhVien(list, n6);
    themThanhVien(list, n7);
    themThanhVien(list, n8);
    themThanhVien(list, n9);
}

void chayTestCase() {
    cout << "\n=== CHAY KIEM THU TU DONG ===\n";
    LinkedList testList;
    initList(testList);
    taoDuLieuMau(testList);

    cout << "Test 1 (Them trung ID 3): ";
    bool tc1 = kiemTraHopLe(testList, 3, 1980, 0);
    cout << (!tc1 ? "DAT (Da chan trung ID)\n" : "KHONG DAT\n");

    cout << "Test 2 (Nam mat 1980 < Nam sinh 1990): ";
    bool tc2 = kiemTraHopLe(testList, 10, 1990, 1980);
    cout << (!tc2 ? "DAT (Da chan loi nam)\n" : "KHONG DAT\n");

    cout << "Test 3 (Xoa node cha ID 3 - Nguyen Van Binh): ";
    xoaThanhVien(testList, 3);
    Node* con = timKiemTheoID(testList, 6);
    cout << (con != nullptr && con->cha == nullptr ? "DAT (Con tro cha cua con da reset ve nullptr)\n" : "KHONG DAT\n");

    destroyList(testList);
}
