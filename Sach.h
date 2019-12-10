#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Sach
{
private:
	string tenSach;
	string maSach;
	string author;
	string NXB;
	int giaTien;
	int hide;
	//hide=0: khong an thuoc tinh nao
	//hide=1: an NXB
	//hide=2: an author
public:
	Sach();
	void setHide(int an);
	void setHide(const Sach& a);
	void setTenSach(const Sach& a);
	void setMaSach(const Sach& a);
	void setGiaTien(const Sach& a);
	void setNXB(const Sach& a);
	void setNXB(string name);
	void setAuthor(const Sach& a);
	void setAuthor(string name);
	void nhapTenSach();
	void nhapMaSach();
	void nhapNXB();
	void nhapAuthor();
	void nhapGiaTien();
	string getTenSach();
	string getMaSach();
	string getNXB();
	string getAuthor();
	int getGiaTien();
	void updateTenSach(string name);
	void updateMaSach(string name);
	void updateNXB(string name);
	void updateAuthor(string name);
	void updateGiaTien(int money);
	bool compareName(string name);
	bool compareID(string name);
	void inSach();
	void ghiLenFile(ofstream& file);


	bool isOnDeal(string deal, int type);
};





