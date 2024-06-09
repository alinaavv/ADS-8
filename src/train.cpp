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
    Train::Cage* currentCage = first;
    if (!currentCage) return 0;

    if (!currentCage->light) {
        currentCage->light = true;
        countOp++;
    }
    int totalCages = 0;
    int trainLength = 0;
    bool counting = true;
    while (counting) {
        int cageCounter = 0;
        do {
            currentCage = currentCage->next;
            cageCounter++;
        } while (!currentCage->light);
        
        currentCage->light = false;
        trainLength = cageCounter;
        
        while (cageCounter > 0) {
            currentCage = currentCage->prev;
            cageCounter--;
        }
        
        if (!currentCage->light) {
            counting = false;
        } else {
            countOp++;
        }
    }
    return trainLength;
}

int Train::getOpCount() {
    return countOp;
}
