// serializacion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
using namespace std;
class Student 
{
    public:
        string name;
        int roll;
        string branch;
        friend ofstream & operator<<(ofstream & ofs, Student & s); // fichero y objeto. Inserta operador en el file, 
        // no en la consola. 
};

ofstream & operator<<(ofstream & ofs, Student & s) // Tengo sobrecargado el operador. 
{
    ofs << s.name << endl;
    ofs << s.roll << endl;
    ofs << s.branch << endl;
    return ofs;
}
int main()
{
    Student s1;
    s1.name = "Jose"; s1.roll = 20; s1.branch = "CS";
    //Inicializar el objeto en el fichero. 
    ofstream ofs("Student.txt", ios::trunc); // si no hay nada allí lo trunco. 
    //ofs << s1.name << s1.roll << s1.branch << endl; // Esto no es necesario con la funció operator, directamente se 
    // envía el objeto como la siguiente instrucción. 
    ofs << s1;
    ofs.close();
    return 0;
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
