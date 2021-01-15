#pragma once

#include <string_view>
#include <stdint.h>
#include "math.hpp"

class BMPImage
{
    private:
        uint32_t m_width;
        uint32_t m_height;
        vec4ub* m_data;
    
    public:
        BMPImage():m_data(NULL) {}
        BMPImage(uint32_t width, uint32_t height): m_width(width), m_height(height), m_data(new vec4ub[m_width * m_height]) {}
        BMPImage(uint32_t width, uint32_t height, vec4ub color): m_width(width), m_height(height), m_data(new vec4ub[m_width * m_height]) 
        {
            for (size_t i = 0; i < m_width * m_height; ++i)
                m_data[i] = color;
        }

        bool SaveBMPImage(std::string_view FileName) const;
        void setPixel(size_t x, size_t y, const vec4ub& c) { m_data[x + y * m_width] = c; }
        void changeEndian();
};
