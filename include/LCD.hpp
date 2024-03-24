#define __LCD_HPP__

class LCD {
public:
    LCD(uint8_t addr, uint8_t cols, uint8_t rows, uint8_t charSize = LCD_5x8DOTS);
    void init();

    void clear();
    void home();

    void setCursor(uint8_t col, uint8_t row);

    void write(uint8_t value);
    void print(const char* message);
    void print(int message);
    void print(float message, uint8_t decimalPlaces = 2);

    void blinkCursor();
    void noBlinkCursor();
    void cursor();
    void noCursor();
    void display();
    void noDisplay();

    void scrollDisplayLeft();
    void scrollDisplayRight();
    void leftToRight();
    void rightToLeft();
    void autoscroll();
    void noAutoscroll();

private:
    uint8_t _addr;
    uint8_t _cols;
    uint8_t _rows;
    uint8_t _charSize;

    void command(uint8_t value);
};