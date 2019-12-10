#pragma once
#include "Sach.h"
#include "DanhSach.h"

class HoaDon
{
protected:
	Sach book;
	int soLuong;
	long tienSach;
public:
	HoaDon();
	HoaDon(Sach a, int n);
	void themHoaDon(Sach a, int n);
	void timKiemVaThem(DanhSach ds);
	Sach getBook();
	int getSoLuong();
	long getTienSach();
	void setSoLuong(int n);
	void tangSoLuong(int n);//tang them n
	void inHoaDon();
	void ghiLenFile(ofstream& f);
	void updateTien();
};


