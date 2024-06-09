// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool lamp) {
    Cage* newCage = new Cage();
    newCage->light = lamp;
    newCage->next = newCage->prev = nullptr;

    if (first) {
        Cage* last = first->prev;
        last->next = newCage;
        newCage->prev = last;
        newCage->next = first;
        first->prev = newCage;
    } else {
        first = newCage;
        first->next = first->prev = first;
    }
    countOp++;
}

int Train::getLength() {
    if (!first) return 0;

    Cage* current = first;
    if (!current->light) {
        current->light = true;
        countOp++;
    }

    int len = 0;
    while (true) {
        current = current->next;
        len++;
        if (current->light) {
            current->light = false;
            countOp++;
            Cage* temp = current;
            for (int i = 0; i < len; i++) {
                temp = temp->prev;
            }
            if (!temp->light) {
                return len;
            }
            current->light = true;
            countOp++;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
