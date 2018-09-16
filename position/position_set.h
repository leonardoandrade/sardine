#ifndef POSITION_SET_H
#define POSITION_SET_H

typedef struct PositionSet {
  int size;
  Position * positions;
} PositionSet;

PositionSet * makePositionSet();
PositionSet * addPosition(PositionSet *);

#endif