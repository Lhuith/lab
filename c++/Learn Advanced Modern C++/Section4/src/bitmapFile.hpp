#ifndef BITMAP_FILE_H
#define BITMAP_FILE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

namespace bitmapFile
{
#pragma pack(push, 2) // the file header members must start on 16-bit int ??
	struct bitmap_file_header
	{
		char header[2]{'B', 'M'};
		int32_t file_size;
		int32_t reserved{0};
		int32_t data_offset;
	};
#pragma pack(pop) // revert to default alignment

	struct bitmap_info_header
	{
		int32_t header_size{40};
		int32_t width;
		int32_t height;
		int16_t planes{1};
		int16_t bits_per_pixel{24};
		int32_t compression{0};
		int32_t data_size{0};
		int32_t horizontal_resolution{2400};
		int32_t vertical_resolution{2400};
		int32_t colours{0};
		int32_t important_colours{0};
	};

	struct pixel
	{
		uint8_t blue;
		uint8_t green;
		uint8_t red;
	};

	class bitmap
	{
	private:
		int width{800};
		int height{600};
		std::string filename; // the name of the bitmap;
		std::vector<pixel> pixels;

	public:
		// constructor
		bitmap(std::string filename) : filename(filename), pixels(width * height) {}

		// set pixel at (x, y)
		void set_pixel(int x, int y, pixel p)
		{
			int idx = y * width + x; // calculate the offset
			pixels[idx] = p;		 // the vector index is the pixel offset
		}

		// set all the pixels in an entire row
		void set_row(int row, pixel p)
		{
			for (int i = 0; i < width; ++i)
			{
				set_pixel(i, row, p);
			}
		}
		// set all pixels in the image
		void set_all(pixel p)
		{
			for (int i = 0; i < height; ++i)
			{
				set_row(i, p);
			}
		}

		// save the image data to file
		bool write()
		{
			bitmap_file_header file_header;
			bitmap_info_header info_header;

			// calculate the size of the bitmap
			file_header.file_size = sizeof(bitmap_file_header) +
									sizeof(bitmap_info_header) +
									width * height * sizeof(pixel);
			file_header.data_offset = sizeof(bitmap_file_header) + sizeof(bitmap_info_header);

			// set the image's width and height
			info_header.width = width;
			info_header.height = height;

			// open the file where we will write bitmap
			ofstream ofile(filename, fstream::out | fstream::binary);

			if (!ofile.is_open())
			{
				cout << "can't open! sorry! \n";
				return false;
			}

			// write the file header
			ofile.write(reinterpret_cast<char *>(&file_header), sizeof(bitmap_file_header));

			// write the info header
			ofile.write(reinterpret_cast<char *>(&info_header), sizeof(bitmap_info_header));

			// the first argument to write is an array containing the image data
			// the second argument is the size of the data
			ofile.write(reinterpret_cast<char *>(pixels.data()), pixels.size() * sizeof(pixel));

			if (!ofile)
			{
				cout << "something happened during writing! SORRY \n";
				return false;
			}
			ofile.close();

			return true;
		}
	};

	int main()
	{
		const int width{800};
		const int height{600};
		const int x_mid = width / 2;
		const int y_mid = height / 2;
		const int x_unit = x_mid / 4;
		const int y_unit = y_mid / 4;

		bitmap bmp("../data/cpp.bmp");

		pixel background{0, 0, 0};
		bmp.set_all(background);

		pixel cyan{251, 217, 143};

		// draw stem of "C"
		for (int x = 0; x < x_unit; ++x)
			for (int y = 0; y < height; ++y)
				bmp.set_pixel(x, y, cyan);

		// draw top and bottom of "C"
		for (int x = x_unit; x < x_mid; ++x)
		{
			for (int y = 0; y < y_unit; ++y)
			{
				bmp.set_pixel(x, y, cyan);
			}
			for (int y = height - y_unit; y < height; ++y)
			{
				bmp.set_pixel(x, y, cyan);
			}
		}

		// draw first +
		for (int x = x_mid - 2 * x_unit; x < x_mid; ++x)
		{
			for (int y = y_mid - y_unit / 2; y < y_mid + y_unit / 2; ++y)
			{
				bmp.set_pixel(x, y, cyan);
			}
		}

		for (int x = x_mid - 3 * x_unit / 2; x < x_mid - x_unit / 2; ++x)
		{
			for (int y = 3 * y_unit; y < 5 * y_unit; ++y)
			{
				bmp.set_pixel(x, y, cyan);
			}
		}

		// draw second +
		for (int x = 5 * x_unit; x < 7 * x_unit; ++x)
		{
			for (int y = y_mid - y_unit / 2; y < y_mid + y_unit / 2; ++y)
			{
				bmp.set_pixel(x, y, cyan);
			}
		}

		for (int x = x_mid + 3 * x_unit / 2; x < x_mid + 5 * x_unit / 2; ++x)
		{
			for (int y = 3 * y_unit; y < 5 * y_unit; ++y)
			{
				bmp.set_pixel(x, y, cyan);
			}
		}

		if (bmp.write())
			std::cout << "success!\n";
		else
			std::cout << "fail!\n";

		return 0;
	}
}
#endif // BITMAP_FILE_H