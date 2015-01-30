//
//  Service.cpp
//  EjerciciosDeBusqueda.Ejercicio3
//
//  Created by Jonathan Ginsburg on 1/29/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Service.h"
#include "Helper.h"

Service::Service(): price(0), serviceKind(typeUndefined){}

Service::Service(int newPrice, ServiceKind newServiceKind): price(newPrice), serviceKind(newServiceKind){}

std::ostream& operator<<(std::ostream& outputStream, Service service){
    outputStream << "Service of type " << Helper::intToString((int)service.serviceKind) << ", with price: $" << Helper::intToString(service.price);
    return outputStream;
}
