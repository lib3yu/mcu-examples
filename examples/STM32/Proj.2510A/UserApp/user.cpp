#include "main.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdint.h>
//#include <map>
//#include <string>
#include "etl_profile.h"
#include <etl/map.h>
#include <etl/string.h>
#include <etl/array.h>
#include <etl/function.h>
#include <etl/hash.h>
#include <etl/vector.h>
#include <etl/memory.h>
#include <etl/error_handler.h>

#if __cplusplus
extern "C" {
#endif

int user_app(void) 
{
    // etl::error_handler
    using MyValueString = etl::string<20>;
    const char *str = "Hello MycoNet\n";
    static etl::map<etl::string<20>, MyValueString, 20> a;
    static etl::array<MyValueString, 20> aa;
    static etl::vector<MyValueString, 20> v;
    
    while (1) 
    {
        a["iam3oR"] = "iamnot3oR\n";
        const auto &b = a["iam3oR"];
        HAL_UART_Transmit(&huart1, (const uint8_t *)b.data(), b.size(), UINT32_MAX);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
        HAL_Delay(1000);
    }

}

#if __cplusplus
}
#endif
