void hallEffect(){
  //Filter kebisingan dengan 10 pengukuran
  long measure = 0;
  for(int i = 0; i < 10; i++){
      int value = 
      measure += analogRead(pinHall);
  }
  measure /= 10;
   
  //Hitung tegangan dalam mV yang memberikan output dari sensor Hall
  outputV = measure * 5000.0 / 1023;
   
  //Interpolasi kerapatan medan magnet (rumus)
  magneticFlux =  outputV * 53.33 - 133.3;

  delay(500);
}
