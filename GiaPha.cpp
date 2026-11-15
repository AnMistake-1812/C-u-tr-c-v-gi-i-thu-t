#include "GiaPha.h"
#include <iostream>
#include <iomanip>

using namespace std;
// Khởi tạo danh sách rỗng: head = nullptr                       -> O(1)
void initList(LinkedList& list) {
    list.head = nullptr;
}
// Tạo một node mới chứa x, next = nullptr                       -> O(1)
Node* createNode(const Item& x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

// Chèn vào đầu danh sách                                        -> O(1)
//   (1) tạo node mới
//   (2) newNode->next = head cũ
//   (3) head = newNode
// Chỉ đổi 2 con trỏ, không phụ thuộc số phần tử n.

void insertHead(LinkedList& list, const Item& x) {
    Node* newNode = createNode(x);
    newNode->next = list.head;
    list.head = newNode;
}

// Chèn vào cuối danh sách                                       -> O(n)
//   DSLK đơn chỉ có head nên muốn biết node cuối phải duyệt từ đầu
//   (n-1 bước). Việc gắn node mới vào cuối chỉ là O(1), nhưng bước
//   tìm node cuối quyết định độ phức tạp là O(n).

void insertTail(LinkedList& list, const Item& x) {
    Node* newNode = createNode(x);

    if (list.head == nullptr) {       // danh sách rỗng
        list.head = newNode;
        return;
    }
    Node* last = list.head;           // tìm node cuối cùng
    while (last->next != nullptr)
        last = last->next;
    last->next = newNode;             // gắn node mới vào cuối
}

// Tìm kiếm theo ID (duyệt tuần tự)                              -> O(n)
//   Tốt nhất  : ID nằm ở node đầu          -> O(1)
//   Xấu nhất  : ID ở node cuối / không có  -> n phép so sánh = O(n)

Node* timKiemTheoID(const LinkedList& list, int id) {
    Node* cur = list.head;
    while (cur != nullptr) {
        if (cur->data.id == id)
            return cur;               // tìm thấy
        cur = cur->next;
    }
    return nullptr;                   // không tìm thấy
}

// Thêm thành viên (kiểm tra trùng ID rồi chèn cuối)             -> O(n)
//   timKiemTheoID : O(n)  +  insertTail : O(n)  => tổng O(n)

bool themThanhVien(LinkedList& list, const Item& x) {
    if (timKiemTheoID(list, x.id) != nullptr) {
        cout << "[Loi] ID " << x.id << " da ton tai, khong the them.\n";
        return false;
    }
    insertTail(list, x);
    return true;
}


// tìm theo ID và cập nhật dữ liệu ngay trên node hiện tại -> O(n)
bool suaThanhVien(LinkedList& list, int id, const Item& thongTinMoi)
{
    Node* node = timKiemTheoID(list, id);
    if (node == nullptr)
    { return false; }

    node->data.hoTen = thongTinMoi.hoTen;
    node->data.namSinh = thongTinMoi.namSinh;
    node->data.gioiTinh = ThongTinMoi.gioiTinh;
    return True;
}

// Duyệt tìm node và gỡ các liên kết gia đình trước khi giải phóng -> O(n)
bool xoaThanhVien(LinkedList& list, list, int id)
{
    Node* prev = nullptr;
    Node* node = list.head;
    while (node != nullptr && node->data.id != id) 
    {
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

     for(Node* cur = list.head; cur != nullptr; cur = cur->next) 
        {
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
// In danh sách ra màn hình (duyệt từ head đến nullptr)          -> O(n)
void printList(const LinkedList& list) {
    if (list.head == nullptr) {
        cout << "Gia pha rong." << endl;
        return;
    }
    cout << left
         << setw(8)  << "ID"
         << setw(25) << "Ho ten"
         << setw(10) << "Nam sinh"
         << setw(10) << "Gioi tinh" << endl;
    cout << string(53, '-') << endl;
    int dem = 0;
    Node* cur = list.head;
    while (cur != nullptr) {
        cout << left
             << setw(8)  << cur->data.id
             << setw(25) << cur->data.hoTen
             << setw(10) << cur->data.namSinh
             << setw(10) << cur->data.gioiTinh << endl;
        cur = cur->next;
        ++dem;
    }
    cout << "Tong so thanh vien: " << dem << endl;
}
// Giải phóng toàn bộ code                                    -> O(n)
//   Lưu next trước khi delete, nếu không sẽ mất con trỏ tới node sau.
void destroyList(LinkedList& list) {
    Node* cur = list.head;
    while (cur != nullptr) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
    list.head = nullptr;
}
