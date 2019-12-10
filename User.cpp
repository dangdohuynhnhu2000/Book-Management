#include "User.h"
#include <conio.h>

void User::setUser()
{
	cout << "Ten user: ";
	getline(cin, name);
	do
	{
		cout << "Tuoi user: ";
		cin >> tuoi;
		if (tuoi <= 0)
		{
			cout << "Khong hop le!" << endl;
		}
	} while (tuoi <= 0);

	do
	{
		cout << "Gioi tinh: " << endl;
		cout << "1. Nam, 2: Nu, 3: Khac" << endl;
		cin >> gioiTinh;
		if (gioiTinh < 1 || gioiTinh > 3)
		{
			cout << "Khong hop le!" << endl;
		}
	} while (gioiTinh < 1 || gioiTinh > 3);
	
	getchar();
	cout << "ID uer: ";
	getline(cin, ID);
	cout << "Password: ";
	getline(cin, pass);
}

string User::getPassUser()
{
	return pass;
}

string User::getNameUser()
{
	return name;
}

string User::getIDUser()
{
	return ID;
}

int User::getTuoiUser()
{
	return tuoi;
}

int User::getGioiTinhUser()
{
	return gioiTinh;
}

int User::getSttUser(string ID, string pass)
{
	int stt = 0;
	ifstream f;
	f.open("User.txt");
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return false;
	}
	string s1, s2, s3, s4, s5;
	while (!f.eof())
	{
		stt++;
		getline(f, s1);//lay ten
		name = s1;
		getline(f, s4); //lay tuoi
		tuoi = stoi(s4);
		getline(f, s5);
		gioiTinh = stoi(s5);
		getline(f, s2);//lay ID
		if (s2 == ID)
		{
			getline(f, s3);//lay mat khau
			if (s3 == pass)
			{
				f.close();
				return stt;
			}
			else
			{
				f.close();
				return 0;
			}
		}
		getline(f, s3);//lay mat khau
	}
	f.close();
	return 0;
}

bool User::logInUser()
{
	cout << "ID: ";
	getline(cin, ID);
	cout << "Password: ";
	getline(cin, pass);
	if (getSttUser(ID, pass) == 0)
	{
		return false;
	}
	return true;
}

int User::ktUserTonTai(string ID)
{
	ifstream f;
	f.open("User.txt");
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return 0;
	}
	string s1, s2, s3, s4, s5;
	while (!f.eof())
	{
		getline(f, s1); //lay ten
		name = s1;
		if (s1 == "") //truong hop file rong
		{
			return 0;
		}
		getline(f, s4);//lay tuoi
		tuoi = stoi(s4);
		getline(f, s5);//lay gioi tinh
		gioiTinh = stoi(s5);
		getline(f, s2);//lay ID
		if (s2 == ID)
		{
			f.close();
		}
		getline(f, s3);//lay mat khau
		pass = s3;
	}
	f.close();
	return 0;
}

void User::addGioHang(Sach a, int soLuong)
{
	gioHang.addListHoaDon(a, soLuong);
}

void User::addGioHang(HoaDon hd)
{
	gioHang.addListHoaDon(hd);
}

void User::chinhSuaSoLuong()
{
	int n;
	string name, ID;
	cout << "Nhap ten quyen sach ban muon chinh sua so luong: ";
	getline(cin, name);
	cout << "Nhap ma sach quyen sach ban muon chinh sua so luong: ";
	getline(cin, ID);
	int pos = gioHang.timSach(name, ID);
	if (pos >= 0)
	{
		do
		{
			cout << "So luong ban muon la: ";
			cin >> n;
			if (n < 0)
			{
				cout << "So luong khong hop le!" << endl;
			}
		} while (n < 0);
		gioHang.setSoLuongAtPos(pos, n);

	}
	else
	{
		cout << "Quyen sach nay khong ton tai!" << endl;
		return;
	}
	cout << endl << "Chinh sua thanh cong!" << endl;
}

