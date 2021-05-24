#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(){
	fstream modelD,brandD,operatorD,serialnoD,batteryD,statusD;
	string brandDS,batteryDS,operatorDS,serialnoDS,modelDS,statusDS;
	char modelDC[20],brandDC[20],serialnoDC[20],operatorDC[20],batteryDC[20],statusDC[20];

	//config
	system("adb shell getprop ro.product.brand > brand.txt");
	system("adb shell dumpsys battery | grep level | tail -c 3 > battery.txt");
	system("adb shell getprop gsm.sim.operator.alpha > sim.txt");
	system("adb shell getprop ro.serialno > serialno.txt");
	system("adb shell getprop ro.product.model > model.txt");
	system("adb get-state > status.txt");

	//settings
	brandD.open("brand.txt");
	brandD >> brandDS;
	sprintf(brandDC,"%s",brandDS.c_str());
	brandD.close();

	batteryD.open("battery.txt");
	batteryD >> batteryDS;
	sprintf(batteryDC,"%s",batteryDS.c_str());
	batteryD.close();

	operatorD.open("sim.txt");
	operatorD >> operatorDS;
	sprintf(operatorDC,"%s",operatorDS.c_str());
	operatorD.close();

	serialnoD.open("serialno.txt");
	serialnoD >> serialnoDS;
	sprintf(serialnoDC,"%s",serialnoDS.c_str());
	serialnoD.close();

	modelD.open("model.txt");
	modelD >> modelDS;
	sprintf(modelDC,"%s",modelDS.c_str());
	modelD.close();

	statusD.open("status.txt");
	statusD >> statusDS;
	sprintf(statusDC,"%s",statusDS.c_str());
	statusD.close();

	//clear
	system("rm brand.txt");
	system("rm battery.txt");
	system("rm sim.txt");
	system("rm serialno.txt");
	system("rm model.txt");
	system("rm status.txt");

	//draw
	int buffer;
	printf("┌─────────────┐\n");
	printf("│");
	for(int i=0;i<13/3;i++) printf(" ");
	printf("%s",brandDC);
	for(int i=0;i<13/3;i++) printf(" ");
	printf("│\n");
	printf("├─────────────┤\n");
	buffer=13-strlen(batteryDC)-strlen(operatorDC);
	printf("│%s",operatorDC);
	for(int i=0;i<buffer-1;i++) printf(" ");
	printf("%s\%│\n",batteryDC);
	printf("│             │\n");
	printf("│serialno:    │\n");
	buffer=13-strlen(serialnoDC);
	printf("│%s",serialnoDC);
	for(int i=0;i<buffer;i++) printf(" ");
	printf("│\n");
	printf("│             │\n");
	printf("│model:       │\n");
	buffer=13-strlen(modelDC);
	printf("│%s",modelDC);
	for(int i=0;i<buffer;i++) printf(" ");
	printf("│\n");
	printf("│             │\n");
	printf("│Status:      │\n");
	buffer=13-strlen(statusDC);
	printf("│%s",statusDC);
	for(int i=0;i<buffer;i++) printf(" ");
	printf("│\n");
	printf("├─────────────┤\n");
	printf("│    ┌───┐    │\n");
	printf("│    └───┘    │\n");
	printf("└─────────────┘\n");

	/*printf("brand: %s\n",brandDC);
	printf("battery: %s\n",batteryDC);
	printf("operator: %s\n",operatorDC);
	printf("serialno: %s\n",serialnoDC);
	printf("model: %s\n",modelDC);
	printf("status: %s\n",statusDC);*/

	return 0;
}
/*
ro.serialno
x=15
┌─────────────┐
│    meizu    │
├─────────────┤
│68%     tele2│
│             │
│serialno:    │
│710HVBR8226KM│
│             │
│model:       │
│M5c          │
│             │
│Status:      │
│device       │
├─────────────┤
│    ┌───┐    │
│    └───┘    │
└─────────────┘

*/