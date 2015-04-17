
/**
    @file city_model.h
    @a class that tracks the cities 
    @author Mike Neergaard <mike.neergaard@gmail.com>
    @version 1.0

    @section LICENSE
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Copyright (C) 2015  Mike Neergaard

*/

#ifndef latin_names_H
#define latin_names_H

static s_name LATIN_given_name[] =  { 
{"", "María"}, 
{"", "Juan"}, 
{"", "Carlos"}, 
{"", "Ana"}, 
{"", "Jorge"}, 
{"", "Marta"}, 
{"", "Susana"}, 
{"", "Alicia"}, 
{"", "Rosa"}, 
{"", "De"}, 
{"", "Silvia"}, 
{"", "Jose"}, 
{"", "Luis"}, 
{"", "Graciela"}, 
{"", "Roberto"}, 
{"", "Alberto"}, 
{"", "José"}, 
{"", "Eduardo"}, 
{"", "Beatriz"}, 
{"", "Norma"}, 
{"", "Elsa"}, 
{"", "Ricardo"}, 
{"", "Carmen"}, 
{"", "Miguel"}, 
{"", "Oscar"}, 
{"", "Daniel"}, 
{"", "Liliana"}, 
{"", "Antonio"}, 
{"", "Mario"}, 
{"", "Elena"}, 
{"", "Sara"}, 
{"", "Lidia"}, 
{"", "Olga"}, 
{"", "Patricia"}, 
{"", "Marcelo"}, 
{"", "Francisco"}, 
{"", "Mirta"}, 
{"", "Pablo"}, 
{"", "Teresa"}, 
{"", "Adriana"}, 
{"", "Alejandro"}, 
{"", "Gustavo"}, 
{"", "Enrique"}, 
{"", "Dora"}, 
{"", "Nelida"}, 
{"", "Julio"}, 
{"", "Guillermo"}, 
{"", "Juana"}, 
{"", "Claudia"}, 
{"", "Fernando"}, 
{"", "Hector"}, 
{"", "Laura"}, 
{"", "Delia"}, 
{"", "Horacio"}, 
{"", "Angela"}, 
{"", "Pedro"}, 
{"", "Osvaldo"}, 
{"", "Irma"}, 
{"", "Margarita"}, 
{"", "Isabel"}, 
{"", "Hugo"}, 
{"", "Alfredo"}, 
{"", "Manuel"}, 
{"", "Martha"}, 
{"", "Nélida"}, 
{"", "Héctor"}, 
{"", "Marcela"}, 
{"", "Nora"}, 
{"", "Sergio"}, 
{"", "Angel"}, 
{"", "Luisa"}, 
{"", "Cristina"}, 
{"", "Rodolfo"}, 
{"", "Julia"}, 
{"", "Blanca"}, 
{"", "Andrea"}, 
{"", "Monica"}, 
{"", "Raquel"}, 
{"", "Claudio"}, 
{"", "Celia"}, 
{"", "Mónica"}, 
{"", "Diego"}, 
{"", "Norberto"}, 
{"", "Mabel"}, 
{"", "Elvira"}, 
{"", "Gabriela"}, 
{"", "Mercedes"}, 
{"", "Esther"}, 
{"", "Nelly"}, 
{"", "Clara"}, 
{"", "Hilda"}, };

static s_name LATIN_surname[] = {
{"","Fernández"}, 
{"","Rodríguez"}, 
{"","González"}, 
{"","García"}, 
{"","López"}, 
{"","Martínez"}, 
{"","Pérez"}, 
{"","Álvarez"}, 
{"","Gómez"}, 
{"","Sánchez"}, 
{"","Díaz"}, 
{"","Vásquez"}, 
{"","Castro"}, 
{"","Romero"}, 
{"","Suárez"}, 
{"","Blanco"}, 
{"","Ruiz"}, 
{"","Alonso"}, 
{"","Torres"}, 
{"","Domínguez"}, 
{"","Gutiérrez"}, 
{"","Sosa"}, 
{"","Iglesias"}, 
{"","Giménez"}, 
{"","Ramírez"}, 
{"","Martín"}, 
{"","Varela"}, 
{"","Ramos"}, 
{"","Núnez"}, 
{"","Rossi"}, 
{"","Silva"}, 
{"","Méndez"}, 
{"","Hernández"}, 
{"","Flores"}, 
{"","Pereyra"}, 
{"","Ferrari"}, 
{"","Ortiz"}, 
{"","Medina"}, 
{"","Benítez"}, 
{"","Herrera"}, 
{"","Arias"}, 
{"","Acosta"}, 
{"","Moreno"}, 
{"","Aguirre"}, 
{"","Otero"}, 
{"","Cabrera"}, 
{"","Rey"}, 
{"","Rojas"}, 
{"","Vidal"}, 
{"","Molina"}, 
{"","Russo"}, 
{"","Paz"}, 
{"","Vega"}, 
{"","Costa"}, 
{"","Bruno"}, 
{"","Romano"}, 
{"","Morales"}, 
{"","Ríos"}, 
{"","Miranda"}, 
{"","Muñoz"}, 
{"","Franco"}, 
{"","Castillo"}, 
{"","Campos"}, 
{"","Bianchi"}, 
{"","Luna"}, 
{"","Correa"}, 
{"","Ferreyra"}, 
{"","Navarro"}, 
{"","Quiroga"}, 
{"","Colombo"}, 
{"","Cohen"}, 
{"","Pereyra"}, 
{"","Vera"}, 
{"","Lorenzo"}, 
{"","Gil"}, 
{"","Santos"}, 
{"","Delgado"}, 
{"","Godoy"}, 
{"","Rivas"}, 
{"","Rivero"}, 
{"","Gallo"}, 
{"","Peralta"}, 
{"","Soto"}, 
{"","Figueroa"}, 
{"","Juárez"}, 
{"","Marino"}, 
{"","Ponce"}, 
{"","Calvo"}, 
{"","Ibáñez"}, 
{"","Cáceres"}, 
{"","Carrizo"}, 
{"","Vargas"}, 
{"","Mendoza"}, 
{"","Aguilar"}, 
{"","Ledesma"}, 
{"","Guzmán"}, 
{"","Soria"}, 
{"","Villalba"}, 
{"","Prieto"}, 
{"","Maldonado"} };

/// This class gives us the names
class latin

{ public:
  static std::string give_name(int index) 
{
    int surnames = 100;
    std::string ret_val;
    int s, g;
    s = index % surnames;
    g = (int) index/surnames;
    ret_val = LATIN_given_name[g].roman_name + " "+LATIN_surname[s].roman_name;
    return ret_val;
  }


  static int select_name(double p) 
{
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return 42;

  int ret_val = (int) (100) * (91)*p;

    // In theory, (int) p*x*y will never actually be x*y,
    return ret_val;
  }
};
#endif
