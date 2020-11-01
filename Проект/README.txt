проект Reminder состоит из

полей:
1) vector<dateStruct> vecZadani; - вектор напоминаний
2) time_t realTimeSec; - реальное время в секундах с 1970 года
3) tm* realDateTm = new tm; - оъбект временной структуры для получения нормальной даты и времени
4) dateStruct realDate; - объект собственной переписанной временной структуры для облегчения работы
5) int amountReminder; - количесво напоминаний

методов:
1)  Program(); - конструктор класса
2)  void opredVrem(); - метод для получения realTimeSec; 
3)  void opredDate(); - метод для перевода realTimeSec; в realDate; 
4)  void addReminder(string textReminder, int year,int mon,int mday, int hour, int min); - метод для добавления новых напоминаний, принимате текст напоминания, год, месяц, число месяца, час и минуту
5)  void sortVecZadani(); - метод для сортировки напоминаний в vecZadani; 
6)  void fromStringToWchar_t(string text, wchar_t *text2); - собственный метод для конвертации переменных типа string в wchar_t для упрощения и удобства работы с MessageBox
7)  void provZad(); - метод для проверки времени и вывода MessageBox в нужное время
8)  void main(); - главный метод, так же используется как GUI 
9)  void save(); - метод для сохраниени vecZadani; в файл для прекращени работы программы
10) void download(); - метод для загрузки vecZadani; из файла
11) void threadF(); - метод объеденяющий все потоки