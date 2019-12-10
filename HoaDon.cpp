#include "HoaDon.h"

HoaDon::HoaDon()
{
	soLuong = 0;
	tienSach = 0;
}

HoaDon::HoaDon(Sach a, int n)
{
	book.setTenSach(a);
	book.setMaSach(a);
	book.setGiaTien(a);
	soLuong = n;
	tienSach = soLuong * book.getGiaTien();
}

void HoaDon::themHoaDon(Sach a, int n)
{
	book.setTenSach(a);
	book.setMaSach(a);
	book.setAuthor(a);
	book.setNXB(a);
	book.setGiaTien(a);
	soLuong = n;
	tienSach = n * book.getGiaTien();
}

void HoaDon::timKiemVaThem(DanhSach ds)
{
	string name;
	cout << "Nhap ten sach ma ban muon them vao hoa don: ";
	getline(cin, name);
	int k;
	k = ds.findBook(name);
	if (k == -2)
	{
		cout << "Sach ban muon them vao hoa don khong ton tai!" << endl;
		return;
	}
	else if (k == -1)
	{
		string ID;
		cout << "Nhap ma so sach ma ban muon them vao hoa don: ";
		getline(cin, ID);
		k = ds.findByID(ID);
		if (k == -2)
		{
			cout << "Khong tim thay!" << endl;
			return;
		}
	}

	Sach temp;
	temp = ds.getSach(k);
	book.setTenSach(temp);
	book.setMaSach(temp);
	book.setAuthor(temp);
	book.setNXB(temp);
	book.setGiaTien(temp);
	book.setHide(temp);
	cout << "Nhap so luong sach ban muon mua: ";
	cin >> soLuong;
	getchar();
	tienSach = soLuong * book.getGiaTien();
	cout << endl << "Them thanh cong!" << endl;
}

Sach HoaDon::getBook()
{
	return book;
}

int HoaDon::getSoLuong()
{
	return soLuong;
}

void HoaDon::tangSoLuong(int n)
{
	soLuong = soLuong + n;
}

long HoaDon::getTienSach()
{
	return tienSach;
}

void HoaDon::inHoaDon()
{
	book.inSach();
	cout << "+ So luong: " << soLuong << endl;
}

void HoaDon::ghiLenFile(ofstream& f)
{
	book.ghiLenFile(f);
	f << soLuong << endl;
}

void HoaDon::setSoLuong(int n)
{
	soLuong = n;
}

void HoaDon::updateTien()
{
	tienSach = soLuong * book.getGiaTien();
}
