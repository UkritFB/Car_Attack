//Function  ในการ offset ค่าที่ได้จาก pit ของรีโมท ให้อยู่ในช่วง 0 - 100 %
int offset_CH(int pin, int min_val, int max_val) {
  return map(pulseIn(pin, HIGH), min_val, max_val, 0, 100);
}

