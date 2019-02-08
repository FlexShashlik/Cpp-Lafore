// constfu.cpp
// применение константных методов
class aClass
{
private:
	int alpha;
public:
	void nonFunc()	// неконстантный метод
	{ 
		alpha = 99;
	}	  // корректно
	void conFunc()const   // константный метод
	{ 
		alpha = 99;
	}	// ошибка: нельзя изменить значение поля
};
