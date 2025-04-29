#include <Arduino.h>
#include <stdio.h>

#define MAX_INPUT_LENGTH 64  // Maximum length of the input buffer

char inputBuffer[MAX_INPUT_LENGTH];  // Array to hold the incoming data
int inputIndex = 0; 

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
    if (Serial.available() > 0)
    {
        // Read the incoming byte
        char incomingChar = Serial.read();

        if (incomingChar == '\n' || incomingChar == '\r') {
            if (inputIndex > 0) {
                Serial.write('\n');  // Print a newline character
                inputBuffer[inputIndex] = '\0';  // Null-terminate the string
                Serial.print("You typed: ");
                Serial.println(inputBuffer);  // Echo the input back to the serial monitor
                inputIndex = 0;  // Reset the index for the next input
            }
        } else if (inputIndex < MAX_INPUT_LENGTH - 1) {
            Serial.write(incomingChar);  // Echo the character back immediately
            inputBuffer[inputIndex++] = incomingChar;  // Store the character in the buffer
        } else {
            Serial.println("Input too long!");  // Handle buffer overflow
            inputIndex = 0;  // Reset the index to prevent overflow
        }
    }
}
