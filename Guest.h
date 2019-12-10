#pragma once
#include "DanhSach.h"
#include "User.h"

class Guest : public DanhSach
{
public:
	void timSach(DanhSach ds);
	bool dangKyUser(User& user);
	void runGuest(DanhSach ds, Sach book);
};

