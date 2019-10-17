# Step 10: Fine Tuning

We haven't used our potentiometer / dial yet as part of this project. 

Wouldn't it be nice if we could quickly cycle through some color options.  As our final step, we're going to modify our code to do exactly this.

To do this, we're going to use a function called `wheel()` that will take a value in the HSV color space and translate it into the RGB Color space. Add the following to your code.

````
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t wheel(byte WheelPos) {
  if(WheelPos < 85) {
    redValue = WheelPos * 3;
    greenValue = 255 - WheelPos * 3;
    blueValue = 0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   redValue = 255 - WheelPos * 3;
   greenValue = 0;
   blueValue = WheelPos * 3;
  } else {
   WheelPos -= 170;
   redValue = 0;
   greenValue = WheelPos * 3;
   blueValue = 255 - WheelPos * 3;
  }
}

````

Next, we'll modify the `loop`... 

After the `else` statement we'll change the code to do the following

- Read in the current potentiometer value
- To check the potentiometer value against the last value and see if it's changed enough
- Map this value from the analog range (0-4095) to the digital/PWM range (0-255)
- Convert the digital value using wheel into red, green and blue values.
- Update the LED color
- Update the stored potentiometer reading

````
   if( !currentHueState ){
       offColorLED( );
   }else{
		
      int currentVal = analogRead( potPin );
      if( abs( currentVal - potReading ) > 15 ) {
        int val = map(potReading , 0, 4095, 0, 255 );
        wheel( val );
        updateColorLED();
        potReading = currentVal;
      }
   }
````

## Over to you

Have fun, experiment, try some stuff out, add some new features or remix functionality from this device !