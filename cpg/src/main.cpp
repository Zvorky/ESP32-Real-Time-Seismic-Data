// ESP32 Real-Time Seismic Data
// Enzo 'Zvorky' Delevatti - August 2025

/* CPG - Geophysical Processing Center
    - Receives data from the ESR.
    - Validates integrity using the parity bit.
    - In case of error (simulation: 1 out of every 20 transmissions), requests retransmission.
    - When valid, confirms reception and converts the 7-bit value into an integer, displaying it on the serial monitor.
*/


#include <Arduino.h>

void setup() {
    Serial.begin(9600);
    Serial.println("CPG Started.");
}

void loop() {
    Serial.println("Loop");
    delay(1000);
}