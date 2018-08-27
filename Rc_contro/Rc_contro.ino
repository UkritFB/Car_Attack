#include "Offset.h"
//#################### Config Pin Motor Driver #########################
// สำหรับการ Set Pin Drive Motor
int PIN_ENA  = 9;
int PIN_ENB  = 11;
int PIN_L1   = 7;
int PIN_L2   = 8;
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
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  Serial.begin(9600);

}
//**********************************************************************
void loop() {
  read_rc();
  if (DATA_CH1 <= 40 && DATA_CH1 >= 60) {       //กรณีที่โยก Pit | เพียงอย่างเดียว จะเดินหน้ากรือถอยหลัง
    
  }else if(DATA_CH2 <= 40 && DATA_CH2 >= 60){   //กรณีที่โยก Pit - เพียงอย่างเดียว จะเลียวซ้ายหรือเลี้ยวขวา
    
  }
  else{   // ในกรณีที่ pit X หรือ /   \  
    
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
  analogWrite(PIN_ENA, SP_M);
}
void M_L_B(int SP_M) {
  digitalWrite(PIN_L1, 0);
  digitalWrite(PIN_L2, 1);
  analogWrite(PIN_ENA, SP_M);
}
void M_L_S() {
  digitalWrite(PIN_L1, 0);
  digitalWrite(PIN_L2, 0);
  analogWrite(PIN_ENA, 0);
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
void M_R_S() {
  digitalWrite(PIN_R1, 0);
  digitalWrite(PIN_R2, 0);
  analogWrite(PIN_ENB, 0);
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
void L(int SP_M) {
  M_R_G(SP_M);
}
void R( int SP_M)
{
  M_L_G(SP_M);
}
void B() {
  M_L_S();
  M_R_S();
}
//#####################################################################