void User::xoaSach()
{
	int n;
	string name, ID;
	cout << "Nhap ten quyen sach ban muon xoa khoi gio hang: ";
	getline(cin, name);
	cout << "Nhap ma sach: ";
	getline(cin, ID);
	int pos = gioHang.timSach(name, ID);
	if (pos >= 0)
	{
		gioHang.xoaSach(pos);
	}
	else
	{
		cout << "Quyen sach nay khong ton tai!" << endl;
		return;
	}
	cout << endl << "Xoa thanh cong!" << endl;
}

void User::inGioHang()
{
	cout << "--------------GIO HANG----------------" << endl << endl;
	gioHang.inListHoaDon();
}

void User::thanhToan()
{
	inGioHang();
	cout << endl;
	cout << "*** Tong tien thanh toan: " << gioHang.getTongTien() << endl;
}

void User::capNhatGioHang(DanhSach ds)
{
	int select;
	int soLuong;
	cout << "***CAP NHAT GIO HANG***" << endl;
	cout << "1/ Them sach" << endl;
	cout << "2/ Chinh sua so luong sach" << endl;
	cout << "3/ Xoa sach khoi gio hang" << endl;
	do
	{
		cout << "Lua chon: ";
		cin >> select;
		if (select < 0)
		{
			cout << "Lua chon khong hop le!" << endl;
		}
	} while (select < 0);

	getchar();
	if (select == 1)
	{
		HoaDon hd;
		hd.timKiemVaThem(ds);
		addGioHang(hd);
	}
	else if (select == 2)
	{
		system("cls");
		inGioHang();
		cout << endl;
		chinhSuaSoLuong();
	}
	else
	{
		system("cls");
		inGioHang();
		cout << endl;
		xoaSach();
	}
}

void User::runUser(DanhSach& ds)
{
	dealProgram(ds); //cap nhat danh sach neu co khuyen mai
	int select = 0;
	do
	{
		cout << "1. Cap nhat gio hang." << endl;
		cout << "2. Thanh toan gio hang." << endl;
		cout << "3. Xem gio hang." << endl;
		cout << "4. Hop tin nhan." << endl;
		cout << "5. Thoat." << endl;
		cout << "Lua chon: ";
		cin >> select;
		getchar();
		if (select == 1)
		{
			system("cls");
			capNhatGioHang(ds);
			inGioHangLenFile();
			backToMenu(ds);
		}
		else if (select == 2)
		{
			system("cls");
			thanhToan();
			backToMenu(ds);
		}
		else if (select == 3)
		{
			system("cls");
			inGioHang();
			backToMenu(ds);
		}
		else if (select == 4)
		{
			system("cls");
			cout << "------HOP THU------" << endl;
			cout << "1. Doc tin nhan moi cua ban." << endl;
			cout << "2. Gui tin nhan" << endl;
			cout << "3. Tim kiem cuoc tro chuyen." << endl;
			cout << "4. Thoat." << endl;
			int choose;
			do
			{
				cout << "Lua chon: ";
				cin >> choose;
				if (choose < 1 || choose>4)
				{
					cout << "Khong hop le!" << endl;
				}
			} while (choose < 1 || choose > 4);
			getchar();
			if (choose == 1)//xem tin nhan moi
			{
				vector <string > newSender;
				newSender = newMessage();
				if (newSender.empty())
				{
					cout << "Khong co tin nhan moi nao gui den cho ban!" << endl;
				}
				else
				{
					int stt = 1;
					cout << "------TIN NHAN MOI-----" << endl << endl;
					for (int i = 0; i < newSender.size(); i++)
					{
						if (i % 2 == 0)
						{
							cout << stt << "/ " << newSender[i];
							stt++;
							cout << endl;
						}
					}
					int chon;
					do
					{
						cout << endl << "Lua chon tin nhan ban muon xem: ";
						cin >> chon;
						if (chon<1 || chon>newSender.size() / 2)
						{
							cout << "Khong hop le!" << endl;
						}
					} while (chon<1 || chon>newSender.size() / 2);
					findAndReadConversation(newSender[chon * 2 - 2]);
					updateMessage(newSender[chon * 2 - 2]);
				}
			}
			else if (choose == 2)
			{
				system("cls");
				string receiverID;
				cout << "Nhap ID nguoi ban muon gui tin: ";
				getline(cin, receiverID);
				sendMessage(receiverID);
			}
			else if (choose == 3)
			{
				system("cls");
				string friendID;
				cout << "Nhap ID ban muon xem cuoc tro chuyen: ";
				getline(cin, friendID);
				findAndReadConversation(friendID);
			}
			else
			{
				backToMenu(ds);
			}
		}
		else if (select == 5)
		{
			return;
		}
		else
		{
			cout << "Khong hop le!" << endl;
		}
	} while (select < 1 || select > 5);
}

