//Function  ในการ offset ค่าที่ได้จาก pit ของรีโมท ให้อยู่ในช่วง 0 - 100 %
int offset_CH(int pin, int min_val, int max_val) {
  return map(pulseIn(pin, HIGH), min_val, max_val, 0, 100);
}




//signal_A1 = pulseIn(A1, HIGH); // อ่าน  PWM ขา A0 เมื่อสัญญานเป็น HIGH
//signal_A2 = pulseIn(A2, HIGH);
//signal_A3 = pulseIn(A3, HIGH);
//signal_A4 = pulseIn(A4, HIGH);
//signal_A1 = map(signal_A1, 1130, 1950, 0, 100); // การแปลงค่า CH1
//signal_A2 = map(signal_A2, 1120, 1920, 0, 100);
//signal_A3 = map(signal_A3, 1160, 1820, 0, 255);
//signal_A4 = map(signal_A4, 1070, 1910, 0, 100);
