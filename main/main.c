#include "driver/gpio.h"
#include "esp_spi_flash.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "sdkconfig.h"
#include <stdio.h>

char task_1[10] = "task1";
char task_2[10] = "task2";
char task_3[10] = "task3";

void task1(void *parameter)
{
    // loop forever //
    volatile uint32_t ul;
    while (1)
    {
        for (ul = 0; ul < 50; ul++)
        {
            printf("Task 1 is running\t%d\n", ul);
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
        printf("Task 1 is ending\n");
    }
    vTaskDelete(NULL);
}

void task2(void *parameter)
{
    volatile uint32_t ul;
    while (1)
    {
        for (ul = 0; ul < 50; ul++)
        {
            printf("Task 2 is running\t%d\n", ul);
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
        printf("Task 2 is ending\n");
    }
    vTaskDelete(NULL);
}

void task3(void *parameter)
{
    volatile uint32_t ul;
    while (1)
    {
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        for (ul = 0; ul < 10; ul++)
        {
            printf("Task 3 is running\t%d\n", ul);
        }
        printf("Task 3 is ending\n");
    }
    vTaskDelete(NULL);
}

void app_main()
{
    xTaskCreate(task1, "task1", 10000, (void *)task_1, 1, NULL);
    xTaskCreate(task2, "task2", 10000, (void *)task_2, 2, NULL);
    xTaskCreate(task3, "task3", 10000, (void *)task_3, 3, NULL);
}