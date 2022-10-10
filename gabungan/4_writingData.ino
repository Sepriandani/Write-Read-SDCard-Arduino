void writingData(){
  myFile = SD.open("kkk.txt", FILE_WRITE);
  if (myFile) {
    String Date = String(tanggal) + "-" + String(bulan) + "-" + String(tahun);
    String Time = String(jam) + ":" + String(menit) + ":" + String(detik);
    Data = Date + "     " + Time + "      " + String(outputV) + "       " + String(magneticFlux) + "         " + String(suhu);
    myFile.println(Data);
    Serial.println(Data);
    myFile.close();
  } else {
    Serial.println("error opening");
  }
}
