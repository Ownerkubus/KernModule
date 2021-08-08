#include "DeltaTime.h"

DeltaTime::DeltaTime() {

}

DeltaTime::~DeltaTime() {

}

void DeltaTime::UpdateDT() {
    dt = clock.restart().asSeconds();
}