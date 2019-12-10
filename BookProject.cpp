// 18120219.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Header.h"

int main()
{
	DanhSach ds;
	ds.docDanhSach();
	ds.dealProgram();
	runMainMenu(ds);
	_getch();
	return 0;
}
