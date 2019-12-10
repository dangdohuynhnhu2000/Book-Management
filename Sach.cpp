#include "Sach.h"
#include <iostream>
using namespace std;


Sach::Sach()
{
	giaTien = 0;
	hide = 0;
}


void Sach::setTenSach(const Sach& a)
{
	tenSach = a.tenSach;
}

void Sach::setMaSach(const Sach& a)
{
	maSach = a.maSach;
}

void Sach::setNXB(const Sach& a)
{
	NXB = a.NXB;
}

void Sach::setNXB(string name)
{
	NXB = NXB;
}

void Sach::setAuthor(const Sach& a)
{
	author = a.author;
}

void Sach::setAuthor(string name)
{
	author = name;
}

void Sach::setGiaTien(const Sach& a)
{
	this->giaTien = a.giaTien;
}

string Sach::getTenSach()
{
	return this->tenSach;
}

string Sach::getMaSach()
{
	return this->maSach;
}

string Sach::getNXB()
{
	return this->NXB;
}

string Sach::getAuthor()
{
	return this->author;
}

int Sach::getGiaTien()
{
	return this->giaTien;
}

void Sach::nhapTenSach()
{

	cout << "- Nhap ten sach: ";
	getline(cin, tenSach);
}

void Sach::nhapMaSach()
{
	cout << "- Nhap ma sach: ";
	getline(cin, maSach);
}

void Sach::nhapNXB()
{
	cout << "- Nhap NXB: ";
	getline(cin, NXB);
}

void Sach::nhapAuthor()
{
	cout << "- Nhap tac gia: ";
	getline(cin, author);
}

void Sach::nhapGiaTien()
{
	cout << "- Nhap gia tien: ";
	cin >> giaTien;
	getchar();
}


bool Sach::compareName(string name)
{
	if (tenSach == name)
	{
		return true;
	}
	return false;
}

bool Sach::compareID(string ID)
{
	if (maSach == ID)
	{
		return true;
	}
	return false;
}

void Sach::inSach()
{
	cout << "+ Ten sach: " << tenSach << endl;
	cout << "+ Ma sach: " << maSach << endl;
	if (hide != 1)
	{
		cout << "+ NXB: " << NXB << endl;
	}
	if (hide != 2)
	{
		cout << "+ Tac gia: " << author << endl;
	}
	cout << "+ Gia tien 1 quyen sach: " << giaTien << endl;
}

void Sach::updateTenSach(string name)
{
	tenSach = name;
}

void Sach::updateMaSach(string name)
{
	maSach = name;
}

void Sach::updateNXB(string name)
{
	NXB = name;
}

void Sach::updateAuthor(string name)
{
	author = name;
}

void Sach::updateGiaTien(int money)
{
	giaTien = money;
}

void Sach::setHide(int an)
{
	hide = an;
}

void Sach::setHide(const Sach& a)
{
	hide = a.hide;
}

void Sach::ghiLenFile(ofstream& file)
{
	file << tenSach << endl;
	file << maSach << endl;
	file << author << endl;
	file << NXB << endl;
	file << giaTien << endl;
	file << hide << endl;
}

bool Sach::isOnDeal(string deal, int type) //kiem tra xem sach co thoa dieu kien deal
{
	if (type == 1) //khuyen mai theo ten sach
	{
		if (tenSach == deal)
		{
			return true;
		}
	}
	else if (type == 2) //khuyen mai theo ma sach
	{
		if (maSach == deal)
		{
			return true;
		}
	}
	else if (type == 3) //khuyen mai theo ten tac gia
	{
		if (author == deal)
		{
			return true;
		}
	}
	else if (type == 4) //khuyen mai theo ten NXB
	{
		if (NXB == deal)
		{
			return true;
		}
	}
	return false;
}

