# MinimalSPORTVoltmeter
Arduino Voltmeter compatible to FrSky SPort Telemetry with minimal additional hardware

# Advantages and disadvantages
Compared to the FrSky FLVSS sensor this module
* is extremely cheap. The FLVSS costs €14+, while this one can be built with parts for less than €2
* is a little more lightweight. The FLVSS weighs around 5g while this weighs less than 2g

The only real disadvantage is that it can only measure the first cell's voltage, compared to the FLVSS that can measure each cell's voltage. But when flying I usually don't care about how well the battery is balanced, I only want to know whether I have enough battery left to fly or if I need to land. And for that only measuring the first cell is enough.

# Hardware
To build this you only need very few components:

* Arduino Mini Pro 5V/16MHz Bersion
* 1x 4.7k Ohm Resistor
* 1x Female-Female Jumper Cable
* 3x Female-Male Jumper Cable

Make sure you get the 5V/16MHz Arduino since the Arduino can only measure voltage up to it's voltage without further work.
The resistor is optional but strongly recommended. It will probably work without but it might damage your receiver.

Wire the whole thing up like so:

![Diagram showing the wireing](https://raw.githubusercontent.com/Dakkaron/MinimalSPORTVoltmeter/master/wireing.png)

So it is pretty easy:
* Connect Arduino Pin 2 to the 4.7k Ohm resistor and the other side of the resistor to the S pin on the receiver's SPort connector
* Connect Arduino GND pin to the GND pin (black cable) on the Battery Balancer connector
* Connect Arduino A0 pin to first cell pin (the one next to the black cable) on the Battery Balancer connector
* Connect Arduino RAW pin to second cell pin (the one next to the first cell pin) on the Battery Balancer connector

**DO NOT CONNECT ANYTHING TO THE POSITIVE SPORT PIN!**

## Software
You can either use the ready-build hex files avalable in the [hex](https://github.com/Dakkaron/MinimalSPORTVoltmeter/tree/master/hex) folder or you can build it yourself.
To build it you first need to download pawelsky's amazing FrSky S-Port telemetry library from [here](https://www.rcgroups.com/forums/showthread.php?2245978-FrSky-S-Port-telemetry-library-easy-to-use-and-configurable) and put it into your Arduino-library folder. Then open up SPortVoltmeter.ino in Arduino and compile it.
