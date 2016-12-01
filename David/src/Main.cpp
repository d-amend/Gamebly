/* By default, the APA102 library uses pinMode and digitalWrite
 * to write to the LEDs, which works on all Arduino-compatible
 * boards but might be slow.  If you have a board supported by
 * the FastGPIO library and want faster LED updates, then install
 * the FastGPIO library and uncomment the next two lines: */
// #include <FastGPIO.h>
// #define APA102_USE_FAST_GPIO

#include <APA102.h>
// Define which pins to use.
const uint8_t dataPin = 13;
const uint8_t clockPin = 14;

// Create an object for writing to the LED strip.
APA102<dataPin, clockPin> ledStrip;

// Set the number of LEDs to control.
const uint16_t ledCount = 30;

// Create a buffer for holding the colors (3 bytes per color).
rgb_color colors[ledCount];

// Set the brightness to use (the maximum is 31).
const uint8_t brightness = 1;

const uint16_t columnCount = 5; //Spaltenanzahl
const uint16_t lineCount = 6;   //Zeilenanzahl





//turns all LEDs on (white)
void turnAllOn()
{
  ledStrip.startFrame();
  for(uint16_t i = 0; i < ledCount; i++)
  {
    ledStrip.sendColor(255,255,255,1);
  }
  ledStrip.endFrame(ledCount);
}

//turns all LEDs off
void turnAllOff()
{
  ledStrip.startFrame();
  for(uint16_t i = 0; i < ledCount; i++)
  {
    ledStrip.sendColor(0,0,0,0);
  }
  ledStrip.endFrame(ledCount);
}

//turns on a random LED in one line, line by line, beginning with the first
void oneInLineByline()
{
  uint16_t minLed = 0;
  uint16_t maxLed = columnCount;

  for(uint16_t i = 0; i < lineCount; i++)
  {
    uint8_t ballPos = random(minLed, maxLed);
    for(uint16_t j = 0; j < ledCount; j++)
    {

      if(j == ballPos)
      {
        colors[j].red = 50;
        colors[j].green = 205;
        colors[j].blue = 50;
      }
      else
      {
        colors[j].red = 0;
        colors[j].green = 0;
        colors[j].blue = 0;
      }
    }
    ledStrip.write(colors, ledCount, brightness);
    delay(500);
    minLed = minLed + columnCount;
    maxLed = maxLed + columnCount;
  }
}

void loop()
{


}


void setup()
{
  turnAllOff();
  turnAllOn();
}
