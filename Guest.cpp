#include "Guest.h"
#include <conio.h>


void Guest::timSach(DanhSach ds)
{
	cout << endl << endl;
	string name;
	cout << "Nhap ten cua cuon sach ban muon tim: ";
	getline(cin, name);
	int k = ds.findBook(name);
	if (k == -2)
	{
		return;
	}
	Sach temp = ds.getSach(k);
	cout << "Thong tin cuon sach ban muon tim: " << endl;
	temp.inSach();
	runGuest(ds, temp);
}

void Guest::runGuest(DanhSach ds, Sach book)
{
	int seclect = 0;
	cout << endl;
	cout << "Ban co muon mua quyen sach nay khong: " << endl;
	cout << "Nhap 0 neu muon thoat chuong trinh" << endl;
	cout << "Nhap 1 neu muon mua quyen sach vua tim kiem" << endl;
	cout << "Nhap 2 neu muon tiep tuc tim kiem sach" << endl;
	do
	{
		cout << "Lua chon: ";
		cin >> seclect;
		if (seclect < 0 || seclect>2)
		{
			cout << "Lua chon khong hop le, moi nhap lai!" << endl;
		}
	} while (seclect < 0 || seclect>2);
	getchar();

	if (seclect == 0)
	{
		return;
	}
	else if (seclect == 1)
	{
		int choose;
		system("cls");
		cout << "1. Dang nhap user de tiep tuc." << endl;
		cout << "2. Dang ky tai khoan user." << endl;
		cout << "3.Thoat." << endl;
		do
		{
			cout << "Lua chon: ";
			cin >> choose;
			if (choose < 0 || choose>3)
			{
				cout << "Lua chon khong hop le, moi nhap lai!" << endl;
			}
		} while (choose < 0 || choose>3);
		getchar();
		if (choose == 1)
		{
			User user;
			if (user.logInUser())
			{
				user.docGioHangTuFile();
				user.runUserGuestMode(ds, book);
			}
		}
		else if (choose == 2)
		{
			User user;
			if (dangKyUser(user))
			{
				user.runUser(ds);
				user.backToMenu(ds);
			}
		}
	}
	else
	{
		timSach(ds);
		system("cls");
	}
}

bool Guest::dangKyUser(User& user)
{
	ofstream f, file;
	f.open("User.txt", ios::app);
	file.open("ID.txt", ios::app);
	if (!f || !file)
	{
		cout << "Error to open file" << endl;
		return false;
	}
	string passWord, nameUser, IDUser;
	int ageUser, sexUser;
	user.setUser();
	passWord = user.getPassUser();
	nameUser = user.getNameUser();
	ageUser = user.getTuoiUser();
	sexUser = user.getGioiTinhUser();
	IDUser = user.getIDUser();
	if (user.ktUserTonTai(IDUser) == false)
	{
		f << nameUser << endl;
		f << ageUser << endl;
		f << sexUser << endl;
		f << IDUser << endl;
		f << passWord << endl;
		file << IDUser << endl;
		cout << "Dang ky User thanh cong!" << endl;
		return true;
	}
	else
	{
		cout << "Tai khoan nay da ton tai! " << endl;
		return false;
	}
	f.close();
	file.close();
}