
#include<Servo.h>
Servo servo_pan, servo_tilt1, servo_tilt2;

//data siap olah
//data uji 1 kanan atas (robotiik)
//float antenna[3] = {112.61451557, -7.95462998, 495}; //lon, lat, alt of antenna
float antenna[3] = {0.61253074, 0.94969303, 495}; //lon, lat, alt of antenna - lokasi lomba
float payload[3]; //lon, lat, alt of payload

//data input dari payload
float pay_deg[2] = {36, 56}; //lon, lat
float pay_minut[2] = {44, 58}; //lon, lat
float pay_sec[2] = {39, 3}; //lon, lat
int sign [2] = {101, 115}; //lon, lat
//data uji 2 kanan bawah
/*float pay_deg[2] = {112, 7}; //lon, lat
float pay_minut[2] = {36, 57}; //lon, lat
float pay_sec[2] = {52.1388, 17.3016}; //lon, lat
int sign [2] = {101, 115}; //lon, lat*/
/*payload[0] = 112.614483;
payload[1] = -7.954806;*/
//data uji 3 kiri bawah
/*float pay_deg[2] = {112, 7}; //lon, lat
float pay_minut[2] = {36, 57}; //lon, lat
float pay_sec[2] = {51.3684, 17.28}; //lon, lat
int sign [2] = {101, 115}; //lon, lat*/
/*payload[0] = 112.614269;
payload[1] = -7.954800;*/
//data uji 4 kiri atas
/*float pay_deg[2] = {112, 7}; //lon, lat
float pay_minut[2] = {36, 57}; //lon, lat
float pay_sec[2] = {51.4296, 16.4808}; //lon, lat
int sign [2] = {101, 115}; //lon, lat*/
/*payload[0] = 112.614286;
payload[1] = -7.954578;*/

float alt = 1;

//perhitungan sudut
float X, Y, Z, bearing, tilt;
float to_deg = 180.0/PI;
float to_rad = PI/180.0;
float R = 6378140; //radius earth (meter)

//derajat putar servo
float deg_horizon;
float deg_vertic;

void setup() {
  /*//selatan
  payload[0] = 112.61451557;
  payload[1] = -7.95565801;
  payload[2] = 497;
  //timur
  payload[0] = 112.61545435;
  payload[1] = -7.95468046;
  payload[2] = 497;
  //barat
  payload[0] = 112.61340246;
  payload[1] = -7.95462467;
  payload[2] = 497;
  //utara
  payload[0] = 112.6144968;
  payload[1] = -7.95384369;
  payload[2] = 497;*/

  //lomba
  //selatan teknik elektro
  /*payload[0] = 112.61267826;
  payload[1] = -7.95075561;
  payload[2] = 504;*/
  //timur FIA
  /*payload[0] = 112.61357412;
  payload[1] = -7.94969303;
  payload[2] = 504;*/
  //barat lapangan fisip
  payload[0] = 112.61187896;
  payload[1] = -7.94967975;
  payload[2] = 504;
  //utara FKH
  /*payload[0] = 112.61298403;
  payload[1] = -7.9478229;
  payload[2] = 504;*/
  Serial.begin(9600);
  Serial1.begin(9600);
  servo_pan.attach(8); //horizontal servo
  servo_tilt1.attach(9); //vertical servo 1
  servo_tilt2.attach(10); //vertical servo 2
  servo_pan.write(90);
  servo_tilt1.write(90);
  servo_tilt2.write(90);
}

void loop() {
  //receive_m();
  //convert();
  move_please();
}
