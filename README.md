<img width="1346" height="772" alt="image" src="https://github.com/user-attachments/assets/7162f226-ebe0-4e84-9e41-8bdcba224111" />


<h1 align="center">UtiliArm: A Custom Open Source 5-DOF Robotic Arm</h1>
<p align="center">Project Files:</p>


<p align="center">
  <a href="https://cad.onshape.com/documents/7d4782fc1d2b81b2411dc364/w/61aa74bc50ffa663fe78e913/e/d61dc358418eba5ccd3d28ce?renderMode=0&uiState=6911170d58c8610499119733">Onshape CAD Files</a> •
  <a href="https://docs.google.com/spreadsheets/d/1jZwi7d67DiPdZLEvy5LfeC6HyOPPZ9pO3xaRMX1j6oo/edit?usp=sharing">Bill of Materials</a> •
  <a href="https://blueprint.hackclub.com/projects/599">Blueprint Journal</a>
</p>


I made this to learn more about how robot arms work, how they are designed, controlled, and the types of end-effectors that can be used on them. Once I finish this arm, I want to be able to design different types of end-effectors that can go on the end of this. I also wanted to learn how to design a custom PCB as well as a custom wireless UI that can control this.

## Features
- 5 Degrees of Freedom: The base rotates and tilts, the arm tilts, and the wrist rotates and tilts, allowing for easy movement.
- Cost-Effective: This robot arm with a custom PCB and all parts included costs around $300 to build, making it cost-effective.
- Wireless Control: This arm is powered by an ESP 32 microcontroller with has WIFI capability
- Custom UI: This project also includes a custom UI that will connect to the ESP to control the arm wirelessly from a laptop.
- Encoder Compatibility: This arm uses AS5600 encoders on each stepper motor joint, which allows you to get absolute encoder values and create programs to make the arm go to certain positions.
- Mostly 3D Printed: This arm is mostly 3D printed and doesn't require any machined parts or gearboxes.
- Includes an Emergency Stop
- Will include a fully wireless handheld control panel in the future.

## Design and CAD

The Onshape link can be found at the top of the README.
Each part of the arm is printed separately and then put together using M3 and M4 hardware and heat-set inserts that melt into the plastic using a soldering iron. Bearings are press fit. The pulleys each use a specific belt size, which means there is no need to cut belts. The pulleys are spaced to perfectly fit the belts and tension them properly, which also means no belt tensioners are needed.

This is the base. The top part rotates on bearings and is screwed in from the bottom so it doesn't fall off.

<img width="1007" height="787" alt="image" src="https://github.com/user-attachments/assets/8ae3fb79-872d-4f43-ae59-586c16dc865b" />

This is the big pulley that tilts the arm. It sits in the bearings, which are shown in the part above.

<img width="981" height="775" alt="image" src="https://github.com/user-attachments/assets/4d500f2d-a7c7-4d79-87da-b5e972e68865" />

This is the Arm and the part that holds the arm. It includes a mount on the right side for the AS5600 encoder.

<img width="1058" height="677" alt="image" src="https://github.com/user-attachments/assets/0d0644af-189d-4f2b-a46c-0f0ecc5b4c6c" />
<img width="567" height="676" alt="image" src="https://github.com/user-attachments/assets/9f30b8c6-36b6-4ac7-8188-21837ed510ee" />

This is the wrist and the part that mounts the wrist onto the arm. The wrist just connects to a stepper motor that allows it to rotate. The wrist uses an MG996R Servo to tilt up and down.

<img width="727" height="532" alt="image" src="https://github.com/user-attachments/assets/82c8c8c4-631b-42be-bc11-25df8d251e3e" />
<img width="460" height="390" alt="image" src="https://github.com/user-attachments/assets/d8028ecc-ad1c-4222-839c-d56b9e8fef0d" />

This is the full assembly:

<img width="1301" height="767" alt="image" src="https://github.com/user-attachments/assets/050ddd89-9244-41e3-b913-501e973ec708" />

## PCB and Schematics:

This is the schematic for the custom PCB. The arm is powered from a bench power supply. There is a buck converter that converts into 5V. The main microcontroller is an ESP32 and there are three stepper drivers, slots for servo motors, an external Nema 23 driver, an I2C multiplexer for encoders,s and an expansion slot to add another PCB later on. There is also a screw terminal for an E-Stop. The PCB also has a GND pour and VIA's connecting the layers.

<img width="1116" height="796" alt="image" src="https://github.com/user-attachments/assets/9f6cd6bb-e9ff-4b75-a6ce-61cfedf70052" />

<img width="898" height="875" alt="image" src="https://github.com/user-attachments/assets/e9e3fa8d-6d1e-4a1d-8c8f-73defdd70e22" />

## Bill of Materials
These are the components needed. The prices and links can be found here:  <a href="https://docs.google.com/spreadsheets/d/1jZwi7d67DiPdZLEvy5LfeC6HyOPPZ9pO3xaRMX1j6oo/edit?usp=sharing">Bill of Materials Google Sheets</a>

- 1 PCB
- All 3D printed parts
- 3 x Nema 17 Motors
- 1 x Nema 23 Motor
- 3 x TMC2209 Drivers
- 1 x ESP32 Dev Kit
- 1 x TB6600 Driver
- Solder
- Solder Flux
- 3 x AS5600 Magnet Encoders
- 8 x 4x10x4 Bearings
- 8 x 20mm x 47mm x 14mm Bearings
- 1 x GT2 600mm Timing Belt
- 2 x GT2 400mm Timing Belt
- 1 x GT2 420mm Timing Belt
- 5 x 20t Pulleys
- 3 x 5mm to 5mm Shaft Couplers
- 1 x 5mm Shaft
- 8 x 5mm Shaft Collars
- 1 x E-Stop Button
- 1 x TC9548A I2C Multiplexer
- 1 x LM2596 24v to 5v Buck Convertor
- 1 x KF301-2P Screw Terminal
- 1 x XT60 to Banana Plug Cable
- 1 x XT60 to PCB Connector
- 1 x LED
- 1 x 1x3 Headers Pack
- 1 x 1x6 Headers Pack
- 1 x JST-XH-4Pin Connectors Pack
- 1 x 6 Pin Screw Terminals Pack
- 1 x 220R Resistor
- 3 x 0.1uF Capacitors
- 3 x 100 uF Capacitors
- 1 x SS54 Input Diode
- 1 x Pack of M3 M4 Hardware
- 1 x Pack of M4 Heat Set Inserts
- 1 x Pack of Jumper Cables
- 1 x Pack of Heat Shrink for Cables
- 1 x 12x12 Piece of Wood for Base
- 1.5kg x PLA Filament
- 1 x Pack of M2x6mm Philips Head Screws