void User::runUserGuestMode(DanhSach& ds, Sach a)
{
	int select;
	int soLuong;
	dealProgram(ds, a);
	do
	{
		system("cls");
		cout << "------------USER------------- " << endl;
		cout << endl;
		cout << "1. Them sach vua tim vao gio hang." << endl;
		cout << "2. Cap nhat gio hang." << endl;
		cout << "3. Thanh toan gio hang." << endl;
		cout << "4. Xem gio hang." << endl;
		cout << "5. Hop tin nhan." << endl;
		cout << "6. Thoat." << endl;
		cout << endl;
		do
		{
			cout << "Lua chon: ";
			cin >> select;
			if (select < 0)
			{
				cout << "Lua chon khong hop le!" << endl;
			}
		} while (select < 0);

		if (select == 1)
		{
			do
			{
				cout << "Nhap so luong sach: ";
				cin >> soLuong;
				if (soLuong <= 0)
				{
					cout << "So luong khong hop le!" << endl;
				}
			} while (soLuong <= 0);
			addGioHang(a, soLuong);
			inGioHangLenFile();
			backToMenu(ds);
		}
		else if (select == 2)
		{
			system("cls");
			capNhatGioHang(ds);
			inGioHangLenFile();
			backToMenu(ds);
		}
		else if (select == 3)
		{
			system("cls");
			thanhToan();
			backToMenu(ds);
		}
		else if (select == 4)
		{
			system("cls");
			inGioHang();
			backToMenu(ds);
		}
		else if (select == 5)
		{
			system("cls");
			cout << "------HOP THU------" << endl;
			cout << "1. Doc tin nhan moi cua ban." << endl;
			cout << "2. Gui tin nhan" << endl;
			cout << "3. Tim kiem cuoc tro chuyen." << endl;
			cout << "4. Thoat." << endl;
			int choose;
			do
			{
				cout << "Lua chon: ";
				cin >> choose;
				if (choose < 1 || choose>4)
				{
					cout << "Khong hop le!" << endl;
				}
			} while (choose < 1 || choose > 4);
			if (choose == 1)//xem tin nhan moi
			{
				vector <string > newSender;
				newSender = newMessage();
				if (newSender.empty())
				{
					cout << "Khong co tin nhan moi nao gui den cho ban!" << endl;
				}
				else
				{
					int stt = 1;
					cout << "------TIN NHAN MOI-----" << endl << endl;
					for (int i = 0; i < newSender.size(); i++)
					{
						if (i % 2 == 0)
						{
							cout << stt << "/ " << newSender[i];
							stt++;
						}
					}
					int chon;
					do
					{
						cout << "Lua chon tin nhan ban muon xem: ";
						cin >> chon;
						if (chon<1 || chon>newSender.size() / 2)
						{
							cout << "Khong hop le!" << endl;
						}
					} while (chon<1 || chon>newSender.size() / 2);
					findAndReadConversation(newSender[chon * 2 - 2]);
					updateMessage(newSender[chon * 2 - 2]);
				}
			}
			else if (choose == 2)
			{
				system("cls");
				string receiverID;
				cout << "Nhap ID nguoi ban muon gui tin: ";
				getline(cin, receiverID);
				sendMessage(receiverID);
			}
			else if (choose == 3)
			{
				system("cls");
				string friendID;
				cout << "Nhap ID ban muon xem cuoc tro chuyen: ";
				getline(cin, friendID);
				findAndReadConversation(friendID);
			}
			else
			{
				backToMenu(ds);
			}
		}
		else
		{
			cout << "Thoat chuong trinh!" << endl;
			return;
		}
		_getch();
	} while (select != 6);
}

