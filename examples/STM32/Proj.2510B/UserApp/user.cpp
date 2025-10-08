#include "main.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdint.h>

#include <unity.h>

#if __cplusplus
extern "C" {
#endif

    
void setUp(void){}
void tearDown(void){}
    
void test_func_1(void) 
{
    const int x = 1;
    TEST_ASSERT_EQUAL_INT(1, x);
}

void test_func_2(void) 
{
    const int x = 1;
    TEST_ASSERT_NOT_EQUAL_INT(2, x);
}

void test_func_3(void) 
{
    const double x = 1.0009;
    TEST_ASSERT_EQUAL_DOUBLE(1, x);
}

void test_func_4(void) 
{
    const double x = 1.00101;
    TEST_ASSERT_NOT_EQUAL_DOUBLE(1, x);
}

int user_app(void) 
{
    UNITY_BEGIN();
    RUN_TEST(test_func_1);
    RUN_TEST(test_func_2);
    /* check UNITY_DOUBLE_PRECISION */
    RUN_TEST(test_func_3);
    RUN_TEST(test_func_4);
    UNITY_END();
    
    while (1) 
    {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
        HAL_Delay(1000);
    }

}

#if __cplusplus
}
#endif
