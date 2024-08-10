# Overview of the C Code
The C code provided is designed to operate an up-down counter on the VSDquad Mini board. The counter increments or decrements a value from 0 to 99, which is displayed on two seven-segment displays. The code handles user input via buttons to start, stop, and change the counting direction. It also controls the display of the counter value on the seven-segment displays using GPIO pins configured for the board.

# Circuit Components
1) VSDquad Mini Board: This is the main microcontroller development board.
2) Microcontroller: The board uses an embedded RISC-V microcontroller, CH32V003X
3) GPIO Pins: Used to interface with buttons and seven-segment displays.
4) Seven-Segment Displays: Two displays are used to show the counter value (tens and units digits).
5) Push Buttons:Start/Stop Button: Allows the user to control the operation of the counter.

# Circuit Diagram



