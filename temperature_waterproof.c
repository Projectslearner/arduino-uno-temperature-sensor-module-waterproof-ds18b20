/*
    Project name : Temperature sensor module Waterproof DS18B20
    Modified Date: 09-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-temperature-sensor-module-waterproof-ds18b20
*/

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  
  // Start up the library
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); // Send the command to get temperatures
  
  // Read temperature in Celsius from the sensor
  float temperatureC = sensors.getTempCByIndex(0);

  // Check if reading temperature failed
  if (temperatureC == -127.00) {
    Serial.println("Failed to read temperature from DS18B20 sensor");
  } else {
    // Print the temperature to the serial monitor
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" °C");
  }
  
  // Wait for 1 second before taking the next reading
  delay(1000);
}
