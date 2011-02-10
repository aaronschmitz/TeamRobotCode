#include "TeleoperatedRobot.h"
#include "JoystickPositionEvent.h"
#include "RobotError.h"

TeleoperatedRobot::TeleoperatedRobot(DriveType type)
{
	drive = new DriverWrapper(type);
	myError = RobotError::NoError();
	lastGyroReading = 0.0;
}

TeleoperatedRobot::~TeleoperatedRobot()
{
	delete drive; drive = 0;
	delete myError; myError = 0;
}

bool TeleoperatedRobot::handle(Event *e)
{
	bool ret = false;
	if(!e) {
		if(myError) delete myError;
		myError = new RobotError(Warning, "TeleoperatedRobot received null ptr.");
		return false;
	}
	switch(static_cast<int>(e->type()))
	{
		case JoystickPosition:
			drive->Drive(static_cast<JoystickPositionEvent*>(e)->x(),
						 static_cast<JoystickPositionEvent*>(e)->y(),
						 static_cast<JoystickPositionEvent*>(e)->twist(),
						 lastGyroReading);
			break;
		case GyroAngle:
			//lastGyroReading = static_cast<GyroAngleEvent*>(e)->angle();
			break;
		default:
			if(myError) {
				delete myError; myError = 0;
				myError = new RobotError(Warning, "TeleoperatedRobot received unknown event.");
			}
			break;
	}
	return ret;
}

RobotError* TeleoperatedRobot::lastError()
{
	return myError;
}
