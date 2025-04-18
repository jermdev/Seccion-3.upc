// 12. Una empresa de transporte desea contar con una aplicación, que permita descomponer el código
// de salida de sus buses y determinar el departamento de destino, hora de salida y si se realizan
// paradas o no.
#include <iostream>

using namespace std;

//TODO: En el archivo .h mover esta funcion e importar a este archivo.
bool evaluar_cifras_de_un_numero(int num, int num_cifras_requeria) {
    int contero_de_cifras=0;

    if (num<0) {
        cout << "El numero debe ser positivo\n";
        return false;
    }

    while (num != 0){
        num /= 10;
        contero_de_cifras++;
    }

    if (num_cifras_requeria == contero_de_cifras){
        return true;
    } else {
        cout << "Numero de cifras no es valido\n";
        return false;   
    }
}

int main() {

    int codigo_de_salida, numero_de_digitos = 4, auxnum = 0, aux_codigo_de_salida;
    int num_departamento, num_hora_salida, num_realiza_paradas;
    bool num_cifras_aceptable;

    const char* departamentos[] = { "TUMBES", "AREQUIPA", "PUNO" };
    const char realizan_paradas[] = { 'S', 'N' };

    // Evaluar la sifras del numero digitado para que no haya errores de salida.
    //TODO:Si es posible factorizar esta parte en una funcion reutilizable.
    do{
        cout << "Digite el numero de codigo de salida: ";
        cin>> codigo_de_salida;
        num_cifras_aceptable = evaluar_cifras_de_un_numero(codigo_de_salida, numero_de_digitos);
        aux_codigo_de_salida = codigo_de_salida;
    } while (!num_cifras_aceptable);

    // Descoponemos el codigo de salida.

    while (aux_codigo_de_salida != 0){
        if (evaluar_cifras_de_un_numero(aux_codigo_de_salida, 4)){
            num_realiza_paradas = aux_codigo_de_salida % 10;
            aux_codigo_de_salida /= 10;
        }
        
        if (evaluar_cifras_de_un_numero(aux_codigo_de_salida, 3)) {
            num_hora_salida = aux_codigo_de_salida % 100;
            aux_codigo_de_salida /= 100;
        }

        if (evaluar_cifras_de_un_numero(aux_codigo_de_salida, 1)) {
            num_departamento = aux_codigo_de_salida % 10;
            aux_codigo_de_salida /= 10;
        }
    }

    // Evaluamos si el codigo es valido.
    //TODO:En cambio del return llamar la funcion de pedir codigo de salida.
    if( num_departamento < 1 || 3 < num_departamento ) {
        cout << "El numero de Departamento (" << num_departamento << ") no existe en los destinos disponibles.";
        return 0;
    }

    if( num_hora_salida < 0 ||  24 < num_hora_salida ) {
        cout << "El numero de hora (" << num_hora_salida << ") no es valido.";
        return 0;
    }

    if (num_realiza_paradas < 1 || 2 < num_realiza_paradas) {
        cout << "El numero codificado ("<< num_realiza_paradas << ") no es una opcion disponible";
        return 0;
    }

    // Salida de datos del viaje
    cout<<"Departamento de destino: " << departamentos[num_departamento] << endl;
    cout<<"Hora de salida: " << num_hora_salida << endl;
    cout<<"Realizan paradas: " << realizan_paradas[num_realiza_paradas-1] << endl;
    return 0;
}