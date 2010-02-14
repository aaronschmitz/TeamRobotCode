#include "Output.h"

bool Output::autoCompressing=false;
bool Output::compressing=false;
bool Output::fullyPressurized=true;
bool Output::kicking=false;
bool Output::lifting=true;
bool Output::motors=true;

DriverStationLCD* Output::driverStationLCD = DriverStationLCD::GetInstance();

Output::Output()
{
}
#define C_WIDTH 19
void Output::clear()
{
	driverStationLCD->Printf(DriverStationLCD::kUser_Line1,C_WIDTH,"        ");
	driverStationLCD->Printf(DriverStationLCD::kUser_Line2,C_WIDTH,"        ");
	driverStationLCD->Printf(DriverStationLCD::kUser_Line3,C_WIDTH,"        ");
	driverStationLCD->Printf(DriverStationLCD::kUser_Line4,C_WIDTH,"        ");
	driverStationLCD->Printf(DriverStationLCD::kUser_Line5,C_WIDTH,"        ");
	driverStationLCD->Printf(DriverStationLCD::kUser_Line6,C_WIDTH,"        ");
}
void Output::print()
{
	static bool hasPrintedFirstTime = false;
	if(!hasPrintedFirstTime) {
		driverStationLCD->Printf(DriverStationLCD::kUser_Line1,1,"Autocompressing:    ");
		driverStationLCD->Printf(DriverStationLCD::kUser_Line2,1,"Compressing:        ");
		driverStationLCD->Printf(DriverStationLCD::kUser_Line3,1,"Full Pressure:      ");
		driverStationLCD->Printf(DriverStationLCD::kUser_Line4,1,"Kicking:            ");
		driverStationLCD->Printf(DriverStationLCD::kUser_Line5,1,"ArmLifting:         ");
		driverStationLCD->Printf(DriverStationLCD::kUser_Line6,1,"Motors enabled:     ");
		hasPrintedFirstTime = true;
	}
	clear();
	driverStationLCD->Printf(DriverStationLCD::kUser_Line1,C_WIDTH,boolToString(autoCompressing).c_str());
	driverStationLCD->Printf(DriverStationLCD::kUser_Line2,C_WIDTH,boolToString(compressing).c_str());
	driverStationLCD->Printf(DriverStationLCD::kUser_Line3,C_WIDTH,boolToString(fullyPressurized).c_str());
	driverStationLCD->Printf(DriverStationLCD::kUser_Line4,C_WIDTH,boolToString(kicking).c_str());
	driverStationLCD->Printf(DriverStationLCD::kUser_Line5,C_WIDTH,boolToString(lifting).c_str());
	driverStationLCD->Printf(DriverStationLCD::kUser_Line6,C_WIDTH,boolToString(motors).c_str());
	driverStationLCD->UpdateLCD();
}

void Output::errorCode(int error)
{
}
