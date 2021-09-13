#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#define AnalogReadPin 5 //? Ăsta să fie?
#define ArrayLength 2

#define RefreshTime 40

#define InitializingStateIndex 0
#define DataEntryStateIndex 1
#define MeasuringStateIndex 2
#define ErrorStateIndex 3
#define ReviewStateIndex 4

#define NumberOfStates 5

// #define InitializingState 0
// #define DataEntryState 1
// #define MeasuringState 2
// #define ProblemState 3   //schimbat din error state
// #define ReviewState 4

//views constants
#define InitializingViewIndex 0 //ordine index?
#define DataInputViewIndex 1
#define MeasurementViewIndex 2
#define ProblemViewIndex 3
#define ReviewViewIndex 4

#define NumberOfViews 5

#define NumberOfPhysicalDimensions 3

#define CycleTime 40 //25 fps
#define MeasurementTime 1000 //once per second, according to Peeeony
#define CSpin 5 //trebuie definit pin-ul 
#define FullCapacity 10 //cate cnp-uri se pot inregistra

#endif