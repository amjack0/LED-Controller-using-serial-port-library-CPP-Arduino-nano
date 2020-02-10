# LED-Controller-using-serial-port-library-CPP-Arduino-nano
This repository is created to control LED ws2812b with c++ using serial port library. 

# Getting Started
A project which enables a serial communication between arduino nano and c++ file. Idea behind this is that\
arduino can not process the information, this problem is overcome by using c++ file to process the information and then\
sending commands to arduino nano to control the LED stripws2812b.

# Prerequisites and hardware required

Arduino nano + LED ws2812b strip + jumper wires + Power supply (5v- 3.6 A) - recommended. \
power supply which I have used can be found under; https://joy-it.net/en/products/SBC-POW-BB \
Note that, here we are using 60 leds which requires 3.6 A (for 60 pixels) which means, we need 60 mA per pixel.

# Test Environment

Windows 10 + Arduino IDE + Code Block IDE (Works with any IDE).\
Arduino IDE can be installed here: https://www.arduino.cc/en/main/software \
Code Block IDE can be installed here: http://www.codeblocks.org/downloads/binaries \
for installation instruction for code block IDE can be found here: https://www.youtube.com/watch?v=aS5_jrIbKmA

# Installation & Setup

To begin with LED ws2812b , It is recommended to watch this video https://www.youtube.com/watch?v=9hJyyUTflXA
make sure you install the required Adafruit libraries for LED ws2812b.

# Running a project

1) Make sure you have all the connections made with arduino nano + power supply + LED ws2812b
2) While making connections, make sure to connect ground first.
3) clone the above project1 into your local repository.
4) Before you run the file, make sure to specify the port name. Mine is com4. To see your port name, open ```Arduino IDE > tools > port``` \ 
\5)Then select your board ```Arduino IDE > tools > Board: arduino nano``` (as we are using arduino nano) 
6) select the ```Arduino IDE > tools > processor > (old bootloader)``` (as we are using FAKE arduino nano)

