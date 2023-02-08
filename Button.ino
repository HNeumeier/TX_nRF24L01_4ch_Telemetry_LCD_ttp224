
//************************************************************************************************************************************************************************
// Read input buttons status and send value to loop
//************************************************************************************************************************************************************************
unsigned long buttonTime = 0;

unsigned char read_button()
{
  if (millis() - buttonTime > 150) //150ms
  {
    // buttonSelect
//    if ((PIND & (1 << PIN_BUTTON_SELECT)) == 0) //if ( PIND & (1<<4) ){//Status ist HIGH // if ( !(PIND & (1<<4) ) ){//Status ist LOW
    if (digitalRead(PIN_BUTTON_SELECT)==HIGH)
    //if (!(PIND & (1 << PIN_BUTTON_SELECT)) == 0) //if ( PIND & (1<<4) ){//Status ist HIGH // if ( !(PIND & (1<<4) ) ){//Status ist LOW
    {
      buttonTime = millis();
      return 2;
    }
    
    // buttonUp
    //if (!(PIND & (1 << PIN_BUTTON_UP)) == 0)
    if (digitalRead(PIN_BUTTON_UP)==HIGH)
    {
      buttonTime = millis();
      return 1;
    }
    
    // buttonDown
    //if (!(PIND & (1 << PIN_BUTTON_DOWN)) == 0)
    if (digitalRead(PIN_BUTTON_DOWN)==HIGH)
    {
      buttonTime = millis();
      return 3;
    }
  }
  return 0;
}

//************************************************************************************************************************************************************************
// Macro for read button status definitions
//************************************************************************************************************************************************************************
void read_button_exit()
{
  // excute only one time after buttonExit is up
//  if (exitStatus == 1 && !bit_is_clear(PIND, PIN_BUTTON_EXIT))
  if (exitStatus == 1 && digitalRead(PIN_BUTTON_EXIT)==HIGH)
  {
    // buttonExit pushed
    exitStatus = !exitStatus;
    
    // buttonExit can be cancle button. Go main screen
    if (screen != 0)
    {
      screen = 0;
      menuSubActual = 1;
      menuActual = 0;
      menuPage=0;

      epaSelection = 0xFF;
      subTrimSelection = 0xFF;
      modelNameSelection = 0xFF;
      expoSelection = 0xFF;
      
      return;
    }
  }
  
  if (!bit_is_set(PIND, PIN_BUTTON_EXIT))
  {
    // buttonExit up
    exitStatus = 1;
  }
}
 
