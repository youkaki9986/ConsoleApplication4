// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"locale.h"
#include <windows.h>
#include"atlbase.h"
#include"TlHelp32.h"
#include <stdio.h>
#include <string.h>
#include <string>

#include<tchar.h>
#include<iostream>
#include<assert.h>
#include<fstream>
using namespace std;
//#import "CSApplicationUp.tlb" named_guids raw_interfaces_only
#import "ClassLibrary.tlb" named_guids raw_interfaces_only
#pragma   comment(linker,   "/subsystem:\"windows\"   /entry:\"mainCRTStartup\""   ) 




unsigned char ToHex(unsigned char x)
{
	return  x > 9 ? x + 55 : x + 48;
}

unsigned char FromHex(unsigned char x)
{
	unsigned char y;
	if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
	else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
	else if (x >= '0' && x <= '9') y = x - '0';
	else assert(0);
	return y;
}

std::string UrlEncode(const std::string& str)
{
	std::string strTemp = "";
	size_t length = str.length();
	for (size_t i = 0; i < length; i++)
	{
		if (isalnum((unsigned char)str[i]) ||
			(str[i] == '-') ||
			(str[i] == '_') ||
			(str[i] == '.') ||
			(str[i] == '~'))
			strTemp += str[i];
		else if (str[i] == ' ')
			strTemp += "+";
		else
		{
			strTemp += '%';
			strTemp += ToHex((unsigned char)str[i] >> 4);
			strTemp += ToHex((unsigned char)str[i] % 16);
		}
	}
	return strTemp;
}

std::string UrlDecode(const std::string& str)
{
	std::string strTemp = "";
	size_t length = str.length();
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == '+') strTemp += ' ';
		else if (str[i] == '%')
		{
			assert(i + 2 < length);
			unsigned char high = FromHex((unsigned char)str[++i]);
			unsigned char low = FromHex((unsigned char)str[++i]);
			strTemp += high * 16 + low;
		}
		else strTemp += str[i];
	}
	return strTemp;
}


LRESULT CALLBACK ConsoleApplication41(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}


int main(int argc, char * argv[])
{




	


	//_tsetlocale(LC_ALL, _T("chs"));
	_tprintf(_T("参数: %d 个\n"), argc);



	for (int i = 1; i < argc; ++i)
	{
		printf("输入参数 [%d] = [%s]\n", i, argv[i]);

	}
	printf("%s\n", argv[0]);//获取程序名称 索引为0
	printf("%s\n", argv[1]);//获取程序第一个参数索引为1
	printf("%s\n", argv[2]);//获取程序第二个参数索引为2


	std::string strPath1 = argv[0];
	std::string strPath = argv[1];
	std::string name = strPath.substr(8, strPath.size() - 9);
	int a = 1656;


	printf("%s", name.c_str());
	string str_ansi_en = UrlEncode(name);


	//string str_ansi_de = UrlDecode(name);
	////printf("%i", a);
	printf("%s", str_ansi_en.c_str());



	DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)ConsoleApplication41);


	//printf("%s", strPath.c_str());



	//printf(name.c_str());


	//std::string name1 = name.substr(0, name.size() - 1);

	//printf("%s", name1.c_str());
	CComBSTR infa("sdf");

	CComBSTR resss("sdfgdsfgsd");
	CComBSTR res;
	CComBSTR resds;
	CComBSTR inf(name.c_str());
	CComBSTR res1("fgh");
	const char *str1 = "off";
	const char *str2 = "off";
	CoInitialize(NULL);
	//CSApplicationUp::IMyInterfacePtr p;
	//HRESULT hs = p.CreateInstance(_uuidof(CSApplicationUp::Class1));
	ClassLibrary::IMyInterfacePtr lib;
	HRESULT hs = lib.CreateInstance(_uuidof(ClassLibrary::ConnentEDM3));

	
	//int a = (int)hs;
	//printf("%i", a);


	

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		printf(" CreateToolhelp32Snapshot调用失败！ \n");
	
		return 0;
	}
	
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		//printf(" 进程名称：%f \n", pe32.szExeFile);

		_bstr_t b(pe32.szExeFile);
		const char*pe3 = b;
		if (_stricmp("EDM3.exe", pe3) == 0)
		{
			str2 = "open";
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);
	}
	if (_stricmp(str1, str2) == 0) {

		lib->OpenEDM3(res1);
	

		str2 = "off";


	
	}
	else
	{
		lib->ConnentEDM3Res(&infa);

		lib->Send(inf, &resss);
		

	
	}

	
	
	Sleep( 120 * 1000);

	



	return 0;


	

}

