#include "Application.h"
#include "../GPIO/GPIO.h"
#include "Terminal.h"
#include "HAL.h"
#include "EEPROM.h"

#include <cstring>

byte Application::reset_pin = 'r';

return_code Application::init(void)
{
    char tab[50];
    char * eeprom_tab = 0;

    EEPROM::read(eeprom_tab,tab, sizeof(tab));

    Terminal::print("|");
    Terminal::print(tab);
    Terminal::print("| ");
    Terminal::println(sizeof(tab));
    tab[0]++;
    EEPROM::write(tab, eeprom_tab, sizeof(tab));
    return OK;
}

return_code Application::loop(void)
{
        if( isReset()==true )
            Terminal::println("reset");
        else
            Terminal::println("set");
            HAL::delay_ms(1000);

    return OK;
}

bool Application::isReset()
{
    return (GPIO::digitalRead(reset_pin)==LOW);
}
