#include <iostream>
#include <cstring>
#include <cstdlib>
#include "functions.h"
using namespace std;


/* ---------- Main ---------- */

int main(){
	// Delcare Variables
	iosDevice idevice;
	int device, model, part;
	bool modify = false;
	// User Input
	device = selectDevice();
	newLine();
	model = selectModel(device, idevice);
	newLine();
	part = selectPart(device, idevice);
	idevice.getPartCount(part, device, model);
	if (viewOrModify()){
		idevice.setInventory(part, device, model);
	}
	else {
		cout << "OK!";
	}
	idevice.getPartCount(part, device, model);
	// Process

	// Output

}
