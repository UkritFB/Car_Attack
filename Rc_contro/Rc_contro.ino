// บรรหาร
//#################### Config Pin Motor Driver #########################
// สำหรับการ Set Pin Drive Motor
int PIN_ENL  = 9;
int PIN_ENR  = 11;
int PIN_L1   = 8;
int PIN_L2   = 7;
int PIN_R1   = 12;
int PIN_R2   = 13;
//###################### Config Pin Recive ############################
// สำหรับการ Set Pin Reciver
int PIN_CH1  = A1;
int PIN_CH2  = A2;
int PIN_CH3  = A3;
int PIN_CH4  = A4;
// ---------------------- offset Recive -------------------------------
// สัญญานจาก Remote ที่ผ่านการ Offset แล้ว
int DATA_CH1 = 0; // L  |
int DATA_CH2 = 0; // L  _
int DATA_CH3 = 0; // R  |
int DATA_CH4 = 0; // R  _
//####################### Config Pin Attack ############################
// สำหรับ การ Set Pin Relay
int PIN_Att = 0;
//######################################################################
int signal_A4, signal_A1, signal_A2, signal_A3;
int speed_go, speed_bk;
//######################################################################

//**********************************************************************
void setup() {
  pinMode(DATA_CH1, INPUT);
  pinMode(DATA_CH2, INPUT);
  pinMode(DATA_CH3, INPUT);
  pinMode(DATA_CH4, INPUT);
  pinMode(PIN_L1, OUTPUT);
  pinMode(PIN_L2, OUTPUT);
  pinMode(PIN_R1, OUTPUT);
  pinMode(PIN_R2, OUTPUT);
  pinMode(PIN_ENL, OUTPUT);
  pinMode(PIN_ENR, OUTPUT);
  Serial.begin(9600);

}
//**********************************************************************
void loop() {
  read_rc();
  if (DATA_CH2 >= 60 && DATA_CH1 >= 40 && DATA_CH1 <= 60) {
    B(255);
  } else if (DATA_CH2 <= 40 && DATA_CH1 >= 40 && DATA_CH1 <= 60) {
    G(255);
  } else if (DATA_CH1 >= 60 && DATA_CH2 >= 40 && DATA_CH2 <= 60 ) {
    R(255);
  } else if (DATA_CH1 <= 40 && DATA_CH2 >= 40 && DATA_CH2 <= 60 ) {
    L(255);
  } else if (DATA_CH1 <= 40 && DATA_CH2 <= 40 ) {
    G_L(255);
  } else if (DATA_CH1 >= 60 && DATA_CH2 <= 40 ) {
    G_R(255);
  } else if (DATA_CH1 >= 60 && DATA_CH2 >= 60) {
    B_R(255);
  } else if (DATA_CH1 <= 40 && DATA_CH2 >= 60 ) {
    B_L(255);
  } else {
    S();
  }
}
//**********************************************************************
//#####################################################################
void read_rc() {
  DATA_CH1 = offset_CH(PIN_CH1, 1130, 1950);
  DATA_CH2 = offset_CH(PIN_CH2, 1120, 1920);
  DATA_CH3 = offset_CH(PIN_CH3, 1160, 1820);
  DATA_CH4 = offset_CH(PIN_CH4, 1070, 1910);
}
//#####################################################################
void pread_rc() {
  Serial.print("CH1 : ");
  Serial.print(DATA_CH1);
  Serial.print("  CH2 : ");
  Serial.print(DATA_CH2);
  Serial.print("  CH3 : ");
  Serial.print(DATA_CH3);
  Serial.print("  CH4 : ");
  Serial.println(DATA_CH4);
}
//############################## MOTOR ################################
void M_L_G(int SP_M) {
  digitalWrite(PIN_L1, 1);
  digitalWrite(PIN_L2, 0);
  analogWrite(PIN_ENL, SP_M);
}
void M_L_B(int SP_M) {
  digitalWrite(PIN_L1, 0);
  digitalWrite(PIN_L2, 1);
  analogWrite(PIN_ENL, SP_M);
}
void M_L_S() {
  digitalWrite(PIN_L1, 0);
  digitalWrite(PIN_L2, 0);
  analogWrite(PIN_ENL, 0);
}
void M_R_G(int SP_M) {
  digitalWrite(PIN_R1, 1);
  digitalWrite(PIN_R2, 0);
  analogWrite(PIN_ENR, SP_M);
}
void M_R_B(int SP_M) {
  digitalWrite(PIN_R1, 0);
  digitalWrite(PIN_R2, 1);
  analogWrite(PIN_ENR, SP_M);
}
void M_R_S() {
  digitalWrite(PIN_R1, 0);
  digitalWrite(PIN_R2, 0);
  analogWrite(PIN_ENR, 0);
}
//########################### G B #####################################
void G(int SP_M) {
  M_L_G(SP_M);
  M_R_G(SP_M);
}
void B(int SP_M) {
  M_L_B(SP_M);
  M_R_B(SP_M);
}
//########################### L #######################################
void G_L(int SP_M) {
  M_R_G(SP_M);
  M_L_S();
}
void B_L(int SP_M) {
  M_R_B(255);
  M_L_S();
}
void L(int SP_M) {
  M_R_G(SP_M);
  M_L_B(SP_M);
}
//########################### R #######################################
void G_R( int SP_M)
{
  M_L_G(SP_M);
  M_R_S();
}
void B_R( int SP_M)
{
  M_L_B(SP_M);
  M_R_S();
}
void R( int SP_M)
{
  M_L_G(SP_M);
  M_R_B(SP_M);
}
void S() {
  M_L_S();
  M_R_S();
}
//#####################################################################

//Function  ในการ offset ค่าที่ได้จาก pit ของรีโมท ให้อยู่ในช่วง 0 - 100 %
int offset_CH(int pin, int min_val, int max_val) {
  return map(pulseIn(pin, HIGH), min_val, max_val, 0, 100);
}


