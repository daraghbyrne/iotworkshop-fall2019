# Step 9: Remote On/Off

We can also let you remotely control the on and off functionality. 

To do this, let's add a few more cloud features

Start by adding a cloud variable to see if the lamp is on or off

````
  Particle.variable("isOn", currentHueState );

````

Then add a cloud function called `state` that will map to function called `changeState`

````
  Particle.function("state", changeState );
````

Add this method:


````
	int changeState( String command )
	{
	  command = command.toUpperCase();
	  blinkStatusLED();

	  if( command.equals( "ON" ) || command.equals( "HIGH" ) ){
	    currentHueState = HIGH;
	    Particle.publish( "iot-workshop-2019/hue/status", "ON" );
	    updateColorLED();
	    return 1;
	  }

	  if( command.equals( "OFF" ) || command.equals( "LOW" ) ){
	    currentHueState = LOW;
	    Particle.publish( "iot-workshop-2019/hue/status", "OFF" );

	  }

	  return -1;
	}
````	

Flash your code, open the console, find the cloud function called `state` and type in `ON`
Cross your fingers and hope it works!!!