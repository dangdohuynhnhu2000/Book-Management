#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "ListHoaDon.h"

class User
{
protected:
	string name;
	int tuoi;
	int gioiTinh;
	//1: Nam
	//2: Nu
	//3: Khac
	string ID;
	string pass;
	ListHoaDon gioHang;
public:
	void setUser();
	void docGioHangTuFile();
	string getPassUser();
	string getNameUser();
	string getIDUser();
	int getTuoiUser();
	int getGioiTinhUser();
	int getSttUser(string ID, string pass);
	bool logInUser();
	int ktUserTonTai(string ID);//kiem tra user co ton tai trong file khong, neu co tra ve stt cua user
	void addGioHang(Sach a, int soLuong);
	void addGioHang(HoaDon hd);
	void inGioHangLenFile();
	void chinhSuaSoLuong();
	void xoaSach();
	void inGioHang();
	void thanhToan();
	void runUserGuestMode(DanhSach& ds, Sach a);
	void capNhatGioHang(DanhSach ds);
	void runUser(DanhSach& ds);
	void backToMenu(DanhSach& ds);
	bool IDExist(string ID);
	void sendMessage(string receiverID);
	void findAndReadConversation(string friendID);
	void updateMessage(string friendID);//dung de danh dau da doc tin nhan
	vector <string> newMessage(); //tra ve id va tin nhan cua nhung nguoi gui tin nhan moi den ban
	
	//nhom chuc nang khuyen mai
	
	bool isOnDeal(int deal, int type);//kiem tra xem user co thoa dieu kien khuyen mai hay khong
	int getTypeDeal();
	int getNameDeal();
	float getDiscountDeal();
	void dealProgram(DanhSach &ds);
	void dealProgram(DanhSach& ds, Sach& a);//danh cho che do guest
};
