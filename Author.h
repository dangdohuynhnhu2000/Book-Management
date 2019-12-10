#pragma once 
#include <string>
#include "DanhSach.h"
#include <fstream>
#include <iostream>
using namespace std;
class Author
{
protected:
	string name;
	int tuoi;
	int gioiTinh;
	string ID;
	string pass;
	DanhSach listSach;
public:
	void setAuthor();
	string getPassAuthor();
	string getNameAuthor();
	string getIDAuthor();
	int getTuoiAuthor();
	int getGioiTinhAuthor();
	void setListSachAuthor(DanhSach ds);
	void setNameAuthor(string name);
	bool ktAuthorTonTai(string ID);
	bool logInAuthor();
	void themSachAuthor(DanhSach& ds);
	void xoaSachAuthor(DanhSach& ds);
	void suaSachAuthor(DanhSach& ds);
	void inDanhSachAuthor();
	void runAuthor(DanhSach& ds);
	void backToMenu(DanhSach& ds);
	bool IDExist(string ID);
	void sendMessage(string receiverID);
	void findAndReadConversation(string friendID);
	void updateMessage(string friendID);
	vector <string> newMessage();
};
