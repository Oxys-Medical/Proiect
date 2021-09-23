//#include "BaseView.h"
//#include "InitializingView.h"
//#include "DataInputView.h"
//#include "MeasurementView.h"
//#include "ProblemView.h"
//#include "ReviewView.h"
#include "ViewController.h"
//#include "Constants.h"
//#include "Commands.h"
//#include "UiButton.h"
//#include "UiElement.h"

//void UiElement::Animate(){}

ViewController::ViewController()
{
//    _stateMachine = StateMachine();
//    _displayDriver = DisplayDriver();
//    _displayDriver.Initialize();
//
//    _viewArray = new BaseView[NumberOfViews];
//
//    InitializingView initializingView = InitializingView();
//    _viewArray[InitializingViewIndex] = initializingView;
//    DataInputView dataInputView = DataInputView(_displayDriver, _stateMachine);
//    _viewArray[DataInputViewIndex] = dataInputView;
//    MeasurementView measurementView = MeasurementView(_displayDriver, _stateMachine);
//    _viewArray[MeasurementViewIndex] = measurementView;
//    ProblemView problemView = ProblemView(_displayDriver, _stateMachine);
//    _viewArray[ProblemViewIndex] = problemView;
//    ReviewView reviewView = ReviewView(_displayDriver, _stateMachine);
//    _viewArray[ReviewViewIndex] = reviewView;
//
//    _currentViewIndex = 99; //trebe initializat undeva
//    UpdateView(InitializingViewIndex); //trebuie facuta functie update view
};
void ViewController :: HandleCommand() 

{Serial.println("Roxana  afost aici");
//    int* contactPoint = _displayDriver.GetContactPoint();
//    byte nextViewIndex = _currentView.HandleCommand(contactPoint);
//    UpdateView(nextViewIndex);
}

void ViewController :: UpdateView(byte viewIndex) //am facut bine? E bine, boss.
{
//    if (viewIndex != _currentViewIndex)
//    {
//        _currentViewIndex = viewIndex;
//        _currentView = _viewArray[viewIndex];
//        _currentView.Display();
//    }
}
