#include <Arduino.h>
#include <stdio.h>

void setup()
{
    Serial.begin(9600);

    // Print a welcome message
    Serial.println("Arduino Serial Echo");
    Serial.println("Type something to see it echoed back!");
}

void loop()
{
    // Check if data is available to read
    int available = Serial.available();
    if (available > 0)
    {
        // Read the incoming byte
        char incomingByte = Serial.read();

        // Echo the incoming byte back
        Serial.print("Received:\n");
        Serial.write(incomingByte);
        Serial.println("\nEOF");
    }
}
