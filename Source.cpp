#include "Header.h"



void runMainMenu(DanhSach& ds)
{
	int select = 0;
	do
	{
		system("cls");
		cout << "1. Dang nhap tai khoan Admin." << endl;
		cout << "2. Dang nhap tai khoan Author." << endl;
		cout << "3. Dang nhap tai khoan NXB." << endl;
		cout << "4. Dang nhap tai khoan User." << endl;
		cout << "5. Xem duoi che do Guest." << endl;
		cout << "6. Thoat." << endl;
		cout << "Lua chon: ";
		cin >> select;
		getchar();
		if (select == 1)
		{
			Admin ad;
			system("cls");
			if (ad.logInAdmin())
			{
				ad.runAdmin(ds);
				backToMainMenu(ds);
			}
			else
			{
				cout << "Dang nhap khong thanh cong!" << endl;
			}
		}
		else if (select == 2)
		{
			Author tg;
			system("cls");
			if (tg.logInAuthor())
			{
				tg.runAuthor(ds);
				backToMainMenu(ds);
			}
			else
			{
				cout << "Dang nhap khong thanh cong!" << endl;
			}
		}
		else if (select == 3)
		{
			NXB nxb;
			system("cls");
			if (nxb.logInNXB())
			{
				nxb.runNXB(ds);
				backToMainMenu(ds);
			}
			else
			{
				cout << "Dang nhap khong thanh cong!" << endl;
			}
		}
		else if (select == 4)
		{
			User user;
			system("cls");
			if (user.logInUser())
			{
				user.docGioHangTuFile();
				user.runUser(ds);
				backToMainMenu(ds);
			}
			else
			{
				cout << "Dang nhap khong thanh cong!" << endl;
			}
		}
		else if (select == 5)
		{
			Guest guest;
			system("cls");
			guest.timSach(ds);
			backToMainMenu(ds);
		}
		else if (select == 6)
		{
			return;
		}
		else
		{
			cout << "Khong hop le!" << endl;
		}
	} while (select < 1 || select > 6);
}

void backToMainMenu(DanhSach& ds)
{
	cout << endl << "-------------------------" << endl;
	int select = 0;
	do
	{
		cout << "1. Quay tro lai menu chinh." << endl;
		cout << "2. Thoat." << endl;
		cout << "Lua chon: ";
		cin >> select;
		getchar();
		if (select == 1)
		{
			system("cls");
			runMainMenu(ds);
		}
		else if (select == 2)
		{
			return;
		}
		else
		{
			cout << "Khong hop le!" << endl;
		}
	} while (select < 1 || select > 2);
}