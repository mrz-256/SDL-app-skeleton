#include "../../headers/app/UI.h"

UI::UI() : window(nullptr), renderer(nullptr), running(true), game(nullptr)
{}

int UI::onExecute()
{
    return 123;
}



int main()
{
    UI app;
    return app.onExecute();
}