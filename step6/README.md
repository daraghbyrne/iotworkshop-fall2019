# Step 6: Remote control 

Our RGB LED is up and running. Now it's time to start making it connected. 

We'll repeat a little of the concepts from Step 4 'Adding Internet' and get each of the R, G, and B components hooked up to the web. 


## Seeing Red (and green and blue)

Let's add some Particle variables to see what the red, green and blue components are currently mapped to.

Add the following code to your `setup()`

````
  Particle.variable("r", redValue );
  Particle.variable("g", greenValue );
  Particle.variable("b", blueValue);
````

Flash your code and visit the Particle Console. You should now see these values change as the colors do. Neat. 

## Controlling Red

Next, we'll add a `Particle.function()` to let us remotely control the red component of our LED.

First things first, we'll want to remove the elements of our loop. If we keep the loop as it is, it will continually change the LED color and we won't be able to see the changes we're making online!

Comment out or deleting the contents of the loop. You should now have a loop that looks like this 

````
	void loop(){
		
	}
````

Great. Now let's add a Particle.function. Edit the `setup()` and add a line that says:

````
  Particle.function("ledR", changeR);
````

This tells our microcontroller we want to name a cloud function `ledR` (this is what will display in the Particle console) and map it to a function in our code called `changeR`. So, the next thing we need to do is create a function called `changeR`

Add the following to your code:

````

	int changeR( String command )
	{
	    // get the red component...
	    int colorValue = command.toInt();

	   // write the mixed color
	   redValue = colorValue;
	   updateColorLED();
	   return 1;
	}

````

Finally, we'll add the method: `updateColorLED()` this will be a simple and easy method to call `setRGBColor()` using the current color values. 

````
void updateColorLED( ){

  setRGBColor( redValue, greenValue, blueValue);

}		
````

Flash your code and visit the Particle Console. You should now see a function available named `setR`, type in a color value and press the button. Hopefully the RED component changes. 

### Over to you.

Repeat the step above and add 

- A Particle function to control the _blue_ component
- A Particle function to control the _green_ component



### Try it yourself

Experiment with these colors - they can be any where from 0 - 255 for each component. Try out a few variations 


