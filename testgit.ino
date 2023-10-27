#include "hard.h"
class byteArray
{
    uint16_t size;
    uint8_t *buff;

public:
    byteArray(uint16_t tama) : size(tama), buff(new uint8_t[tama]{}){};
    byteArray(const byteArray &otro) = delete;
    byteArray(byteArray &&otro) = delete;
    ~byteArray()
    {
        delete buff;
    }
    uint8_t &operator[](uint16_t index)
    {
        return buff[index];
    }
};

void setup()
{
    pinMode(13, OUTPUT);
    Serial.begin(115200);
    TCCR0A = 0;// set entire TCCR0A register to 0
  TCCR0B = 0;// same for TCCR0B
  TCNT0  = 0;//initialize counter value to 0
}

void loop()
{
    static uint8_t estado = 0;
    static uint16_t tiempo = 500;
    char car;
    digitalWrite(13, estado);
    delay(tiempo);
    if (Serial.available())
    {
        car = Serial.read();
        if (car == 'a')
        {
            tiempo++;
            Serial.println("Incremento");
        }
        else if (car == 's')
        {
            tiempo--;
            Serial.println("Decremento");
        }
    }
    estado = 1 - estado;
    // Serial.println("Escribo");
}

int main()
{
    init();
    setup();
    byteArray apa(123);
    while (true)
    {
        loop();
    }
}
