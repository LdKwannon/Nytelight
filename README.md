# Nytelight
Nightlight with added Temperature Sensor for Arduino Uno (C++)

//Nightlight with Temperature Sensor for visual check of child's room over color camera baby monitor.
//
//This was something I put together as a safety device and nightlight for my children shortly after they were born.
//Very useful if you're home has uneven temperatures from room to room, so you can know at a glance from the hallway or
//a color baby monitor, whether or not the temperature in your child's room is within the range you specify. Temp is in Fahrenheit.
//
//I am using a 25 LED Adafruit NeoPixel ring in this project and a temperature sensor with an Arduino-UNO.
//It is bright enough in a globe enclosure frankly to light up the room like the sun, so my advice, alter your build with a lightshield
//or use no more than a 5 led light with a shroud.
//
//Always keep the nightlight within visual field of the color camera.
//
//If you use a black and white camera, you're only going to see it go bright and you won't know whether or not it is too hot or too cold on sight. You'll have to go
//in the room or alter the code to your liking.. maybe a pulse pattern? But, lets not wake up the kinder with flashing lights in the night, eh?
//
//Code will let you know if the temperature/humidity sensor is disconnected or non functional via led.
//
//uses FastLED (led library) and dht (temp and humidity sensor) libraries, you'll have to seek the library for FastLED here on github (link provided).
//Included relevant dht library from author who passed his version into the public domain.
//YOU WILL NEED FastLED **AND** dht libraries.
//
/*The MIT License (MIT)
Copyright (c) 2013 FastLED : https://github.com/FastLED/FastLED
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/

//    FILE: dht.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.14
// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
//     URL: http://arduino.cc/playground/Main/DHTLib
//
// HISTORY:
// inspired by DHT11 library
//
// Released to the public domain
/////////////////////////////////////////

//Humidity sensor is NOT used in this build, though the option exists.
//
//Programmer: Lourdes Bond
