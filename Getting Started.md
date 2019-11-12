#My Random Car Hack & Exploration Mind Dump Secret Diary



cansend can0 5A1#11.22.33.44.55.66.77.88
cansniffer -c can0

cansend can0 0C9#8021C0071B101000

0x7c
0x7B 0x7E


sudo modprobe can
sudo slcand -o -c -s6 /dev/ttyACM0 can0
sudo ifconfig can0 up
