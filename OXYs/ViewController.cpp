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
    contactPoint = _displayDriver.GetContactPoint();
    byte nextViewIndex = _currentView.HandleCommand(contactPoint);
    _currentView = _viewArray[nextViewIndex];
    //notificare că s-a schimbat view-ul
    //BaseView::HandleCommand(contactPoint); oare trebe
    return nextViewIndex;
}
