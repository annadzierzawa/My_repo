#include"Struct illness.h"


void date::set_date(int day_, int month_, int year_)           ///podaje argumenty poniewa� podaj� je z pliku           
{
	day =day_;
	month = month_;
	year = year_;
}

std::ostream & operator<<(std::ostream & out, date & k)        /// przeci��am operator strumieniowy << 
{
	out << k.day << " " <<k.month << " " << k.year;
	return out;
}