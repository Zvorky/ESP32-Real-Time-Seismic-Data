# ESP32-Real-Time-Seismic-Data
Simulation of real-time transmission, reception, and pre-processing of seismic data using two ESP32 microcontrollers connected via serial communication.

[Leia-me em Português](LEIAME.md)

## Objective
Reproduce the operation of a Remote Seismological Station (ESR) sending data to a Geophysical Processing Center (CPG), including integrity verification mechanisms, acknowledgment/resend protocols, and real-time visualization in the serial terminal.

## Real-Time Seismic Data Processing
The Global Geophysical Research Center operates a network of Remote Seismological Stations (ESR) in tectonically active locations. These stations continuously monitor seismic activity, capturing vibration patterns as raw data sequences (represented by 8-bit binary strings).

This vital data is transmitted via a secure serial communication link to the Geophysical Processing Center (CPG), where it must be quickly converted into a numeric format and displayed on the computer’s serial terminal for immediate analysis by seismologists trying to predict events or better understand Earth’s dynamics.

Transmission and processing must be efficient and robust. Due to the critical nature of the application, each reception at the CPG must inform the ESR whether the data has successfully arrived or not. As is generally known, serial communication may suffer bit alterations during transmission. A protocol for error detection (e.g., parity) and a request for retransmission in case of failure is required.

## System Architecture
### [ESR](./esr/src/main.cpp) (Remote Seismological Station – ESP32 #1)
- Generates simulated seismic data as binary sequences of 7 bits + 1 parity bit.
- Transmits the data to the CPG via serial (1 data packet per second).
- Displays logs on the serial monitor:
  - Date/time of transmission.
  - Transmitted data (with the parity bit separated).
  - Confirmation of reception or retransmission request.

### [CPG](./cpg/src/main.cpp) (Geophysical Processing Center – ESP32 #2)
- Receives data from the ESR.
- Validates integrity using the parity bit.
- In case of error (simulation: 1 out of every 20 transmissions), requests retransmission.
- When valid, confirms reception and converts the 7-bit value into an integer, displaying it on the serial monitor.

## Operation Flow
1. ESR generates a random 7-bit sequence.
2. The 8th bit (parity) is added.
3. The data is transmitted to the CPG.
4. The CPG validates data integrity:
   - If valid → confirms reception and converts it to an integer.
   - If corrupted → requests retransmission from the ESR.
5. The ESR retransmits the data until the CPG receives it correctly.

## Features
- [ ] Robust serial communication between two ESP32 boards.
- [ ] Generation of binary data with parity bit.
- [ ] Transmission failure simulation (~5%).
- [ ] Error detection and correction protocol (retransmission).
- [ ] Detailed logs on both serial terminals.
- [ ] Automatic conversion of received data into numeric values for immediate analysis.
