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
    countOp++;
}

int Train::getLength() {
    if (!first) return 0;
    first->light = true;
    int length = 1;
    Cage* current = first->next;
    countOp = 1;

    while (!current->light) {
        current->light = true;
        current = current->next;
        length++;
        countOp++;
    }

    current = first;
    for (int i = 0; i < length; ++i) {
        current->light = false;
        current = current->next;
        countOp++;
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}
