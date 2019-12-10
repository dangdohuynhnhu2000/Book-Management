#include "Admin.h"

void Admin::setAdmin()
{
	cout << "Ten admin: ";
	getline(cin, name);
	do
	{
		cout << "Tuoi admin: ";
		cin >> tuoi;
		if (tuoi <= 0)
		{
			cout << "Khong hop le!" << endl;
		}
	} while (tuoi <= 0);

	do
	{
		cout << "Gioi tinh admin: " << endl;
		cout << "1. Nam, 2: Nu, 3: Khac" << endl;
		cin >> gioiTinh;
		if (gioiTinh < 1 || gioiTinh>3)
		{
			cout << "Khong hop le!" << endl;
		}
	} while (gioiTinh < 1 || gioiTinh>3);
	getchar();
	cout << "ID: ";
	getline(cin, ID);
	cout << "Password: ";
	getline(cin, pass);
}

void Admin::themAuthor()
{
	ofstream f;
	ofstream file;
	f.open("Author.txt", ios::app);
	file.open("ID.txt", ios::app);
	if (!f || !file)
	{
		cout << "Error to open file" << endl;
		return;
	}
	string passWord, nameAuthor, IDAuthor;
	int ageAuthor, sexAuthor;
	setAuthor();
	passWord = getPassAuthor();
	nameAuthor = getNameAuthor();
	IDAuthor = getIDAuthor();
	ageAuthor = getTuoiAuthor();
	sexAuthor = getGioiTinhAuthor();
	if (ktAuthorTonTai(IDAuthor) == false)
	{
		f << nameAuthor << endl;
		f << ageAuthor << endl;
		f << sexAuthor << endl;
		f << IDAuthor << endl;
		f << passWord << endl;
		file << IDAuthor << endl;
		cout << "Them Author thanh cong!" << endl;
	}
	else
	{
		cout << "Tai khoan nay da ton tai! " << endl;
	}
	f.close();
	file.close();
}

void Admin::themNXB()
{
	ofstream f;
	ofstream file;
	f.open("NXB.txt", ios::app);
	file.open("ID.txt", ios::app);
	if (!f || !file)
	{
		cout << "Error to open file" << endl;
		return;
	}
	string passWord, nameNXB, IDNXB;
	setNXB();
	passWord = getPassNXB();
	nameNXB = getNameNXB();
	IDNXB = getIDNXB();
	if (ktNXBTonTai(IDNXB) == false)
	{
		f << nameNXB << endl;
		f << IDNXB << endl;
		f << passWord << endl;
		file << IDNXB << endl;
		cout << "Them NXB thanh cong!" << endl;
	}
	else
	{
		cout << "Tai khoan nay da ton tai! " << endl;
	}
	f.close();
	file.close();
}

void Admin::themUser()
{
	ofstream f, file;
	f.open("User.txt", ios::app);
	file.open("ID.txt", ios::app);
	if (!f || !file)
	{
		cout << "Error to open file" << endl;
		return;
	}
	string passWord, nameUser, IDUser;
	int ageUser, sexUser;
	setUser();
	passWord = getPassUser();
	nameUser = getNameUser();
	IDUser = getIDUser();
	ageUser = getTuoiUser();
	sexUser = getGioiTinhUser();

	if (ktUserTonTai(IDUser) == false)
	{
		f << nameUser << endl;
		f << ageUser << endl;
		f << sexUser << endl;
		f << IDUser << endl;
		f << passWord << endl;
		file << IDUser << endl;
		cout << "Them User thanh cong!" << endl;
	}
	else
	{
		cout << "Tai khoan nay da ton tai! " << endl;
	}
	f.close();
	file.close();
}

