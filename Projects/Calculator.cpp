/*
 * Calculator.cpp
 *
 *  Created on: Mar 14, 2013
 *      Author: bourgein
 */
 #include "Calculator.h"

 using namespace std;

Calculator::Calculator(Location firstLoc, Location secondLoc) {
	loc1 = firstLoc;
	loc2 = secondLoc;
	loc1DecLat = convertToDec(firstLoc.getLatDeg(), firstLoc.getLatMin(),
			firstLoc.getLatDirection());
	loc1DecLon = convertToDec(firstLoc.getLonDeg(), firstLoc.getLonMin(),
			firstLoc.getLonDirection());
	loc2DecLat = convertToDec(secondLoc.getLatDeg(), secondLoc.getLatMin(),
			secondLoc.getLatDirection());
	loc2DecLon = convertToDec(secondLoc.getLatDeg(), secondLoc.getLatMin(),
			secondLoc.getLatDirection());

	calcDistBetween();
}

double Calculator::getDistanceBetween() {
	return distanceBetween;
}

double Calculator::convertToDec(int deg, int min, string isNeg) {
	double result = deg + (min / 60);
	if (isNeg == "w" || isNeg == "s") {
		result = result * -1;
	}
	return result;

}

void Calculator::calcDistBetween() {
	double dLat = loc2DecLat - loc1DecLat;
	double dLon = loc2DecLon - loc1DecLon;
	double a = (pow((sin(dLat / 2)), 2)) + (cos(loc1DecLat) * cos(loc2DecLat) * (pow((sin(dLon / 2)), 2)));
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double d = EARTH_RAD * c;

	distanceBetween = d;
}


