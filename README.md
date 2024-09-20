-----------------
Team RoboRenegade
-----------------
What makes our bot different from the rest:\
(1) Unique design :\
	&emsp;➢We used two layers of acrylic sheets,\
	&emsp;➢also, the tyres seem fixed to the bottom layer but aren't because it is impossible due to the size constraints.\
	&emsp;➢The tyres are clamped to the upper layer, and the upper layer is bound to the lower one.\
	&emsp;➢All of the circuit is on top of the lower acrylic sheet, which leaves lots of space on top of the upper acrylic sheet for additional features(like a cannon!)\
	&emsp;➢Our bot is not affected by rain because the upper acrylic sheet acts as a roof for the circuit below. \
	&emsp;➢Lower acrylic sheet was designed to embed the tyres and motors so the bot wouldn't be too wide, and it looks cool. \
(2) Speed regulation:\
	&emsp;➢We can precisely control its speed by changing the controller's angle. \
	&emsp;➢We modified the code in Rpi Pico W to establish a linear relationship between the controller's angle and the bot's speed.\
(3) RGB LED brightness \
	&emsp;➢Our LED was brighter than others because we connected it to 5V power supply of motor driver. \
	&emsp;➢The brightness of an RGB LED attached to our bot also depended upon the bot's speed. \
(4) Trigger of the cannon\
	&emsp;➢We saw gold in what others do not even see dust\
	&emsp;➢We created three new virtual switches in the pre-existing controller using the imu data(gx,gy,gz) without hardware changes.
