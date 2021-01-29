#include "BMPImage.hpp"
#include <fstream>

bool BMPImage::SaveBMPImage(std::string_view FileName) const
{
    std::ofstream file(FileName.data(), std::ios_base::binary);
    if (file.is_open())
    {
        #pragma pack(push, 1)
        struct {
            uint16_t file_type{ 0x4D42 };          // File type always BM which is 0x4D42 (stored as hex uint16_t in little endian)
            uint32_t file_size{ 0 };               // Size of the file (in bytes)
            uint16_t reserved1{ 0 };               // Reserved, always 0
            uint16_t reserved2{ 0 };               // Reserved, always 0
            uint32_t offset_data{ 0 };             // Start position of pixel data (bytes from the beginning of the file)
        } BMPFileHeader;

        struct {
            uint32_t size{ 0 };                      // Size of this header (in bytes)
            int32_t width{ 0 };                      // width of bitmap in pixels
            int32_t height{ 0 };                     // width of bitmap in pixels
                                                    //       (if positive, bottom-up, with origin in lower left corner)
                                                    //       (if negative, top-down, with origin in upper left corner)
            uint16_t planes{ 1 };                    // No. of planes for the target device, this is always 1
            uint16_t bit_count{ 32 };                 // No. of bits per pixel
            uint32_t compression{ 0 };               // 0 or 3 - uncompressed. THIS PROGRAM CONSIDERS ONLY UNCOMPRESSED BMP images
            uint32_t size_image{ 0 };                // 0 - for uncompressed images
            int32_t x_pixels_per_meter{ 0 };
            int32_t y_pixels_per_meter{ 0 };
            uint32_t colors_used{ 0 };               // No. color indexes in the color table. Use 0 for the max number of colors allowed by bit_count
            uint32_t colors_important{ 0 };          // No. of colors used for displaying the bitmap. If 0 all colors are required
        } BMPInfoHeader;
        BMPFileHeader.offset_data = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) ;
        BMPInfoHeader.size = sizeof(BMPInfoHeader);
        BMPInfoHeader.width = m_width;
        BMPInfoHeader.height = m_height;
        #pragma pack(pop)
        
		file.write((char*)&BMPFileHeader, sizeof(BMPFileHeader));
		file.write((char*)&BMPInfoHeader, sizeof(BMPInfoHeader));
		file.write((char*)m_data, m_width * m_height * sizeof(*m_data));
    }

    return false;
}

void BMPImage::changeEndian()
{
    for (size_t i = 0; i < m_width * m_height; ++i)
        std::swap(m_data[i].r, m_data[i].b);
}