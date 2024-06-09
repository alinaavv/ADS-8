// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage* newCage = new Cage();
    newCage->light = light;
    if (!first) {
        first = newCage;
        first->next = first->prev = first;
    } else {
        Cage* last = first->prev;
        last->next = newCage;
        newCage->prev = last;
        newCage->next = first;
        first->prev = newCage;
    }
}

int Train::getLength() {
    if (!first) return 0;
    first->light = true;
    int length = 1;
    Cage* current = first->next;
    while (!current->light) {
        current->light = true;
        current = current->next;
        length++;
    }
    current = first;
    for (int i = 0; i < length; ++i) {
        current->light = false;
        current = current->next;
    }
    countOp = length;
    return length;
}

int Train::getOpCount() {
    return countOp;
}
