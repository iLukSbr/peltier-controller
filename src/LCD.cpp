#include "LCD.hpp"


LCD::LCD(uint8_t addr, uint8_t cols, uint8_t rows, uint8_t charsize)
{
	_i2c_addr = addr;
	_cols = cols;
	_rows = rows;
	_charsize = charsize;

	if (_rows > 1) {
		_currLine = 0;
	}

	Wire.begin();
}

size_t LCD::write(uint8_t value)
{
	send(value, Rs);
	return 1; // assume sucess
}

void LCD::clear()
{
	send(0x01, 0);
	delayMicroseconds(2000); // this command takes a long time!
}

void LCD::home()
{
	send(0x02, 0);
}

void LCD::setCursor(uint8_t col, uint8_t row)
{
	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	if (row > _rows) {
		row = _rows-1;    // we count rows starting w/0
	}

	send(0x80 | (col + row_offsets[row]), 0);
}

void LCD::autoscroll()
{
	send(0x05, 0);
}

void LCD::noAutoscroll()
{
	send(0x04, 0);
}

void LCD::on()
{
	send(0x0C, 0);
}

void LCD::off()
{
	send(0x08, 0);
}

void LCD::send(uint8_t value, uint8_t mode)
{
	Wire.beginTransmission(_i2c_addr);
	Wire.write(mode | (value & 0xF0));
	Wire.write((value << 4) | mode);
	Wire.endTransmission();

	delayMicroseconds(100); // datasheet says 37us, but we'll be conservative
}

