Here's a crazy idea, let's build a subtle tachometer (rev counter) for my 1972 Mercedes-Benz W108 280SE.

The idea isn't new and has been done many times, using many different approaches but you don't learn by just copying, at least in book. So the plan was to learn as much as I could about how this all works and this repo is that journey.

#### The Beginning

A tachometer works by reading the pulse generated from the coil. The coil takes 12V from the battery and opens and closes the points per crank revolution. In my case i've converted the car to electronic ignition from Pertronix but the same concept applies.

My engine, the M130, is a straight-six 2.8 litre so has 3 pulses per revolution.

Before we can read these pulses, we need to make the pulse safe to work with and also try and produce a proper square wave for the Arduino to read. If you attach a logic analyser, you should see something like this (*the voltage will be higher, these readings were taken after the voltage smoothing circuit was built as I didn't want to zap my Saleae*)

![coil_pulse1](Images/coil_pulse1.png)

![coil_pulse3](Images/coil_pulse3.png)

#### Voltage Smoother©

Because the Pertronix has the capability to push out high voltage and this would fry a lot of equipment, so I had to build a circuit that takes the high voltage and does fancy stuff with it. After many weeks of working out what and why, I came up with

![LTSpice](Images/LTSpice.png)

![breadboard](Images/breadboard.png)

The Bill of Materials (BOM) is as follows:

1. Zener diode
2. 1k Resistor
3. 370 Resistor
4. Zener Diode 5.1v
5. H111N 6-PIN DIP HIGH SPEED LOGIC OPTOCOUPLER
6. 290 Resistor
7. Arduino Nano

The idea for the above is that we have potentially 14+v coming in from the coil. We need to drop that down to 5v before it hits the opto coupler on pin 1, and when we supply 3.3v from the Arduino, it will output a lovely square wave, which is better to read using C++

Using LTSpice to confirm this (it's a great tool if you haven't used it before) confirms it works in theory

![LTSpice](Images/LTSpice.png)

Plugging in the Saleae, you can see this in action

![analog_versus_digital](Images/analog_versus_digital.png)

![analog_versus_digital2](Images/analog_versus_digital2.png)

![analog_versus_digital3](Images/analog_versus_digital3.png)

Channel 0 is connected to the output of the octocoupler in which the Arduino will read the pulses.
