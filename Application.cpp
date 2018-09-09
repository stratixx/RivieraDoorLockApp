#include "Application.h"
#include "../GPIO/GPIO.h"
#include "Terminal.h"
#include "HAL.h"
#include "EEPROM.h"

byte Application::reset_pin = 'r';

return_code Application::init(void)
{
    return OK;
}

return_code Application::loop(void)
{
        if( isReset()==true )
            Terminal::println("reset");
        else
            Terminal::println("set");
            HAL::delay_ms(100);

    return OK;
}

bool Application isReset()
{
    return (GPIO::digitalRead(reset_pin)==LOW);
}
