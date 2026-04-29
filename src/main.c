#include <driver/gpio.h>

#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    ESP_LOGI("main,init", "Initialize GPIO");
    gpio_reset_pin(GPIO_NUM_2);
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);

    ESP_LOGI("main,blink,start", "Start blinking on GPIO 2");
    while (true)
    {
        gpio_set_level(GPIO_NUM_2, 1);
        ESP_LOGI("main,blink", "ON");
        vTaskDelay(pdMS_TO_TICKS(1000));

        gpio_set_level(GPIO_NUM_2, 0);
        ESP_LOGI("main,blink", "OFF");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
