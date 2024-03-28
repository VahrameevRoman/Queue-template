#include <iostream>
using namespace std;

template <class T>
class QueueElement
{
public:
    T data;
    QueueElement<T>* previous;
    QueueElement<T>* next;

};

template<typename T>
QueueElement<T>* Insert(QueueElement<T>* p, T element)
{
    if (p == nullptr)
    {
        p = new QueueElement<T>;
        p->data = element;
        p->next = nullptr;
        p->previous = nullptr;
        return p;
    }
    else
    {
        QueueElement<T>* newElement = new QueueElement<T>;
        newElement->data = element;
        newElement->next = nullptr;
        newElement->previous = p;
        p->next = newElement;
        return newElement;
    }
}

template<typename T>
T Delete(QueueElement<T>* p)
{
    if (p->previous == nullptr)
    {
        T firstElement = p->data;
        if (p->next != nullptr)
        {
            (p->next)->previous = nullptr;
            delete p;
        }
        else //удаляем последний элемент в очереди
        {
            delete p;
        }
        return firstElement;
    }
    else return Delete(p->previous);
}

template<typename T>
void Show(QueueElement<T>* p)
{
    if (p == nullptr) return;
    else
    {
        cout << p->data << endl;
        Show(p->previous);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    QueueElement<int>* lastInt = nullptr;
    QueueElement<char>* lastChar = nullptr;

    int choice;
    char ch;
    int element;

    do
    {
        cout << "\nВыберите тип данных для работы с очередью:\n";
        cout << "1. Очередь целочисленных значений\n";
        cout << "2. Очередь символьных значений\n";
        cout << "3. Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            do
            {
                cout << "\nМеню рабы с очередью целочисленных значений:\n";
                cout << "1. Добавить элемент в очередь\n";
                cout << "2. Извлечь элемент из очереди\n";
                cout << "3. Показать элементы очереди\n";
                cout << "4. Выйти\n";
                cout << "Ваш выбор: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Введите целое число для добавления: ";

                    cin >> element;
                    //проверка ввода
                    while (cin.fail())
                    {
                        cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Некорректное значение. Введите значение повторно:";
                        cin >> element;
                    }
                    lastInt = Insert(lastInt, element);
                    break;
                case 2:
                    if (lastInt == nullptr) cout << "Очередь уже пуста\n";
                    else if (lastInt->previous == 0)
                    {
                        cout << "Извлекаемый последний элемент очереди: " << Delete(lastInt) << endl;
                        lastInt = nullptr;
                    }
                    else cout << "Извлекаемый элемент: " << Delete(lastInt) << endl;
                    break;
                case 3:
                    if (lastInt == nullptr) cout << "Очередь пуста\n";
                    else Show(lastInt);
                    break;
                case 4:
                    break;
                default:
                    cout << "Неверный выбор. Повторите попытку.\n";
                }
            } while (choice != 4);
            break;
        case 2:
            do
            {
                cout << "\nМеню работы с очередью символов:\n";
                cout << "1. Добавить элемент в очередь\n";
                cout << "2. Извлечь элемент из очереди\n";
                cout << "3. Показать элементы очереди\n";
                cout << "4. Выйти\n";
                cout << "Ваш выбор: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Введите символ для добавления: ";
                    cin >> ch;
                    //проверка ввода
                    while (cin.fail())
                    {
                        cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Некорректное значение. Введите значение повторно:";
                        cin >> ch;
                    }
                    lastChar = Insert(lastChar, ch);
                    break;
                case 2:
                    if (lastChar == nullptr) cout << "Очередь уже пуста\n";
                    else if (lastChar->previous == 0)
                    {
                        cout << "Извлекаемый последний элемент очереди: " << Delete(lastChar) << endl;
                        lastChar = nullptr;
                    }
                    else cout << "Извлекаемый элемент: " << Delete(lastChar) << endl;
                    break;
                case 3:
                    if (lastChar == nullptr) cout << "Очередь пуста\n";
                    else Show(lastChar);
                    break;
                case 4:
                    break;
                default:
                    cout << "Неверный выбор. Повторите попытку.\n";
                }
            } while (choice != 4);
            break;

        case 3:
            cout << "Выход из программы.\n";
            break;

        default:
            cout << "Неверный выбор. Повторите попытку.\n";
        }
    } while (choice != 3);

    return 0;
}