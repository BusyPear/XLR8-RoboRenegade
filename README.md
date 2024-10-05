I am Aaryan Barupal


-----------------
Team RoboRenegade
-----------------
<h3>What makes our bot different from the rest:</h3><br />
(1) Unique design:<br />
	&emsp;➢We used two layers of acrylic sheets,<br />
	&emsp;➢also, the tyres seem fixed to the bottom layer but aren't because it is impossible due to the size constraints.<br />
	&emsp;➢The tyres are clamped to the upper layer, and the upper layer is bound to the lower one.<br />
	&emsp;➢All of the circuit is on top of the lower acrylic sheet, which leaves lots of space on top of the upper acrylic sheet for additional features(like a cannon!)<br />
	&emsp;➢Our bot is not affected by rain because the upper acrylic sheet acts as a roof for the circuit below. <br />
	&emsp;➢Lower acrylic sheet was designed to embed the tyres and motors so the bot wouldn't be too wide, and it looks cool. <br /><br />
(2) Speed regulation:<br />
	&emsp;➢We can precisely control its speed by changing the controller's angle. <br />
	&emsp;➢We modified the code in Rpi Pico W to establish a linear relationship between the controller's angle and the bot's speed.<br /><br />
(3) RGB LED brightness: <br />
	&emsp;➢Our RGB LED(Common Anode) was brighter than others because we connected it to 5V power supply of motor driver. <br />
	&emsp;➢The brightness of an RGB LED attached to our bot also depended upon the bot's speed. <br /><br />
(4) Trigger of the cannon: <br />
	&emsp;➢We saw gold in what others do not even see dust<br />
	&emsp;➢We created three new virtual switches in the pre-existing controller using the imu data(gx,gy,gz) without hardware changes.<br /><br /><br />
<h3>Motivation:</h3><br />
(1) Mentor warned about the strength of the acrylic sheets, as they had broken them before their run during their xlr8 journey.<br />
(2) Robust design.<br />
(3) We could not control the bot's speed well with the given code. <br />
(4) The controls and brightness of the RGB led weren't satisfactory.<br />
(5) We wanted to keep the controller as simple as possible to use but also act as trigger for the cannon.<br />
