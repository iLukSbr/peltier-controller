#define __MAX6675_HPP__

class MAX6675
{
public:
    MAX6675(int8_t sck, int8_t cs, int8_t miso);

    uint16_t readRaw();
    float readTempC();
    float readTempF();

private:
    int8_t _sck, _cs, _miso;
};