#!/bin/bash
if [ $# -ne 2 ]; then
         echo "Usage : convert-avrora filename1.exe filename2.od"
         exit 1
    fi
avr-objcopy --output-target=srec  $1 temp.srec
avr-objdump -zhD $1 > $2 
rm temp.srec
# following are the ways in which avrora can be run : first one is for single node emulation and second one is for network simulation
#avrora  -platform=mica2 -seconds=15.0 filename.od                    
#java -jar /home/gireesh/Documents/wsn/simulators/avrora/avrora.jar -simulation=sensor-network -seconds=20.0 -nodecount=2 blink2radio.od


