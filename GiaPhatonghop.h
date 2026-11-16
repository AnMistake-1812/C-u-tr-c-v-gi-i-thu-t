#ifndef GIAPHA_H
#define GIAPHA_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node {
    int id;
    string hoTen;
    string gioiTinh;
    int namSinh;
    int namMat;
    string voChong;
    Node* cha;
    Node* me;
    Node* next;
};

struct LinkedList {
    Node* head;
};

Node* taoNode(int id, string hoTen, string gioiTinh, int namSinh, int namMat, string voChong);

void initList(LinkedList& list);
void insertHead(LinkedList& list, Node* newNode);
void insertTail(LinkedList& list, Node* newNode);
Node* timKiemTheoID(const LinkedList& list, int id);
bool themThanhVien(LinkedList& list, Node* newNode);
void printList(const LinkedList& list);
void destroyList(LinkedList& list);

bool suaThanhVien(LinkedList& list, int id, string hoTen, string gioiTinh, int namSinh, int namMat, string voChong);
bool xoaThanhVien(LinkedList& list, int id);

void timCuTo(const LinkedList& list);
void inConCai(const LinkedList& list, int id);
void inAnhChiEm(const LinkedList& list, int id);
void xemTatCaQuanHe(const LinkedList& list, int id);

void taoDuLieuMau(LinkedList& list);
bool kiemTraHopLe(const LinkedList& list, int id, int namSinh, int namMat);
void chayTestCase();

#endif
