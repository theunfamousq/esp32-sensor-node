#include <driver/gpio.h>

#include "esp_err.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "main";
static const gpio_num_t LED_GPIO = GPIO_NUM_2;
static const TickType_t BLINK_DELAY = pdMS_TO_TICKS(1000);

void app_main(void)
{
    ESP_LOGI(TAG, "Initialize GPIO");
    ESP_ERROR_CHECK(gpio_reset_pin(LED_GPIO));
    ESP_ERROR_CHECK(gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT));

    ESP_LOGI(TAG, "Start blinking on GPIO %d", LED_GPIO);
    while (1)
    {
        gpio_set_level(LED_GPIO, 1);
        ESP_LOGI(TAG, "ON");
        vTaskDelay(BLINK_DELAY);

        gpio_set_level(LED_GPIO, 0);
        ESP_LOGI(TAG, "OFF");
        vTaskDelay(BLINK_DELAY);
    }
}
