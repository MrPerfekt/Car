/*!
Copyright 2013 Andreas Gruber
*/

#ifndef MOUSE_SENSOR_PAN101BSI
#define MOUSE_SENSOR_PAN101BSI

#include "DefineLib.h"
//#include "arduino.h"
#include "Coordinates.h"
#include "MovementSensor.h"
#include "TurnMovement.h"

class MouseCoordinates {
private:
	TurnMovement mov;
public:
	int32_t x;
	int32_t y;
	MouseCoordinates();
	MouseCoordinates(int32_t x,int32_t y);
	Movement& getMovement(uint16_t resolution);
	MouseCoordinates operator+= (const MouseCoordinates &coordinates);
};

/*!
* Mouse Sensor
*/
class MouseSensorPan101 : public MovementSensor{
private:
	enum Registers{
		r_productID = 0x00,
		//r_reserved = 0x01,
		r_motionStatus = 0x02,
		r_deltaX = 0x03,
		r_deltaY = 0x04,
		r_operationMode = 0x05,
	};
	enum MotionStatusBits{
		ms_res = 0,//! resolution ([0=800,1=400] counts per inch)
		// ms_reserved = 1,
		// ms_reserved = 2,
		ms_dxovf = 3,//! x overflow
		ms_dyovf = 4,//! y overflow
		// ms_reserved = 5,
		// ms_reserved = 6,
		ms_motion = 7,//! motion detected
	};
	enum OperationModeBits{
		om_wakeup = 0,//! if set to 1 => wakeup and reset to 0
		om_slp1mu = 1,//! if set to 1 => enter sleep1 mode and reset to 0
		om_slp2mu = 2,//! if set to 1 => enter sleep2 mode and reset to 0
		om_slp2au = 3,//! sleep mode2 [0=disable, 1=enable]
		om_slpEnh = 4,//! sleep mode [0=disable, 1=enable]
		om_res = 5,//! resolution ([0=800,1=400] counts per inch)
		om_xyEnh = 6,//! xy quadrature output [0=disable, 1=enable]
		// om_reserved = 7,
	};

	uint8_t pinSCK;
	uint8_t pinSDA;
	uint8_t pinPD;
	MouseCoordinates currentMouseCoordinates;
public:  
	enum PowerSettings{
		ps_normal = om_wakeup,
		ps_sleep1 = om_slp1mu,
		ps_sleep2 = om_slp2mu,
	};
	enum Preferences{
		p_enableSleepMode = om_slpEnh,
		p_enableSleepMode2 = om_slp2au,
		p_lowResolution = om_res,
		p_enableQuadratureOutput = om_xyEnh,
	};

	uint8_t productID;
	uint8_t operationMode;

	/*!
	Initialice the IC
	@param pinSCK The pin where SCK is connected
	@param pinSDA The pin where SDA is connected
	@param pinPD The pin where PD is connected
	@param centerDistance The distance to the center where the car can't move left or right
	*/
	MouseSensorPan101();
	/*!
	Write a byte to the IC
	@param data a byte
	*/
	void writeByte(uint8_t data);
	/*!
	Read a byte from the IC
	@return the byte
	*/
	uint8_t readByte();
	/*!
	Write an register of the IC
	@param adr Address
	@param data Data
	*/
	void writeToAddress(uint8_t adr, uint8_t data);
	/*!
	Read an register of the IC
	@param adr Address
	@return Data
	*/
	uint8_t readFromAddress(uint8_t adr);
	/*!
	Reset the IC
	*/
	void reset();
	/*!
	Turn off the IC
	Turn on with reset();
	*/
	void powerDown();
	/*!
	Get the Product-ID
	@return Product-ID
	*/
	uint8_t readProductID();
	/*!
	Get the operation mode
	@return operation mode
	*/
	uint8_t readOperationMode();
	/*!
	Refresh the stored Product-ID
	*/
	void refreshStoredProductID();
	/*!
	Refresh the stored operation mode
	*/
	void refreshStoredOperationMode();
	/*!
	Upload the stored operation mode
	*/
	void uploadStoredOperationMode();
	/*!
	Check if the IC is in sync with the microcontroller
	@return is in Synk
	*/
	bool isInSynk();
	/*!
	Check and repair the connection
	*/
	void checkRepairConnection();
	/*!
	Update and return the relativ Position
	@return relativ Position in MouseCoordinates
	*/
	MouseCoordinates getMovementMouseCoordinates();
	/*!
	Updates currentMouseCoordinates which will be returned as Movement by getMovement().
	This means that the data of the mousesensor will be cleared by an invoke of update().
	*/
	void update();
	/*!
	Update and return the relativ Position
	Note: Before getMovement() can be executed update() have to be invoked.
	@return relativ Position
	*/
	Movement& getMovement();
	/*!
	Set new power settings
	@param powerSettings powerSettings
	*/
	void setPowerSettings(PowerSettings powerSettings);
	/*!
	Get preference
	Before: refreshStoredOperationMode();
	@param preferences NewOperationMode
	*/
	bool getPreference(Preferences preference);
	/*!
	Set preference
	After: uploadStoredOperationMode();
	@param preferences NewOperationMode
	*/
	void setPreference(Preferences preference,bool value);
	/*!
	Get current resolution
	After: uploadStoredOperationMode();
	@return resolution
	*/
	uint16_t getResolution();
};

#endif