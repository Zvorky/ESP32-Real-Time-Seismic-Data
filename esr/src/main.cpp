// ESP32 Real-Time Seismic Data
// Enzo 'Zvorky' Delevatti - August 2025

/* ESR - Remote Seismological Station
    - Generates simulated seismic data as binary sequences of 7 bits + 1 parity bit.
    - Transmits the data to the CPG via serial (1 data packet per second).
    - Displays logs on the serial monitor:
        - Date/time of transmission.
        - Transmitted data (with the parity bit separated).
        - Confirmation of reception or retransmission request.
*/


#include <Arduino.h>

void setup() {
    Serial.begin(9600);
    Serial.println("ESR Started.");
}

void loop() {
    Serial.println("Loop");
    delay(1000);
}