void User::backToMenu(DanhSach& ds)
{
	cout << endl << "-------------------------" << endl;
	int select = 0;
	do
	{
		cout << "1. Quay tro lai menu truoc do." << endl;
		cout << "2. Thoat." << endl;
		cout << "Lua chon: ";
		cin >> select;
		getchar();
		if (select == 1)
		{
			system("cls");
			runUser(ds);
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

void User::inGioHangLenFile()
{
	ofstream file;
	string nameFile;
	nameFile = "User" + to_string(getSttUser(ID, pass)) + ".txt";
	file.open(nameFile);
	if (!file)
	{
		cout << "Error to open file!" << endl;
		return;
	}
	gioHang.ghiLenFile(file);
	file.close();
}

void User::docGioHangTuFile()
{
	ifstream file;
	string nameFile = "User" + to_string(getSttUser(ID, pass)) + ".txt";
	file.open(nameFile);
	if (!file)
	{
		//neu file chua ton tai thi tao file moi
		fstream f;
		f.open(nameFile);
		f.close();
		return;
	}

	while (!file.eof())
	{
		Sach temp;
		string str;
		int n;
		getline(file, str);
		if (str == "")
		{
			return;
		}
		temp.updateTenSach(str);
		getline(file, str);
		temp.updateMaSach(str);
		getline(file, str);
		temp.updateAuthor(str);
		getline(file, str);
		temp.updateNXB(str);
		getline(file, str);
		temp.updateGiaTien(stoi(str));
		getline(file, str);
		temp.setHide(stoi(str));
		getline(file, str);
		n = stoi(str);
		addGioHang(temp, n);
	}
	file.close();
}

bool User::IDExist(string ID)
{
	ifstream f;
	string str;
	f.open("ID.txt");
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return false;
	}
	while (!f.eof())
	{
		getline(f, str);
		if (ID == str)
		{
			f.close();
			return true;
		}
	}
	f.close();
	return false;
}

void User::sendMessage(string receiverID)
{
	string str;
	string message;
	if (!IDExist(receiverID))
	{
		cout << "This ID does not exist!" << endl;
		return;
	}
	else
	{
		cout << "Moi nhap tin nhan: " << endl;
		getline(cin, message);
		ofstream f, file;
		string fileName = ID + ".txt";
		f.open(fileName, ios::app);
		fileName = receiverID + ".txt";
		file.open(fileName, ios::app);
		if (!f || !file)
		{
			cout << "Khong the gui tin nhan!" << endl;
			return;
		}
		f << receiverID << endl;
		f << "0" << "1" << message << endl;//0 thu 1 la ki hieu cua chuoi duoc gui di
		file << ID << endl;					//1 thu 2 la ki hieu tin nhan da duoc doc
		file << "1" << "0" <<message << endl;//1 la ki hieu cua chuoi nhan
		file.close();						//1 thu 2 la ki hieu cua tin nhan chua duoc doc
		f.close();
	}
}

void User::findAndReadConversation(string friendID)
{
	if (!IDExist(friendID))
	{
		cout << "The ID you find does not exist!" << endl;
		return;
	}
	string fileName = ID + ".txt";
	ifstream f;
	f.open(fileName);
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return;
	}
	string str, s;
	while (!f.eof())
	{
		getline(f, str); //lay ID nguoi cung tro chuyen
		getline(f, s); //lay tin nhan
		if (str == friendID)
		{
			if (s[0] == '0')
			{
				s=s.substr(2);
				cout << "You: " << s << endl;
			}
			else
			{
				s=s.substr(2);
				cout << friendID << ": " << s << endl;
			}
		}
	}
	f.close();
}

void User::updateMessage(string friendID)
{
	vector<string> newListMessage;
	string fileName = ID + ".txt";
	ifstream f;
	f.open(fileName);
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return;
	}
	string str, s;
	while (!f.eof())
	{
		getline(f, str); //lay ID nguoi cung tro chuyen
		if (str == "")
		{
			break;
		}
		getline(f, s); //lay tin nhan
		if (str == friendID)
		{
			s[1] = '1';//danh dau da doc tin nhan
		}
		newListMessage.push_back(str);
		newListMessage.push_back(s);
	}
	f.close();
	if (!newListMessage.empty())
	{
		//in tro lai vao file
		ofstream file;
		file.open(fileName);
		for (int i = 0; i < newListMessage.size(); i++)
		{
			file << newListMessage[i] << endl;
		}
		file.close();
	}	
}

