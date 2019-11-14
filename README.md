# Swarm-Robotics-on-TIVA-Board

![](https://github.com/Shubhanshu07/Swarm-Robotics-on-TIVA-Board/blob/master/Images%20and%20Videos/Images/bot_image3.jpeg)
## Abstract
Swarm robotics is an approach to the coordination of multiple robots as a system which consists of large numbers of mostly simple physical robots. Under the excuse of this project, we made a bot that copies the movement of the other bot without any delay. The aim of the project was to make the bot that will the copy the movement of the line following bot.

## COMPONENT USED
**1. LSA-08**

LSA-08 [2] is the Advanced auto calibrated Line following sensor. It consists of 8 IR transmitter and IR receiver pairs. LSA-08 is typically used for embedded system or robots for line following task.

**2. TIVA Launchpad**
		
The EK-TM4C123GXL [4] LaunchPad is a very capable board with a 32-bit 80MHz ARM Cortex-M4F processor. It has many peripherals so it’s possible to do some pretty high performance applications. It also has a very bright RGB LED.

**3. Node MCU**

Node MCU [1] is an open source IoT platform. It includes firmware which runs on the ESP8266 Wi-Fi SoC from Espressif Systems, and hardware which is based on the ESP-12 module.

## METHODOLOGY

![](https://github.com/Shubhanshu07/Swarm-Robotics-on-TIVA-Board/blob/master/Images%20and%20Videos/Images/flowchart.png)
### Making of Bot 1
1. Bot 1 is a line following bot. It uses the LSA-08 to performance the aforementioned functionality. The LSA-08 is calibrated to read as white strip as ’1’ and read the black background as ’0’. 
2. These readings are sent to the Tiva board. Here some processing is done that calculates the speed and direction in which the motor drivers must be driven. 
3. This calculated data is first sent to the Node MCU and then to the motor driver of Bot 1. This order of transmission is done to minimize the delay in communication between Bot 1 and Bot 2. 
4. The Node MCU sends its data to a WiFi server that broadcasts it to any active Node MCUs. The motor driver drives the wheels according according to the information it receives. 
5. UART transmission is done between the Tiva and nodeMCU with baud rate of 115200.

### Making of Bot 2

This bot comprises a nodeMCU and a motor driver and other basic components. The nodeMCU simply receives the data and sends it to the motor driver. The motor driver then drives the wheels of the bot.

## USE CASE
Testing of our bots was done on an arena made by white strips on a black chart paper. As soon as a line was detected the bot 1 immediately followed it and the bot 2 copied the movements made by bot 1.
![](https://github.com/Shubhanshu07/Swarm-Robotics-on-TIVA-Board/blob/master/Images%20and%20Videos/Images/Arena.jpeg)

## CHALLENGES
1. Using UART [3] between TIVA Board and Node MCU as we have to set equal baud rate on the both the microcontrollers.
2. Interfacing of two node MCU such that the delay is minimum and maximum number of data packets are transmitted.
3.  Optimizing code to minimize the delay on the TIVA Board.
4. The speed of the bot was too high for our track making it follow a sinusoidal path. A slower bot would have performed better.

## Future Improvements
1. Including PWM for Speed control of Motor.
2. Including PID control for the Line Following Bot
3.  Relative positional awareness is not present in our bots.

## ACKNOWLEDGEMENT

We would like to thank Prof. Bishnu Prasad Das for giving us the opportunity to do this project, teaching the prerequisites for this project and sponsoring the project. We would also like to thank [Models and Robotics Section, IIT Roorkee](https://github.com/marsiitr) for providing the components and tools for the project.

## CONCLUSION

Through this project we were able to make a bot copy a line following bot using Node MCU for communication and Tiva board for processing and were able to successfully test them on our demo arena.

## Team Member
1. [Samriddh Bhalla](https://github.com/Samriddh1998)
2. [Shubhanshu Agarwal](https://github.com/Shubhanshu07)

## References
1. https://en.wikipedia.org/wiki/NodeMCU. Wikimedia Foundation.
2.  https://www.robotshop.com/media/files/pdf/manual-lsa08.pdf.
3.  http://users.ece.utexas.edu/~valvano/.
4.  http://www.ti.com/tool/EK-TM4C123GXL. Texas Instrument.
