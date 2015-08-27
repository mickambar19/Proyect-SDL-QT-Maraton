#ifndef LEERENTERO_H
#define LEERENTERO_H
#include <iostream>
#include <limits>
using namespace std;

int leer_int (void) {
    int entero;
    do {
        cin >> entero;
        if (cin.fail ()) {
            cout << "El valor debe ser num�rico." << endl;

            /* Limpiar las banderas de error*/
            cin.clear();

            /* Este cin.ignore descarta todo hasta que encuentra el enter */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            /* Este cin.ignore descarta todo hasta que encuentra el enter */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    } while (1);

    return entero;
}
#endif // LEERENTERO_H
