#include "Offset.h"
//#################### Config Pin Motor Driver #########################
// สำหรับการ Set Pin Drive Motor
int PIN_ENA  = 0;
int PIN_ENB  = 0;
int PIN_L1   = 0;
int PIN_L2   = 0;
int PIN_R1   = 0;
int PIN_R2   = 0;
//####################### Config Pin Recive ############################
// สำหรับการ Set Pin Reciver
int PIN_CH1  = 0;
int PIN_CH2  = 0;
int PIN_CH3  = 0;
int PIN_CH4  = 0;
// ---------------------- offset Recive -------------------------------
// สัญญานจาก Remote ที่ผ่านการ Offset แล้ว
int DATA_CH1 = 0;
int DATA_CH2 = 0;
int DATA_CH3 = 0;
int DATA_CH4 = 0;
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
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  Serial.begin(9600);
  
}
//**********************************************************************
void loop() {
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
  analogWrite(PIN_ENA, SP_M);
}
void M_L_B(int SP_M) {
  digitalWrite(PIN_L1, 0);
  digitalWrite(PIN_L2, 1);
  analogWrite(PIN_ENA, SP_M);
}
void M_R_G(int SP_M) {
  digitalWrite(PIN_R1, 1);
  digitalWrite(PIN_R2, 0);
  analogWrite(PIN_ENB, SP_M);
}
void M_R_B(int SP_M) {
  digitalWrite(PIN_R1, 0);
  digitalWrite(PIN_R2, 1);
  analogWrite(PIN_ENB, SP_M);
}
//#####################################################################
void go(int SP_M) {
  M_L_G(SP_M);
  M_R_G(SP_M);
}

void back(int SP_M) {
  M_L_B(SP_M);
  M_R_B(SP_M);
}

void L() {
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  analogWrite(9, 255);
}
void R()
{
  digitalWrite(13, 1);
  digitalWrite(12, 0);
  analogWrite(11, 255);
}
void B()
{
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  analogWrite(9, 0);

  digitalWrite(13, 0);
  digitalWrite(12, 0);
  analogWrite(11, 0);
}


