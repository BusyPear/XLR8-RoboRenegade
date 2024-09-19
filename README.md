-----------------
Team RoboRenegade
-----------------
What makes our bot different from the rest:
(1) Unique design :
	➢We used two layers of acrylic sheets,
	➢also, the tyres seem to be fixed to the bottom layer but aren't because it is impossible due to the size constraints.
	➢The tyres are clamped to the upper layer and upper layer is bound to the lower one.
	➢All of the circuit is on top of the lower acrylic sheet, which leaves lots of space on top of the upper acrylic sheet for additional features(like a cannon!)
	➢Our bot is not affected by rain because the upper acrylic sheet acts as a roof for the circuit below. 
	➢Lower acrylic sheet was designed to embed the tyres and motors so the bot wouldn't be too wide, and it looks cool. 
(2) Speed regulation:
	➢We can precisely control its speed by changing the angle of the controller. 
	➢The code in Rpi Pico W was modified to establish a linear relationship between angle of the controller and the speed of the bot.
(3) RGB LED brightness 
	➢Our LED was brighter than others because we connected it to 5V power supply of motor driver. 
	➢The brightness of a RGB LED attached to our bot also depended upon the speed of the bot. 
(4) Trigger of the cannon
	➢We saw gold in what others donot even see dust
	➢We created three new virtual switches in the pre-existing controller using the imu data(gx,gy,gz) without any hardware changes.
 
