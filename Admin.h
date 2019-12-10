#pragma once
#include "Author.h"
#include "NXB.h"
#include "User.h"
#include <fstream>
class Admin : public Author, NXB, User
{
protected:
	string name;
	int tuoi;
	int gioiTinh;
	string ID;
	string pass;
public:
	void setAdmin();
	void themAuthor();
	void themNXB();
	void themUser();
	void themSachByAdmin(DanhSach& ds);
	void xoaSachByAdmin(DanhSach& ds);
	void suaSachByAdmin(DanhSach& ds);
	bool ktAdminTonTai(string ID);
	bool logInAdmin();
	void runAdmin(DanhSach& ds);
	void backToMenu(DanhSach& ds);

	//nhom chuc nang tin nhan
	bool IDExist(string ID);
	void sendMessage(string receiverID);
	void findAndReadConversation(string friendID);
	void updateMessage(string friendID);
	vector <string> newMessage();

	//nhom chuc nang khuyen mai
	int setTypeDeal();
	string setNameDealString(int type);
	int setNameDealInt(int type);
	float setDiscount();
	template <typename T>
	void setDealProgram(T deal, int type, float discount)
	{
		//ghi deal len file
		ofstream f;
		f.open("deal.txt");
		if (!f)
		{
			cout << "Error to open file!" << endl;
			return;
		}
		f << type << "|" << deal << "|" << discount << endl;
		f.close();
	}
};


