// elev_app.cpp
// клиентский файл
#include "elev.h"                        // дл€ объ€влений классов

int main()
{
	//system("chcp 1251 > nul");

	building theBuilding;
	while(true)
	{
		theBuilding.master_tick();       // послать временные метки всем лифтам
		wait(1000);                      // пауза

		theBuilding.record_floor_reqs(); // получить запросы этажей от пользователей
	}

	return 0;
}
