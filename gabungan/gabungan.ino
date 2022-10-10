#include <SPI.h>
#include <SD.h>
#include "RTClib.h"
File myFile;
RTC_DS3231 rtc;
char dataHari[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
String hari;
int tanggal, bulan, tahun, jam, menit, detik;
float suhu;

String Data;
float outputV,magneticFlux;

const int pinHall = A0;

void setup() {
  Serial.begin(9600);
  pinMode(pinHall, INPUT);

  //setup rtc
  if (! rtc.begin()) {
    Serial.println("RTC Tidak Ditemukan");
    Serial.flush();
    abort();
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //  rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

  //setup SD Card
  while (!Serial) {
  ; 
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  Serial.println("Date          Time       OutputV        Flux Magnet       Temperature");

}

void loop() {
  hallEffect();
  sensorRtc();
  writingData();
}
