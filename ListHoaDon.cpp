#include "ListHoaDon.h"

ListHoaDon::ListHoaDon()
{
	countType = 0;
	tongTien = 0;
}

void ListHoaDon::nhapListHoaDon(DanhSach ds)
{
	HoaDon bill;
	Sach temp;
	cout << "Ban muon mua bao nhieu loai sach: ";
	cin >> countType;
	getchar();
	for (int i = 0; i < countType; i++)
	{
		cout << "- Nhap quyen sach thu " << i + 1 << ":" << endl;
		bill.timKiemVaThem(ds);
		temp = bill.getBook();
		if (timSachTrung(temp) >= 0)
		{
			bill.tangSoLuong(1);
		}
		listBill.push_back(bill);
		tongTien = tongTien + bill.getTienSach();
	}
}

int ListHoaDon::timSachTrung(Sach a)
{
	Sach temp;
	for (int i = 0; i < listBill.size(); i++)
	{
		temp = listBill[i].getBook();
		if (a.getTenSach() == temp.getTenSach())
		{
			if (a.getMaSach() == temp.getMaSach())
			{
				return i;
			}
		}
	}
	return -1; //khong co quyen nao truoc do
}

void ListHoaDon::inListHoaDon()
{
	if (countType == 0)
	{
		cout << "RONG!" << endl;
		return;
	}
	for (int i = 0; i < countType; i++)
	{
		cout << "- Don hang thu " << i + 1 << ": " << endl << endl;
		listBill[i].inHoaDon();
	}
	cout << endl << "** Tong tien: " << tongTien << endl;
}

void ListHoaDon::ghiLenFile(ofstream& f)
{
	for (int i = 0; i < countType; i++)
	{
		listBill[i].ghiLenFile(f);
	}
}

void ListHoaDon::addListHoaDon(Sach a, int soLuong)
{
	HoaDon hd;
	hd.themHoaDon(a, soLuong);
	int k = timSachTrung(a);
	if (k == -1)
	{
		listBill.push_back(hd);
		countType++;
		tongTien = tongTien + hd.getTienSach();
	}
	else
	{
		listBill[k].tangSoLuong(hd.getSoLuong());
		tongTien = tongTien + a.getGiaTien() * hd.getSoLuong();
	}
}

void ListHoaDon::addListHoaDon(HoaDon hd)
{
	int k;
	k = timSachTrung(hd.getBook());
	if (k == -1)
	{
		listBill.push_back(hd);
		countType++;
		tongTien = tongTien + hd.getTienSach();
	}
	else
	{
		Sach temp;
		temp = hd.getBook();
		listBill[k].tangSoLuong(hd.getSoLuong());
		tongTien = tongTien + temp.getGiaTien() * hd.getSoLuong();
	}
}

long ListHoaDon::getTongTien()
{
	return tongTien;
}

int ListHoaDon::getCountType()
{
	return countType;
}

int ListHoaDon::timSach(string name, string ID)
{
	Sach temp;
	for (int i = 0; i < countType; i++)
	{
		temp = listBill[i].getBook();
		if ((temp.getTenSach() == name) && (temp.getMaSach() == ID))
		{
			return i;
		}
	}
	return -1;
}

void ListHoaDon::setSoLuongAtPos(int pos, int n)
{
	int temp;
	temp = tongTien - listBill[pos].getTienSach(); //tien khi khong co quyen sach can thay doi so luong
	listBill[pos].setSoLuong(n);
	listBill[pos].updateTien();
	//update lai tong tien
	tongTien = temp + listBill[pos].getTienSach();
}

void ListHoaDon::xoaSach(int pos)
{
	tongTien = tongTien - listBill[pos].getTienSach();
	listBill.erase(listBill.begin() + pos);
	countType--;
}

