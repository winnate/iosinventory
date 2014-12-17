#include <iostream>
#include "functions.h"
using namespace std;


int iosDevice::getPartCount(int part, int device, int model){
	newLine(2);
	if (inventory[part][device][model] > 1){
		cout << "There are " << inventory[part][device][model];
		cout << " ";
		showPart(device, part);
		cout << "'s in stock for the ";
		showDevice(device);
		cout << " ";
		showModel(device, model);
	}
	else if (inventory[part][device][model] > 0){
		cout << "There is " << inventory[part][device][model];
		cout << " ";
		showPart(device, part);
		cout << " in stock for the ";
		showDevice(device);
		cout << " ";
		showModel(device, model);
	}
	else{
		cout << "There are no ";
		showPart(device, part);
		cout << "'s in stock for the ";
		showDevice(device);
		cout << " ";
		showModel(device, model);
	}
	newLine(2);
}

void iosDevice::showModelList(int device){
	if (device == 1){
		for (int i = 0; i < 3; i++)
			cout << i+1 << ") " << iPhoneModelList[i] << "\t\t";
		newLine();
		for (int i = 3; i < 6; i++)
			cout << i+1 << ") " << iPhoneModelList[i] << "\t\t";
		newLine();
		for (int i =6 ; i < 9; i++)
			cout << i+1 << ") " << iPhoneModelList[i] << "\t\t";
	}
	else if (device == 2){
		for (int i = 0; i < 3; i++)
			cout << i+1 << ") " << iPadModelList[i] << "\t";
		newLine();
		for (int i = 3; i < 6; i++)
			cout << i+1 << ") " << iPadModelList[i] << "\t";
	}
	else {
		for (int i = 0; i < 3; i++)
			cout << i+1 << ") " << iPodModelList[i] << "\t";
		newLine();
		for (int i = 3; i < 5; i++)
			cout << i+1 << ") " << iPodModelList[i] << "\t";
	}
}

void iosDevice::showPartList(int device){
	if (device == 1){
		for (int i = 0; i < 3; i++)
			cout << i+1 << ") " << iPhonePartList[i] << "\t\t";
	}
	else if (device == 2){
		for (int i = 0; i < 3; i++)
			cout << i+1 << ") " << iPadPartList[i] << "\t\t";
	}
	else {
		for (int i = 0; i < 3; i++)
			cout << i+1 << ") " << iPodPartList[i] << "\t\t";
	}
}

iosDevice::iosDevice(){
	inventory[20][3][9] = 0;
}

void iosDevice::showPart(int device, int part){
	if (device == 1){
		cout << iPhonePartList[part - 1];
	}
	else if (device == 2){
		cout << iPadPartList[part - 1];
	}
	else {
		cout << iPodPartList[part - 1];
	}
}

void iosDevice::showModel(int device, int model){
	if (device == 1)
		cout << iPhoneModelList[model - 1];
	else if (device == 2)
		cout << iPadModelList[model - 1];
	else 
		cout << iPodModelList[model - 1];
}

void iosDevice::showDevice(int device){
	if (device == 1)
		cout << "iPhone";
	else if (device == 2)
		cout << "iPad";
	else 
		cout << "iPod";
}

void iosDevice::setInventory(int part, int device, int model){
	char answer('A');
	int amountAdd, amountRemove;
	bool ok = false;
	do {
		cout << "Are you adding (A) or removing (R) stock?: ";
		cin >> answer;
		if (toupper(answer) == 'A'){
			cout << "How many would you like to add?: ";
			cin >> amountAdd;
			addInventory(part, device, model, amountAdd);
			ok = true;
		}
		else if (toupper(answer) == 'R'){
			do {
				cout << "How many would you like to remove?: ";
				cin >> amountRemove;
				if (amountRemove <= 0){
					topBreak();
					cout << "Error! Incorrect input.  Try again.";
					bottomBreak();
				}
		} while (amountRemove <= 0);
			removeInventory(part, device, model, amountRemove);
			ok = true;
		}
		else{
			ok = false;
			cout << "Error!  Incorrect input. Try again.";
		}
	} while (!(ok));
}

void iosDevice::addInventory(int part, int device, int model, int amountAdd){
	inventory[part][device][model] += amountAdd;
}

void iosDevice::removeInventory(int part, int device, int model, int amountRemove){
	inventory[part][device][model] -= amountRemove;
}