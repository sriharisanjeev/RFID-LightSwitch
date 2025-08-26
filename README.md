RFID Controlled AC Bulb Project

📌 Overview

This project is an RFID-based access control system that can switch an AC bulb ON/OFF using RFID cards. Only authorized cards can control the bulb. Unauthorized cards will not affect the bulb.

It is a simple and effective way to understand how embedded systems, RFID technology, and relays can be combined to control real-world electrical devices.
Demo Video YT link - 


🎥 Demo Video  



⚙️ Components Used

Arduino (Uno/Nano/ESP32 etc.)

RFID Reader (RC522)

RFID Tags/Cards

Relay Module

AC Bulb & Holder

Jumper Wires

Breadboard / PCB


🔌 Working Principle

The RFID module reads the unique ID of the card.

The Arduino checks if the card is authorized.

If authorized → Relay toggles the AC bulb ON/OFF.

If unauthorized → Nothing happens.

The relay acts as a switch between the Arduino (low voltage) and the AC bulb (high voltage).



🚀 How to Run

Connect the components as per the circuit diagram.

Upload the Arduino code (included in this repo) to your board.

Power the circuit.

Tap the RFID card on the reader:

If it’s an authorized card, the bulb will toggle.

If not, the bulb will remain unchanged.



📂 Repository Contents

RFID.ino/ → Arduino sketch (.ino file)

circuit_diagram/ → Circuit design images

videos/ (optional) → Demo videos of working project

README.md → This documentation



📝 Future Improvements

Add multiple authorized users.

Add a buzzer for unauthorized attempts.

Connect with IoT (ESP32 + WiFi) for remote control.

Replace bulb with other appliances (fan, door lock, etc.).



✨ Author

Project built by Srihari Sanjeev Bharadwaj (ECE Student, BMSCE) & Hemsagar BC (EIE Student, BIT)
