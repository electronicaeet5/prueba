
class pepe
{
    int8_t a;
    public:
        pepe():a(0)
        {};
        //pepe(const pepe &otro)=delete;
        //pepe(pepe && otro)=delete;
        ~pepe()=default;
};

void setup()
{
    pinMode(13, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    static uint8_t estado = 0;
    digitalWrite(13, estado);
    delay(500);
    estado = 1 - estado;
    Serial.println("Escribo");
}

int main()
{
    init();
    setup();
    pepe apa;
    while(true)
    {
        loop();
    }
}
