#ifndef _INC_EKU_IO_CONCOL
#define _INC_EKU_IO_CONCOL

/*Header file to color text and background in windows console applications
Global variables - textcol,backcol,deftextcol,defbackcol,colorprotect*/

#include<windows.h>
#include<iosfwd>

namespace dkremer
{

#ifndef CONCOL
#define CONCOL
	enum concol  // alte CGA  MS-DOS Bezeichnungen   etwa 1986 ??
	{
		black = 0,
		dark_blue = 1,
		dark_green = 2,
		dark_aqua, dark_cyan = 3,
		dark_red = 4,
		dark_purple = 5, dark_pink = 5, dark_magenta = 5,
		dark_yellow = 6,
		dark_white = 7,
		grey = 8,
		blue = 9,
		green = 10,
		aqua = 11, cyan = 11,
		red = 12,
		purple = 13, pink = 13, magenta = 13,
		yellow = 14,
		white = 15
	};
#endif //CONCOL

	HANDLE std_con_out;
	//Standard Output Handle
	bool colorprotect = true;
	//If colorprotect is true, background and text colors will never be the same
	concol textcol, backcol, deftextcol, defbackcol;
	/*textcol - current text color
	backcol - current back color
	deftextcol - original text color
	defbackcol - original back color*/

	inline void update_colors()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(std_con_out, &csbi);
		textcol = concol(csbi.wAttributes & 15);
		backcol = concol((csbi.wAttributes & 0xf0) >> 4);
	}

	inline void setcolor(concol textcolor, concol backcolor)
	{
		if (colorprotect && textcolor == backcolor)return;
		textcol = textcolor; backcol = backcolor;
		unsigned short wAttributes = ((unsigned int)backcol << 4) | (unsigned int)textcol;
		SetConsoleTextAttribute(std_con_out, wAttributes);
	}

	inline void settextcolor(concol textcolor)
	{
		if (colorprotect && textcolor == backcol)return;
		textcol = textcolor;
		unsigned short wAttributes = ((unsigned int)backcol << 4) | (unsigned int)textcol;
		SetConsoleTextAttribute(std_con_out, wAttributes);
	}

	inline void setbackcolor(concol backcolor)
	{
		if (colorprotect && textcol == backcolor)return;
		backcol = backcolor;
		unsigned short wAttributes = ((unsigned int)backcol << 4) | (unsigned int)textcol;
		SetConsoleTextAttribute(std_con_out, wAttributes);
	}

	inline void concolinit()
	{
		std_con_out = GetStdHandle(STD_OUTPUT_HANDLE);
		update_colors();
		deftextcol = textcol; defbackcol = backcol;
	}

	template<class elem, class traits>
	inline std::basic_ostream<elem, traits>& operator<<(std::basic_ostream<elem, traits>& os, concol col)
	{
		os.flush();
		settextcolor(col);   // kein os << xxxx
		return os;
	}



	template<class elem, class traits>
	inline std::basic_istream<elem, traits>& operator>>(std::basic_istream<elem, traits>& is, concol col)
	{
		std::basic_ostream<elem, traits>* p = is.tie();
		if (p != NULL)p->flush();
		settextcolor(col);
		return is;
	}
}
#endif	//_INC_EKU_IO_CONCOL 
