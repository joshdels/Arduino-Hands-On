#include "BARCODE.h"

const int barcodePin = 12;
const int txPin = 10;
const int rxPin = 11;

BARCODE scanner(barcodePin, txPin, rxPin);  // Correct object initialization


void setup() {
  Serial.begin(9600);
  Serial.println("System Ready....");
}

void loop(){
  scanner.scanBarcodes();
}


