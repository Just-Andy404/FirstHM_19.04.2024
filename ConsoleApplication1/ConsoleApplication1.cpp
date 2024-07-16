/*
Создайте шаблонный класс обычной очереди для работы с
с целыми значениями. Требуется создать реализации для
типичных операций над элементами:
■ IsEmpty - проверка очереди на пустоту;
■ IsFull - проверка очереди на заполнение;
■ Enqueue - добавление элемента в очередь;
■ Dequeue - удаление элемента из очереди;
■ Show - отображение всех элементов очереди на экран.
*/
#include <iostream>
#include "Queue.h"

void showMenu() {
    cout << "Меню:\n";
    cout << "1. Проверка очереди на пустоту\n";
    cout << "2. Проверка очереди на заполнение\n";
    cout << "3. Добавление элемента в очередь\n";
    cout << "4. Удаление элемента из очереди\n";
    cout << "5. Отображение всех элементов очереди\n";
    cout << "6. Выход\n";
    cout << "Выберите пункт меню: ";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int capacity;
    cout << "Введите максимальную емкость очереди: ";
    cin >> capacity;

    Queue<int> queue(capacity);

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            if (queue.IsEmpty()) {
                cout << "Очередь пуста.\n";
            }
            else {
                cout << "Очередь не пуста.\n";
            }
            break;

        case 2:
            if (queue.IsFull()) {
                cout << "Очередь заполнена.\n";
            }
            else {
                cout << "Очередь не заполнена.\n";
            }
            break;

        case 3:
            if (!queue.IsFull()) {
                int num;
                cout << "Введите число для добавления в очередь: ";
                cin >> num;
                queue.Enqueue(num);
                cout << "Элемент добавлен.\n";
            }
            else {
                cout << "Очередь заполнена, невозможно добавить элемент.\n";
            }
            break;

        case 4:
            if (!queue.IsEmpty()) {
                int dequeued = queue.Dequeue();
                if (dequeued != -1) {
                    cout << "Удален элемент: " << dequeued << endl;
                }
            }
            else {
                cout << "Очередь пуста, невозможно удалить элемент.\n";
            }
            break;

        case 5:
            cout << "Элементы очереди: ";
            queue.show();
            break;

        case 6:
            cout << "Выход из программы.\n";
            break;

        default:
            cout << "Неверный выбор, попробуйте снова.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}

