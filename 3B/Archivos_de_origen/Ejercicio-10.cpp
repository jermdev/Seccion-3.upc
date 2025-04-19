/* Se le solicita que elabore un programa en C++ que reciba como datos la cantidad de años que el empleado
labora en la entidad y los estudios realizados y nos determine e imprima el puntaje obtenido*/
#include <iostream>
#include <cctype> 

using namespace std;

struct Nivel_Academico{
    char sigla_nivel_academico;
    int puntos;
};

bool exist_nivel_academico_digitado(Nivel_Academico arr_niveles[], int i_arr, char nivel_estudio ) {
    for (int i = 0; i < i_arr; i++){
        if (arr_niveles[i].sigla_nivel_academico == toupper(nivel_estudio)){
            return true;
        }
    }
    return false;
}

int Puntos_estudios(Nivel_Academico arr_niveles[],int i_arr, char nivel_estudio) {
    for (int i = 0; i < i_arr; i++){
        if(arr_niveles[i].sigla_nivel_academico == toupper(nivel_estudio)){
            return arr_niveles[i].puntos;
        }
    }
    return 0;
}

int main() {

    int num_años_en_empresa, cantid_niveles = 4;
    int puntos_años_empresa, puntos_por_estudios;
    char sigla_nivel_estudio;

    Nivel_Academico niveles_estudios[cantid_niveles] = { {'P', 5}, {'S', 10}, {'U', 20}, {'G', 30} };

    do{   
        cout << "Ingrese la catidad de anios que labora: "; cin >> num_años_en_empresa;
    } while (num_años_en_empresa<=0);

    do{
        cout << "ingrese su nivel de estudios\nEstudios (P: primaria; S: secundaria; U: universitario; G: posgrado): ";
        cin >> sigla_nivel_estudio;
    } while (!exist_nivel_academico_digitado(niveles_estudios, cantid_niveles, sigla_nivel_estudio));
    
    if (num_años_en_empresa < 5 ) {
        puntos_años_empresa = 5;
    } else {
        puntos_años_empresa = 10;
    }

    puntos_por_estudios = Puntos_estudios(niveles_estudios, cantid_niveles, sigla_nivel_estudio);

    cout << "Puntaje Obtenido: " << puntos_años_empresa + puntos_por_estudios;
    return 0;
}