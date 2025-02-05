# Semáforo com LEDs - Raspberry Pi Pico

Este é um projeto simples de semáforo utilizando a placa **Raspberry Pi Pico** e LEDs para simular um semáforo. O código foi desenvolvido em C, utilizando a biblioteca `pico/stdlib` para controle dos pinos GPIO e `hardware/timer` para configurar temporizadores. O semáforo alterna entre os LEDs vermelho, azul e verde a cada 3 segundos, enquanto imprime mensagens no terminal a cada 1 segundo para indicar o estado do semáforo.

## Funcionalidades

- **Alternância de LEDs**: Os LEDs vermelho, azul e verde alternam de acordo com o ciclo do semáforo.
- **Temporização**: O semáforo troca de estado a cada 3 segundos.
- **Comunicação serial**: O estado atual do semáforo é impresso no terminal a cada 1 segundo.

## Requisitos

- **Raspberry Pi Pico** ou qualquer outra placa compatível com o Raspberry Pi Pico.
- **Ambiente de desenvolvimento** configurado para programar o Raspberry Pi Pico com C (como o [SDK do Raspberry Pi Pico](https://www.raspberrypi.org/documentation/pico/getting-started/)).
- **LEDs** (vermelho, azul e verde) e resistores adequados.
- **Cabo micro USB** para conectar o Raspberry Pi Pico ao computador.

## Como usar

1. **Configuração do ambiente**:
   - Instale o SDK do Raspberry Pi Pico e configure seu ambiente de desenvolvimento C para a placa. Para instruções detalhadas, consulte a [documentação oficial](https://www.raspberrypi.org/documentation/pico/getting-started/).
   
2. **Conectando os LEDs**:
   - Conecte os LEDs aos pinos GPIO 11 (vermelho), GPIO 12 (azul) e GPIO 13 (verde) do Raspberry Pi Pico.
   - Use resistores para proteger os LEDs.

3. **Compilação e carregamento**:
   - Compile o código com o ambiente de desenvolvimento do Raspberry Pi Pico.
   - Carregue o código para o Raspberry Pi Pico através do ambiente de desenvolvimento.

4. **Execução**:
   - Após carregar o código, conecte o Raspberry Pi Pico a um computador via USB.
   - Abra o terminal serial (por exemplo, utilizando o `minicom`, `screen` ou outro software de terminal) para monitorar o output.
   - O semáforo começará a funcionar, alternando entre os LEDs e imprimindo no terminal o estado atual a cada 1 segundo.

## Estrutura do Código

- **Função `setup()`**: Inicializa os pinos dos LEDs e configura suas direções como saída.
- **Função `repeating_timer_callback()`**: Função chamada a cada 3 segundos para alternar o estado do semáforo.
- **Função `main()`**: Inicializa a comunicação serial, chama `setup()` para configurar os pinos e inicia o temporizador para alternância dos LEDs.

## Exemplo de Saída no Terminal

Semáforo em operação...
Sinal VERMELHO Semáforo em operação... 
Sinal AZUL Semáforo em operação... 
Sinal VERDE Semáforo em operação... 
Sinal VERMELHO

#Vídeo
(https://drive.google.com/file/d/19chHpDNntYOKw6xD9HK9V2mz4K1ea7Y6/view?usp=sharing)


## Licença

Este projeto está licenciado sob a **MIT License** - veja o arquivo [LICENSE](LICENSE) para mais detalhes.

