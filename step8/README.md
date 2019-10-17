# Step 8: On/Off

I'm sure we won't always want our Particle Hue to be on! Let's use the push button to turn off the lamp for a bit.

Let's make a quick change to toggle on and off the lamp.  All of these changes will go into our `loop()`

First we'll need to read in our button. Add this line to the top of the loop. It'll see if the button is pushed by checking for power on the button pin

````
// Track if it's on or off
bool currentHueState = true;

// store the last value the button registered
bool previousButtonState = LOW;

````

Next, if the button is pushed (reading `LOW`) then we want to toggle it on or off by adding the following code to the `loop()`

````
  int buttonState = digitalRead( buttonPin );

  if( buttonState != previousButtonState && buttonState == LOW )
  {

    currentHueState = !currentHueState;
		
    if( currentHueState == HIGH ){
      Particle.publish( "iot-workshop-2019/hue/status", "toggledOn" );
    }else{
      Particle.publish( "iot-workshop-2019/hue/status", "toggledOff" );
    }

  }		
	
  previousButtonState = buttonState;
	

````

You can also publish the toggle to see it as it happens through the Particle console!

Then finally we just decide if we should display the change or nothing at all based on the variable `ledState`. Modify the loop to wrap `displayChange()`  in an `if` statement like so

````

    if( !currentHueState ){
        offColorLED( );
    }else{
        updateColorLED();
    }

    // wait 1 second
    delay( 1000 );

````

Finally, add the function for `offColorLED()`

````
void offColorLED( ){
  setRGBColor(0,0,0);
}

````


And you're done!

Compile, flash and try it out! Push the button, dial the knob and find out what the markets are like for bitcoin!

Nice work. 