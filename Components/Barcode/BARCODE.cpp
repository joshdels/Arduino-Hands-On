#include "BARCODE.h"
#include "Arduino.h"

BARCODE::BARCODE(int barcodePin, int txPin, int rxPin)
  : barcodeSerial(txPin, rxPin)
{
  this->barcodePin = barcodePin;  // Set the barcodePin
  this->txPin = txPin;            // Set the txPin
  this->rxPin = rxPin;            // Set the rxPin

  pinMode(barcodePin, OUTPUT);
  barcodeSerial.begin(9600);
  lastBarcode = "";

}

void BARCODE::scanBarcodes() {
  digitalWrite(barcodePin, HIGH);  // Activate barcode scanner

  if (barcodeSerial.available()) {  // Check if data is available from the scanner (SoftwareSerial)
    String barcode = "";

    while (barcodeSerial.available()) {
      char c = barcodeSerial.read();
      if (c == '\n') break;         // Stop reading at newline (end of barcode)
      barcode += c;                 // Append character to barcode string
    }

    // Check if the barcode is new
    if (barcode.length() > 0 && barcode != lastBarcode) {
      lastBarcode = barcode;        // Update last scanned barcode
      Serial.print("Scanned Barcode: ");
      Serial.println(barcode);      // Print barcode to Serial Monitor
    }
  }

  digitalWrite(barcodePin, LOW);  // Deactivate barcode scanner
  delay(5000);                     // Delay for 5 seconds before scanning again
  
}