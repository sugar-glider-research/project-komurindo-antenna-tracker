void convert(){
  //for(int i = 0; i<2; i++){
  payload[0] = (pay_deg[0]/60) + ((pay_minut[0]/60.0)/60.0) + (((pay_sec[0] /60.0)/60.0)/60.0);
    if(sign[0] == 110){             //n
      payload[0] = payload[0] * 1;
    }else if(sign[0] == 115){       //s
      payload[0] = payload[0] * -1;
    }else if(sign[0] == 119){       //w
      payload[0] = payload[0] * -1;
    }else if(sign[0] == 101){       //e
      payload[0] = payload[0] * 1;
    }
  //}

  
  payload[1] = (pay_deg[1]/60) + ((pay_minut[1]/60.0)/60.0) + (((pay_sec[1] /60.0)/60.0)/60.0);
  if(sign[1] == 110){             //n
      payload[1] = payload[1] * 1;
    }else if(sign[1] == 115){       //s
      payload[1] = payload[1] * -1;
    }else if(sign[1] == 119){       //w
      payload[1] = payload[1] * -1;
    }else if(sign[1] == 101){       //e
      payload[1] = payload[1] * 1;
    }
  payload[2] = alt;
}

