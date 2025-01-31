# Release V0.1


## PCB
### Overall Notes

If you add a pull-up resistor (with magnet wire or some other wire), pretty much all features are working. The display was not tested.

The diode footprint is very small making it difficult to build. __SOD-323 diodes are masochistic__. When building this keyboard, __a hot hair station is recommended__. It probably won't work with only a soldering iron.

### Working
+ LED
+ All switches
+ TX and RX
+ Power
+ Battery (in conjunction with a nice!nano V2)

## Not Working
- hadedness detection (can be set manually in firmware or a pull down resistor can be added to the right side.)

### Not tested
- OLED
- Low power display (the kind you'd want to use in a wireless build)


