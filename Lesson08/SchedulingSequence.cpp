//NMEC: 93049
//NOME: José Vasco Carvalho de Sousa

// Complete the functions (marked by ...)
// so that it passes all tests in DateTimeTest.

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TimeInterval.h"
#include "SchedulingSequence.h"

// Create a SchedulingSequence capable of storing up to (capacity) intervals.
SchedulingSequence *SchedulingSequenceCreate(int capacity)
{
  assert(capacity >= 0);
  // You must allocate space for the struct and for the intervals array!
  SchedulingSequence *sch = (SchedulingSequence *)malloc(sizeof(*sch));
  sch->intervals = (TimeInterval **)malloc(sizeof(*sch->intervals));
  sch->capacity = capacity;
  sch->size = 0;
  return sch;
}

// Destroy SchedulingSequence *pss
void SchedulingSequenceDestroy(SchedulingSequence **pss)
{
  assert(*pss != NULL);
  free((*pss)->intervals);
  free(*pss);
}

int SchedulingSequenceIsEmpty(SchedulingSequence *ss)
{
  return ss->size == 0;
}

int SchedulingSequenceIsFull(SchedulingSequence *ss)
{
  return ss->size == ss->capacity;
}

// Add interval *ti to *ss.
// Return true on success,
// return false if *ti olverlaps any of the intervals in *ss.
int SchedulingSequenceAdd(SchedulingSequence *ss, TimeInterval *ti)
{
  assert(!SchedulingSequenceIsFull(ss));
  int i = 0;
  for (; i < ss->size; i++)
  {
    if (TimeIntervalOverlaps(ti, ss->intervals[i]))
      return 0;
  }
  ss->intervals[ss->size] = ti;
  ss->size++;
  return 1;
}

// Get the interval at position (idx) of *ss.
// idx=0 is the first position idx=ss->size-1 is the last position.
// Precondition: 0 <= idx < ss->size.
TimeInterval *SchedulingSequenceGet(SchedulingSequence *ss, int idx)
{
  assert(0 <= idx && idx < ss->size);
  return ss->intervals[idx];
}

void swap(TimeInterval **t1, TimeInterval **t2)
{
  TimeInterval *tmp = *t1;
  *t1 = *t2;
  *t2 = tmp;
}

// Remove the interval at position (idx) of *ss, and return it.
// idx=0 is the first position idx=ss->size-1 is the last position.
// Precondition: 0 <= idx < ss->size.
TimeInterval *SchedulingSequencePop(SchedulingSequence *ss, int idx)
{
  assert(0 <= idx && idx < ss->size);
  assert(!SchedulingSequenceIsEmpty(ss));
  TimeInterval *ti = ss->intervals[idx];
  int i = idx;
  for (; i < ss->size - 1; i++)
  {
    swap(&(ss->intervals[i]), &(ss->intervals[i++]));
  }
  ss->size--;
  return ti;
}
