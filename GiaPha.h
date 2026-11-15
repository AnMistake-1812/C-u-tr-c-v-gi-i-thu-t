#ifndef GIAPHA_H
#define GIAPHA_H

#include <string>

//  Cấu trúc dữ liệu (theo Chương 4 - Danh sách liên kết đơn)
//  Item  : dữ liệu của một thành viên trong gia phả
//  Node  : data + next (con trỏ tới node kế tiếp)
//  LinkedList : chỉ giữ con trỏ head

struct ThanhVien {
    int         id;         // Mã ID (khóa tìm kiếm, không trùng nhau)
    std::string hoTen;
    int         namSinh;
    std::string gioiTinh;   // "Nam" / "Nu"
};

typedef ThanhVien Item;     // data của node là một thành viên

struct Node {
    Item  data;
    Node* next;
    Node* cha = nullptr;
    Node* me = nullptr;
};

struct LinkedList {
    Node* head;
};

// Khởi tạo / tạo node 
void  initList(LinkedList& list);                 // O(1)
Node* createNode(const Item& x);                  // O(1)

//  Thêm phần tử 
void insertHead(LinkedList& list, const Item& x); // O(1)
void insertTail(LinkedList& list, const Item& x); // O(n) - phải duyệt tới node cuối

// Thêm thành viên có kiểm tra trùng ID (thêm vào cuối).
// Trả về true nếu thêm thành công, false nếu ID đã tồn tại.  O(n)
bool themThanhVien(LinkedList& list, const Item& x);

// sua thông tin theo ID, giữ nguyên ID và các liên kết của node.
bool suaThanhVien(LinkedList& list, int id, const Item& thongTinMoi);

// Xóa theo ID, đặt lại liên kết cha/ mẹ trỏ đến node bị xóa về nullptr.
bool xoaThanhVien(Linked& list, int id);

//  Duyệt: tìm kiếm & in 
Node* timKiemTheoID(const LinkedList& list, int id); // O(n), nullptr nếu không thấy
void  printList(const LinkedList& list);             // O(n)

//  Giải phóng bộ nhớ 
void destroyList(LinkedList& list);               // O(n)

#endif // GIAPHA_H
