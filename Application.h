#ifndef APPLICATION_H
#define APPLICATION_H

#include "../return_code.h"
#include <stdint.h>

#ifndef byte
	#define byte uint8_t
#endif

class Application
{
    public:
        static return_code init(void);
        static return_code loop(void);

        static byte reset_pin;
    protected:
        static bool isReset();
    private:
        Application() {  };
};

#endif // APPLICATION_H
