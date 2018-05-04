# Orange-Crush-3026-2018
2018 FRC Comp Bot Code

FRC Team 3026 Orange Crush Robotics LabVIEW code for the 2018 competition season

## Functions
### Command and Control LabVIEW  <br />
### Autonomus
- Motion Profiling Drive
- SRX processed points timing for manipulators in auto
- Capability of loading new paths on the fly and not changing code
- Can change paths match by match to acomadate alliance
### Drive Train 
- Field Centric Mecanum 4ft/sec <br />
- Robot Centric Mecanum 4ft/sec <br />
-  Field Centric Mecanum 14ft/sec <br />
-  Robot Centric Mecanum 14ft/sec <br />
-  Robot Centric 6 Wheel Tank 4ft/sec <br />
-  Robot Centric 6 Wheel Tank 14ft/sec <br />
-  Turn to angle (NavX) <br />
-  Strafe Correction (NavX) <br />
-  Auto Balancing <br />
-  Auto shifting 2 speed gearboxes <br />
-  Drive to distance <br />
-  Cube Centric<br />
-  Switch Centric<br />
-  Pursuit Mode (Tracking other robots to play defence)<br />
### Arm Actuator <br /> 
- Manual Movement <br />
- Positional Movement (PID on potentiometer) <br />
- Soft limits using potentiometer <br />
- Joystick scaling for smoth movement <br />
- Actuating arm for up to 10 in extention <br /> 
- Auto actuate arm extender to stay within 16 inches <br /> 
### Intake Wheels <br />
- Intake wheels mapped to arcade drive joystick <br />
- Shooting feature <br />
- Constant speed control <br />
### Claw Rotation
- Manual rotation of claw <br />
- Preset position control (PID on potentiometer) <br />
- Auto rotate Claw to stay within 16 inches <br />
### Climber
- Adjustable speed climber <br />
- Amp limits to prevent brownouts and tripping breakers <br />
### Arduino LED Lights
- Led Lights indicating drive mode <br />
- Driven by DIO conveted from binary used in switch statement <br />
### Vision Tracking
- TCP/IP connection to UP^2 Development board <br />
- API calls communicating to RoboRealm vision tracking software <br />
- Displays Eagle Eye view to dashboard (newer car overhead display) <br />
- Vision Tracking cubes <br />
- Vision Tracking switch <br />
- Vision Tracking opposing robots <br />
