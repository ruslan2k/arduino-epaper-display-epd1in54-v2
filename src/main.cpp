#include <Arduino.h>
#include <stdio.h>

#define MAX_INPUT_LENGTH 60 // Maximum length of the input buffer
#define MAX_ARGS_COUNT 5 // Maximum number of arguments
#define MAX_ARG_LENGTH 12 // Maximum length of each argument

int readStringFromSerial(char *buffer, int maxLength);

char inputBuffer[MAX_INPUT_LENGTH]; // Array to hold the incoming data

void setup()
{
    Serial.begin(9600);

    Serial.println("Arduino Serial Echo");
    Serial.println("Type something to see it echoed back!");
}

void loop() {
    char argsArray[MAX_ARGS_COUNT][MAX_ARG_LENGTH]; // Array to hold the arguments
    int length = readStringFromSerial(inputBuffer, MAX_INPUT_LENGTH);
    char *token;

    if (length > 0) {
        // Print the received string
        Serial.print("You typed [");
        Serial.print(inputBuffer);
        Serial.print("]\n");

        token = strtok(inputBuffer, " "); // Tokenize the input string
        for (int i = 0; i < MAX_ARGS_COUNT; i++) {
            if (token == NULL) {
                argsArray[i][0] = '\0';
                break;
            }
            strcpy(argsArray[i], token);
            token = strtok(NULL, " ");
        }

        // Print the arguments
        Serial.print("Arguments:\n");
        for (int i = 0; i < MAX_ARGS_COUNT; i++) {
            if (argsArray[i][0] == '\0') { break; }

            Serial.print("arg[");
            Serial.print(i);
            Serial.print("]: ");
            Serial.println(argsArray[i]);
        }
    }
}

// Function that reads a string from serial until newline
// Returns: number of characters read (0 if nothing or only newline was read)
int readStringFromSerial(char *buffer, int maxLength) {
    int index = 0;

    // Wait for data to be available
    while (1) {
        if (Serial.available() <= 0) {
            continue; // No data available, keep waiting
        }
        // Read the incoming byte
        char incomingChar = Serial.read();

        // If the incoming char is a newline, terminate the string
        if (incomingChar == '\n' || incomingChar == '\r') {
            if (index > 0) { // Only process if buffer contains data
                Serial.write('\n'); // Echo the newline character
                // Add null terminator to make it a proper C string
                buffer[index] = '\0';
                // index = 0; // Reset index for next input
                return index; // Return the length of the string (without null terminator)
            }
        }
        // Otherwise, add the incoming character to the buffer if there's room
        else if (index < maxLength - 1) {
            Serial.write(incomingChar); // Echo the character back immediately
            // Leave room for null terminator
            buffer[index] = incomingChar;
            index++;
        }
    }

    // If we reach here without returning, it means we didn't get a complete line yet
    return 0;
}
