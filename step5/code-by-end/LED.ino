
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

	
}

void loop()
{
		
    setRGBColor( 255,255,255);    // set it to white
		delay( 2000);						// wait 2 seconds
    setRGBColor( 255,0,0);    // set it to red
		delay( 2000);						// wait 2 seconds
    setRGBColor( 255,255,0);    // set it to yellow
		delay( 2000);						// wait 2 seconds
    setRGBColor( 255,127,0);    // set it to orange
		delay( 2000);						// wait 2 seconds
    setRGBColor( 255,0,255);    // set it to magenta
		delay( 2000);						// wait 2 seconds
    setRGBColor( 0,255,0);    // set it to green
		delay( 2000);						// wait 2 seconds
    setRGBColor( 0,255,0);    // set it to green
		delay( 2000);						// wait 2 seconds

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