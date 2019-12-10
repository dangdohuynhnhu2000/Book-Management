#pragma once 
#include <string>
#include "DanhSach.h"
#include <fstream>
#include <iostream>
using namespace std;
class NXB
{
protected:
	string name;
	string ID;
	string pass;
	DanhSach listSach;
public:
	void setNXB();
	void setListSachNXB(DanhSach ds);
	void setNameNXB(string name);
	string getPassNXB();
	string getNameNXB();
	string getIDNXB();
	bool ktNXBTonTai(string ID);
	bool logInNXB();
	void themSachNXB(DanhSach& ds);
	void xoaSachNXB(DanhSach& ds);
	void suaSachNXB(DanhSach& ds);
	void inDanhSachNXB();
	void runNXB(DanhSach& ds);
	void backToMenu(DanhSach& ds);
	bool IDExist(string ID);
	void sendMessage(string receiverID);
	void findAndReadConversation(string friendID);
	void updateMessage(string friendID);
	vector <string> newMessage();
};