void Admin::themSachByAdmin(DanhSach& ds)
{
	Sach temp;
	temp.nhapTenSach();
	temp.nhapMaSach();
	temp.nhapAuthor();
	temp.nhapNXB();
	temp.nhapGiaTien();
	ds.themSach(temp);
	ofstream file;
	file.open("DanhSach.txt");
	if (!file)
	{
		cout << "Error to open file!" << endl;
		return;
	}
	ds.ghiLenFile();
	file.clear();
	cout << "Them sach thanh cong!" << endl;

}

void Admin::xoaSachByAdmin(DanhSach& ds)
{
	string name;
	cout << "Moi nhap ten quyen sach ban muon xoa: ";
	getline(cin, name);
	ds.deleteBook(name);
	ofstream file;
	file.open("DanhSach.txt");
	if (!file)
	{
		cout << "Error to open file!" << endl;
		return;
	}
	ds.ghiLenFile();
	file.close();
}

void Admin::suaSachByAdmin(DanhSach& ds)
{
	string ten, ma, NXB, author;
	string tenSach;
	int tien;
	cout << "Moi nhap ten quyen sach ban muon sua thong tin: ";
	getline(cin, tenSach);
	int index = ds.findBook(tenSach);
	if (index != -2)
	{
		cout << "Ten sach moi: ";
		getline(cin, ten);
		ds.updateTenSachAt(index, ten);
		cout << "Ma sach moi: ";
		getline(cin, ma);
		ds.updateMaSachAt(index, ma);
		cout << "NXB moi: ";
		getline(cin, NXB);
		ds.updateNXBAt(index, NXB);
		cout << "Gia tien moi: ";
		cin >> tien;
		ds.updateGiaTienAt(index, tien);
		cout << "Sua sach thanh cong!" << endl;
	}
	ofstream file;
	file.open("DanhSach.txt");
	if (!file)
	{
		cout << "Error to open file!" << endl;
		return;
	}
	ds.ghiLenFile();
	file.close();

}

bool Admin::ktAdminTonTai(string ID)
{
	ifstream f;
	f.open("Admin.txt");
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return false;
	}
	string s1, s2, s3, s4, s5;
	while (!f.eof())
	{
		getline(f, s1); //lay ten
		name = s1;
		getline(f, s4);//lay tuoi
		tuoi = stoi(s4);
		getline(f, s5);//lay gioi tinh
		gioiTinh = stoi(s5);
		getline(f, s2);//lay ID
		if (s2 == ID)
		{
			f.close();
			return true;
		}
		getline(f, s3);//lay mat khau
		pass = s3;
	}
	f.close();
	return false;
}

bool Admin::logInAdmin()
{
	cout << "ID: ";
	getline(cin, ID);
	cout << "Password: ";
	getline(cin, pass);
	ifstream f;
	f.open("Admin.txt");
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return false;
	}
	string s1, s2, s3, s4, s5;
	while (!f.eof())
	{
		getline(f, s1);//lay ten
		name = s1;
		getline(f, s4);//lay tuoi
		tuoi = stoi(s4);
		getline(f, s5);//lay gioi tinh
		gioiTinh = stoi(s5);
		getline(f, s2);//lay ID
		if (s2 == ID)
		{
			getline(f, s3);//lay mat khau
			if (s3 == pass)
			{
				f.close();
				return true;
			}
			else
			{
				f.close();
				return false;
			}
		}
		getline(f, s3);//lay mat khau
	}
	f.close();
	return false;
}

