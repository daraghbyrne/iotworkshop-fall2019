
int redValue = 255; // Full brightness for an ANODE RGB LED is 0, and off 255
int greenValue = 255; // Full brightness for an ANODE RGB LED is 0, and off 255
int blueValue = 255; // Full brightness for an ANODE RGB LED is 0, and off 255</td>

int redPin = D4;    // RED pin of the LED to PWM pin **d2**
int greenPin = D5;  // GREEN pin of the LED to PWM pin **d3**
int bluePin = D6;   // BLUE pin of the LED to PWM pin **D4**

// Define a pin we'll place an LED on
int ledPin = D2;

// Our button wired to D0
int buttonPin = D3;

// Define a pin that we'll place the pot on
int potPin = A5;

// Create a variable to hold the pot reading
int potReading = 0;

// Create a variable to store the LED brightness.
int ledBrightness = 0;

// Track if it's on or off
bool currentHueState = true;

// store the last value the button registered
bool previousButtonState = LOW;


void setup()
{
  // Set up the LED for output
  pinMode(ledPin, OUTPUT);
  
  pinMode( redPin, OUTPUT );
  pinMode( greenPin, OUTPUT );	
  pinMode( bluePin, OUTPUT );	
	
  // For input, we define the
  // pushbutton as an input-pullup
  // this uses an internal pullup resistor
  // to manage consistent reads from the device

  pinMode( buttonPin , INPUT_PULLUP); // sets pin as input

  // Create a cloud variable of type integer
  // called 'dial' mapped to potReading



  Particle.variable("dial", &potReading, INT);

  Particle.variable("brightness", &ledBrightness, INT);

  Particle.variable("r", redValue );
  Particle.variable("g", greenValue );
  Particle.variable("b", blueValue);
  
  //Register our Particle function here
  Particle.function("ledR", changeR);
  Particle.function("ledG", changeG);
  Particle.function("ledB", changeB );
  
  Particle.variable("isOn", currentHueState );
  Particle.function("state", changeState );
  
	
}

void loop()
{
		
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
	
   if( !currentHueState ){
       offColorLED( );
   }else{
       updateColorLED();
   }

   // wait 1 second
   delay( 1000 );

}


void offColorLED( ){
  setRGBColor(0,0,0);
}

// Note that 
// Full brightness for an ANODE RGB LED is 0, and off 255
// So we set our RGB values to be 255 - value (invert them)

void setRGBColor( int r, int g, int b ){
	
  redValue = r;
  greenValue = g;
  blueValue = b;
	
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

}



int changeR( String command )
{
    // get the red component...
    int colorValue = command.toInt();
    // make it blink 3 times
    blinkStatusLED();

   // write the mixed color
   redValue = colorValue;
   updateColorLED();
   return 1;
}

int changeB( String command )
{
    // get the red component...
    int colorValue = command.toInt();
    // make it blink 3 times
    blinkStatusLED();

   // write the mixed color
   blueValue = colorValue;
   updateColorLED();

   return 1;
}

int changeG( String command )
{
    // get the red component...
    int colorValue = command.toInt();
    // make it blink 3 times
    blinkStatusLED();
   // write the mixed color
   greenValue = colorValue;
   updateColorLED();

   return 1;
}

void updateColorLED( ){

  setRGBColor( redValue, greenValue, blueValue);

}	

void blinkStatusLED(){

  for( int i = 0 ; i < 3; i++){
    digitalWrite(ledPin, HIGH);
    delay( 100 );
    digitalWrite(ledPin, LOW);
    delay( 100 );
  }

}	

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