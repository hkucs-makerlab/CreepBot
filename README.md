# CreepBot For ROS
CreepBot - 3D Printed Mini Quadruped Robot For [ROS](https://ros.org/) Programming Workshops

<img src="wiki/creepbot2.png" width="400">
<img src="wiki/creepbot1.png" width="400">

## Introduction

CreepBot is a low cost 3D printed mini quadruped robot. The firmware implements ROSSerial protocol to publish and subscribe topics 
via Bluetooth SPP to support ROS framework. It is designed and intended for students to practice writing ROS packages and learn 3D printing to make robot.

## Robot Firmware

Download [AVRDUDESS](https://blog.zakkemble.net/avrdudess-a-gui-for-avrdude/) to upload robot firmware

<img src="wiki/AVRDUDESS-2.4.png" width="400">

## Electronic Components
### Robot
<ol>
  <li><a href="https://youtu.be/woJ8mIrGqf4?si=4_YU_JZL80stXMVt" target=_blank>HuaDuino</a> - Arduino Nano Compatible Board with Lithium Battery Power Up & Charging</li>
  <li>8 x MG90s servos</li>
  <li>HC-SR04 Ultrasonic sensor (for no camera head version)</li>
  <li>HC-04/05 or compatible Bluetooth SPP module, set baud rate to 38400
  <li>CC2541 Bluetooth LE module (optional)</li>
  <li>Buzzer</li>
  <li>18650 lithium battery with x2.54 connector</li>
  <li>Some M2x6/M2x10 tapping screws</li>
  <li>Some dupoint wires</li>
</ol>

### Camera head
  <ol>
    <li>ESP32cam</li>
    <li>Some dupoint wires</li>
    <li>firmware - https://github.com/sunfounder/ai-camera-firmware</li>
  </ol>

## Video of How to Make a CreepBot
### Camera Head Version
[![how to make a creepbot](https://img.youtube.com/vi/wkgwL2prcCM/0.jpg)](https://www.youtube.com/watch?v=wkgwL2prcCM)

[![creepbot demo](https://img.youtube.com/vi/PgKKCWNNcuk/0.jpg)](https://www.youtube.com/watch?v=PgKKCWNNcuk)

### Ultrasonic Sensor Head Version
[![how to make a creepbot](https://img.youtube.com/vi/LDjwKNZhbA8/0.jpg)](https://www.youtube.com/watch?v=LDjwKNZhbA8)
