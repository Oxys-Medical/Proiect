#include "InitializingView.cpp"
#include "DataInputView.cpp"
#include "MeasurementView.cpp"
#include "ProblemView.cpp"
#include "ReviewView.cpp"
#include "ViewController.h"
#include "Constants.h"
#include "BaseView.h"

ViewController::ViewController()
{
    _stateMachine = StateMachine();
    _displayDriver = DisplayDriver();
    _displayDriver.Initialize();

    _viewArray = new BaseView[NumberOfViews];

    InitializingView initializingView = InitializingView();
    _viewArray[InitializingViewIndex] = initializingView;
    DataInputView dataInputView = DataInputView();
    _viewArray[DataInputViewIndex] = dataInputView;
    MeasurementView measurementView = MeasurementView();
    _viewArray[MeasurementViewIndex] = measurementView;
    ProblemView problemView = ProblemView();
    _viewArray[ProblemViewIndex] = problemView;
    ReviewView reviewView = ReviewView();
    _viewArray[ReviewViewIndex] = reviewView;

    _currentView = _viewArray[InitializingViewIndex];
};

byte ViewController::HandleCommand(int* contactPoint)
{
    int* contactPoint = _displayDriver.GetContactPoint();
    byte nextViewIndex = _currentView.HandleCommand(contactPoint);
    _currentView = _viewArray[nextViewIndex];
    //notificare că s-a schimbat view-ul
BaseView::HandleCommand(contactPoint);
return nextViewIndex;
}
