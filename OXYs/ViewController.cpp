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
    _viewPointerArray = new BaseView[NumberOfViews];

    InitializingView initializingView = InitializingView();
    _viewPointerArray[InitializingViewIndex] = initializingView;
    DataInputView dataInputView = DataInputView();
    _viewPointerArray[DataInputViewIndex] = dataInputView;
    MeasurementView measurementView = MeasurementView();
    _viewPointerArray[MeasurementViewIndex] = measurementView;
    ProblemView problemView = ProblemView();
    _viewPointerArray[ProblemViewIndex] = problemView;
    ReviewView reviewView = ReviewView();
    _viewPointerArray[ReviewViewIndex] = reviewView;

    _currentView = _viewPointerArray[InitializingViewIndex];
}

ViewController::HandleCommand(byte command)
{
    byte nextViewIndex = _currentView.HandleCommand(command);
    _currentView = _viewPointerArray[nextViewIndex];
    //notificare că s-a schimbat view-ul
}