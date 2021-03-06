/*
  AeroQuad v3.0 - March 2011
  www.AeroQuad.com
  Copyright (c) 2011 Ted Carancho.  All rights reserved.
  An Open Source Arduino based multicopter.
 
  This program is free software: you can redistribute it and/or modify 
  it under the terms of the GNU General Public License as published by 
  the Free Software Foundation, either version 3 of the License, or 
  (at your option) any later version. 

  This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
  GNU General Public License for more details. 

  You should have received a copy of the GNU General Public License 
  along with this program. If not, see <http://www.gnu.org/licenses/>. 
*/

#include <Wire.h>
  
#include "Arduino.h"
#include <droneMath.h>
double accel[3];
#include <Accelerometer_LSM303DLHC.h>

unsigned long timer;



void setup() {
  
  Serial.begin(115200);
  Serial.println("Accelerometer library test (LSM303DLHC)");

  Wire.begin();
 
  initializeAccel();
  // computeAccelBias();
  // changing the scale factor is necessary to get non-0 values from this test sketch
  // don't worry about how accurate the data is at this point, just make sure it changes as you move the board
  // accelScaleFactor[XAXIS]=accelScaleFactor[YAXIS]=accelScaleFactor[ZAXIS]=-0.038;
  Serial.println("Acceleromter Calibration values");
  Serial.println(accelzerodiffcross[0], 4);
  Serial.println(accelzerodiffcross[1], 4);
  Serial.println(accelzerodiffcross[2], 4);
  Serial.println(accelzerodiff, 4);
}


void loop() {
  
  

  if((millis() - timer) > 5000) // 100Hz
  {
    timer = millis();
    measureAccel();
    
    
    Serial.print("Roll: ");
    Serial.print(accel[0]);
    Serial.print(" Pitch: ");
    Serial.print(accel[1]);
    Serial.print(" Yaw: ");
    Serial.print(accel[2]);
    Serial.println();
    
    
  }
}
