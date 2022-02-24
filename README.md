How to get EMG data to VRChat:

Buy:

https://www.sparkfun.com/products/13723

Some electrodes like these or similar:

https://www.aliexpress.com/item/1005002328537609.html

And ESP-WROOM-32 or similar

https://www.ebay.com/itm/203534027865


Wire it like this:
![wiring](https://github.com/Greendayle/Esp32_emg_vrchat/blob/main/esp-wroom-32.png)


Blue: 3v3 <-> + on myoware

Violet: GND <-> - on myoware

Violet: WHITE <-> SIG on myoware

White is connected to VP, which is CH0 of ADC1. Only ADC1 can work when wifi is enabled on ESP32.

Then, you flash ESP32 with the https://github.com/Greendayle/Esp32_emg_vrchat/blob/main/emg_monitor_pub.ino file using Arduino IDE. https://www.arduino.cc/en/software

Before flashing adjust the file to put your WiFi SSID, password, and you local LAN IP address of the PC which is running VRChat (or your quest).
ESP will send OSC messages directly to vrchat, it will try to modify `emg` avatar parameter.


ATTENTION NEVER ATTACH EMG SENSOR TO YOUR BODY WHEN IT'S CONNECTED TO YOUR PC VIA USB, IT CAN CAUSE **DEATH** AT WORST CASE SCENARIO.


Connect the ESP32 to powerbank, attach the Myoware to electrodes, put electrodes in the center of your target muscle, third (cabled) connection must be NOT on the muscle, but somewhere nearby.
Consult Myoware manual for placement or experiment yourself. 
Done! ESP is now sending muscle activation to your vrchat!

