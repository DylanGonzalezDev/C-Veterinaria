#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstring>

using namespace std;

typedef struct{             //estructura de mascotas con dos tipos de datos
        char name[256];        //string, name y pedigree, un tipo de dato entero
        char pedigree[256];    //age para indicar la edad y un tipo de dato float
        int age;            // para el peso.
        float weight;
} pets;                     //el nombre de la estructura es pets.

pets pet[30];               //array de mascotas con un limite de 30.
int contPets = 0;           //el contador de todas las mascotas.
char space;
void mostrarUnaMascota(pets mascota){ //funcion para dar formato a un retorno por consola.
    cout << "nombre: "<< mascota.name << " pedigree: " << mascota.pedigree;
    cout << " edad: " << mascota.age << " peso: " <<mascota.weight << "\n" <<endl;
} //imprime una sola mascota.

void mostrarMascotas(){              //recorre el array pet[] y muestra 
    for(int i=0;i<contPets;i++){    //en consola todas las mascotas.
        mostrarUnaMascota(pet[i]);
    } 
}

pets comparacionDePeso(pets mascota1, pets mascota2){   //compara el peso entre 
    if(mascota1.weight > mascota2.weight){              //dos mascotas y retorna 
        return mascota1;                                //la mas pesada.
    }else{
        return mascota2;
    }   
}

void mascota_mas_pesada(){  //Muestra por consola la mascota mas pesada de todo el array. 
    pets mayor_peso = pet[0];    
    for(int i=0;i<contPets;i++){
        //recorre el array y compara con la funcion comparacionDePeso()
         mayor_peso = comparacionDePeso(pet[i], mayor_peso);
        //guarda el valor retornado en la variable del tipo pets y vuelve al bucle.
    }
    mostrarUnaMascota(mayor_peso);
    cout << mayor_peso.name << " es la mascota mas pesada" << endl;
}

void mayores_a10(){ //muestra en consola las mascotas mayores a 10.
    for(int i= 0;i<contPets;i++){
    if(pet[i].age >= 10){
        mostrarUnaMascota(pet[i]);
        }
    }
}

void buscar_pedigree(string pedigree){  //Busca por pedigree en todo el array pet[] e
        for(int i = 0;i<contPets;i++){  //imprime todos los resultados con los que matchee.
            if(pedigree == pet[i].pedigree){
                //printf("llegue aca");
                mostrarUnaMascota(pet[i]);
            }
        }
}

void agregarMascota(){ //agrega una mascota.
        printf("ingresar nombre de la mascota\n");
        cin.ignore();
        cin.getline(pet[contPets].name,256,'\n');
        //cin >> pet[contPets].name;
        printf("\ningresar su pedigree\n");
        cin.getline(pet[contPets].pedigree,256,'\n');
        //cin.getline(pet[contPets].pedigree,256,"\n");
        //cin >> pet[contPets].pedigree;
        printf("\ningresar su edad\n");
        scanf(" %d",&pet[contPets].age);
        printf("\ningresar su peso\n");
        scanf(" %f",&pet[contPets].weight);
        printf("\ndesea agregar otra mascota? 0:No\n");
}

void menu(){    //menu de opciones.
    printf("agragar una mascota: presione 1\n");
    printf("mostrar todas las mascotas: presione 2\n");
    printf("mostrar la mascota mas pesada: presione 3\n");
    printf("desea ver las mayores a 10: presione 4\n");
    printf("desea buscar por pedigree: presione 5 e ingrese el pedigree buscado\n");
}

void respuestaAlMenu(int res){  //Funcion con estructura switch para 
    int response = 1;           //ingresar en la opcion indicada por 
    char pedigree_res[256];        //el usuario.
    switch(res){
        case 1:{
            while(response != 0){
                agregarMascota();
                contPets++;
                scanf(" %d",&response);
            }
            break;
            
        };
        case 2:{
            mostrarMascotas();
            break;
        };
        case 3:{
            mascota_mas_pesada();
            break;
        };
        case 4:{
            mayores_a10();
            break;
        };
        case 5:{
            cin.ignore();
            cin.getline(pedigree_res,256,'\n');
            //cout << pedigree_res;
            buscar_pedigree(pedigree_res);
            break;
        };
    }
}


int main(){
    int res = 1;    //variables de respuesta al 
    int salir = 1;  //sistema.
    while(salir != 0){
        menu();
        cin >> res;
        respuestaAlMenu(res);
        printf("si desea continuar ingrese 1, desea salir? ingrese 0\n");
        scanf("%d",&salir);
    }
    printf("\n\nGracias por usar esta aplicacion, esperamos que vuelva pronto!\n\n");
    return 0;
}






