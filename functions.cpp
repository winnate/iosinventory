#include <iostream>
#include "functions.h"
using namespace std;

/* ---------- Function Definitions ---------- */

int selectDevice(){
	int device;
	
	do {
		topBreak();
		cout << "1) iPhone\t2) iPad\t\t3) iPod";
		bottomBreak();
		cout << "\nSelect Device: ";
		cin >> device;
		if (!(checkDeviceValidity(device)))
			cout << "\nError! Try again!\n";
	} while (!(checkDeviceValidity(device)));
	
	return device;
}

int selectModel(int device, iosDevice idevice){
	int model;
	topBreak();
	idevice.showModelList(device);
	bottomBreak();
	do {
		cout << "\nSelect Model: ";
		cin >> model;
		if (!(checkModelValidity(model, device)))
			cout << "Error! Try again!\n";
	} while (!(checkModelValidity(model, device)));
	return model;
};

int selectPart(int device, iosDevice idevice){
	int part;
	topBreak();
	idevice.showPartList(device);
	bottomBreak();
	cout << "\nChoose Part to view or modify: ";
	cin >> part;
	return part;
}

bool viewOrModify(){
	char answer;
	newLine();
	cout << "Would you like to modify inventory? (Y/N):  ";
	cin >> answer;
	if (toupper(answer) == 'Y')
		return true;
	else
		return false;
}

void newLine(int size){
	for (int i = 0; i < size; i++){
		cout << "\n";
	}
}

void newLine(){
	cout << "\n";
}

bool checkDeviceValidity(int device){
	if ((device < 1) || (device > 3))
		return false;
	else 
		return true;
}

bool checkModelValidity(int model, int device){
	if (device == 1){
		if ((model < 1) || (model > 9))
			return false;
	}
	else if (device == 2){
		if ((model < 1) || (model > 6))
		return false;
	}
	else {
		if ((model < 1) || (model > 5))
			return false;
	}
	return true;
}

void topBreak(){
	for (int i = 0; i < 1; i++){
		cout << "\n";
		for (int j = 0; j < 50; j++){
			cout << "*";
		}
		cout << "\n";
	}
}

void bottomBreak(){
	for (int i = 0; i < 1; i++){
		cout << "\n";
		for (int j = 0; j < 50; j++){
			cout << "*";
		}
		cout << "\n";
	}
}

