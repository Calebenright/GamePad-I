const uint8_t mainChar_MASK[8][120] PROGMEM={
{0, 0, 0, 0, 254, 0, 1, 254, 0, 3, 255, 224, 7, 254, 128, 7, 255, 128, 7, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 1, 254, 0, 1, 254, 0, 1, 248, 0, 1, 240, 0, 1, 240, 0, 1, 240, 0, 3, 240, 0, 3, 240, 0, 7, 248, 0, 7, 248, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 1, 240, 0, 1, 240, 0, 1, 240, 0, 0, 240, 0, 0, 224, 0, 0, 224, 0, 0, 224, 0, 3, 240, 0, 7, 240, 0, 3, 240, 0, },
{0, 0, 0, 0, 254, 0, 1, 254, 0, 3, 255, 224, 7, 254, 128, 7, 255, 128, 7, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 1, 254, 0, 1, 254, 0, 1, 248, 0, 1, 240, 0, 1, 240, 0, 1, 240, 0, 3, 240, 0, 3, 240, 0, 7, 248, 0, 7, 248, 0, 7, 252, 32, 7, 253, 224, 7, 255, 224, 7, 255, 224, 15, 255, 128, 31, 252, 0, 63, 252, 0, 57, 252, 0, 1, 240, 0, 1, 240, 0, 1, 240, 0, 0, 240, 0, 0, 240, 0, 1, 240, 0, 3, 216, 0, 3, 140, 0, 7, 142, 0, 7, 14, 0, },
{0, 0, 0, 0, 254, 0, 1, 254, 0, 3, 255, 224, 7, 254, 128, 7, 255, 128, 7, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 1, 254, 0, 1, 254, 0, 1, 248, 0, 1, 240, 0, 1, 240, 0, 1, 240, 0, 3, 240, 0, 3, 240, 0, 7, 248, 0, 7, 248, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 1, 240, 0, 1, 240, 0, 1, 240, 0, 0, 240, 0, 0, 224, 0, 0, 224, 0, 0, 224, 0, 3, 240, 0, 7, 240, 0, 3, 240, 0, },
{0, 0, 0, 0, 254, 0, 1, 254, 0, 3, 255, 224, 7, 254, 128, 7, 255, 128, 7, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 3, 255, 0, 1, 254, 0, 1, 254, 0, 1, 248, 0, 1, 240, 0, 1, 240, 0, 1, 240, 0, 3, 240, 0, 3, 240, 0, 7, 248, 0, 7, 248, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 7, 252, 0, 15, 252, 0, 7, 252, 0, 1, 252, 0, 1, 240, 0, 1, 240, 0, 1, 240, 0, 0, 240, 0, 0, 240, 0, 1, 240, 0, 3, 216, 0, 3, 140, 0, 7, 142, 0, 7, 14, 0, },
{0, 0, 0, 0, 127, 0, 0, 127, 128, 7, 255, 192, 1, 127, 224, 1, 255, 224, 0, 255, 224, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 127, 128, 0, 127, 128, 0, 31, 128, 0, 15, 128, 0, 15, 128, 0, 15, 128, 0, 15, 192, 0, 15, 192, 0, 31, 224, 0, 31, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 15, 128, 0, 15, 128, 0, 15, 128, 0, 15, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 15, 192, 0, 15, 224, 0, 15, 192, },
{0, 0, 0, 0, 127, 0, 0, 127, 128, 7, 255, 192, 1, 127, 224, 1, 255, 224, 0, 255, 224, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 127, 128, 0, 127, 128, 0, 31, 128, 0, 15, 128, 0, 15, 128, 0, 15, 128, 0, 15, 192, 0, 15, 192, 0, 31, 224, 0, 31, 224, 4, 63, 224, 7, 191, 224, 7, 255, 224, 7, 255, 224, 1, 255, 240, 0, 63, 248, 0, 63, 252, 0, 63, 156, 0, 15, 128, 0, 15, 128, 0, 15, 128, 0, 15, 0, 0, 15, 0, 0, 15, 128, 0, 27, 192, 0, 49, 192, 0, 113, 224, 0, 112, 224, },
{0, 0, 0, 0, 127, 0, 0, 127, 128, 7, 255, 192, 1, 127, 224, 1, 255, 224, 0, 255, 224, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 127, 128, 0, 127, 128, 0, 31, 128, 0, 15, 128, 0, 15, 128, 0, 15, 128, 0, 15, 192, 0, 15, 192, 0, 31, 224, 0, 31, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 15, 128, 0, 15, 128, 0, 15, 128, 0, 15, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 15, 192, 0, 15, 224, 0, 15, 192, },
{0, 0, 0, 0, 127, 0, 0, 127, 128, 7, 255, 192, 1, 127, 224, 1, 255, 224, 0, 255, 224, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 255, 192, 0, 127, 128, 0, 127, 128, 0, 31, 128, 0, 15, 128, 0, 15, 128, 0, 15, 128, 0, 15, 192, 0, 15, 192, 0, 31, 224, 0, 31, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 224, 0, 63, 240, 0, 63, 224, 0, 63, 128, 0, 15, 128, 0, 15, 128, 0, 15, 128, 0, 15, 0, 0, 15, 0, 0, 15, 128, 0, 27, 192, 0, 49, 192, 0, 113, 224, 0, 112, 224, },
};
