#include "headers/ui/UI.h"

void UI::onLoop(InputData* input_data, Uint64 elapsed_time)
{
    SceneManager::get()->updateCurrent(input_data, elapsed_time);
}