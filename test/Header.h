#pragma once

const char help_main[] = "���������� ���������� �� K\n\n-h --help\t\t��������� ���������� ���������� �� K\n-s --set_component\t��������� �������� ���������� ����� �����������\n-c --put_circle\t\t��������� ����������\n-x --cut_file\t\t������� �����\n-i --input_file\t\t���� ����������� �����\n-o --output_file \t���� ��������� �����\n-f --file_info\t\t��������� ���������� � �����\n\n������� �� ����� ������� ����� 100 ������";
const char help_cut[] = "���������� ���������� �� -x\n\n-h --help\t\t��������� ���������� ���������� �� -x\n-x --Xnumber\t\t��������� ����� ���������� �� �����������\n-y --Ynumber\t\t��������� ����� ���������� �� ���������\n";
const char help_color[] = "���������� ���������� �� -s\n\n-h --help\t\t��������� ���������� ���������� �� -s\n-c --component\t\t��������� ����������� ����������\n-m --max\t\t��������� ������������� �������� ���������� �����\n-n --min\t\t��������� ������������ �������� ���������� �����\n";
const char help_circ[] = "���������� ���������� �� -c\n\n-h --help\t\t��������� ���������� ���������� �� -c\n-c --by_corners\t\t��������� ����� ����� ���������� �����\n-r --by_radius\t\t��������� ���������� ����� ���������� ������ � ������\n-w --width\t\t��������� ������ ����� ����������\n-l --line_color\t\t��������� ����� ����� ����������\n-f --fill\t\t��������� ����� ������� ����������\n";
const char help_corn_circ[] = "���������� ���������� �� -c-c\n\n-h --help\t\t��������� ���������� ���������� �� -c-c\n-f --first\t\t���� ��������� ������� ����\n-s --second\t\t���� ��������� ������� ����\n";
const char help_rad_circ[] = "���������� ���������� �� -c-r\n\n-h --help\t\t��������� ���������� ���������� �� -c-r\n-c --center\t\t���� ��������� ������ ����������\n-r --radius\t\t���� �������\n";

#pragma pack(push, 1)

struct BitmapFileHeader
{
	unsigned short signature;
	unsigned int filesize;
	unsigned short reserved1;
	unsigned short reserved2;
	unsigned int pixelArrOffset;
};

struct BitmapInfoHeader
{
	unsigned int headerSize;
	unsigned int width;
	unsigned int height;
	unsigned short planes;
	unsigned short bitsPerPixel;
	unsigned int compression;
	unsigned int imageSize;
	unsigned int xPixelsPerMeter;
	unsigned int yPixelsPerMeter;
	unsigned int colorsInColorTable;
	unsigned int importantColorCount;
};

#pragma pack(pop)

struct BGR
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
};

struct CutLines
{
	int x_num;
	int y_num;
};

struct Component
{
	char index;
	int value;
};

struct Circle
{
	int x0;
	int y0;
	int rad_b;
	int x1;
	int y1;
	int x2;
	int y2;
	int width;
	BGR l_color;
	int f_flag;
	BGR f_color;
};

//-----------------------------------------------------------------------------//

const char* s_circ_opt = "hcrw:l:f:";
const char* s_corn_circ_opt = "hf:s:";
const char* s_rad_circ_opt = "hr:c:";
const char* s_cut_opt = "hx:y:";
const char* s_color_opt = "hc:mn";
const char* s_main_opt = "hxsci:o:f:";

const struct option main_opt[] = {
		{"help", 0, NULL, 'h'},
		{"cut_file", 0, NULL, 'x'},
		{"set_component", 0, NULL, 's'},
		{"put_circle", 0, NULL, 'c'},
		{"input_file", 1, NULL, 'i'},
		{"output_file", 1, NULL, 'o'},
		{"file_info", 1, NULL, 'f'},
		{NULL, 0, NULL, 0}
};

const struct option circ_opt[] = {
		{"help", 0, NULL, 'h'},
		{"by_corners", 0, NULL, 'c'},
		{"by_radius", 0, NULL, 'r'},
		{"width", 1, NULL, 'w'},
		{"line_color", 1, NULL, 'l'},
		{"fill", 1, NULL, 'f'},
		{NULL, 0, NULL, 0}
};

const struct option rad_circ_opt[] = {
		{"help", 0, NULL, 'h'},
		{"radius", 1, NULL, 'r'},
		{"center", 1, NULL, 'c'},
		{NULL, 0, NULL, 0}
};

const struct option corn_circ_opt[] = {
		{"help", 0, NULL, 'h'},
		{"first", 1, NULL, 'f'},
		{"second", 1, NULL, 's'},
		{NULL, 0, NULL, 0}
};

const struct option cut_opt[] = {
		{"help", 0, NULL, 'h'},
		{"Xnumber", 1, NULL, 'x'},
		{"Ynumber", 1, NULL, 'y'},
		{NULL, 0, NULL, 0}
};

const struct option color_opt[] = {
		{"help", 0, NULL, 'h'},
		{"Colorcomp", 1, NULL, 'c'},
		{"max", 0, NULL, 'm'},
		{"min", 0, NULL, 'n'},
		{NULL, 0, NULL, 0}
};

char* itoa(int number);
int read_file(BitmapFileHeader* f_BFH, BitmapInfoHeader* f_BIH, BGR*** f_BM, char* path_in);
int cut_file(CutLines lines, char* path_in, char* path_out);
int set_component(Component new_color, char* path_in, char* path_out);
int put_circle(Circle circle, char* path_in, char* path_out);
void print_info(char* path);
int opt_set_component(int* command, Component* component, int argc, char* argv[]);
int opt_put_circle(int* command, Circle* circle, int argc, char* argv[]);
int opt_cut_file(int* command, CutLines* lines, int argc, char* argv[]);