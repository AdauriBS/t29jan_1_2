#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos para os LEDs
#define LED_RED 11
#define LED_BLUE 12
#define LED_GREEN 13

// Variável para controlar o estado atual do semáforo
int state = 0;

// Função de setup para inicializar os pinos dos LEDs
void setup() {
    // Inicializa os pinos dos LEDs
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
}

// Função de callback chamada a cada 3 segundos
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de mudar o estado
    gpio_put(LED_RED, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_GREEN, 0);

    // Controle do ciclo do semáforo: vermelho → azul → verde
    if (state == 0) {
        gpio_put(LED_RED, 1);      // Liga o LED vermelho
        printf("Sinal VERMELHO\n");
    } else if (state == 1) {
        gpio_put(LED_BLUE, 1);     // Liga o LED azul
        printf("Sinal AZUL\n");
    } else {
        gpio_put(LED_GREEN, 1);    // Liga o LED verde
        printf("Sinal VERDE\n");
    }

    // Avança para o próximo estado (0 → 1 → 2 → 0 ...)
    state = (state + 1) % 3;

    return true;  // Mantém o temporizador ativo
}

int main() {
    stdio_init_all();  // Inicializa a comunicação serial USB

    setup();  // Chama a função de setup para inicializar os pinos

    // Configura o temporizador para alternar o semáforo a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal: imprime uma mensagem a cada 1 segundo
    while (true) {
        printf("Semáforo em operação...\n");
        sleep_ms(1000);
    }

    return 0;
}
