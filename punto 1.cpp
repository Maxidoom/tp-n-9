#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Alumno {
private:
	string nombre;
	int edad;
	double nota1, nota2, nota3;
	string estado;

	void actualizarEstado() {
		estado = (calcularPromedio() >= 7) ? "Aprobado" : "Desaprobado";
	}

public:
	Alumno(string nombre, int edad, double nota1, double nota2, double nota3)
		: nombre(nombre), edad(edad), nota1(nota1), nota2(nota2), nota3(nota3) {
		actualizarEstado();
	}

	string getNombre() const {
		return nombre;
	}
	int getEdad() const {
		return edad;
	}
	double getNota1() const {
		return nota1;
	}
	double getNota2() const {
		return nota2;
	}
	double getNota3() const {
		return nota3;
	}
	string getEstado() const {
		return estado;
	}
	void setNota1(double n) {
		nota1 = n;
		actualizarEstado();
	}
	void setNota2(double n) {
		nota2 = n;
		actualizarEstado();
	}
	void setNota3(double n) {
		nota3 = n;
		actualizarEstado();
	}

	double calcularPromedio() const {
		return (nota1 + nota2 + nota3) / 3;
	}
};

int main() {
	vector<Alumno> alumnos;
	string nombre;
	int edad, numAlumnos;
	double nota1, nota2, nota3;

	cout << "Ingrese el número de alumnos: ";
	cin >> numAlumnos;
	for (int i = 0; i < numAlumnos; i++) {
		cout << "Ingrese el nombre del alumno: ";
		cin >> nombre;
		cout << "Ingrese la edad del alumno: ";
		cin >> edad;
		cout << "Ingrese la nota 1 del alumno: ";
		cin >> nota1;
		cout << "Ingrese la nota 2 del alumno: ";
		cin >> nota2;
		cout << "Ingrese la nota 3 del alumno: ";
		cin >> nota3;
		alumnos.push_back(Alumno(nombre, edad, nota1, nota2, nota3));
	}

	cout << "\nDatos de los alumnos:" << endl;
	for (const auto& a : alumnos) {
		cout << "Nombre: " << a.getNombre() << endl;
		cout << "Edad: " << a.getEdad() << endl;
		cout << "Nota 1: " << a.getNota1() << endl;
		cout << "Nota 2: " << a.getNota2() << endl;
		cout << "Nota 3: " << a.getNota3() << endl;
		cout << "Promedio: " << a.calcularPromedio() << endl;
		cout << "Estado: " << a.getEstado() << endl << endl;
	}

	return 0;
}