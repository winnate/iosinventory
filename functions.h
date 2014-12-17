#pragma once
#include <cstring>
#include <cstring>
#include <iostream>
using namespace std;

class iosDevice {
public:
	iosDevice();
	void showPart(int device, int part);
	void showModel(int device, int model);
	void showDevice(int device);
	int getPartCount(int part, int model, int device);
	int setPartCount(int part);
	bool add = true;
	void showModelList(int device);
	void showPartList(int device);
	void setInventory(int part, int model, int device);
	void addInventory(int part, int model, int device, int amountAdd);
	void removeInventory(int part, int model, int device, int amountAdd);
protected:
	string iPhoneModelList[9] = {"3G", "3GS", "4", "4S", "5", "5C", "5S", "6", "6+"};
	string iPadModelList[6] = {"1stGen", "2ndGen", "3rdGen", "4thGen", "Air   ", "Air2"};
	string iPodModelList[5] = {"1stGen","2ndGen", "3rdGen", "4thGen", "5thGen"};
	string iPhonePartList[3] = {"Lcd", "Back", "SimTray"};
	string iPadPartList[3] = {"Lcd", "Back", "WifiAntenna"};
	string iPodPartList[3] = {"Lcd", "Back", "HeadphoneJack"};
	int inventory[20][9][3];
};



void newLine(int size);
int selectDevice();
int selectModel(int device, iosDevice idevice);
int selectPart(int device, iosDevice idevice);
void newLine();
bool viewOrModify();
bool checkDeviceValidity(int device);
void modifyInventory();
bool checkModelValidity(int model, int device);
void topBreak();
void bottomBreak();

