# esp32_analog_read_speed
Simple test to see how quick ESP32 ADC works

This code doesn't need anything connected to the ESP32 but the USB to the computer to power ESP32 and you can read results from Serial Monitor.

This will tell you something like that:

```
Readtime     : 1.500002 seconds.
Analog reads : 17077 values.
Average time : 87.837563 micro seconds per read.
Sample rate  : 11384 sps (samples-per-second).
- - - -
```

Pretty slow...
Much better is to use is2-dma-adc readings.
