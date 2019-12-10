#pragma once
#include <vector>
#include "HoaDon.h"

class ListHoaDon
{
protected:
	vector<HoaDon> listBill;
	int countType;
	long tongTien;
public:
	ListHoaDon();
	int timSachTrung(Sach a);
	int timSach(string name, string ID);
	void nhapListHoaDon(DanhSach ds);
	void addListHoaDon(Sach a, int soLuong);
	void addListHoaDon(HoaDon hd);
	void inListHoaDon();
	void ghiLenFile(ofstream& f);
	long getTongTien();
	int getCountType();
	void setSoLuongAtPos(int pos, int n);
	void xoaSach(int pos);
};


