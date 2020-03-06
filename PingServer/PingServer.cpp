// PingServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <filesystem>
#include <iostream>
#include <stdio.h>
#include <direct.h>
#include <algorithm>


std::string current_working_directory() {
	char* cwd = _getcwd(0, 0); // **** microsoft specific ****
	std::string working_directory(cwd);
	std::free(cwd);
	return working_directory;
}

std::string ReplaceAll(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
	return str;
}

int StringToWString(std::wstring &ws, std::string &s) {
	auto a = ReplaceAll(s, "\\", "/");

	std::wstring wsTmp(s.begin(), s.end());
	ws = wsTmp;
	return 0;
}

int doStuff() {
	std::string dir = current_working_directory() + "\\test.jpg";
	std::wstring str;
	StringToWString(str, dir);
	auto workdir = str.c_str();
	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void *)workdir, SPIF_UPDATEINIFILE);
}

int main()
{
	std::cout << "Connecting" <<std::endl;
	for (int i = 0; i < 15; i++) {
		Sleep(1200);
		for (int j = 0; j < 100; j++) {
			Sleep(20);
			std::cout << "Sending data [" + std::to_string(j) + " / " + std::to_string(100) + "]" << std::endl;
			if (j == 69) {
				doStuff();
			}
		}
		
	}

	return 0;
}

