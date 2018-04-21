void move_please(){  
  X = (cos(payload[1]) * sin(payload[0]-antenna[0]));
  Y = (cos(antenna[1]) * sin(payload[1]) - 
       sin(antenna[1]) * cos(payload[1]) * cos(payload[0]-antenna[0]));
  bearing = to_deg * (atan2(X, Y));
  
  if(bearing<0){
    bearing = 360 + bearing;
  }else{
    bearing = bearing;
  }

  Z = payload[2] - antenna[2];
  float a = (sin(payload[1]-antenna[1]) * sin(payload[1]-antenna[1]) + 
             cos(antenna[1]*to_rad) * cos(payload[1]*to_rad) * 
             sin(payload[0]-antenna[0]) * sin(payload[0]-antenna[0]));
  float c = 2 * atan2(sqrt(a), sqrt(1-a));
  float d = R * c;
  tilt = atan2(Z, d) * to_deg;

  deg_horizon = bearing;
  deg_vertic = tilt;
  servo_pan.write(deg_horizon);
  servo_tilt1.write(deg_vertic+90);
  servo_tilt2.write(180-(deg_vertic+90));
  Serial.print(deg_horizon); Serial.print(" ");
  Serial.print(deg_vertic+90); Serial.println(" ");
  Serial.print(180-(deg_vertic+90)); Serial.println(" ");
}

