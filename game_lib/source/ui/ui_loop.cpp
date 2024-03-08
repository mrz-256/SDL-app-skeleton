#include "headers/ui/UI.h"

void UI::onLoop(InputData* input_data, Uint64 elapsed_time)
{
    scene_manager->updateCurrent(input_data, elapsed_time);
}