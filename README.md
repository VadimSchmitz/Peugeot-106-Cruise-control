# Peugeot-106-Cruise-control
This repository is an overview of all the progress and work I have done for an implementation of a "home made" cruise control for my peugeot 106. 

>Disclaimer: Due to this being a very niche project i have not yet put in the time to explain every step and component of the project, if there are any people who want to replicate this feel free to email me at vadimschmitz99@gmail.com
----

## The car
The car is a Peugeot 106 1.1 accent from the year 2000.
The exact specifications of the car can be found [Here](https://www.cars-data.com/en/peugeot-106-accent-1-1-specs/34029). This information is useful to know due to the fact that there were alot of engine options with their own throttle body.

 The electronics and code will probaly most likely work on other specs too however the mounting solution would need to be tweaked for it to work.  

---
## Proof of concept
The initial Proof Of Concept (POC) will be quite simple. To create a POC a few things need to be considered. These are most important Questions and Answers I had before starting the creation of a POC.

### Q) The bare bones functionality of the cruise control?
A) The initial cruise control should have the following functionalities:
- Being able to turn the system on and off
- A way to control the throttle position
- A safety mechanism to turn off the cruise control like a production cruise control (Off switch when brake is pressed)

<br>

### Q) What electronics could to be used to realise these functionalities?
A) After a lot of brainstorming and itterations i came up with the folling electornics that could work as a proof of concetpt. These electronics can be split up in multiple sections.
- Userinterface
  - On/off switch for the control panel (Button)
  - off switch when brake is pressed (Wire into the excisting brake signal)
  - Indicator to see if the system is on or off (Led light)
- The computer that takes inputs and controls the throttle (Arduino)
- Electronical device that can control the Throttle (Servo) 

<br>

### Q) What is the best way to mount the entire contraption?
A) There are multiple things to mount, the userinterface, brake safety, arduino and the device to control the throttle position. After much brain storming i came up with the following solutions
- Userinterface <br  >
There are switches for electric windows in the center console. Since my car does not have the electronic window option the space where the switches would be is blocked off with a plasic plate, this can be removed and the PCB will be mounted there. Picture for reference

    <img src="https://cdn.discordapp.com/attachments/501427840873529364/994225417236009000/20220706_145624.jpg" alt="drawing" style="width:300px;"/>

- Brake safety switch (Not wired or programmed yet) <br  >
  After some prodding around with the brake switch i found out that a reverse switch is used, this means that while it is pressed the circuit is broken, when the brake peddle is pressed the switch will be unpressed and closes the circuit letting 12v go thorugh the system. Therefore all that needs to be done is step the 12v down to 6v and feed this signal into the arduino. the wiring is done directly into the the terminals of the brake switch. 

- Arduino <br  >
  After considering mounting the arduino within the cabin of the car i eventually opted for mounting the arduino within the fuse box.

  <img src="https://cdn.discordapp.com/attachments/501427840873529364/994220712619421726/20220706_143740.jpg" alt="drawing" style="width:300px;"/>

- Servo <br  >
  After a few design iterations I came up with a pulley system. one pulley is connected to the throttle body of the car and the other is connected to a servo which is mounted close by the throttlebody. The final iteration for the proof of concept looks like this

    <img src="https://cdn.discordapp.com/attachments/501427840873529364/994222752632418304/20220706_144603.jpg" alt="drawing" style="width:500px;"/>

    <img src="https://cdn.discordapp.com/attachments/501427840873529364/994222947780808754/20220706_144646.jpg" alt="drawing" style="width:500px;"/>
<br>

---
## Next steps and refinements
Overall the proof of concept works great, I have used it to go to Poland and it has not broken yet. However there are a few things that i want to improve. The aspects of the project could be refined into a real product with the following steps
- Design a custom pcb for the Arduino nano and the user interface
- Laser cut aluminium mounting plate for the pulley
- Make metal or resin printed pulleys 


## Next goal
The main goal right now is creating a true cruise control. This can be done by taking data such as the speed of the car from the CAN BUS of the car and using that data to tweak the throttle position.





