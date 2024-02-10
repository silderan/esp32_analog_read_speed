/*
 * This code for Arduino IDE 2 for ESP32, makes a performance test reading analog values.
 * This, efectively, can tell us how ADC behave and the maximum sample speed you can obtain.
 */

// This defines the pin input to read from.
// It's up to ESP32 board. In mine, 32, GPIO32, es the ADC1_CHANEL_4
#define ADC_INPUT_PIN   (32)

// This defines how many time (in uSecs) will keep reading.
// In my tests, with 1 second is good time.
#define AVERAGE_UTIME   (1000000)

void setup()
{
  Serial.begin(115200);

  // Resolution of 12 bits is the maximum hardware can do.
  analogReadResolution(12);
}

void loop()
{
  uint32_t sTime = micros() + AVERAGE_UTIME;
  uint32_t reads = 0;

  uint32_t initTime = micros();
  while( sTime > micros() )
  {
    analogRead(ADC_INPUT_PIN);
    reads++;
  }
  uint32_t readTime = micros() - initTime;

  Serial.printf("Total analog reads       : %d values.\n", reads);
  Serial.printf("Full read time           : %f seconds.\n", readTime/1000000.0);
  Serial.printf("Average single read time : %f micro seconds per read.\n", readTime/float(reads));
  Serial.printf("Maximum sample rate      : %d sps (samples-per-second).\n", int(float(reads)/readTime*1000000));
  Serial.println("- - - -");
}