void Admin::runAdmin(DanhSach& ds)
{
	int select = 0;
	do
	{
		system("cls");
		cout << "-----ADMIN------" << endl << endl;
		cout << "1. Them NXB." << endl;
		cout << "2. Them Author." << endl;
		cout << "3. Them User." << endl;
		cout << "4. Them sach." << endl;
		cout << "5. Sua sach." << endl;
		cout << "6. Xoa sach." << endl;
		cout << "7. Xem sach." << endl;
		cout << "8. Hop tin nhan." << endl;
		cout << "9. Tao chuong trinh khuyen mai." << endl;
		cout << "10. Thoat." << endl;
		cout << "Lua chon: ";
		cin >> select;
		getchar();
		if (select == 1)
		{
			system("cls");
			themNXB();
			backToMenu(ds);
		}
		else if (select == 2)
		{
			system("cls");
			themAuthor();
			backToMenu(ds);
		}
		else if (select == 3)
		{
			system("cls");
			themUser();
			backToMenu(ds);
		}
		else if (select == 4)
		{
			system("cls");
			themSachByAdmin(ds);
			backToMenu(ds);
		}
		else if (select == 5)
		{
			system("cls");
			suaSachByAdmin(ds);
			backToMenu(ds);
		}
		else if (select == 6)
		{
			system("cls");
			xoaSachByAdmin(ds);
			backToMenu(ds);
		}
		else if (select == 7)
		{
			ds.inDanhSach();
			backToMenu(ds);
		}
		else if (select == 8)
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
		else if (select == 9)
		{
			system("cls");
			int type;
			string dealName1;
			int dealName2;
			float discount;
			type = setTypeDeal();
			discount = setDiscount();
			getchar();
			if (type >= 1 && type <= 4)
			{
				dealName1 = setNameDealString(type);
				setDealProgram<string>(dealName1, type, discount);
			}
			else
			{
				dealName2 = setNameDealInt(type);
				setDealProgram<int>(dealName2, type, discount);
			}
		}
		else if (select == 10)
		{
			return;
		}
		else
		{
			cout << "Khong hop le!" << endl;
		}
	} while (select < 1 || select > 10);
}

void Admin::backToMenu(DanhSach& ds)
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
			runAdmin(ds);
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

bool Admin::IDExist(string ID)
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

void Admin::sendMessage(string receiverID)
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
		file << "1" << "0" << message << endl;//1 la ki hieu cua chuoi nhan
		file.close();						//1 thu 2 la ki hieu cua tin nhan chua duoc doc
		f.close();
	}
}

void Admin::findAndReadConversation(string friendID)
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
				s = s.substr(2);
				cout << "You: " << s << endl;
			}
			else
			{
				s = s.substr(2);
				cout << friendID << ": " << s << endl;
			}
		}
	}
	f.close();
}

void Admin::updateMessage(string friendID)
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

vector <string> Admin::newMessage()
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

int Admin::setTypeDeal()
{
	int type;
	cout << "1. Deal theo ten sach." << endl;
	cout << "2. Deal theo ma sach." << endl;
	cout << "3. Deal theo ten tac gia." << endl;
	cout << "4. Deal theo ten NXB." << endl;
	cout << "5. Deal theo tuoi nguoi dung." << endl;
	cout << "6. Deal theo gioi tinh nguoi dung." << endl;
	do
	{
		cout << "Lua chon: ";
		cin >> type;
		if (type < 1 || type>6)
		{
			cout << "Khong hop le!" << endl;
		}
	} while (type < 1 || type>6);
	getchar();
	return type;
}

string Admin::setNameDealString(int type)
{
	string str;
	if (type == 1)
	{
		cout << "Nhap ten sach: ";
		getline(cin, str);
	}
	else if (type == 2)
	{
		cout << "Nhap ma sach: ";
		getline(cin, str);
	}
	else if (type == 3)
	{
		cout << "Nhap ten tac gia: ";
		getline(cin, str);
	}
	else if (type == 4)
	{
		cout << "Nhap ten NXB: ";
		getline(cin, str);
	}
	return str;
}

int Admin::setNameDealInt(int type)
{
	int x;
	if (type == 5)
	{
		cout << "Nhap do tuoi nguoi dung: ";
		cin >> x;
	}
	else
	{
		cout << "Nhap gioi tinh nguoi dung: ";
		cin >> x;
	}
	return x;
}

float Admin::setDiscount()
{
	float discount;
	cout << "Nhap discount: ";
	cin >> discount;
	return discount;
}

