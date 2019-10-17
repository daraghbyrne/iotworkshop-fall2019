# Step 7: Displaying Remote Interactions


We have that lovely LED that we could use to display when a change or interaction has been triggered remotely. 

In this case we're going to modify our code to blink the single color LED 3 times whenever a remote / cloud action is fired. 

## All about loops

In this section, we’re going to look at loops - another element of the Wiring language that’s incredibly useful.

Think back to that blinking LED. We could make it blink on and off 3 times and then stop if a button is pressed by writing some code like this:

````
	if( digitalRead( buttonPin)  == LOW ){

		digitalWrite( ledPin, HIGH );
		delay( 1000 );
		digitalWrite( ledPin, LOW );
		delay( 1000 );

		digitalWrite( ledPin, HIGH );
		delay( 1000 );
		digitalWrite( ledPin, LOW );
		delay( 1000 );

		digitalWrite( ledPin, HIGH );
		delay( 1000 );
		digitalWrite( ledPin, LOW );
		delay( 1000 );

	}
````

Yes, this absolutely works and its one way you could make this happen, but its far from ideal. Why? Because we’ve introduced a lot of redundancy into our code. We’re using the same blocks of code repeatedly. If ever we want to change how the blinking behaves (to make it faster or slower), we’ll need to edit in lots of different places. Because we have to make lots of edits, we also risk introducing errors - by forgetting to change one of the delays for example. Additionally, it’s just verbose. By having to make each action explicit and repeating it over and over, we’re adding a lot of code to our project and that makes it harder to read and figure out what’s really happening.

Thankfully, most coding languages have a trick to help simplify the process of making a set of actions repeatedly occur. This is known as a `loop`. The most common type of loop is a `for loop` and this is what we’ll look at in this section.

With a for loop, we can transform this long set of statement into something much more sleek and efficient, like so:

````
	if( digitalRead( buttonPin)  == LOW ){

		for( int i = 0; i < 3; i++ )
		{
			digitalWrite( ledPin, HIGH );
			delay( 1000 );
			digitalWrite( ledPin, LOW );
			delay( 1000 );
		}
	}
````

This is a heck of a lot neater. So what’s happening here. Well the for loop needs three things to operate. This is what happens on the first line:

`for( int i = 0; i < 3; i++ )`

could be read as:

`for( [set up a starting condition]; [condition to check at the end of each loop]; [what happens when each iteration of the loop completes] )`

Basically, the loop needs to know three things:

- We’ve got to create a variable it’ll use to store the status of the loop e.g. int i = 0; int i = 20; int i = 1. Your starting condition can be whatever you like - you just need to define it.
- We’ve got to tell the loop how to check to see if it should stop running. In the example above, it’s going to stop when i gets to 3 i.e. i < 3. You can adjust this condition to be whatever you like but keep in mind how this comparison is going to effect the behavior of the loop. You could use i < 5 and it’ll loop 5 times. You could use i < 100 and it’ll loop 100 times. You can even make this loop dependent on the value of another variable i < numTimes - providing you define that variable elsewhere in your code.
- We have to tell the loop what to do when each iteration of the loop finishes. Normally, this will be adding 1 to the loop counter (e.g. i++) or subtracting 1 from our loop counter (i--). This bit will occur when the loop executes the code between the curly brackets {...} and reaches the } containing the loops actions. In this case it’s going to add one to our loop counter, then it backtracks, checks this variable against the completion condition and sees if it should proceed with another iteration or stop the loop entirely.


## Let's add a loop

Add the following method to your code:

````
	void blinkStatusLED(){

	  for( int i = 0 ; i < 3; i++){
	    digitalWrite(ledPin, HIGH);
	    delay( 100 );
	    digitalWrite(ledPin, LOW);
	    delay( 100 );
	  }

	}	
````

Now...  Modify the `changeR()`, `changeB()` and `changeG()` functions to call this method:

````
	int changeG( String command )
	{
	    // get the red component...
	    int colorValue = command.toInt();
			// make it blink 3 times
	    blinkStatusLED();
````

Flash it and test it. 

### Over to you.

- Modify the loop to blink 5 times. 


