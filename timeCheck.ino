

void setup() {
}

void loop() {
	// Take the time, and send it.  This will block until complete
	unsigned long start_time = micros();                             

	// Set up a timeout period, get the current microseconds
	unsigned long started_waiting_at = micros();               

	// do something
	delay(1000);

	Serial.println(micros() - started_waiting_at);
	
	delay(1000);
}
 