vector <string> User::newMessage()
{
	vector <string> newSender;
	string fileName = ID + ".txt";
	ifstream f;
	f.open(fileName);
	if (!f)
	{
		f.close();
		fstream f;
		f.open(fileName);
	}
	else
	{
		string id, message;
		while (!f.eof())
		{
			getline(f, id); //lay id cua nguoi cung tro chuyen
			if (id == "")
			{
				return newSender;
			}
			getline(f, message); //lay tin nhan
			if (message[1] == '0')
			{
				newSender.push_back(id);
				newSender.push_back(message);
			}
		}
	}
	f.close();
	return newSender;
}

bool User::isOnDeal(int deal, int type)
{
	if (type == 5) //khuyen mai theo toi nguoi dung
	{
		if (tuoi == deal)
		{
			return true;
		}
	}
	else if (type == 6) //khuyen mai theo gioi tinh nguoi dung
	{
		if (gioiTinh == deal)
		{
			return true;
		}
	}
	return false;
}

int User::getTypeDeal()
{
	ifstream f;
	string str;
	int type;
	f.open("deal.txt");
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return 0;
	}
	while (!f.eof())
	{
		getline(f, str, '|');
		if (str == "") //truong hop file rong
		{
			return 0;
		}
		type = stoi(str);
		return type;
	}
	f.close();
}

int User::getNameDeal()
{
	ifstream f;
	string str;
	int type, deal=0;
	f.open("deal.txt");
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return deal;
	}
	while (!f.eof())
	{
		getline(f, str, '|');
		type = stoi(str);
		getline(f, str, '|');
		deal = stoi(str);
		return deal;
	}
	f.close();

}

float User::getDiscountDeal()
{
	ifstream f;
	string str;
	int type;
	float discount;
	f.open("deal.txt");
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return 0;
	}
	while (!f.eof())
	{
		getline(f, str, '|');//lay type
		getline(f, str, '|');//lay deal name
		getline(f, str);//lay discount;
		discount = stof(str);
		return discount;
	}
	f.close();
}

void User::dealProgram(DanhSach& ds)
{
	int deal;
	int type;
	float discount;
	type = getTypeDeal();
	if (type == 0)//file rong, khong co chuong trinh khuyen mai nao ca
	{
		return;
	}
	if (type == 5 || type == 6) //truong hop khuyen mai theo nguoi dung
	{
		deal = getNameDeal();
		discount = getDiscountDeal();
		if (isOnDeal(deal, type))
		{
			int currentPrice, afterDealPrice;
			for (int i = 0; i < ds.getSoLuong(); i++)
			{
				Sach temp;
				temp = ds.getSach(i);
				currentPrice = temp.getGiaTien();
				//tinh toan gia tien moi
				afterDealPrice = (int)(currentPrice * (1 - discount));
				ds.updateGiaTienAt(i, afterDealPrice);
			}
		}
	}
}

void User::dealProgram(DanhSach& ds, Sach& a)
{
	int deal;
	int type;
	float discount;
	type = getTypeDeal();
	if (type == 0)//file rong, khong co chuong trinh khuyen mai nao ca
	{
		return;
	}
	if (type == 5 || type == 6) //truong hop khuyen mai theo nguoi dung
	{
		deal = getNameDeal();
		discount = getDiscountDeal();
		if (isOnDeal(deal, type))
		{
			int currentPrice, afterDealPrice;
			for (int i = 0; i < ds.getSoLuong(); i++)
			{
				Sach temp;
				temp = ds.getSach(i);
				currentPrice = temp.getGiaTien();
				//tinh toan gia tien moi
				afterDealPrice = (int)(currentPrice * (1 - discount));
				ds.updateGiaTienAt(i, afterDealPrice);
			}
			//tinh toan lai gia tien cua quyen sach vua tim kiem trong che do guest
			currentPrice = a.getGiaTien();
			afterDealPrice = (int)(currentPrice * (1 - discount));
			a.updateGiaTien(afterDealPrice);
		}
	}
}