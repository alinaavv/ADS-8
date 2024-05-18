// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>

Train::~Train() {
    if (first) {
        Cage *current = first->next;
        while (current != first) { 
            Cage *temp = current;
            current = current->next;
            delete temp;
        }
        delete first; 
    }
}
// добавления вагона
void Train::addCage(bool light) {
    Cage *newCage = new Cage();
    newCage->light = light;
    if (!first) {
        first = newCage;
        first->next = first->prev = first; 
    } else {
        Cage *last = first->prev;
        last->next = newCage;
        newCage->prev = last;
        newCage->next = first;
        first->prev = newCage;
    }
}
// получение длины поезда
int Train::getLength() {
    if (!first) return 0; 
    first->light = true; 
    int length = 1;
    Cage *current = first->next;
    while (!current->light) { 
        current->light = true;
        current = current->next;
        length++;
        countOp++;
    }
    for (int i = 0; i < length; ++i) {
        current->light = false;
        current = current->next;
    }
    return length;
}
