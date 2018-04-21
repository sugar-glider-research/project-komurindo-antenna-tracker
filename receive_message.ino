void receive_m() {
  boolean count = false;
  boolean tampung = false;
  boolean insert = false;
  
  int counter = 0;
  int var_count = 0;
  int which_var = 0; //lon, lon_minut, lon_sec, lon_sign, lat ....., alt
  
  char temp[4];
  char data;

  //data uji
  char data_uji[39] = {0xFF,
                      ' ', '0', '0', '1', ' ', '0', '0', '2', ' ', '0', '0', '3', ' ', '1', '0', '1',
                      ' ', '0', '0', '4', ' ', '0', '0', '5', ' ', '0', '0', '6', ' ', '1', '1', '0',
                      ' ', '0', '0', '7', '\n'};
  int index = 0;
                        
  //hingga pindah baris
  while(data != '\n'){
    
    //baca data input
    /*if(Serial1.available()) {
      char data = Serial1.read();
    }*/

    //baca data uji
    char data = data_uji[index];
    index++;
    
    //hitung mulai elemen 0xFF
    if(data == 0xFF){
      count = true;
      counter  = 0;
    }
    if(count == true){
      counter++;
    }
  
    //tampung data
    if(data == 0x20){
      tampung = true;
      var_count = 0;
      which_var++;
    }
    if(insert == true){
      temp[var_count] = data;
      var_count++;
    }
    if(var_count == 3){
      var_count = 0;
      tampung = false;
      insert = true;
    }
  
    //insert ke variable
    if(insert){
      switch(which_var){
        case 1 : pay_deg[0] = atoi(temp); break;
        case 2 : pay_minut[0] = atoi(temp); break;
        case 3 : pay_sec[0] = atoi(temp); break;
        case 4 : sign[0] = atoi(temp); break;
        case 5 : pay_deg[1] = atoi(temp); break;
        case 6 : pay_minut[1] = atoi(temp); break;
        case 7 : pay_sec[1] = atoi(temp); break;
        case 8 : sign[1] = atoi(temp); break;
        case 9 : alt = atoi(temp); break;
        default : which_var = 0; break;
      }
      insert = false;
    }    
  }
}
