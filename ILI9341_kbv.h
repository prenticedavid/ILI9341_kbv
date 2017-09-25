#ifndef ILI9341_KBV_H_
#define ILI9341_KBV_H_ 100

#define USE_MBED 0

#if ARDUINO < 165
#define USE_GFX_KBV
#include "ADA_GFX_kbv.h"
#else
#include "Adafruit_GFX.h"
#endif

class ILI9341_kbv : public Adafruit_GFX {

	public:
	ILI9341_kbv();
	void     reset(void);                                       // you only need the constructor
	void     begin(uint16_t ID = 0x9341);                                       // you only need the constructor
	virtual void     drawPixel(int16_t x, int16_t y, uint16_t color);  // and these three
    void     pushCommand(uint16_t cmd, uint8_t * block, int8_t N);
	uint16_t color565(uint8_t r, uint8_t g, uint8_t b) { return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3); }
	uint16_t readID(void); // { return 0x9341; }

	virtual void     fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
	virtual void     drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) { fillRect(x, y, 1, h, color); }
	virtual void     drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) { fillRect(x, y, w, 1, color); }
	virtual void     fillScreen(uint16_t color)                                     { fillRect(0, 0, _width, _height, color); }
	virtual void     setRotation(uint8_t r);
	virtual void     invertDisplay(boolean i);

	uint8_t readcommand8(uint8_t reg, uint8_t idx = 0);         //this is the same as Adafruit_ILI9341
	uint16_t readReg(uint16_t reg, uint8_t idx = 0);            //note that this reads pairs of data bytes
	int16_t  readGRAM(int16_t x, int16_t y, uint16_t *block, int16_t w, int16_t h);
	uint16_t readPixel(int16_t x, int16_t y) { uint16_t color; readGRAM(x, y, &color, 1, 1); return color; }
	void     setAddrWindow(int16_t x, int16_t y, int16_t x1, int16_t y1);
	void     pushColors(uint16_t *block, int16_t n, bool first);
	void     pushColors(uint8_t *block, int16_t n, bool first);    //NEW
	void     pushColors(const uint8_t *block, int16_t n, bool first, bool bigend = false); //NEW
	void     vertScroll(int16_t top, int16_t scrollines, int16_t offset);
	
	protected:
	
	private:
	uint16_t        _lcd_ID;
};

#endif
