#include "NXB.h"

void NXB::setListSachNXB(DanhSach ds)
{
	Sach temp;
	for (int i = 0; i < ds.getSoLuong(); i++)
	{
		temp = ds.getSach(i);
		if (temp.getNXB() == name)
		{
			listSach.themSach(temp);
		}
	}
}

void NXB::setNameNXB(string name)
{
	this->name = name;
}

void NXB::themSachNXB(DanhSach& ds)
{
	Sach temp;
	temp.nhapTenSach();
	temp.nhapMaSach();
	temp.nhapAuthor();
	temp.nhapGiaTien();
	temp.setNXB(name);
	ds.themSach(temp);
	listSach.themSach(temp);
	cout << "Them sach thanh cong!" << endl;
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

void NXB::xoaSachNXB(DanhSach& ds)
{
	inDanhSachNXB();
	string name;
	cout << "Moi nhap ten quyen sach ban muon xoa: ";
	getline(cin, name);
	int pos = ds.findBook(name);
	if (pos == -2)
	{
		return;
	}
	ds.setHideAt(pos, 1);
	listSach.deleteBook(name);
	ofstream file;
	file.open("DanhSach.txt");
	if (!file)
	{
		cout << "Error to open file!" << endl;
		return;
	}
	ds.ghiLenFile();
	file.clear();
}

void NXB::suaSachNXB(DanhSach& ds)
{
	inDanhSachNXB();
	string ten, ma, author;
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
		listSach.updateTenSachAt(index, ten);
		cout << "Ma sach moi: ";
		getline(cin, ma);
		ds.updateMaSachAt(index, ma);
		listSach.updateMaSachAt(index, ma);
		cout << "Tac gia moi: ";
		getline(cin, author);
		ds.updateAuthorAt(index, author);
		listSach.updateAuthorAt(index, author);
		cout << "Gia tien moi: ";
		cin >> tien;
		ds.updateGiaTienAt(index, tien);
		listSach.updateGiaTienAt(index, tien);
		ds.setHideAt(index, 0);
		listSach.setHideAt(index, 0);
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
	file.clear();
}

void NXB::inDanhSachNXB()
{
	listSach.inDanhSach();
}

bool NXB::logInNXB()
{
	cout << "ID: ";
	getline(cin, ID);
	cout << "Password: ";
	getline(cin, pass);
	ifstream f;
	f.open("NXB.txt");
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return false;
	}
	string s1, s2, s3;
	while (!f.eof())
	{
		getline(f, s1);//lay ten
		name = s1;
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

void NXB::setNXB()
{
	cout << "Ten NXB: ";
	getline(cin, name);
	cout << "ID: ";
	getline(cin, ID);
	cout << "Password: ";
	getline(cin, pass);
}

string NXB::getPassNXB()
{
	return pass;
}

string NXB::getNameNXB()
{
	return name;
}

string NXB::getIDNXB()
{
	return ID;
}

bool NXB::ktNXBTonTai(string ID)
{
	ifstream f;
	f.open("NXB.txt");
	if (!f)
	{
		cout << "Error to open file!" << endl;
		return false;
	}
	string s1, s2, s3;
	while (!f.eof())
	{
		getline(f, s1); //lay ten
		name = s1;
		if (s1 == "") //truong hop file rong
		{
			return false;
		}
		getline(f, s2);//lay ID
		if (s2 == ID)
		{
			f.close();
			return true;
		}
		getline(f, s3); //lay mat khau
		pass = s3;
	}
	f.close();
	return false;
}

void NXB::runNXB(DanhSach& ds)
{
	int select = 0;
	setListSachNXB(ds);
	do
	{
		cout << "-----NHA XUAT BAN------" << endl << endl;
		cout << "1. Them sach." << endl;
		cout << "2. Sua sach." << endl;
		cout << "3. Xoa sach." << endl;
		cout << "4. Xem list sach cua NXB." << endl;
		cout << "5. Hop tin nhan." << endl;
		cout << "6. Thoat." << endl;
		cout << "Lua chon: ";
		cin >> select;
		getchar();
		if (select == 1)
		{
			themSachNXB(ds);
			backToMenu(ds);
		}
		else if (select == 2)
		{
			suaSachNXB(ds);
			backToMenu(ds);
		}
		else if (select == 3)
		{
			xoaSachNXB(ds);
			backToMenu(ds);
		}
		else if (select == 4)
		{
			listSach.inDanhSach();
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
		else if (select == 6)
		{
			return;
		}
		else
		{
			cout << "Khong hop le!" << endl;
		}
	} while (select < 1 || select > 5);
}

void NXB::backToMenu(DanhSach& ds)
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
			runNXB(ds);
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

bool NXB::IDExist(string ID)
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

void NXB::sendMessage(string receiverID)
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

void NXB::findAndReadConversation(string friendID)
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

void NXB::updateMessage(string friendID)
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

vector <string> NXB::newMessage()
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
