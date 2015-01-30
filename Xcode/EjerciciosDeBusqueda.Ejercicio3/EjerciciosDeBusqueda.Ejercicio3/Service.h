//
//  Service.h
//  EjerciciosDeBusqueda.Ejercicio3
//
//  Created by Jonathan Ginsburg on 1/29/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __EjerciciosDeBusqueda_Ejercicio3__Service__
#define __EjerciciosDeBusqueda_Ejercicio3__Service__

#include <stdio.h>
#include <iostream>

enum ServiceKind {
    type1,
    type2,
    type3,
    typeUndefined,
};

class Service {
public:
    int price;
    ServiceKind serviceKind;
    Service();
    Service(int newPrice, ServiceKind newServiceKind);
    friend std::ostream& operator<<(std::ostream& outputStream, Service service);
};

#endif /* defined(__EjerciciosDeBusqueda_Ejercicio3__Service__) */
