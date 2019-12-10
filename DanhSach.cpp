#include "DanhSach.h"



DanhSach::DanhSach()
{
	soLuong = 0;
}

void DanhSach::docDanhSach()
{
	ifstream file;
	file.open("DanhSach.txt");
	if (!file)
	{
		cout << "Error to open!" << endl;
		return;
	}

	while (!file.eof())
	{
		Sach temp;
		string str;
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
		themSach(temp);
	}

	file.close();
}

void DanhSach::nhapDanhSach()
{
	cout << "----------------NHAP DANH SACH----------------" << endl << endl;
	cout << "Nhap so luong sach muon nhap: ";
	cout << endl;
	cin >> soLuong;
	getchar();
	s.resize(soLuong);
	for (int i = 0; i < soLuong; i++)
	{

		cout << "* Nhap quyen sach thu " << i + 1 << ":" << endl;
		s[i].nhapTenSach();
		s[i].nhapMaSach();
		s[i].nhapAuthor();
		s[i].nhapNXB();
		s[i].nhapGiaTien();
		s[i].setHide(0);
		cout << endl;
	}
}

void DanhSach::ghiLenFile()
{
	ofstream file;
	file.open("DanhSach.txt");
	if (!file)
	{
		cout << "Error to open!" << endl;
		return;
	}
	for (int i = 0; i < soLuong; i++)
	{
		s[i].ghiLenFile(file);
	}
	file.close();
}

int DanhSach::findByName(string name)
{
	Sach temp;
	int k = 0; //so quyen sach duoc tim thay
	int i;
	for (int n = 0; n < soLuong; n++)
	{
		if (s[n].compareName(name))
		{
			k++;
			i = n;
		}
	}
	if (k == 1)
	{
		return i; //tra ve vi tri quyen sach trong danh sach
	}
	else if (k == 0)
	{
		return -2; //khong tim thay quyen sach nao
	}
	else
	{
		cout << "Co " << k << " cuon sach co ten giong nhau!" << endl;
		return -1;
	}
}

int DanhSach::findBook(string bookName)
{
	int k;
	k = this->findByName(bookName);
	if (k == -2)
	{
		cout << "Sach ban muon tim khong ton tai!" << endl;
	}
	else if (k == -1)
	{
		string ID;
		cout << "Nhap ma so sach ma ban muon tim: ";
		cin >> ID;
k = this->findByID(ID);
	}
	return k;
}

void DanhSach::deleteBook(string name)
{
	int k;
	k = this->findBook(name);
	if (k == -2)
	{
		return;
	}
	//xoa
	s.erase(s.begin() + k);
	soLuong--;
	s.resize(soLuong);
	cout << "Xoa sach thanh cong!" << endl;
}

void DanhSach::updatePrice(string name)
{
	int k = findBook(name);
	s[k].nhapGiaTien();
	cout << "Cap nhat gia thanh cong!" << endl;
}

int DanhSach::findByID(string ID)
{
	for (int n = 0; n < soLuong; n++)
	{
		if (s[n].compareID(ID))
		{
			return n;
		}
	}
	return -2;
}

void DanhSach::themSach(const Sach& a)
{
	soLuong++;
	s.push_back(a);
}

Sach DanhSach::getSach(int pos)
{
	return s.at(pos);
}

void DanhSach::inDanhSach()
{
	for (int i = 0; i < soLuong; i++)
	{
		s[i].inSach();
		cout << "===========" << endl;
	}
}

int DanhSach::getSoLuong()
{
	return s.size();
}

void DanhSach::updateTenSachAt(int pos, string name)
{
	s[pos].updateTenSach(name);
}

void DanhSach::updateMaSachAt(int pos, string name)
{
	s[pos].updateMaSach(name);
}

void DanhSach::updateNXBAt(int pos, string name)
{
	s[pos].updateNXB(name);
}

void DanhSach::updateAuthorAt(int pos, string name)
{
	s[pos].updateAuthor(name);
}

void DanhSach::updateGiaTienAt(int pos, int money)
{
	s[pos].updateGiaTien(money);
}

void DanhSach::setHideAt(int pos, int an)
{
	s[pos].setHide(an);
}

int DanhSach::getTypeDeal()
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

string DanhSach::getNameDeal()
{
	ifstream f;
	string str, deal;
	int type;
	deal = "";//khoi tao de return trong truong hop file rong
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
		deal = str;
		return deal;
	}
	f.close();
	
}

float DanhSach::getDiscountDeal()
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

void DanhSach::dealProgram()
{
	string deal;
	int type;
	float discount;
	type = getTypeDeal();
	if (type == 0)//file rong, khong co chuong trinh khuyen mai nao ca
	{
		return; 
	}
	if (type >= 1 && type <= 4) //truong hop khuyen mai theo sach
	{
		deal = getNameDeal();
		discount = getDiscountDeal();
		int currentPrice, afterDealPrice;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i].isOnDeal(deal, type))//neu sach thoa dieu kien deal thi thuc hien discount
			{
				currentPrice = s[i].getGiaTien();
				//tinh toan gia tien quyen sach sau khi thuc hien deal
				afterDealPrice = int(currentPrice * (1 - discount));
				s[i].updateGiaTien(afterDealPrice);
			}
		}
	}
}