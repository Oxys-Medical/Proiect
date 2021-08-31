#include "BaseView.h"
#include "InitializingView.h"
#include "DataInputView.h"
#include "MeasurementView.h"
#include "ProblemView.h"
#include "ReviewView.h"
#include "ViewController.h"
#include "Constants.h"
#include "Commands.h"


ViewController::ViewController()
{
    _stateMachine = StateMachine();
    _displayDriver = DisplayDriver();
    _displayDriver.Initialize();

    _viewArray = new BaseView[NumberOfViews];

    InitializingView initializingView = InitializingView();
    _viewArray[InitializingViewIndex] = initializingView;
    DataInputView dataInputView = DataInputView(DisplayDriver,StateMachine);
    _viewArray[DataInputViewIndex] = dataInputView;
    MeasurementView measurementView = MeasurementView();
    _viewArray[MeasurementViewIndex] = measurementView;
    ProblemView problemView = ProblemView();
    _viewArray[ProblemViewIndex] = problemView;
    ReviewView reviewView = ReviewView();
    _viewArray[ReviewViewIndex] = reviewView;

    _currentViewIndex = 99; //trebe initializat undeva
    UpdateView(InitializingViewIndex); //trebuie facuta functie update view
};

void ViewController :: HandleCommand() 
{
    int* contactPoint = _displayDriver.GetContactPoint();
    byte nextViewIndex = _currentView.HandleCommand(contactPoint);
    UpdateView(nextViewIndex);
}

void ViewController :: UpdateView(byte viewIndex) //am facut bine?
{
    if (viewIndex != _currentViewIndex)
    {
        _currentViewIndex = viewIndex;
        _currentView = _viewArray[viewIndex];
        _currentView.Display();
    }
}
