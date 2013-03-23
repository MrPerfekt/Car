/*!
Copyright 2013 Andreas Gruber
*/

#ifndef DEFINE_LIB
#define DEFINE_LIB

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"

/*
class BumperSensor;
class Car;
class Coordinates;
class DisplayProxy;
class DistanceSensor;
class EnvironmentPathPlaner;
class EnvironmentSensor;
class FloorSensor;
class GeneralMovement;
template<class T> class Iterator;
template<class T> class List;
class MotionLogger;
class Motor;
class MouseSensorPan101;
class Movement;
class MovementPositionCalculator;
class MovementSensor;
template<class T> class Node;
class OrientationCoordinates;
class Path;
class PathExecutor;
class PathPlaner;
class PositionCalculator;
class Sensor;
class ServoProxy;
class ShortestPathPlaner;
class SteeringManager;
class StraightMovement;
class TurnMovement;
class VoltageDivider;
class WheelSensor;
*/

/*!
Contains the angle of a full circle.
E.c. deg=360, rad=2*pi, grd=400, ...
This is no configuration. So this is not saved in Config.h
*/
static const double circle = 2*PI; //!Get removed in future releases and replaced by 2pi

#define __LDBL_MAX__ 3.40282347e+38L
#define __DBL_MAX__ 3.40282347e+38
#define __FLT_MAX__ 3.40282347e+38F 

uint16_t freeSRam ();

#endif