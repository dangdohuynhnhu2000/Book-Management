#pragma once
#include "Sach.h"
#include <vector>
#include <fstream>

class DanhSach
{
protected:
	vector <Sach> s;
	int soLuong; //do luong sach trong danh sach
public:
	DanhSach();
	void docDanhSach();
	void nhapDanhSach();
	void ghiLenFile();
	int findBook(string bookName);
	int findByName(string name);
	void deleteBook(string name);
	void updatePrice(string name);
	int findByID(string name);
	void themSach(const Sach& a);
	Sach getSach(int pos);
	int getSoLuong();
	void inDanhSach();
	void setHideAt(int pos, int an);
	void updateTenSachAt(int pos, string name);
	void updateMaSachAt(int pos, string name);
	void updateNXBAt(int pos, string name);
	void updateAuthorAt(int pos, string name);
	void updateGiaTienAt(int pos, int money);

	//nhom cac chuc nang khuyen mai
	int getTypeDeal();
	string getNameDeal();
	float getDiscountDeal();
	void dealProgram();
	
};

